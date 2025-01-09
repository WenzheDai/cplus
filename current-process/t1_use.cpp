#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>


// custom function
void func1(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// affine function
// 成员变量，和成员函数如果不指定，默认为私有权限
class Myclass {
public:
    void operator()(int start, int end) {
        for (int i = start; i <= end; ++i) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};


int main() {
    // 1. thread
    std::thread t1(func1, 1, 10);

    //2. thread
    std::thread t2((Myclass()), 10, 20);

    sleep(1);

    //3.thead // lambda function
    std::thread t3([](const std::string& str) -> void {std::cout << str << std::endl;}, "I am thread-3");

    sleep(1);

    // 移动
    std::thread t4 = std::thread(func1, 4, 20);
    std::thread t5(std::move(t4));   // 不能拷贝，只能移动构造

    t1.join();
    t2.join();
    t3.join();
    // t4.join();   //报错 因为t4 转移给  t5
    t5.join();

    return 0;
}