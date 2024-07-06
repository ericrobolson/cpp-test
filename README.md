# cpp-test

Header only C++ unit testing library.

This is a simple test framework that provides several macros and functions for testing:

- `IS_TRUE(x)` - If x is true, the test passes
- `IS_FALSE(x)` - If x is false, the test passes
- `IS_EQUAL(x, y)` - If x == y, test passes
- `IS_NOT_EQUAL(x, y)` - If x != y, test passes
- `start_tests()` - sets up environment for test execution
- `end_tests()` - reports test results

Usage

- Define `CPP_UNIT_TEST` in your test compilation call.
- Write tests in functions.
- Create a `main` function that runs test functions.
- Call `start_tests()` and `end_tests()`.

There is an example project showing how it can be used under the `example` directory.

WARNING: This is not a full-featured test framework. It is a simple test framework that is easy to use and understand. It is written to be single threaded at this point.

## Example Usage

```
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
```

Output:

```
Starting tests...
Tests passed: 6
Tests failed: 0
```
