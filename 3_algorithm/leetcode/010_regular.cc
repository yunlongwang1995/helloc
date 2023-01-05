/**
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 */

#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    return isMatch(s.c_str(), p.c_str());
}

bool isMatch(const char* s, const char* p) {
    // p 为空，则取决与 s 是否为空
    if(*p == 0)
        return *s == 0;

    // p 不为空
    auto first_match = *s && (*s == *p || *p == '.');

    if(*(p+1) == '*'){
        return isMatch(s, p+2) || (first_match && isMatch(++s, p));
    } else {
        return first_match && isMatch(++s, ++p);
    }
}

// 简易版，容易理解，要明白*的出现场景
//bool isMatch(string s, string p) {
//    // p 为空，则取决与 s 是否为空
//    if (p.empty())
//        return s.empty();
//
//    // p 不为空
//    auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
//
//    if (p.length() >= 2 && p[1] == '*') {
//        return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
//    } else {
//        return first_match && isMatch(s.substr(1), p.substr(1));
//    }
//}

int main() {
    cout << isMatch("bc", "a*bc") << endl;
}