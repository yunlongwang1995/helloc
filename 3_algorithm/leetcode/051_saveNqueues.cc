/**
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * n皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<string>> result;
string line;

bool slash(int n, bool **matrix, int row, int col) {
    int r = row - 1;
    int c = col - 1;
    while (r >= 0 && c >= 0) {
        if (matrix[r][c]) {
            return true;
        }
        r--;
        c--;
    }

    r = row - 1;
    c = col + 1;
    while (r >= 0 && c < n) {
        if (matrix[r][c]) {
            return true;
        }
        r--;
        c++;
    }

    return false;
}

void backtracking(const int n, bool **matrix, bool cols[], int okNum, vector<string> &tmp) {
    // 基准
    if (okNum == n) {
        result.emplace_back(tmp);
        return;
    }

    // 遍历递归
    for (int i = 0; i < n; ++i) {
        // 剪枝：已经保证了不同行
        // 剪枝：同列
        if (cols[i]) {
            continue;
        }
        // 剪枝: 斜线
        if (okNum > 0 && slash(n, matrix, okNum, i)) {
            continue;
        }

        cols[i] = true;
        matrix[okNum][i] = true;
        okNum++;

        string s = line;
        tmp.emplace_back(s.replace(i, 1, "Q"));
        backtracking(n, matrix, cols, okNum, tmp);

        // 回溯
        cols[i] = false;
        okNum--;
        matrix[okNum][i] = false;
        tmp.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n) {
    line.reserve(n);
    for (int i = 0; i < n; ++i) {
        line.push_back('.');
    }
    bool cols[n];
    for (int i = 0; i < n; ++i) {
        cols[i] = false;
    }
    bool *matrix[n];
    for (int i = 0; i < n; i++) {
        bool *item = new bool[n];
        for (int j = 0; j < n; j++) {
            item[j] = false;
        }
        matrix[i] = item;
    }
    vector<string> tmp;
    backtracking(n, matrix, cols, 0, tmp);
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    return result;
}


int main() {
    auto res = solveNQueens(4);
    for (auto item: res) {
        for (auto item1: item) {
            cout << item1 << " ";
        }
        cout << endl;
    }
}