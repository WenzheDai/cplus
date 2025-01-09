#include <iostream>
#include <mutex>
#include <thread>


int g_val = 0;
int g_val_mutex_1 = 0;
int g_val_mutex_2 = 0;
std::mutex mtx;


void func_mutex_1(int n) {
    while(n--) {
        mtx.lock();
        g_val_mutex_1++;
        mtx.unlock();
    }
}

void func_mutex_2(int n) {
    mtx.lock();
    while(n--) {
        g_val_mutex_2++;
    }
    mtx.unlock();
}

void func(int n) {
    while(n--) {
        g_val++;
    }
}

int main() {
    int n = 20000;

    // 并行
    size_t begin_1 = std::clock();
    std::thread t1(func_mutex_1, n);
    std::thread t2(func_mutex_1, n);
    t1.join();
    t2.join();
    size_t end_1 = std::clock();
    std::cout << "g_val_mutex: " << g_val_mutex_1 << "   time: " << end_1 - begin_1 << std::endl;

    // 串行--- 不需要频繁加减锁
    size_t begin_2 = std::clock();
    std::thread t3(func_mutex_2, n);
    std::thread t4(func_mutex_2, n);
    t3.join();
    t4.join();
    size_t end_2 = std::clock();
    std::cout << "g_val_mutex: " << g_val_mutex_2 << "   time: " << end_2 - begin_2 << std::endl;

    std::thread t5(func, n);
    std::thread t6(func, n);
    t5.join();
    t6.join();

    std::cout << "g_val: " << g_val << std::endl;
    return 0;
}