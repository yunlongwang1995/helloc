/**
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void func(vector<string> &res, string str, int l, int r, int n) {
    if (l > n || r > n || r > l)
        return;
    if (l == n && r == n) {
        res.push_back(str);
        return;
    }

    func(res, str + '(', l + 1, r, n);
    func(res, str + ')', l, r + 1, n);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    func(res, "", 0, 0, n);
    return res;
}

int main() {
    for (auto item: generateParenthesis(3)) {
        cout << item << endl;
    }
}