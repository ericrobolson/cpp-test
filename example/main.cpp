#include <iostream>
#include <cstdint>

#ifdef CPP_UNIT_TEST
#include "../cpp-test.hpp"

void math_tests()
{
    IS_EQUAL(1 + 1, 2);
    IS_EQUAL(2 * 2, 4);

    IS_NOT_EQUAL(2 * 2, 5);
    IS_NOT_EQUAL(2 * 2, 3);

    IS_TRUE(1 == 1);
    IS_FALSE(1 == 2);
}

#endif

int main()
{
#ifdef CPP_UNIT_TEST
    // Reset state for tests.
    start_tests();

    // Example of calling a function that runs tests.
    math_tests();

    // Print results.
    test_results();
    return 0;
#endif

    // Non-unit test code.
    std::cout << "Hello world!" << std::endl;

    return 0;
}
