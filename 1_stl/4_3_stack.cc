//
// Created by wangyunlong01 on 2022/6/22.
//
#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << endl;
}