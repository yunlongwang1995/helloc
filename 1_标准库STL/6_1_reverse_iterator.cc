//
// Created by wangyunlong01 on 2022/6/22.
//
#include <list>
#include <iostream>

using namespace std;

int main() {
    list<int> values = {1,2,3,4,5,6};

    reverse_iterator<list<int>::iterator> rbegin = values.rbegin();
    reverse_iterator<list<int>::iterator> rend = values.rend();

    cout << "倒序: ";
    while (rbegin != rend) {
        cout << *rbegin << "  ";
        ++rbegin;
    }
}
