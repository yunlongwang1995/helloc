//
// Created by wangyunlong01 on 2022/4/12.
//
#include <iostream>
#include <mutex>
#include <unistd.h>
#include <thread>

void mock_self_deadlock();
void mock_deadlock();

/**
 * 入门用例
 * @param argc 　　参数个数 3
 * @param argv 　　参数列表 ./main hello 123
 * @return
 */
int main(int argc, char* argv[]) {

  if (argc == 1) {
    std::cout << "hello c++ world" << std::endl;
    return 0;
  }

  if (argc == 2) {
    std::cout << "hello program self deadlock!!!" << std::endl;
    mock_self_deadlock();
    return 0;
  }

  if (argc == 3) {
    std::cout << "hello program deadlock!!!" << std::endl;
    mock_deadlock();
    return 0;
  }

  if (argc == 4) {
    std::cout << "hello program crash!!!" << std::endl;
    std::cout << "sudo service apport stop" << std::endl;
    std::cout << "ulimit -c unlimited" << std::endl;
    std::cout << 100/(argc-3) << std::endl;
    return 0;
  }

  if (argc == 5) {
    std::cout << "hello memory leak!!!" << std::endl;
    std::cout << "valgrind --tool=memcheck --leak-check=full ./main hello 1 3" << std::endl;
    int* p = new int(88);
    std::cout << "my leak ptr: " << *p << std::endl;
    return 0;
  }
}

std::mutex mutex_a;
std::mutex mutex_b;

void get_a_b() {
  mutex_a.lock();
  std::cout << "get_a_b: get resource a" << std::endl;
  sleep(3);

  mutex_b.lock();
  std::cout << "get_a_b: get resource b" << std::endl;
  sleep(3);

  mutex_b.unlock();
  mutex_a.unlock();
}
void get_b_a() {
  mutex_b.lock();
  std::cout << "get_b_a: get resource b" << std::endl;
  sleep(3);

  mutex_a.lock();
  std::cout << "get_b_a: get resource a" << std::endl;
  sleep(3);

  mutex_a.unlock();
  mutex_b.unlock();
}

void mock_self_deadlock() {
  std::mutex mutex;

  mutex.lock();
  std::cout << "get lock" << std::endl;
  sleep(1);

  mutex.lock();
  std::cout << "get lock again" << std::endl;
  sleep(1);

  mutex.unlock();
  mutex.unlock();
}
void mock_deadlock() {
  std::thread t1(get_b_a);
  get_a_b();
  t1.join();
}