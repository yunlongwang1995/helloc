/**
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target，
 * 找出 candidates 中可以使数字和为目标数 target 的 所有不同组合 ，并以列表形式返回。
 * 你可以按 任意顺序 返回这些组合。
 * 每个数字只能用一次
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

//bool isLeftEqualRight(vector<int>& left, vector<int>& right) {
//    if (left.size() != right.size()) {
//        return false;
//    }
//    for (int i=0; i<left.size(); ++i) {
//        if (left[i] != right[i]) {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//bool isLeftInRight(vector<int>& left, vector<vector<int>>& right) {
//    for (auto item: right) {
//        if (isLeftEqualRight(left, item)) {
//            return true;
//        }
//    }
//
//    return false;
//}

vector<vector<int>> res;
void dfs(vector<int>& candidates, int target, int n, int tmpSum, vector<int>& tmp) {
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

    for (int i=n; i<candidates.size(); ++i) {
        if (tmpSum+candidates[i] > target) {
            break;
        }
        if (i>n && candidates[i]==candidates[i-1]) {
            continue;
        }
        tmp.push_back(candidates[i]);
        dfs(candidates, target, i+1, tmpSum+candidates[i], tmp);
    }
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
    vector<int> candidate = {2,5,2,1,2};
    vector<vector<int>> res = combinationSum(candidate, 5);
    for (auto item: res) {
        for (auto item1: item) {
            cout << item1 << " ";
        }
        cout << endl;
    }
}