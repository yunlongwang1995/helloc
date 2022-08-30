/**
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 * 输入：head = []
 * 输出：[]
 */

#include "../../base.h"

ListNode* reverseList(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode* secondNode = head->next;
  ListNode* cur = head->next;         // 当前节点
  ListNode* next;                     // 下一个处理节点
  while (cur) {
    next = cur->next;

    cur->next = head->next;
    head->next = cur;

    cur = next;
  }

  secondNode->next = head;
  ListNode* newHead = head->next;
  head->next = nullptr;
  return newHead;
}

int main() {

}