//
// Created by wangyunlong01 on 2022/6/22.
//

/**
 * lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。
 * 也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，
 * 还可能是比目标值大的元素。
 * @return
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool mycmp(int i, int j) {
    return i > j;
}

int main() {

    // 在 [first, last) 区域内查找不小于 val 的元素
    vector<int> values = {1,3,5,9,10};
    auto p = lower_bound(values.begin(), values.end(), 5);
    cout << "p = " << *p << endl;

    // 在 [first, last) 区域内查找第一个不符合 comp 规则的元素
    vector<int> values2 = {15, 12,6,10,5};
    auto p2 = lower_bound(values2.begin(), values2.end(), 7, mycmp);
    cout << "p2 = " << *p2 << endl;
}