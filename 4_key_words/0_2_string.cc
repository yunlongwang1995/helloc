//
// Created by wangyunlong01 on 2022/6/27.
//

#include <string>
#include <iostream>
using namespace std;

int main() {
    string val = "axc";
    // c_str
    const char* p = val.c_str();
    cout << "c_str():\n" << *p << endl;
    p++;
    cout << *p << endl;
    p+=2;
    cout << (*p == 0) << endl;

    // data()
    const char* p2 = val.data();
    cout << "\ndata():\n" << *p2 << endl;
    p2++;
    cout << *p2 << endl;
    p2+=2;
    cout << (*p2 == 0) << endl;
}