#include <iostream>
#include <vector>
#include <memory>


class Test2;

class Test1 {
public:
    Test1() {
        std::cout << "init" << std::endl;
    }

    ~Test1() {
        std::cout << "release" << std::endl;
    }
public:
    // std::shared_ptr<Test2> p1;   使用shared_ptr会导致不释放
    std::weak_ptr<Test2> p1;
};


class Test2 {
public:
    Test2() {
        std::cout << "init" << std::endl;
    }

    ~Test2() {
        std::cout << "release" << std::endl;
    }

public:
    // std::shared_ptr<Test2> p1;   使用shared_ptr会导致不释放
    std::weak_ptr<Test1> p2;
};


int main() {
    std::shared_ptr<Test1> p1(new Test1());
    std::shared_ptr<Test2> p2(new Test2());

    (*p1).p1 = p2;
    (*p2).p2 = p1;

    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
}