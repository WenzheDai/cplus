#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>


std::mutex mtx;
int count = 0;
std::condition_variable cv;


void increment() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        std::cout << "计数器增加： " << count << std::endl;
        cv.notify_one();
    }
}


void print() {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock);
        std::cout << "当前计数： " << count << std::endl;
    }
}


int main() {
    std::thread t1(increment);
    std::thread t2(print);

    t1.join();
    t2.join();

    return 0;
}