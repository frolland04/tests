#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::ostream & os{std::cout};
int j{0};
std::mutex m;
const int l{1000000};

void task(int i)
{
    for (auto k = 0 ; k < l ; ++k) {
        std::lock_guard<std::mutex> lg(m);
        j++;
    }
}

int main()
{
    std::vector<std::thread> ts;
    const auto p{std::thread::hardware_concurrency()*10};

    os << "A" << p << std::endl;
    for(auto i = 0 ; i < p ; ++i) {
        ts.push_back(std::thread(task, i));
    }

    os << "B" << std::endl;
    for(auto & t : ts) t.join();

    os << "C" << j << ' ' << l*p << std::endl;

    // A80
    // B
    // C80000000 80000000

    return 0;
}