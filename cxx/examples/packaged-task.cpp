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

    return i*10;
}

int main()
{
    os << "A" << std::endl;
    std::packaged_task<int(int)> p1{task};
    auto f1{p1.get_future()}; // store the future somewhere

    os << "B" << std::endl;

    // ...

    p1(5); // call the task from where you want

    os << "C" << f1.get() << std::endl;
    // retrieve the result (or wait!)

    // A
    // B
    // task: 5
    // task 5 end.
    // C50

    return 0;
}