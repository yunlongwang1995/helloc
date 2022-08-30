//
// Created by wangyunlong01 on 2022/6/23.
//
/**
 * 目录:
 * search: 查询子序列 B 在序列 A 中的第一个位置，与 find_end 函数相反
 * search_n: 在指定区域内查找第一个符合要求的子序列。search 查找的子序列中可包含多个不同的元素,
 *           而后者查找的只能是包含多个相同元素的子序列。
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // search
    vector<int> values = {4,2,3,1,5,3,1};
    int sub_array[] = {3, 1};
    auto it = search(values.begin(), values.end(), sub_array, sub_array+2);
    if (it != values.end()) {
        cout << "first sub array position: " << it - values.begin() << endl;
    }

    //

}

