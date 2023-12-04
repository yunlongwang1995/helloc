/**
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
 * 返回满足题意的二叉搜索树的种数。
 *
 * 输入：n = 3
 * 输出：5
 */

#include "../../../base.h"

//int helper(int begin, int end) {
//  // 基准
//  if (begin > end) {
//    return 0;
//  }
//  if (begin == end) {
//    return 1;
//  }
//
//  int num = 0;
//  for (int i=begin; i<=end; ++i) {
//    int subLeft = helper(begin, i-1);
//    int subRight = helper(i+1, end);
//    if (subLeft == 0) {
//      num+=subRight;
//      continue;
//    }
//    if (subRight == 0) {
//      num+=subLeft;
//      continue;
//    }
//    num+= subLeft*subRight;
//  }
//
//  return num;
//}
//
//int numTrees(int n) {
//  if (n <= 1) {
//    return n;
//  }
//
//  return helper(1, n);
//}

// 动态规划
int numTrees(int n) {
  if (n <= 1) {
    return n;
  }

  int dp[n+1];
  dp[0] = 1;
  dp[1] = 1;
  for (int i=2; i<=n; ++i) {
    dp[i] = 0;
    for (int j=1; j<=i; ++j) {
      dp[i] += dp[j-1] * dp[i-j];
    }
  }

  return dp[n];
}

int main() {
  cout << numTrees(3) << endl;
}