#include <iostream>
#include <thread>
#include <mutex>


std::mutex mtx;


void dangerousFunction(int id) {
    try {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread " << id << "is running" << std::endl;

        if (id == 1) {
            throw std::runtime_error("Thread 1 encountered an error!");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in thread!" << id << ":" << e.what() << std::endl;
    }

    // 无需手动解锁，std::lock_guard 会在作用域结束时自动解锁
}


int main() {
    try {
        std::thread t1(dangerousFunction, 1);
        std::thread t2(dangerousFunction, 2);

        t1.join();
        t2.join();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught:" << e.what() << std::endl;
    }

    return 0;
}