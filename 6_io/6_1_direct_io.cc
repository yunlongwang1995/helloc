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
  C++ 语言原生 SDK 貌似不支持 直接IO，都是 缓存IO.
  Linux提供了对这种需求的支持，即在open调用的系统中增加了参数选项O_DIRECT，
  用它打开的文件便可以绕过内核缓冲区，这样便有效的避免了CPU和内存占用时间的消耗。
*/

int main() {

}