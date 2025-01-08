#include <iostream>
#include <thread>
#include <vector>

std::ostream & os{std::cout};
int j{0};
const int l{1000000};

void task(int i)
{
    for (auto k = 0 ; k < l ; ++k) j++;
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
    // C2320849 80000000

    return 0;
}