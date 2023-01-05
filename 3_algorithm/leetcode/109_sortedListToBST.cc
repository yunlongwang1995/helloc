/**
 * 给定一个单链表的头节点 head，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
 *
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点的左右两个子树的高度差不超过 1。
 *
 */

#include "../../base.h"

TreeNode* helper(vector<ListNode*>& list, int begin, int end) {
  // 基准
  if (begin >= end) {
    return nullptr;
  }
  if (begin + 1 == end) {
    return new TreeNode(list[begin]->val);
  }

  int mid = (begin + end) / 2;
  TreeNode* root = new TreeNode(list[mid]->val);
  root->left = helper(list, begin, mid);
  root->right = helper(list, mid+1, end);

  return root;
}

TreeNode* sortedListToBST(ListNode* head) {
  if (head == nullptr) {
    return nullptr;
  }

  vector<ListNode*> list;
  while (head) {
    list.emplace_back(head);
    head = head->next;
  }

  return helper(list, 0, list.size());
}

int main() {
  ListNode n1(-10);
  ListNode n2(-3);
  ListNode n3(0);
  ListNode n4(5);
  ListNode n5(9);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  sortedListToBST(&n1);
}