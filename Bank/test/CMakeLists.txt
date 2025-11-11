
# Find GTest package first
find_package(GTest REQUIRED)

add_executable(bank_tests 
    test.cpp
    ../src/bank.c
)

target_link_libraries(bank_tests 
    GTest::GTest 
    GTest::Main
)

target_include_directories(bank_tests PRIVATE 
    ../include
)

enable_testing()

include(GoogleTest)
gtest_discover_tests(bank_tests)
