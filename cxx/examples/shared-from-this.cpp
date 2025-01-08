#include <iostream>
#include <memory>
 
class B : public std::enable_shared_from_this<B>
{
public:
    std::shared_ptr<B> get()
    {
        return shared_from_this();
    }
    [[nodiscard]] static std::shared_ptr<B> build()
    {
        return std::shared_ptr<B>(new B());
    }
private:
    B() = default;
};
 
int main()
{
    // can't stack-allocate it
    std::shared_ptr<B> b0 = B::build();
    std::shared_ptr<B> b1 = b0->get();
    std::cout << "b1.use_count() = " << b1.use_count() << '\n';
 
    return 0;
}