cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(cpp_playground)


find_package(Boost REQUIRED)

add_executable(fold_expression_test
    fold.cpp
)

set_target_properties(fold_expression_test PROPERTIES CXX_STANDARD 17)
target_compile_features(fold_expression_test PRIVATE cxx_std_17)

# target_link_libraries(fold_expression_test PRIVATE Boost::signals)