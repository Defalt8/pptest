# pptest v1.5.27

An abstract reporting header-only unit-testing library for C++.

## Header files

- [pptest](include/pptest)
- [colored_printer](include/colored_printer)

## Features

- Easy to learn and use.
- No internal dynamic allocations.
- The user decides whether and how to store test results.
- Separate layer of implementation for presentation of test results.
- Mutlithread friendly. i.e. separate instances on separate threads should have no issues.
- Helper macros for Tests, Testcases and Assertions.
- snake-case aliases for public types and defs.
- Tests are runnable inside tests and can be printed with the corresponding depth.
- Provides great `ColoredPrinter` and `StdPrinter` implementations.
- Reporting is easily extesible through inheritance.

## Example

```c++
#include <pptest>
#include <colored_printer>

// Try to fix the function based on the failing tests

static char to_hex_char(int hex_)
{
    return (hex_ >= 0 && hex_ <= 9) 
        ? char('0' + hex_) 
        : (hex_ >= 10 && hex_ <= 15 
            ? char('A' + (hex_ - 10)) 
            : '\0');
}

Begin_Test(to_hex_char_test)

    Begin_Testcase(to_hex_char_test, test_0_to_9)
    {
        for(int i = 0; i < 10; ++i)
            Assert_EQ(to_hex_char(i), char('0' + i));
    }
    End_Testcase(to_hex_char_test, test_0_to_9)

    Begin_Testcase(to_hex_char_test, test_A_to_F)
    {
        for(int i = 0xA; i <= 0xF; ++i)
            Assert_EQ(to_hex_char(i), char('A' + (i - 0xA)));
    }
    End_Testcase(to_hex_char_test, test_A_to_F)

    Begin_Testcase(to_hex_char_test, test_invalid_positive)
    {
        for(int i = 0x10; i <= 0x12; ++i)
            Assert_EQ(to_hex_char(i), '0');
    }
    End_Testcase(to_hex_char_test, test_invalid_positive)

    Begin_Testcase(to_hex_char_test, test_invalid_negative)
    {
        for(int i = -2; i < 0; ++i)
            Assert_EQ(to_hex_char(i), '0');
    }
    End_Testcase(to_hex_char_test, test_invalid_negative)

    Begin_Testcase_Registration(to_hex_char_test)
    {
        Register_Testcase(to_hex_char_test, test_0_to_9)
        Register_Testcase(to_hex_char_test, test_A_to_F)
        Register_Testcase(to_hex_char_test, test_invalid_positive)
        Register_Testcase(to_hex_char_test, test_invalid_negative)
    }
    End_Testcase_Registration(to_hex_char_test)
End_Test(to_hex_char_test)


template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

int main()
{
    return to_hex_char_test().run_all(reporter_t<to_hex_char_test>(pptest::normal));
}

```

Output:

![output](/output.png)
