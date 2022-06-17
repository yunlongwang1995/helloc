//
// Created by wangyunlong01 on 2022/6/17.
//

#include<ctime>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

// C++方式生成指定长度随机字符串
string GenRandomString(int n) {
    srand((unsigned)time(nullptr));                        //产生随机化种子
    std::string str;

    for(int i=1; i<=n; i++) {
        if(rand()%2 == 1)                        //如果flag=1
            str += rand()%('Z'-'A'+1)+'A';       //追加大写字母的ascii码
        else
            str += rand()%('z'-'a'+1)+'a';       //如果flag=0，追加为小写字母的ascii码
    }

    return str;
}

int main() {
    cout << GenRandomString(10) << endl;
}

