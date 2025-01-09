#include <iostream>
#include <thread>

int num = 666;
volatile bool flag = false;

void fun1() {
    // if (flag) {
    //     std::cout << "fun1: flag is true" << std::endl;
    // }
    // else {
    //     std::cout << "fun1: flag is false" << std::endl;
    //     flag = true;
    //     num = 10;
    // }
    num = 10;
    flag = true;
}

void fun2() {
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    if (flag) {
        std::cout << "fun2: flag is true" << std::endl;
        std::cout << "num: " << num << std::endl;
    }
    else {
        std::cout << "fun2: flag is false" << std::endl;
        std::cout << "num: " << num << std::endl;
    }
}


int main() {

    // const int value = 10;
    volatile const int value = 10;

    int *p = (int *)&value;
    std::cout << "init p: " << value << std::endl; // 10

    *p = 100;
    std::cout << "modify p: " << value << std::endl; // 100  if volatile else 10

    std::thread t1(fun1);
    std::thread t2(fun2);

    t1.join();
    t2.join();

    return 0;
}