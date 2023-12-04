/**
 * 两数相加
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 */

#include "../../base.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* res = nullptr;
      ListNode* p = nullptr;
      int val1 = 0;
      int val2 = 0;
      int carry = 0;
      int sum = 0;
      do {
        if (l1) {
          val1 = l1->val;
          l1 = l1->next;
        } else {
          val1 = 0;
        }
        if (l2) {
          val2 = l2->val;
          l2 = l2->next;
        } else {
          val2 = 0;
        }

        sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ListNode* n = new ListNode(sum);
        if (res == nullptr) {
          res = n;
          p = n;
        } else {
          p->next = n;
          p = p->next;
        }
      } while (l1 != nullptr || l2 != nullptr);

      if (carry == 1) {
        ListNode* n = new ListNode(carry);
        p->next = n;
      }

      return res;
    }
};

int main() {

}