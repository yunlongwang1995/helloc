//
// Created by wangyunlong01 on 2022/6/23.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    // all_of
    list<int> values = {11, 13, 15, 17, 19};
    bool is_all_odd_num = all_of(values.begin(), values.end(), [](int v) -> bool {
        return v%2 == 1;
    });
    cout << "is_all_odd_num = " << is_all_odd_num << endl;

    // any_of

    // none_of
    bool is_none_less_12 = none_of(values.begin(), values.end(), [](int v) -> bool {
        return v < 12;
    });
    cout << "is_none_less_12 = " << is_none_less_12 << endl;
}