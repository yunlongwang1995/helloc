/**
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    if (s.length() <= numRows || numRows == 1) {
        return s;
    }

    vector<string> subStrings(numRows);
    for (int i = 0; i < s.length(); ++i) {
        int remainder = i % (2 * numRows - 2);
        if (remainder < numRows) {
            subStrings[remainder].push_back(s[i]);
        } else {
            subStrings[2 * numRows - 2 - remainder].push_back(s[i]);
        }
    }

    string res;
    for (int i = 0; i < numRows; ++i) {
        res.append(subStrings[i]);
    }

    return res;
}


int main() {
    std::cout << convert("PAYPALISHIRING", 3) << std::endl;
}