void f(auto i)
{
    ++i;
    return;
}

auto g(auto i)
{
    ++i;
    return i;
}


int main()
{
    auto a{0};
    auto b{45.12};
    auto c = a + 1;

    f(55);   

    return g(56);
}