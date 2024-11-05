/**
 * 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。
 * 可以按 任意顺序 返回答案。
 *
 *
 */

#include "../../../base.h"

vector<TreeNode*> helper(int begin, int end) {
  // 基准
  if (begin > end) {
    return {NULL};
  }
  vector<TreeNode*> list;
  // 遍历递归
  for (int i=begin; i<=end; ++i) {
    auto subLeft = helper(begin, i-1);
    auto subRight = helper(i+1, end);
    for (auto litem : subLeft) {
      for (auto ritem: subRight) {
        TreeNode* root = new TreeNode(i);
        root->left = litem;
        root->right = ritem;
        list.push_back(root);
      }
    }
  }
  return list;
}

vector<TreeNode*> generateTrees(int n) {
  if (n < 1) {
    return {};
  }
  return helper(1, n);
}

int main() {
  generateTrees(3);
}