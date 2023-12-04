/**
 * 给定一个字符串 s ，找出其中不含有重复字符的 最长子串 的长度。
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) {
        return s.length();
    }

    // 声明局部变量，一定要初始化
    int hash[128];
    for (int i = 0; i < 128; i++) {
        hash[i] = -1;
    }

    int maxLength = 0;
    int temp = 0;
    for (int i = 0; i < s.length(); i++) {
        char item = s.at(i);
        if (hash[item] == -1) {
            temp++;
        } else {
            temp = min(i - hash[item], temp + 1);
        }
        hash[item] = i;
        if (temp > maxLength) {
            maxLength = temp;
        }
    }

    return maxLength;
}

int main() {
    cout << lengthOfLongestSubstring("abba") << endl;
}