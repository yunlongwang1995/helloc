/**
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 */

#include "../../base.h"

class Comp {
public:
  bool operator()(const ListNode* l, const ListNode* r) {
    return l->val > r->val;
  }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  if (lists.empty()) {
    return nullptr;
  }
  priority_queue<ListNode*, vector<ListNode*>, Comp> queue;
  for (auto item: lists) {
    if (item == nullptr) {
      continue;
    }
    queue.push(item);
  }
  if (queue.empty()) {
    return nullptr;
  }

  ListNode* head = queue.top();
  ListNode* p = head;
  queue.pop();
  if (head->next) {
    queue.push(head->next);
  }
  while (!queue.empty()) {
    ListNode* t = queue.top();
    queue.pop();
    if (t->next) {
      queue.push(t->next);
    }
    p->next = t;
    p = p->next;
  }

  return head;
}

int main() {
  ListNode n1 = ListNode(1);
  ListNode n1_1 = ListNode(1);
  ListNode n2 = ListNode(2);
  ListNode n3 = ListNode(3);
  ListNode n4 = ListNode(4);
  ListNode n4_1 = ListNode(4);
  ListNode n5 = ListNode(5);
  ListNode n6 = ListNode(6);

  n1.next = &n4;
  n4.next = &n5;

  n1_1.next = &n3;
  n3.next = &n4_1;

  n2.next = &n6;

  vector<ListNode*> lists = {&n1, &n1_1, &n2};
  ListNode* head = mergeKLists(lists);
  ListNode* p = head;
  while (p) {
    cout << p->val << "  ";
    p = p->next;
  }
}
