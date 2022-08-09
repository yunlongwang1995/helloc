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

#include "../../common.h"

TreeNode* cur;
TreeNode* pre;
TreeNode* t1;
TreeNode* t2;

void inorder(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left);
  pre = cur;
  cur = root;
  if (pre && pre->val > cur->val) {
    if (t1 == nullptr) {
      t1 = pre;
      t2 = cur;
    } else {
      t2 = cur;
    }
  }
  inorder(root->right);
}

void recoverTree(TreeNode* root) {
  inorder(root);
  swap(t1->val, t2->val);
}

int main() {

}