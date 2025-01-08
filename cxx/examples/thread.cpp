#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
std::ostream & os{std::cout};

void task(int i)
{
    os << "task: " << i << std::endl;
    std::this_thread::sleep_for(1000ms*i);
    
    os << "task " << i
       << " end." << std::endl;
}

int main()
{
    os << "A" << std::endl;
    std::thread t1(task, 1);
    os << "B" << std::endl;
    t1.join();
    os << "C" << std::endl;
    return 0;
}