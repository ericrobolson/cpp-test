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
int main()
{
#ifdef CPP_UNIT_TEST
#include "test.hpp"
    start_tests();
    math_tests();
    containers_tests();
    physics_tests();
    test_results();
    return 0;
#endif

    // Non-unit test code.

    return 0;
}
```
