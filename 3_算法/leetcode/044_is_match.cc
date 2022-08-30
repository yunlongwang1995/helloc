/**
 * 给定一个字符串 (s) 和一个字符模式 (p) ，
 * 实现一个支持 '?' 和 '*' 的通配符匹配
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool isMatch(const char *s, int i1, int i2, const char *p, int j1, int j2) {
    // 基准
    if (i1 == i2 && j1 == j2) {
        return true;
    }
    if (j1 == j2) {
        return false;
    }
    if (i1 == i2) {
        for (int i = j1; i < j2; ++i) {
            if (*(p + i) != '*') {
                return false;
            }
        }
        return true;
    }

    // 递归
    if (p[j1] != '*') {
        if (p[j1] == s[i1] || p[j1] == '?') {
            return isMatch(s, i1 + 1, i2, p, j1 + 1, j2);
        }
        return false;
    }

    if (isMatch(s, i1 + 1, i2, p, j1, j2) || isMatch(s, i1, i2, p, j1 + 1, j2)) {
        return true;
    }
    return isMatch(s, i1 + 1, i2, p, j1 + 1, j2);
}

bool isMatch(string s, string p) {
    if (s == p) {
        return true;
    }
    string p1;
    p1.push_back(p[0]);
    for (int i = 1; i < p.size(); ++i) {
        if (p[i] == '*' && p[i - 1] == '*') {
            continue;
        }
        p1.push_back(p[i]);
    }

    return isMatch(s.data(), 0, s.size(), p1.data(), 0, p1.size());
}


int main() {
    cout << isMatch("", "") << endl;
}