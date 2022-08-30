//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录：(本文件下均采用二分查找原理，故前提均需要排好序)
 * binary_search: 查找数组中是否存在目标值
 * equel_range: 查找相等的一群数据
 * lower_bound: >= target
 * upper_bound: > target
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // binary_search
    vector<int> values = {1,2,3,4,5,6,7,8,9,10};
    bool exist = binary_search(values.begin(), values.end(), 8);
    cout << exist << endl;

    // equel_range


}