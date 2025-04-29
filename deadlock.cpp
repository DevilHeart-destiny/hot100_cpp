#include <iostream>
#include <thread>              // 支持 std::thread
#include <mutex>               // 支持 std::mutex 和 std::unique_lock
#include <condition_variable>  // 支持 std::condition_variable
#include <chrono>              // 支持 std::this_thread::sleep_for

std::mutex mtx;                // 正确声明互斥量
std::condition_variable cv;    // 正确声明条件变量
int current = 1;
const int MAX = 10;

void print_odd() {
    while (current <= MAX) {
        std::unique_lock<std::mutex> lock(mtx);
        // 移除 current > MAX 的退出条件，强制死等
        cv.wait(lock, []{ return current % 2 == 1; }); 
        std::cout << "Thread 1: " << current++ << std::endl;
        cv.notify_one();
    }
}

void print_even() {
    while (current <= MAX) {
        std::unique_lock<std::mutex> lock(mtx);
        // 移除 current > MAX 的退出条件，强制死等
        cv.wait(lock, []{ return current % 2 == 0; }); 
        std::cout << "Thread 2: " << current++ << std::endl;
        cv.notify_one();
    }
}
int main() {
    std::thread t1(print_odd);
    std::thread t2(print_even);
    t1.join();
    t2.join();
    return 0;
}