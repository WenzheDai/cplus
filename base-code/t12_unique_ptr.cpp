#include <iostream>
#include <string>
#include <memory>
#include <string>
#include <cstring>

class Test {
public:
    Test() {
        strTest = "hello world";
        std::cout << "this is init" << std::endl;
    }

    ~Test() {
        std::cout << "this is release" << std::endl;
    }

    void print() {
        std::cout << strTest << std::endl;
    }

private:
    std::string strTest;
};


std::unique_ptr<Test> fun2() {
    Test* test1 = new Test();
    std::unique_ptr<Test> p1(test1);
    return p1;
}


int main() {
    Test* test1 = new Test();
    std::unique_ptr<Test> p(test1);

    // p->print();
    (*p).print();

    std::unique_ptr<Test> p2;
    p2 = std::move(p);
    p2->print();

    std::unique_ptr<Test> p3 = fun2();
    p3->print();

    std::cout << "=============release=====================" << std::endl;
    std::unique_ptr<Test> pco(test1);
    p2.release(); // 释放关联的所有权，不摧毁对象
    (*pco).print();


    // std::cout << "=============reset=====================" << std::endl;
    // std::string* str1 = new std::string("123");
    // std::string* str2 = new std::string("456");
    // std::unique_ptr<std::string> ps(str1);
    // ps.reset(str2); // reset 释放指向内存，和对这块内存的所有权
    // std::cout << *ps << std::endl;

    // std::cout << "=============swap=====================" << std::endl;
    // std::string* str3 = new std::string("123");
    // std::string* str4 = new std::string("456");
    // std::unique_ptr<std::string> ps1(str1);
    // std::unique_ptr<std::string> ps2(str2);
    // std::cout << *ps1 << std::endl;
    // std::cout << *ps2 << std::endl;
    // ps1.swap(ps2);
    // std::cout << *ps1 << std::endl;
    // std::cout << *ps2 << std::endl;

    std::cout << "=============get=====================" << std::endl;

    std::unique_ptr<int> ptr;

    // auto ptr = std::unique_ptr<int>(new int(10));   // c++11 使用这个
    auto ptr = std::make_unique<int>(10);   // make_unique c++14 才使用

    std::cout << *ptr.get() << std::endl; // get() 返回unqiue_ptr维护的指针地址

    std::cout << __cplusplus << std::endl;

    return 0;
    
}