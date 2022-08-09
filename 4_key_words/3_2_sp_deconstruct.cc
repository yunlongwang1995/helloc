//
// Created by wangyunlong01 on 2022/4/13.
//

/**
 * 被共享指针修饰过的 堆内存 不需要手动释放
 *
 *
 */

#include "../common.h"

int main(int argc, char **argv) {
  cout << "begin..." << endl;
  {
//    unique_ptr<Animal> sAnimal;
//    Dog* dog = new Dog("111");
//    sAnimal.reset(dog);
//    sAnimal->sayHello();
//    sAnimal = nullptr;
//    delete dog;

      unique_ptr<Animal> dog = make_unique<Dog>("111");
      dog->sayHello();
  }

  cout << "end..." << endl;
}