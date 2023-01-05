/**
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 假设你总是可以到达数组的最后一个位置。
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums) {
    int length = nums.size();
    if (length == 1) {
        return 0;
    }
    int dp[length];
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<length; ++i) {
        int min = dp[i-1] + 1;
        for (int j=i-2; j>=0; --j) {
            if (dp[j] == dp[i-1]) {
                continue;
            }
            if (nums[j]>=(i-j)) {
                min = dp[j] + 1;
            }
        }
        dp[i] = min;
    }

    return dp[length-1];
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums)<< endl;
}