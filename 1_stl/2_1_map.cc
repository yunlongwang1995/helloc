//
// Created by wangyunlong01 on 2022/5/6.
//
#include <iostream>
#include <map>

using namespace std;

int main() {

    // 插入方式
    map<string, string> m;
    m["aa"] = "aa111";
    auto r1 = m.insert(pair<string, string>("aa", "aa---"));
    cout << "success: " << r1.second << endl;

    auto r2 = m.emplace("bb", "bb222");
    cout << "success: " << r2.second << endl;

    auto r3 = m.emplace_hint(r1.first, "cc", "cc333");
    cout << "success: " << r3->second << endl;

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }

    cout << "size = " << m.size() << "  max_size = " << m.max_size() << endl;
}

