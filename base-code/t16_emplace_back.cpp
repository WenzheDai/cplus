#include <iostream>
#include <vector>
#include <string>


struct A {
    int x;
    double y;
    std::string z;
    A(int a, int b, std::string c) : x(a), y(b), z(c) {
        std::cout << "A is constructed!" << std::endl;
    }

    A(const A &otherA) : x(otherA.x), y(otherA.y), z(std::move(otherA.z)) {
        std::cout << "A is moved! " << std::endl;
    }
};

// 对vector的插入过程中，push_back方法构造了一次，移动了两次；
// 使用emplace_back只进行了一次构造，没有进行内存的移动
    /*如果类中没有构造函数，就不可以使用 emplace_back */
int main() {
    std::vector<A> vec;

    std::cout << "------------- emplace_back ---------------------" << std::endl;
    /*如果类中没有构造函数，就不可以使用 emplace_back */
    vec.emplace_back(1, 2, "helloword");

    std::cout << "------------- push_back ---------------------" << std::endl;
    vec.push_back(A(3, 4, "china"));
    return 0;
}