// [x] TODO make simple fold example with different types as input
// [x] TODO see if I can make a fold templated function over a std::variant that can output different things depending on the type defined
#include <type_traits>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <variant>

template <typename... Args>
auto add_up_alot(Args... args)
{

    return (... + [](auto args_entry)
            {
            static_assert((std::is_arithmetic_v<Args> && ...), "all args are required to be number bud");
            return args_entry; }(args));
}

// template <typename ...Args>
// void diff_type_print(Args ... args)
// {

// }

template <typename... args>
void print_all_vec_mems(args... vals)
{
    constexpr auto print = [](auto val)
    {
        
        std::cout << val << std::endl;
    };

    (print(vals), ...);
}

template <typename... args>
void print_depend(args... vals)
{
    constexpr auto print = [](auto val)
    {
    if (std::holds_alternative<double>(val) || std::holds_alternative<int>(val))
        {
            std::cout << std::get<double>(val) * std::get<double>(val) <<  std::endl;
        }
        else {
            std::cout << std::get<std::string>(val)<< std::endl;
        }
    };
    (print(vals), ...);
}

int main()
{
    int test = 3;
    double double_test = 2.0;
    // std::cout << add_up_alot(3.0, 3, "test") <<std::endl; fails as expected
    auto res = add_up_alot(test, double_test, test, 1.2f);
    // std::cout << res << std::endl;
    // std::cout << add_up_alot(3.0, 3, double_test) << std::endl;

    // std::array<int, 3> test_vec{3, 2, 4};
    print_all_vec_mems(3, 2, 4);

    std::variant<int, double, float, std::string> v, w;
    v = (double)32;
    w = "test";

    print_depend(v, w);
    return 0;
}