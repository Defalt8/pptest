# pptest v1.7.32

An abstract reporting header-only unit-testing library for C++.

## Header files

- [pptest](include/pptest) -- quick-doc at the top.
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

char to_hex_char(int hex_)
{
    if(hex_ >= 0 && hex_ <= 9)
        return char('0' + hex_);
    else if(hex_ >= 10 && hex_ <= 15)
        return char('A' + (hex_ - 10));
    else if(hex_ < 0)
        throw hex_;
    return '0';
}

Test(to_hex_char_test)
{
    TestInit(to_hex_char_test);

    // Called before each testcase. Can skip if you throw something.
    PreRun() 
    {
        // if(&_testcase_ == &_test_never_throw) 
        //    throw 0;
    }  
    
    // Called after each testcase
    PostRun() {} 

    Testcase(test_0_to_9)
    {
        for(int i = 0; i < 10; ++i)
            AssertEQ(to_hex_char(i), char('0' + i));
    } TestcaseEnd(test_0_to_9);

    Testcase(test_A_to_F)
    {
        for(int i = 0xA; i <= 0xF; ++i)
            AssertEQ(to_hex_char(i), char('A' + (i - 0xA)));
    } TestcaseEnd(test_A_to_F);

    Testcase(test_invalid_positive_ret_0)
    {
        for(int i = 0x10; i <= 0x12; ++i)
            AssertEQ(to_hex_char(i), '0');
    } TestcaseEnd(test_invalid_positive_ret_0);

    Testcase(test_invalid_negative_ret_0)
    {
        for(int i = -2; i < 0; ++i)
            AssertEQ(to_hex_char(i), '0');
    } TestcaseEnd(test_invalid_negative_ret_0);

    Testcase(test_never_throw)
    {
        ExpectThrowNone(to_hex_char(0));
        ExpectThrowNone(to_hex_char(0xF));
        ExpectThrowNone(to_hex_char(-1));
        ExpectThrowNone(to_hex_char(0x10));
    } TestcaseEnd(test_never_throw);

};

TestRegistry(to_hex_char_test)
{
    Register(test_0_to_9)
    Register(test_A_to_F)
    Register(test_invalid_positive_ret_0)
    Register(test_invalid_negative_ret_0)
    Register(test_never_throw)
};


template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

int main()
{
    return to_hex_char_test().run_all(reporter_t<to_hex_char_test>(pptest::normal));
}
```

Output:

![output_failing](/output_failing.png)

What we want to see:

![output_passing](/output_passing.png)
