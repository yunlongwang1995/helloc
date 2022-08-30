/**
 * 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，
 * 达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
 * 该路径 至少包含一个 节点，且不一定经过根节点。
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 * 思路: root  left  right　三者间组合
 *   - root
 *   - left（与 root 不连接）
 *   - right（与 root 不连接）
 *   - root + left
 *   - root + right
 *   - root + left + right
 */

#include "../../base.h"

int ret = INT32_MIN;
int getMax(TreeNode* root) {
  // 基准情况
  if (root == nullptr) {
    return 0;
  }

  int left = max(0, getMax(root->left));
  int right = max(0, getMax(root->right));
  ret = max(ret, root->val + left + right);
  return max(left, right) + root->val;
}

int maxPathSum(TreeNode *root) {
  getMax(root);
  return ret;
}

int main() {

}