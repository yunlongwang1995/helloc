/**
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 * dp[i][j] 代表是否是合法的括号字串
 * dp[i][j] = (s[i]=='(' && s[j]==')') && dp[i+1][j-1]
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int longestValidParentheses(string s) {
  if (s.size() < 2) {
    return 0;
  }

  int length = s.size();
  bool dp[length][length];
  for (int i = 0; i < length; ++i) {
    for (int j = i; j < length; ++j) {
      dp[i][i] = false;
    }
  }

  int maxLength = 0;
  for (int dis = 1; dis < length;) {
    for (int i = 0; i < length; ++i) {
      int j = i + dis;
      if (j >= length) {
        break;
      }
      if (s[i] == '(' && s[j] == ')') {
        if (dis == 1 || dp[i+1][j-1]) {
          dp[i][j] = true;
        } else {
          if (s[i+1] == ')' && s[j-1] == '(') {
            if (j-i == 3) {
              dp[i][j] = true;
            } else {
              dp[i][j] = dp[i+2][j-2];
            }
          }
        }

        if (dp[i][j]) {
          if (j - i + 1 > maxLength) {
            maxLength = j - i + 1;
          }
        }
      }
    }
    dis = dis + 2;
  }

  return maxLength;
}

int main() {
  cout << longestValidParentheses("(()") << endl;
}