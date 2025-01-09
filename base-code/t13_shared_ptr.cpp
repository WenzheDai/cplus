#include <iostream>
#include <memory>
#include <vector>
#include <string>


class Test {
public:
    Test() {
        str = "Hello world";
        std::cout << "init" << std::endl;
    }

    void print() {
        std::cout << str << std::endl;
    }

    ~Test() {
        std::cout << "release" << std::endl;
    }

private:
    std::string str;
};


int main() {
    Test* test = new Test();
    std::shared_ptr<Test> p1(test);

    std::cout << "p1 use count: " << p1.use_count() << std::endl;

    std::shared_ptr<Test> p2 = p1;
    // std::shared_ptr<Test> p2(test);   // 错误用法
    std::cout << "p1 use count: " << p1.use_count() << std::endl;
    std::cout << "p2 use count: " << p2.use_count() << std::endl;

    (*p1).print();
    (*p2).print();

    return 0;
}