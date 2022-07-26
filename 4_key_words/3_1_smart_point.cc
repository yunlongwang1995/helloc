//
// Created by wangyunlong01 on 2022/4/13.
//

/**
 * 被共享指针修饰过的 堆内存 不需要手动释放
 *
 *
 */

#include "../common.h"
#include <memory>

int main(int argc, char **argv) {
  shared_ptr<Animal> sAnimal;

  Dog* dog = new Dog("111");
  cout << "----" << endl;
  sAnimal.reset(dog);
//  delete dog;
  cout << "----" << endl;
  if (sAnimal.get()) {
    cout << "sAnimal not null" << endl;
  } else {
    cout << "sAnimal is null" << endl;
  }
  sAnimal->sayHello();

  shared_ptr<Animal> sAnimal2 = make_shared<Dog>("222");
  sAnimal2->sayHello();
}