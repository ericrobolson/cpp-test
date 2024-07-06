/*
MIT License

Copyright (c) 2024 Eric Olson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

/*
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

#ifdef CPP_UNIT_TEST
#include "cpp-test.hpp"

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
*/

#pragma once

#ifdef CPP_UNIT_TEST

#include <iostream>

static int tests_passed = 0;
static int tests_failed = 0;

void start_tests()
{
    tests_passed = 0;
    tests_failed = 0;

    std::cout << "Starting tests..." << std::endl;
}

void test_results()
{
    std::cout << "Tests passed: " << tests_passed << std::endl;
    std::cout << "Tests failed: " << tests_failed << std::endl;
}

#define IS_EQUAL(x, y)                                                                                                            \
    {                                                                                                                             \
        if ((x) != (y))                                                                                                           \
        {                                                                                                                         \
            tests_failed++;                                                                                                       \
            std::cout << "  FAILURE: " << __FILE__ << ":" << __LINE__ << " function " << __FUNCTION__ << " failed " << std::endl; \
            std::cout << "    Expected: " << (y) << " but got: " << (x) << std::endl;                                             \
            return;                                                                                                               \
        }                                                                                                                         \
        else                                                                                                                      \
        {                                                                                                                         \
            tests_passed++;                                                                                                       \
        }                                                                                                                         \
    }

#define IS_NOT_EQUAL(x, y)                                                                                                        \
    {                                                                                                                             \
        if ((x) == (y))                                                                                                           \
        {                                                                                                                         \
            tests_failed++;                                                                                                       \
            std::cout << "  FAILURE: " << __FILE__ << ":" << __LINE__ << " function " << __FUNCTION__ << " failed " << std::endl; \
            std::cout << "    Expected: " << (y) << " but got: " << (x) << std::endl;                                             \
            return;                                                                                                               \
        }                                                                                                                         \
        else                                                                                                                      \
        {                                                                                                                         \
            tests_passed++;                                                                                                       \
        }                                                                                                                         \
    }

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x)                                                                                                                \
    {                                                                                                                             \
        if (!(x))                                                                                                                 \
        {                                                                                                                         \
            tests_failed++;                                                                                                       \
            std::cout << "  FAILURE: " << __FILE__ << ":" << __LINE__ << " function " << __FUNCTION__ << " failed " << std::endl; \
            return;                                                                                                               \
        }                                                                                                                         \
        else                                                                                                                      \
        {                                                                                                                         \
            tests_passed++;                                                                                                       \
        }                                                                                                                         \
    }

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_FALSE(x)                                                                                                               \
    {                                                                                                                             \
        if (x)                                                                                                                    \
        {                                                                                                                         \
            tests_failed++;                                                                                                       \
            std::cout << "  FAILURE: " << __FILE__ << ":" << __LINE__ << " function " << __FUNCTION__ << " failed " << std::endl; \
            return;                                                                                                               \
        }                                                                                                                         \
        else                                                                                                                      \
        {                                                                                                                         \
            tests_passed++;                                                                                                       \
        }                                                                                                                         \
    }

#endif
