#include<iostream>


class father {
public:
    father(): value(55) {}
    virtual ~father(){}
    void test1() {std::cout << "father test1..." << std::endl;}

protected:
    int value;
};


class son : private father {
public:
    using father::test1;
    using father::value;
    // void run() {test1();}
    // void test2() {std::cout << "value is " << value << std::endl;}
};


int main() {
    son s;
    // s.run();
    s.test1();
    // s.test2();
    std::cout << "father value is : " << s.value << std::endl;
}