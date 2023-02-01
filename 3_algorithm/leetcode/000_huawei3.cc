#include "../../base.h"

using namespace std;


int cas(int expect_value, int new_value, int* val) {

}

class SpinLock {
 public:
  void Lock() {
    if(cas(0, 1, &lockd_value) == 0) {
      return;
    }

    while (true) {
      if (cas(0, 1, &lockd_value) == 0) {
        break;
      }
    }
  }

  void UnLock() {
    if(cas(1, 0, &lockd_value) == 1) {
      return;
    }

    // 是否 panic

  }

 private:
  int lockd_value = 0;
};




int main(int argc, char* argv[]) {
  cout << "hello world" << endl;


}