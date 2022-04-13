//
// Created by wangyunlong01 on 2022/4/13.
//

int main(int argc, char **argv) {
    int age = 18;
    int age2 = 28;

    // const point
    const int* p1;
    p1 = &age;
    p1 = &age2;
//    *p1 = 38; // error

    // point const
    //int* const p2;  // error, must init
    int* const p2 = &age;
    *p2 = 38;

}
