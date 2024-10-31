/**
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 */


/**
 * 解题思路:
 *
 * 如果 word1[0..i-1] 到 word2[0..j-1] 的变换需要消耗 k 步，
 * 那 word1[0..i] 到 word2[0..j] 的变换需要几步呢？
 * 答: 先使用 k 步，把 word1[0..i-1] 变换到 word2[0..j-1]，消耗 k 步。再把 word1[i] 改成 word2[j]，就行了。
 * 如果 word1[i] == word2[j]，什么也不用做，一共消耗 k 步，否则需要修改，一共消耗 k + 1 步。

 * 如果 word1[0..i-1] 到 word2[0..j] 的变换需要消耗 k 步，那 word1[0..i] 到 word2[0..j] 的变换需要消耗几步呢？
 * 答：先经过 k 步，把 word1[0..i-1] 变换到 word2[0..j]，消耗掉 k 步，再把 word1[i] 删除，
 * 这样，word1[0..i] 就完全变成了 word2[0..j] 了。一共 k + 1 步。

 * 如果 word1[0..i] 到 word2[0..j-1] 的变换需要消耗 k 步，那 word1[0..i] 到 word2[0..j] 的变换需要消耗几步呢？
 * 答：先经过 k 步，把 word1[0..i] 变换成 word2[0..j-1]，消耗掉 k 步，接下来，
 * 再插入一个字符 word2[j], word1[0..i] 就完全变成了 word2[0..j] 了。
 */

#include "../../../base.h"

using namespace std;

int minDistance(string word1, string word2) {
  int m = word1.length();
  int n = word2.length();

  vector<vector<int>> cost(m + 1, vector<int>(n + 1));

  for (int i = 0; i <= m; ++i) {
    cost[i][0] = i;
  }
  for (int j = 0; j <= n; ++j) {
    cost[0][j] = j;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (word1[i - 1] == word2[j - 1]) {
        cost[i][j] = cost[i - 1][j - 1];
      } else {
        cost[i][j] = 1 + min(cost[i - 1][j - 1], min(cost[i][j - 1], cost[i - 1][j]));
      }
    }
  }
  return cost[m][n];
}

int main() {
  cout << minDistance("horse", "ros") << endl;
}