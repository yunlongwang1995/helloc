/**
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 */

#include "../../../base.h"

using namespace std;

/**
 * 反转链表解析(方法1　只有头节点)
 * @param head
 * 1 2 3 4 5
 * 1
 * 1 2
 * 1 3 2
 * 1 4 3 2
 * 1 5 4 3 2
 * 5 4 3 2 1
 *
 * 或者（使用一个临时节点）
 * t 1
 * t 2 1
 * t 3 2 1
 * t 4 3 2 1
 * t 5 4 3 2 1
 * 5 4 3 2 1
 */

/**
 * 反转链表解析(方法2　有头尾节点)
 * @param head
 * @param tail
 * 1 2 3 4 5
 * 5
 * 5 1
 * 5 2 1
 * 5 3 2 1
 * 5 4 3 2 1
 */

void reverseGroup(ListNode* head, ListNode* tail) {
  ListNode* cur = head;   // 当前遍历的节点
  ListNode* next;         // 下一个遍历的节点
  while (cur != tail) {
    next = cur->next;

    cur->next = tail->next;
    tail->next = cur;     // 以尾节点进行插入

    cur = next;
  }
}

ListNode* reverseKGroup(ListNode* head, int k) {
  if (head == nullptr || head->next == nullptr || k <= 1) {
    return head;
  }

  ListNode* res = head;             // 返回的新头节点

  ListNode* curGroupHead;    // 当前操作组
  ListNode* curGroupTail;
  ListNode* tempTail;
  ListNode* nextGroupHead;   // 下一个组头节点

  ListNode* cur = head;
  int n = 0;
  while (cur) {
    if (n == 0) {
      curGroupHead = cur;
    }
    n++;

    if (n == k) {
      curGroupTail = cur;
      n = 0;
      nextGroupHead = cur->next;

      reverseGroup(curGroupHead, curGroupTail);
      if (res == head) {
        res = curGroupTail;
        tempTail = curGroupHead;
      } else {
        tempTail->next = curGroupTail;
        tempTail = curGroupHead;
      }

      cur = nextGroupHead;
      continue;
    }

    cur = cur->next;
  }

  return res;
}

int main() {
  ListNode n1 = ListNode(1);
  ListNode n2 = ListNode(2);
  ListNode n3 = ListNode(3);
  ListNode n4 = ListNode(4);
  ListNode n5 = ListNode(5);
  ListNode n6 = ListNode(6);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;

  ListNode* head = reverseKGroup(&n1, 3);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
}