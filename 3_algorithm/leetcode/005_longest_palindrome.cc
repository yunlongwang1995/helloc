/**
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 * dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]
 */

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int length = s.length();
    if (length <= 1) {
        return s;
    }

    // dp[i][j] 代表字串（i,j）是否是回文字符串
    bool dp[length][length];
    for (int i=0; i<length; ++i) {
        dp[i][i] = true;
    }

    int min = 0;
    int maxSubStr = 1;

    // dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]
    for (int dis=1; dis < length; ++dis) {
        for (int i=0; i<length; ++i) {
            int j = i + dis;
            if (j >= length)
                break;
            if (s.at(i) != s.at(j)) {
                dp[i][j] = false;
                continue;
            }

            if (dis == 1) {
                dp[i][j] = true;
            } else {
                dp[i][j] = dp[i+1][j-1];
            }
            if (dp[i][j] && j-i+1 > maxSubStr) {
                min = i;
                maxSubStr = j - i + 1;
            }
        }
    }

    return s.substr(min, maxSubStr);
}

int main() {
    cout << longestPalindrome("aacabdkacaa") << endl;
}