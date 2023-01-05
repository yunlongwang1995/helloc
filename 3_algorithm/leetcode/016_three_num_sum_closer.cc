/**
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
 * 请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    // 排序
    sort(nums.begin(), nums.end());

    int closetNum = nums[0] + nums[1] + nums[2];
    int gap = abs(closetNum-target);
    // 双指针
    for (int i=0; i<nums.size()-2; ++i) {
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int t = nums[i]+nums[left]+nums[right];
            if (abs(t-target) < gap) {
                closetNum = t;
                gap = abs(t-target);
            }

            if (t < target) {
                left++;
            } else if (t > target) {
                right--;
            } else {
                return closetNum;
            }
        }
    }

    return closetNum;
}

int main() {
    vector<int> param{0, 2, 1, -3};
    cout << threeSumClosest(param, 1) << endl;
}