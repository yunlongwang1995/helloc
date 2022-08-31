//
// Created by wangyunlong01 on 2022/8/30.
//

#ifndef HELLOC_STOPPER_H
#define HELLOC_STOPPER_H

#endif //HELLOC_STOPPER_H

#include <thread>
#include <vector>
#include <iostream>

typedef void (* Task)(std::vector<int>&);

class Stopper {
public:
  Stopper() : thread_num_(0),
              has_running_time_(0),
              running(false) {
  }

  ~Stopper() {}

  void RunTask(Task task) {
    task(list_);
  }

  void RunAsyncTask(Task task) {
    running = true;

    std::thread([=]() {
      while (running) {
        task(list_);
      }
    }).detach();

    thread_num_++;
  }

  void WaitTask(int wait_time) {
    // 等待
    while (has_running_time_ < wait_time) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      has_running_time_++;
    }

    // 设置标记位
    running = false;

    // 等待子线程结束
//    for (int i = 0; i < thread_num_; ++i) {
//      thread_list_[i].join();
//    }

    std::cout << "running over\nthread_num: " << thread_num_
              << "\nrunning_time: " << wait_time << std::endl;
  }

  void PrintStatistics() {
    for (auto item: list_) {
      std::cout << item << "  ";
    }
  }

private:
  int thread_num_;                // 异步线程数
  int has_running_time_;          // 异步已经执行时间
  bool running;                   // 标记
  std::vector<int> list_;

  //  std::vector<std::thread> thread_list_;
};