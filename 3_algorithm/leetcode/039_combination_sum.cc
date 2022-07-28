/**
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target，
 * 找出 candidates 中可以使数字和为目标数 target 的 所有不同组合 ，并以列表形式返回。
 * 你可以按 任意顺序 返回这些组合。
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void dfs(vector<int>& candidates, int target, int n, int tmpSum, vector<int>& tmp) {

  // 基准条件
  if (tmpSum > target) {
    tmp.pop_back();
    return;
  }
  if (tmpSum == target) {
    vector<int> r = tmp;
    res.emplace_back(r);
    tmp.pop_back();
    return;
  }

  // 遍历递归
  for (int i = n; i < candidates.size(); ++i) {
    if (tmpSum + candidates[i] > target) {
      break;
    }
    tmp.push_back(candidates[i]);
    dfs(candidates, target, i, tmpSum + candidates[i], tmp);
  }

  // 回溯
  if (!tmp.empty()) {
    tmp.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  vector<int> tmp;
  dfs(candidates, target, 0, 0, tmp);
  return res;
}

int main() {
  vector<int> candidate = {2};
  vector<vector<int>> res = combinationSum(candidate, 1);
  for (auto item: res) {
    for (auto item1: item) {
      cout << item1 << " ";
    }
    cout << endl;
  }
}