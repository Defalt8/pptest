#include <pptest>
#include <colored_printer>

Begin_Test(passing_assertions_test)

    Begin_Testcase(passing_assertions_test, assert_true)
    {
        Assert_True(true);
    }
    End_Testcase(passing_assertions_test, assert_true)

    Begin_Testcase(passing_assertions_test, assert_throw_any)
    {
        Assert_ThrowAny(throw 5);
    }
    End_Testcase(passing_assertions_test, assert_throw_any)

    Begin_Testcase_Registration(passing_assertions_test)
    {
        Register_Testcase(passing_assertions_test, assert_true)
        Register_Testcase(passing_assertions_test, assert_throw_any)
    }
    End_Testcase_Registration(passing_assertions_test)
End_Test(passing_assertions_test)

Begin_Test(failing_assertions_test)

    Begin_Testcase(failing_assertions_test, assert_true)
    {
        Assert_True(false);
    }
    End_Testcase(failing_assertions_test, assert_true)

    Begin_Testcase(failing_assertions_test, assert_throw_any)
    {
        Assert_ThrowAny();
    }
    End_Testcase(failing_assertions_test, assert_throw_any)

    Begin_Testcase_Registration(failing_assertions_test)
    {
        Register_Testcase(failing_assertions_test, assert_true)
        Register_Testcase(failing_assertions_test, assert_throw_any)
    }
    End_Testcase_Registration(failing_assertions_test)
End_Test(failing_assertions_test)


template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

Begin_Test(assertions_test)


    Begin_Testcase(assertions_test, passing_assertions)
    {
        auto reporter        = reporter_t<passing_assertions_test>(pptest::only_failing);
        auto passing_summary = pptest::TestSummary {};

        passing_assertions_test().run_all(reporter, &passing_summary);
        Assert_EQ(passing_summary.failing_assertions, 0);
    }
    End_Testcase(assertions_test, passing_assertions)

    Begin_Testcase(assertions_test, failing_assertions)
    {
        auto reporter        = reporter_t<failing_assertions_test>(pptest::only_passing);
        auto failing_summary = pptest::TestSummary {};

        failing_assertions_test().run_all(reporter, &failing_summary);
        Assert_EQ(failing_summary.passing_assertions, 0);
    }
    End_Testcase(assertions_test, failing_assertions)

    Begin_Testcase_Registration(assertions_test)
    {
        Register_Testcase(assertions_test, passing_assertions)
        Register_Testcase(assertions_test, failing_assertions)
    }
    End_Testcase_Registration(assertions_test)
End_Test(assertions_test)


int main()
{
    return assertions_test().run_all(reporter_t<assertions_test>(pptest::normal));
}
