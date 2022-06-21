//
// Created by wangyunlong01 on 2022/5/6.
//
#include <iostream>
#include <map>

using namespace std;

int main() {

    map<string, string> m;
    auto r0 = m.insert(pair<string, string>("aa", "aa111"));
    m.emplace("bb", "bb111");
    auto r1 = m.emplace("dd", "dd111");
    cout << r1.first->first << r1.second << endl;
    auto r2 = m.emplace_hint(r1.first, "cc", "cc111");
    cout << r2->first << endl;

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }

    auto r3 = m.at("aa");
    cout << r3 << endl;

    auto r4 = m.find("aa");
    cout << r4->first << " -- " << r4->second << endl;

    auto r5 = m["aa1"];
    cout << "r5 = " << r5 << endl;

    cout << "size = " << m.size() << "  max_size = " << m.max_size() << endl;
}

