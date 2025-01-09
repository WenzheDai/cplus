// 仿函数
#include<iostream>
#include<vector>
#include<algorithm>


class Counter {
    int count;

public:
    Counter() : count(0) {}

    int operator()(){
        return ++count;
    }

};


class ADD {
public:
    int operator()(int i, int j) {
        return i + j;
    }
};


class Compare {
public:
    bool operator()(int a, int b) {
        return a < b;
    }
};


class print {
public:
    void operator()(int i) {
        std::cout << i << " ";
    }
};

void pf(int i) {
    std::cout << i << " ";
}


int main() {
    Counter myCounter;

    // Counter
    std::cout << "======= Counter ==========" << std::endl;
    std::cout << "Counter: " << myCounter() << std::endl;
    std::cout << "Counter: " << myCounter() << std::endl;
    std::cout << "Counter: " << myCounter() << std::endl;

    std::cout << "======= ADD ==========" << std::endl;
    ADD add;
    std::cout << "ADD " << add(5, 6) << std::endl;
    std::cout << "ADD " << ADD()(10, 6) << std::endl;

    std::cout << "======= compare ==========" << std::endl;
    std::vector<int> numbers = {20, 65, 30, 99, 23};

    std::cout << "origin numbers:";
    std::for_each(numbers.begin(), numbers.end(), print());
    std::cout << std::endl;

    std::sort(numbers.begin(), numbers.end(), Compare());
    std::cout << "Sorted numbers:";
    std::for_each(numbers.begin(), numbers.end(), pf);
    std::cout << std::endl;
    return 0;
}