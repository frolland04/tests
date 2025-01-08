#include <iostream>
#include <future>
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
    auto a1 = std::async(task, 1);

    os << "B" << std::endl;
    a1.wait(); // optional, as 'a1' dtor is *blocking*

    os << "C" << std::endl;

    // A
    // B
    // task: 1
    // task 1 end.
    // C

    return 0;
}