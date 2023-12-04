/**
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void recursion(vector<string> &res, string item, int left, int right, int n) {
    if (left > n || right > left) {
        return;
    }
    if (left == n && right == n) {
        res.emplace_back(item);
        return;
    }

    if (left != n) {
        recursion(res, item + "(", left + 1, right, n);
    }
    recursion(res, item + ")", left, right + 1, n);
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    recursion(res, "", 0, 0, n);
    return res;
}

int main() {
    for (auto item: generateParenthesis(3)) {
        cout << item << endl;
    }
}