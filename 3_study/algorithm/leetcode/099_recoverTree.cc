/**
 * 给你二叉搜索树的根节点 root ，该树中的 恰好 两个节点的值被错误地交换。
 * 请在不改变其结构的情况下，恢复这棵树 。
 *
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 *
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 *
 * 思路：中序遍历是排序的
 */

#include "../../../base.h"

void midorder(TreeNode* root, vector<TreeNode*>* array) {
  // 基准
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    array->push_back(root);
    return;
  }

  // 非基准
  midorder(root->left, array);
  array->push_back(root);
  midorder(root->right, array);
}

void recoverTree(TreeNode* root) {
  if (root == NULL) {
    return;
  }
  vector<TreeNode*> array;
  midorder(root, &array);
  TreeNode* first = NULL;
  TreeNode* first_next = NULL;
  TreeNode* second = NULL;
  TreeNode* pre = NULL;

  for (auto cur : array) {
    if (pre == NULL) {
      pre = cur;
      continue;
    }
    if (pre->val >= cur->val) {
      if (first == NULL) {
        first = pre;
        first_next = cur;
      } else {
        second = cur;
        break;
      }
    }
    pre = cur;
  }

  if (second != NULL) {
    swap(first->val, second->val);
  } else {
    swap(first->val, first_next->val);
  }
}

int main() {
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);

  n1->left = n3;
  n3->right = n2;

  recoverTree(n1);
}