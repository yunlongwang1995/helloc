//
// Created by wangyunlong01 on 2022/6/22.
//
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<int> values = {1,2,3,4,5,6,7,8,9};
    copy(values.begin(), values.end(),ostream_iterator<int>(cout, " "));
}
