# pptest

A header-only testing library for C++.

*STATUS:* in-development

## target requirements

- Easy to learn and use.
- No internal dynamic allocations.
- The user decides whether and how to store test results.
- Separate layer of implementation for presentation of test results.
- Mutlithread friendly. i.e. separate instances on separate threads should have no issues.
- Helper macros for Tests, Testcases and Assertions.
- snake-case aliases for usable types and defs.

## example

```c++
Begin_Test(Sample_Test)

    Begin_Testcase(Sample_Test, test_case_1)
    {
        Assert_True(true);
        Assert_False(false);
        Check_EQ(5,3);
        Assert_EQ(10,10);
        Assert_GT(4,3);
    }
    End_Testcase(Sample_Test, test_case_1)

    Begin_Testcase(Sample_Test, test_case_2)
    {
        Check_True(true);
        Check_True(false);
        Assert_Throws(throw "dummy";);
        Check_Nothrow(throw "dummy";);
    }
    End_Testcase(Sample_Test, test_case_2)


    Begin_Testcase_Registration(Sample_Test)
        Register_Testcase(Sample_Test, test_case_1)
        Register_Testcase(Sample_Test, test_case_2)
    End_Testcase_Registration(Sample_Test)
End_Test(Sample_Test)

int main()
{
    Sample_Test test;
    return test.run_all(pptest::StdReporter<Sample_Test>());
    return test.run_all(pptest::MyCustomReporter<Sample_Test>()); // your implementation
    return test.run_all(pptest::std_reporter<Sample_Test>()); // snake-case alt
    return test.run_all(); // for no report
}
```
