#include<iostream>
#include<vector>
#include<thread>
#include<chrono>


int main() {
    std::vector<std::thread> vts(5);

    for (int i = 0; i < 5; ++i) {
        vts[i] = std::thread([]() -> void {
            for (int j = 0; j < 10; ++j) {
                auto id = std::this_thread::get_id();
                std::cout << "my thread id is: " << id << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        });
    }

    for (auto & t : vts)
        t.join();
    
    return 0;
}