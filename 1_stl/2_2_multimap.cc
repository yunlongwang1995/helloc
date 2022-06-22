//
// Created by wangyunlong01 on 2022/6/22.
//

#include <map>
#include <iostream>

using namespace std;

int main() {
    multimap<string, string> m;
    auto r1 = m.insert(pair<string, string>("aa", "aa---"));
    cout << "success: " << r1->second << endl;

    auto r2 = m.insert(pair<string, string>("aa", "aa222"));
    cout << "success: " << r2->second << endl;

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }
}