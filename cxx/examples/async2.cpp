#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;
std::ostream & os{std::cout};

int task(int i)
{
    os << "task: " << i << std::endl;
    std::this_thread::sleep_for(1000ms*i);

    os << "task " << i
       << " end." << std::endl;

    return 10*i;
}

int main()
{
    os << "A" << std::endl;
    auto a5 = std::async(task, 5);
    os << "B" << std::endl;
    auto a8 = std::async(task, 8);

    os << "C" << std::endl;
    os << a5.get() << '\n' << a8.get() << '\n';

    // A
    // B
    // C
    // task: 8
    // task: 5
    // task 5 end.
    // 50
    // task 8 end.
    // 80
    
    return 0;
}