#include <iostream>
#include <thread>
#include <chrono>


void func() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread is running: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));  // 模拟工作
    }
    std::cout << "Thread over!" << std::endl;
}


int main() {
    // create
    std::thread t(func);

    // detach
    t.detach();

    std::cout << "main thread is runing" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(6));

    std::cout << "main thread over" << std::endl;

    return 0;
}