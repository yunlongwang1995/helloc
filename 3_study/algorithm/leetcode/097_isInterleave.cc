/**
 * 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
 *
 * 两个字符串，立即想动态规划
 */

#include "../../../base.h"

bool isInterleave(string s1, string s2, string s3) {
    auto m = s1.length();
    auto n = s2.length();
    if (m + n != s3.length()) {
        return false;
    }

    // 初始化
    bool dp[m+1][n+1];
    for (int i=0; i<=m; ++i) {
        for (int j=0; j<=n; ++j) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for (int i=1; i<=m; ++i) {
        if (s1[i-1] == s3[i-1]) {
            dp[i][0] = true;
        } else {
            break;
        }
    }
    for (int i=1; i<=n; ++i) {
        if (s2[i-1] == s3[i-1]) {
            dp[0][i] = true;
        } else {
            break;
        }
    }

    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            if (s1[i-1] == s3[i-1+j]) {
                if (dp[i-1][j]) {
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
            }
            if (s2[j-1] == s3[i+j-1]) {
                if (dp[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
}