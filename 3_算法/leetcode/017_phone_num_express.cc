/**
 * 电话号码的字母组合
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, string> m = {
        {'2', "abc"},
        {'3',"def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
};

vector<string> letterCombinations(string digits) {
    vector<string> res;
    // 基准情况
    if (digits.empty()) {
        return res;
    }
    if (digits.size() == 1) {
        for (auto item:m[digits[0]]) {
            res.emplace_back(1,item);
        }
        return res;
    }

    // 非基准
    vector<string> subStr = letterCombinations(digits.substr(1));
    for (auto item:m[digits[0]]) {
        for (auto item1: subStr) {
            res.push_back(item+item1);
        }
    }

    return res;
}

int main() {
    for (auto item: letterCombinations("23")) {
        cout << item << "  " << endl;
    }
}