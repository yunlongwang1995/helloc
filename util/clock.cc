//
// Created by wangyunlong01 on 2022/6/17.
//

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


void time_cost_func()
{
    long sum = 0;

    for (long i=0; i<1e9; i++) {
        if (i%2) sum -= i;
        else sum += i*2;
    }
    cout << "sum = " << sum << endl;
}

int main()
{
    high_resolution_clock::time_point t1, t2;
    steady_clock::time_point t3, t4;
    system_clock::time_point t5, t6;

    duration<double> time_span;
    chrono::milliseconds ms;

    // Test high_resolution_clock
    t1 = high_resolution_clock::now();
    time_cost_func();
    t2 = high_resolution_clock::now();

    time_span = duration_cast<duration<double>>(t2 - t1);
    ms = duration_cast<chrono::milliseconds>(t2 - t1); // or, change 't2 - t1' to 'time_span'

    cout << "Test high_resolution_clock: " << endl;
    cout << "This function took " << time_span.count() << " seconds." << endl;
    cout << "This function took " << ms.count() << " milliseconds." << endl;

    // Test steady_clock
    t3 = steady_clock::now();
    time_cost_func();
    t4 = steady_clock::now();

    time_span = duration_cast<duration<double>>(t4 - t3);
    ms = duration_cast<chrono::milliseconds>(t4 - t3);

    cout << "Test steady_clock: " << endl;
    cout << "This function took " << time_span.count() << " seconds." << endl;
    cout << "This function took " << ms.count() << " milliseconds." << endl;

    // Test system_clock
    t5 = system_clock::now();
    time_cost_func();
    t6 = system_clock::now();

    time_span = duration_cast<duration<double>>(t6 - t5);
    ms = duration_cast<chrono::milliseconds>(t6 - t5);

    cout << "Test system_clock: " << endl;
    cout << "This function took " << time_span.count() << " seconds." << endl;
    cout << "This function took " << ms.count() << " milliseconds." << endl;

    return 0;
}
