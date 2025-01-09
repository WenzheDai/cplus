#include <iostream>
#include <thread>


void print() {
    std::cout << "Hello from thread!" << std::endl;
}


int main() {
    std::thread t1(print);

    // 判断thread 是否可执行
    if (t1.joinable()) {
        std::cout << "Thread is joinable." << std::endl;
    } else {
        std::cout << "Thread is not joinable. " << std::endl;
    }

    // 等待thread执行
    t1.join();

    if (t1.joinable()) {
        std::cout << "Thread is joinable." << std::endl;
    } else {
        std::cout << "Thread is not joinable. " << std::endl;
    }

    return 0;
}