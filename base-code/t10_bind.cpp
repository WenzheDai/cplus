#include <iostream>
#include <functional>


void fun(int i, int j = 2) {std::cout << (i > j ? i : j) << std::endl;}

void fun1(int i, int j) {std::cout << (i > j ? i : j) << std::endl;}

static void fun2(int i, int j) {std::cout << (i > j ? i : j) << std::endl;}

template <typename T1 = int, typename T2 = int>
void fun3(T1 i, T2 j) {std::cout << (i > j ? i : j) << std::endl;}


class Test {
public:
    void fun1(int i, int j) {std::cout << (i > j ? i : j) << std::endl;}

    static void fun2(int i, int j) {std::cout << (i > j ? i : j) << std::endl;}

    template <typename T1 = int, typename T2 = int>
    void fun3(T1 i, T2 j) {std::cout << (i > j ? i : j) << std::endl;}

    void fun4() {
        auto fun1Test = std::bind(&Test::fun1, this, 1, 2);
        fun1Test();
    }

public:
    int m_X = 10;
};


class Compare {
public:
    void operator()(int i, int j) {
        std::cout << (i > j ? i : j) << std::endl;
    }
};


int main() {
    std::cout << "==============Function===================" << std::endl;
    auto fun1Test = std::bind(fun1, 1, 2);
    auto fun2Test = std::bind(fun2, 1, 2);
    auto fun3Test = std::bind(fun3<>, 1, 2);

    fun1Test();
    fun2Test();
    fun3Test();

    std::cout << "==============Class===================" << std::endl;
    Test test;
    Test* pTest = &test;

    auto Cfun1Test = std::bind(&Test::fun1, test, 1, 2);
    auto Cfun2Test = std::bind(Test::fun2, 1, 2);
    auto Cfun3Test = std::bind(&Test::fun3<>, &test, 1, 2);
    auto memberVar  = std::bind(&Test::m_X, pTest);

    Cfun1Test();
    Cfun2Test();
    Cfun3Test();
    test.fun4();
    std::cout << memberVar() << std::endl;

    std::cout << "==============Lambda && functor===================" << std::endl;
    auto ffun1 = std::bind(Compare(), 1, 2);
    auto lfun2 = std::bind([](int i, int j) {std::cout << (i > j ? i : j);}, 1, 2);

    ffun1();
    lfun2();

    std::cout << "==============占位符===================" << std::endl;
    auto dfun1 = std::bind(fun, 1,  std::placeholders::_1);
    auto dfun2 = std::bind(fun, std::placeholders::_1, 2);
    auto dfun3 = std::bind(fun, std::placeholders::_2, std::placeholders::_1);

    dfun1(2);
    dfun2(1);
    dfun3(1, 2);

    return 0;
}
