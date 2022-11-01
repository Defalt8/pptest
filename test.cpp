#include <pptest>
#include <colored_printer>

Begin_Test(Passing_Assertions_Test)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_True)
	{
		Assert_True(true);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_True)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_False)
	{
		Assert_False(false);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_False)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_Null)
	{
		int * ptr = nullptr;
		Assert_Null(ptr);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_Null)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_NotNull)
	{
		int i  = 5;
		Assert_NotNull(&i);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_NotNull)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_EQ)
	{
		int i = 2;
		Assert_EQ(i, 2);
		Assert_EQ(i, i);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_EQ)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_NEQ)
	{
		int i = 3;
		Assert_NEQ(i, 2);
		Assert_NEQ(i, i+1);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_NEQ)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_GT)
	{
		int i = 3;
		Assert_GT(i, 2);
		Assert_GT(i, i-1);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_GT)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_LT)
	{
		int i = 3;
		Assert_LT(i, 5);
		Assert_LT(i, i+1);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_LT)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_GE)
	{
		int i = 3;
		Assert_GE(i, 2);
		Assert_GE(i, i-1);
		Assert_GE(i, i);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_GE)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_LE)
	{
		int i = 3;
		Assert_LE(i, 5);
		Assert_LE(i, i+1);
		Assert_LE(i, i);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_LE)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_Throw)
	{
		Assert_Throw(int, throw 5);
		Assert_Throw(char const *, throw "oops");
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_Throw)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_NoThrow)
	{
		Assert_NoThrow(int);
		Assert_NoThrow(int, throw "oops");
		Assert_NoThrow(char const *, throw 5);
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_NoThrow)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_ThrowAny)
	{
		Assert_ThrowAny(throw 5);
		Assert_ThrowAny(throw "oops");
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_ThrowAny)

	Begin_Testcase(Passing_Assertions_Test, test_Assert_ThrowNone)
	{
		Assert_ThrowNone();
	}
	End_Testcase(Passing_Assertions_Test, test_Assert_ThrowNone)

	Begin_Testcase_Registration(Passing_Assertions_Test)
	{
		Register_Testcase(Passing_Assertions_Test, test_Assert_True)
		Register_Testcase(Passing_Assertions_Test, test_Assert_False)
		Register_Testcase(Passing_Assertions_Test, test_Assert_Null)
		Register_Testcase(Passing_Assertions_Test, test_Assert_NotNull)
		Register_Testcase(Passing_Assertions_Test, test_Assert_EQ)
		Register_Testcase(Passing_Assertions_Test, test_Assert_NEQ)
		Register_Testcase(Passing_Assertions_Test, test_Assert_GT)
		Register_Testcase(Passing_Assertions_Test, test_Assert_LT)
		Register_Testcase(Passing_Assertions_Test, test_Assert_GE)
		Register_Testcase(Passing_Assertions_Test, test_Assert_LE)
		Register_Testcase(Passing_Assertions_Test, test_Assert_Throw)
		Register_Testcase(Passing_Assertions_Test, test_Assert_NoThrow)
		Register_Testcase(Passing_Assertions_Test, test_Assert_ThrowAny)
		Register_Testcase(Passing_Assertions_Test, test_Assert_ThrowNone)
	}
	End_Testcase_Registration(Passing_Assertions_Test)
End_Test(Passing_Assertions_Test)


Begin_Test(Failing_Assertions_Test)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_True)
	{
		Assert_True(false);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_True)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_False)
	{
		Assert_False(true);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_False)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_Null)
	{
		int i  = 5;
		Assert_Null(&i);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_Null)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_NotNull)
	{
		int * ptr = nullptr;
		Assert_NotNull(ptr);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_NotNull)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_EQ)
	{
		int i = 2;
		Assert_EQ(i, 3);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_EQ)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_NEQ)
	{
		int i = 3;
		Assert_NEQ(i, 3);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_NEQ)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_GT)
	{
		int i = 3;
		Assert_GT(i, 3);
		Assert_GT(i, i+1);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_GT)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_LT)
	{
		int i = 3;
		Assert_LT(i, 3);
		Assert_LT(i, i-1);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_LT)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_GE)
	{
		int i = 3;
		Assert_GE(i, 4);
		Assert_GE(i, i+1);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_GE)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_LE)
	{
		int i = 3;
		Assert_LE(i, 2);
		Assert_LE(i, i-1);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_LE)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_Throw)
	{
		Assert_Throw(char const *, throw 5);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_Throw)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_Throw_empty)
	{
		Assert_Throw(int);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_Throw_empty)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_NoThrow)
	{
		Assert_NoThrow(int, throw 5);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_NoThrow)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_ThrowAny)
	{
		Assert_ThrowAny();
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_ThrowAny)

	Begin_Testcase(Failing_Assertions_Test, test_Assert_ThrowNone)
	{
		Assert_ThrowNone(throw 5);
	}
	End_Testcase(Failing_Assertions_Test, test_Assert_ThrowNone)

	Begin_Testcase(Failing_Assertions_Test, test_unhandled_exception)
	{
		throw 5;
	}
	End_Testcase(Failing_Assertions_Test, test_unhandled_exception)

	Begin_Testcase_Registration(Failing_Assertions_Test)
	{
		Register_Testcase(Failing_Assertions_Test, test_Assert_True)
		Register_Testcase(Failing_Assertions_Test, test_Assert_False)
		Register_Testcase(Failing_Assertions_Test, test_Assert_Null)
		Register_Testcase(Failing_Assertions_Test, test_Assert_NotNull)
		Register_Testcase(Failing_Assertions_Test, test_Assert_EQ)
		Register_Testcase(Failing_Assertions_Test, test_Assert_NEQ)
		Register_Testcase(Failing_Assertions_Test, test_Assert_GT)
		Register_Testcase(Failing_Assertions_Test, test_Assert_LT)
		Register_Testcase(Failing_Assertions_Test, test_Assert_GE)
		Register_Testcase(Failing_Assertions_Test, test_Assert_LE)
		Register_Testcase(Failing_Assertions_Test, test_Assert_Throw)
		Register_Testcase(Failing_Assertions_Test, test_Assert_Throw_empty)
		Register_Testcase(Failing_Assertions_Test, test_Assert_NoThrow)
		Register_Testcase(Failing_Assertions_Test, test_Assert_ThrowAny)
		Register_Testcase(Failing_Assertions_Test, test_Assert_ThrowNone)
		Register_Testcase(Failing_Assertions_Test, test_unhandled_exception)
	}
	End_Testcase_Registration(Failing_Assertions_Test)
End_Test(Failing_Assertions_Test)

template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

Begin_Test(Assertions_Test)


	Begin_Testcase(Assertions_Test, test_Passing_Assertions)
	{
		auto sub_reporter                    = reporter_t<Passing_Assertions_Test>(pptest::only_failing);
		auto passing_assertions_test_summary = pptest::test_summary {};

		Passing_Assertions_Test().run_all(sub_reporter, &passing_assertions_test_summary, 0);
		Assert_EQ(passing_assertions_test_summary.failing_assertions, 0);
	}
	End_Testcase(Assertions_Test, test_Passing_Assertions)

	Begin_Testcase(Assertions_Test, test_Failing_Assertions)
	{
		auto sub_reporter                    = reporter_t<Failing_Assertions_Test>(pptest::only_passing);
		auto failing_assertions_test_summary = pptest::test_summary {};

		Failing_Assertions_Test().run_all(sub_reporter, &failing_assertions_test_summary, 0);
		Assert_EQ(failing_assertions_test_summary.passing_assertions, 0);
	}
	End_Testcase(Assertions_Test, test_Failing_Assertions)

	Begin_Testcase_Registration(Assertions_Test)
	{
		Register_Testcase(Assertions_Test, test_Passing_Assertions)
		Register_Testcase(Assertions_Test, test_Failing_Assertions)
	}
	End_Testcase_Registration(Assertions_Test)
End_Test(Assertions_Test)


int main()
{
	return Assertions_Test().run_all(reporter_t<Assertions_Test>(pptest::normal));
}