#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex mtx;


void func(int n) {
    if (n == 0) return;

    mtx.lock();
    n--;

    func(n);
    mtx.unlock();
}


int main() {
    int n = 1000;
    std::thread t1(func, n);
    std::thread t2(func, n);

    t1.join();
    t2.join();
    return 0;
}