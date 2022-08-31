//
// Created by wangyunlong01 on 2022/8/30.
//

#include "stopper.h"
#include <iostream>

int main() {
  Task task1 = [](std::vector<int>& list) {
    std::cout << "this is task1" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    list.emplace_back(1);
  };

  Task task2 = [](std::vector<int>& list) {
    std::cout << "this is task2" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    list.emplace_back(2);
  };

  Stopper stopper;
  stopper.RunTask(task1);
  stopper.RunAsyncTask(task2);
  stopper.WaitTask(5);
  stopper.PrintStatistics();
}