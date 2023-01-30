#include "../../base.h"

typedef struct dlist_node {
  struct dlist_node* prev;
  struct dlist_node* next;
} dlist_node;

typedef struct dlist_head {
  dlist_node head; // 提示：该head 为哨兵节点
} dlist_head;

static inline void dlist_init(dlist_head* head) {
  head->head.next = head->head.prev = &head->head;
}

// 实现下面几个函数：
// 判断链表是否为空
static inline bool dlist_is_empty(dlist_head* head){
  if(head->head.next == &head->head) {
    return true;
  }

  return false;
}

// 插入到链表的第一个位置
static inline void dlist_push_head(dlist_head* head, dlist_node* node){
  // 先把插入节点的前后指针连上
  node->next = head->head.next;
  node->prev = &head->head;

  // 再把哨兵节点后的节点　及　哨兵节点指针连上
  head->head.next->prev = node;
  head->head.next = node;
}

// 插入到链表的最后一个位置
static inline void dlist_push_tail(dlist_head* head, dlist_node* node){
  node->next = &head->head;
  node->prev = head->head.prev;

  head->head.prev->next = node;
  head->head.prev = node;
}

// 合并两个链表，确保第二个链表的第一个元素，在第一个链表的最后一个元素后面
static inline void dlist_merge(dlist_head* first, dlist_head* second){
  if (dlist_is_empty(second)) {
    return;
  }

  first->head.prev->next = second->head.next;
  second->head.next->prev = first->head.prev;

  second->head.prev->next = &first->head;
  first->head.prev = second->head.prev;
}



int main(int argc, char* argv[]) {
  std::cout << "hello world" << std::endl;
}