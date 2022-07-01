/**
 * 给定一个含重复数字的数组 nums ，返回其 所有可能的全排列 。
 * 你可以 按任意顺序 返回答案。
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &tmp, bool exist[]) {
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
        if (i>0 && nums[i]==nums[i-1] && exist[i-1]==false) {
            continue;
        }
        tmp.emplace_back(nums[i]);
        exist[i] = true;
        dfs(res, nums, tmp, exist);

        tmp.pop_back();
        exist[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    bool exist[nums.size()];
    for (int i=0; i<nums.size(); ++i) {
        exist[i] = false;
    }

    sort(nums.begin(), nums.end());
    dfs(res, nums, tmp, exist);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = permuteUnique(nums);
    for (auto item: res) {
        for (auto item1: item) {
            cout << item1 << " ";
        }
        cout << endl;
    }
}