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
    多路复用：select
        监听socket会阻塞到listen()
        客户端socket会阻塞到recv()
    而select会统一管理阻塞上面的两种socket

    事件（水平触发）：
        有请求连接（监听socket）
        有数据可读（客户端socket）
        socket断开连接（客户端socket）

    优点：

    缺点：
        １）只能监听1024个socket（当然可以修改，但没必要，每种实现方式都有具体的使用场景），
        若调大效率更低，因为是对 fd_set 进行遍历．
        ２）每次都需要把 fd_set 从用户态拷贝到内核态．
        ３）同时有事件情况很少，但是需要对 fd_set 进行遍历．．．
*/

int main() {

}