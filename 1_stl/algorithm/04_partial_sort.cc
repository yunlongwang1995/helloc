//
// Created by wangyunlong01 on 2022/6/23.
//

/**
 * 目录:
 * partial_sort
 * partial_sort_copy
 *
 * 均采用堆排序
 * 时间复杂度：Nlog(M)
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    vector<int> values = { 3,2,5,4,1,6,9,7};
    partial_sort(values.begin(), values.begin()+3, values.end());
    cout << "partial_sort 排序后: ";
    for (int item: values) {
        cout << item << "  ";
    }

    list<int> list = { 3,2,5,4,1,6,9,7};
    int nums[4] = {};
    partial_sort_copy(list.begin(), list.end(), nums, nums+4);
    cout << endl << "list 排序前: ";
    for (int item: list) {
        cout << item << "  ";
    }

    cout << endl << "partial_sort_copy 排序后: ";
    for (int item: nums) {
        cout << item << "  ";
    }
}