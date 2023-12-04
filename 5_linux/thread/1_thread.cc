//
// Created by wangyunlong01 on 2022/4/19.
//

#include <cstdarg>
#include <pthread.h>
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

void log(const char* format, ...) {
  time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
  ostringstream oss;
  oss << put_time(localtime(&currentTime), "%Y-%m-%d %H:%M:%S");

  va_list args;
  va_start(args, format);
  char buffer[256];
  vsnprintf(buffer, sizeof(buffer), format, args);
  printf("[%s] %s\n", oss.str().c_str(), buffer);
  va_end(args);
}

bool running = true;
pid_t ppid;

void* collectPidInfo(void* arg) {
  int loop = 0;
  for(;;) {
    sleep(1);
    pid_t cur_ppid = getppid();
    if (cur_ppid != ppid) {
      running = false;
      log("collect thread exit: %d != %d", cur_ppid, ppid);
      break;
    }
    loop++;
    loop %= 10;
    if (loop == 0) {
      log("%d == %d", cur_ppid, ppid);
    }
  }

  return nullptr;
}

void* doTask(void* arg) {
  for (;;) {
    int* sleep_second = (int*)(arg);
    sleep(*sleep_second);
    int* age = new int(18);
    (*age)++;
    log("sub thread: age = %d", *age);
    delete age;
    if (!running) {
      log("sub thread exit...");
      break;
    }
  }

  return nullptr;
}

int main(int argc, char* argv[]) {
  // 1.参数校验
  if (argc != 2) {
    log("invalid argc: %d", argc);
    exit(1);
  }
  int thread_num = stoi(argv[1]);
  ppid = getppid();
  log("main pid=%d, main ppid=%d, thread_num=%d", getpid(), ppid, thread_num);

  // 2.启动收集线程
  pthread_t collectTid;
  int ret = pthread_create(&collectTid, nullptr, collectPidInfo, nullptr);
  if (ret != 0) {
    log("pthread_create failed: %d", ret);
    exit(1);
  }

  // 3.启动任务线程
  pthread_t *threads = new pthread_t[thread_num];
  int* args = new int[thread_num];
  for (int i=0; i<thread_num; ++i) {
    int* arg = &args[i];
    *arg = i + 3;
    ret = pthread_create(&threads[i], NULL, doTask, arg);
    if (ret != 0) {
      log("pthread_create failed: %d", ret);
      exit(1);
    }
  }

  for (int i=0; i<thread_num; ++i) {
    pthread_join(threads[i], nullptr);
  }

  delete[] threads;
  delete[] args;
  log("main finish...");
}