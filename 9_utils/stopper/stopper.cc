//
// Created by wangyunlong01 on 2022/8/30.
//

#include "stopper.h"
#include <thread>

enum TaskStatus {
  Reading,
  Running,
  Done
};

class Stopper {
public:
  Stopper(int thread_num, int exec_time) : thread_num_(thread_num),
                                           exec_time_(exec_time) {
    running_ = Reading;
    running_thread_num_ = 0;
    has_executed_time_ = 0;
  }

  ~Stopper() {}

  void Run(void f()) {
    running_ = Running;
    for (int i = 0; i < thread_num_; ++i) {
      running_thread_num_++;
      std::thread([&]() {
        while (running_ != Done) {
          f();
        }
        running_thread_num_--;
      }).detach();
    }

    while (running_thread_num_ > 0) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      has_executed_time_++;
      if (has_executed_time_ > exec_time_) {
        running_ = Done;
      }
    }
  }

private:
  int thread_num_;
  int exec_time_;
  TaskStatus running_;
  int running_thread_num_;
  int has_executed_time_;
};