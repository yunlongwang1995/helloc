/**
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。
 * 你可以 按任意顺序 返回答案。
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, bool exist[]) {
  // 基准
  if (tmp.size() == nums.size()) {
    res.emplace_back(tmp);
    return;
  }

  // 遍历递归
  for (int i = 0; i < nums.size(); ++i) {
    if (exist[i]) {
      continue;
    }
    tmp.emplace_back(nums[i]);
    exist[i] = true;
    dfs(res, nums, tmp, exist);

    tmp.pop_back();
    exist[i] = false;
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> res;
  vector<int> tmp;
  bool exist[nums.size()];
  for (int i = 0; i < nums.size(); ++i) {
    exist[i] = false;
  }

  dfs(res, nums, tmp, exist);
  return res;
}

int main() {
  vector<int> nums = {1, 2, 3};
  auto res = permute(nums);
  for (auto item: res) {
    for (auto item1: item) {
      cout << item1 << " ";
    }
    cout << endl;
  }
}