/**
 * 数独的解法需 遵循如下规则：
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 *
 */

#include "../../base.h"

using namespace std;

bool dfs(vector<vector<char>>& board, array<array<bool, 9>, 9>& row, array<array<bool, 9>, 9>& col, array<array<bool, 9>, 9>& block, int i, int j) {

}

void solveSudoku(vector<vector<char>>& board) {

  // 记录某行，某位数字是否已经被摆放
  array<array<bool, 9>, 9> row;

  // 记录某列，某位数字是否已经被摆放
  array<array<bool, 9>, 9> col;

  // 记录某 3x3 宫格内，某位数字是否已经被摆放
  array<array<bool, 9>, 9> block;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        int num = board[i][j] - '1';
        row[i][num] = true;
        col[j][num] = true;
        // blockIndex = i / 3 * 3 + j / 3，取整
        block[i / 3 * 3 + j / 3][num] = true;
      }
    }
  }
  dfs(board, row, col, block, 0, 0);
}

int main() {

}
