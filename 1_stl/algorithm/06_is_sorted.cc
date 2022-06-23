//
// Created by wangyunlong01 on 2022/6/23.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    vector<int> values = { 2,3,5,4,1,6,9,7};
    cout << is_sorted(values.begin(), values.end()) << endl;
    cout << is_sorted(values.begin(), values.begin()+3) << endl;

    auto it = is_sorted_until(values.begin(), values.end());
    assert(it != values.end());
    cout << "破坏点：" << *it << endl;
}