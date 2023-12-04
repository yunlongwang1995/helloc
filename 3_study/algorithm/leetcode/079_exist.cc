/**
 *
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
 * 如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，
 * 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 */

#include "../../../base.h"

bool dfs(vector<vector<char>>& board, string& word,
         int size, int x, int y, vector<vector<int>>& f) {
  if (size == word.size()) {
    return true;
  }//outofbound
  if (x < 0 || x >= board.size()
      || y < 0 || y > board[0].size()
      || board[x][y] != word[size]) {
    return false;
  }
  if (f[x][y] == 0) {
    f[x][y] = 1;
    if (dfs(board, word, size + 1, x + 1, y, f)
        || dfs(board, word, size + 1, x - 1, y, f)
        || dfs(board, word, size + 1, x, y + 1, f)
        || dfs(board, word, size + 1, x, y - 1, f)) {
      return true;
    }
    f[x][y] = 0;
  }
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  if (board.empty() || word.empty()) {
    return false;
  }
  int row = board.size(), col = board[0].size();
  vector<vector<int>> f(row, vector<int>(col, 0));
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (dfs(board, word, 0, i, j, f)) {
        return true;
      }
    }
  }
  return false;
}

int main() {

}