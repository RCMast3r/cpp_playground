// [x] TODO make simple fold example with different types as input
// [ ] TODO see if I can make a fold templated function over a std::variant that can output different things depending on the type defined
#include <type_traits>
#include <iostream>

template <typename...Args>
auto add_up_alot(Args ... args)
{
    
    return ( ... + [](auto args_entry)
        {
            static_assert((std::is_arithmetic_v<Args> && ...), "all args are required to be number bud");
            return args_entry;
        } (args));
}
int main()
{
    int test = 3;
    double double_test = 2.0;
    // std::cout << add_up_alot(3.0, 3, "test") <<std::endl; fails as expected
    auto res = add_up_alot(test, double_test, test, 1.2f);
    std::cout << res <<std::endl; 
    std::cout << add_up_alot(3.0, 3, double_test) <<std::endl; 
    return 0;
}