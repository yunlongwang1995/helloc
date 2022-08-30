//
// Created by wangyunlong01 on 2022/6/28.
//

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdio.h>
using namespace std;

/**
    多路复用：poll
        与 select 基本一样，区别是：没有1024个文件描述符的限制，
        fd_set 采用数组数据结构（select采用bitmap）．
*/

int main() {

}