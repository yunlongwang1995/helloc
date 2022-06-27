//
// Created by wangyunlong01 on 2022/6/27.
//

#include <string>
#include <iostream>

using namespace std;

int main() {
    string val = "(())";
    // 1. c_str
    const char *p = val.c_str();
    cout << "c_str():\n" << *p << endl;
    p++;
    cout << *p << endl;
    p += 2;
    cout << (*p == 0) << endl;

    // 2. data()
    const char *p2 = val.data();
    cout << "data():\n" << *p2 << endl;
    p2++;
    cout << *p2 << endl;
    p2 += 2;
    cout << (*p2 == 0) << endl;

    // 3. find
    int idx = val.find(")*", 0);
    cout << "first: " << (idx) << endl;

    // 4. find_first_of
    cout << "find_first_of: " << val.find_first_of("()", 0) << endl;

    // 5. sub_str
    cout << "sub_str: " << (val.substr(0, 2) == "((") << endl;
}