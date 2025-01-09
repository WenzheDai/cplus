#include <iostream>
#include <string>
#include <functional>


void fun1(std::string str) {
    std::cout << str << std::endl;
}


auto fun2 = [](std::string str) -> void {std::cout << str << std::endl;};


class Test1 {
public:
    void operator()(std::string str) {
        std::cout << str << std::endl;
    }
};


class Test2 {
public:
    void fun3(std::string str) {std::cout << str << std::endl;}
    static void fun4(std::string str) {std::cout << str << std::endl;}
};


int main() {
    std::function<void(std::string)> Functional;

    Functional = fun1;
    Functional("普通函数");

    Functional = fun2;
    Functional("lambda");

    Test1 test1;
    Functional = test1;
    Functional("仿函数");

    Test2 test2;
    Functional = std::bind(&Test2::fun3, test2, std::placeholders::_1);
    Functional("类成员函数");

    Functional = Test2::fun4;
    Functional("类静态函数");

    return 0;
}