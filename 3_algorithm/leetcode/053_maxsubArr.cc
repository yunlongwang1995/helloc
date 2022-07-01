/**
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int dp[nums.size()];
    dp[0] = nums[0];
    int max = dp[0];
    for (int i=1; i<nums.size(); ++i) {
        if (dp[i-1] <= 0) {
            dp[i] = nums[i];
        } else {
            dp[i] = nums[i] + dp[i-1];
        }

        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
}