//
// Created by wangyunlong01 on 2022/6/22.
//
#include <iostream>
#include <unistd.h>
#include "../base.h"
static int num = 0;

int main() {
  log("main pid: %d, main ppid: %d", getpid(), getppid());
  sleep(3);
  pid_t p = fork();
  if (p == 0) {
    for (int i=0; i<20; i++) {
      log("[%d]sub pid: %d, sub ppid: %d", i, getpid(), getppid());
      sleep(1);
      num++;
    }
  } else if (p > 0) {
    for (int i=0; i<10; i++) {
      log("[%d]main pid: %d, main ppid: %d, num: %d", i, getpid(), getppid(), num);
      sleep(1);
    }
  }

  log("over[%d]", getpid());
}