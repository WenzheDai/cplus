/*
线程函数的参数是以 值拷贝 的方式拷贝到线程栈空间中，
即使线程函数的参数为引用类型，在线程函数中修改后也不会影响到外部实参
因为其实际引用的是线程栈中的拷贝，而不是外部实参。
*/

#include <iostream>
#include <thread>


void add(int& num) {
    num++;
}

void add2(int * num) {
    *num += 10;
}


int main() {
    int num = 0;

    std::thread t(add, std::ref(num));
    t.join();
    std::cout << "num: " << num << std::endl;

    std::thread t2(add2, &num);
    t2.join();
    std::cout << "num: " << num << std::endl;

    std::thread t3([&num] { num += 10;});
    t3.join();
    std::cout << "num: " << num << std::endl;

    return 0;
}