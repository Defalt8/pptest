#include <pptest>
#include <colored_printer>

Test(Passing_Assertions_Test)
{
	TestInit(Passing_Assertions_Test);

	Testcase(test_AssertTrue_true)
	{
		ExpectTrue(true);
		AssertTrue(true);
	} TestcaseEnd(test_AssertTrue_true);

	Testcase(test_AssertFalse_false)
	{
		ExpectFalse(false);
		AssertFalse(false);
	} TestcaseEnd(test_AssertFalse_false);

	Testcase(test_AssertNull_null)
	{
		ExpectNull(nullptr);
		AssertNull(nullptr);
	} TestcaseEnd(test_AssertNull_null);

	Testcase(test_AssertNotNull_valid)
	{
		int valid = 5;
		ExpectNotNull(&valid);
		AssertNotNull(&valid);
	} TestcaseEnd(test_AssertNotNull_valid);

	Testcase(test_AssertEQ_equal)
	{
		ExpectEQ(3, 3);
		AssertEQ(3, 3);
	} TestcaseEnd(test_AssertEQ_equal);

	Testcase(test_AssertNEQ_inequal)
	{
		ExpectNEQ(3, 2);
		AssertNEQ(3, 2);
	} TestcaseEnd(test_AssertNEQ_inequal);

	Testcase(test_AssertGT_greater)
	{
		ExpectGT(3, 2);
		AssertGT(3, 2);
	} TestcaseEnd(test_AssertGT_greater);

	Testcase(test_AssertLT_less)
	{
		ExpectLT(3, 5);
		AssertLT(3, 5);
	} TestcaseEnd(test_AssertLT_less);

	Testcase(test_AssertGE_equal)
	{
		ExpectGE(3, 3);
		AssertGE(3, 3);
	} TestcaseEnd(test_AssertGE_equal);

	Testcase(test_AssertGE_greater)
	{
		ExpectGE(3, 2);
		AssertGE(3, 2);
	} TestcaseEnd(test_AssertGE_greater);

	Testcase(test_AssertLE_equal)
	{
		ExpectLE(3, 3);
		AssertLE(3, 3);
	} TestcaseEnd(test_AssertLE_equal);

	Testcase(test_AssertLE_less)
	{
		ExpectLE(2, 3);
		AssertLE(2, 3);
	} TestcaseEnd(test_AssertLE_less);

	Testcase(test_AssertThrow_expected)
	{
		ExpectThrow(int, throw 5);
		ExpectThrow(char const *, throw "oops");
		AssertThrow(int, throw 5);
		AssertThrow(char const *, throw "oops");
	} TestcaseEnd(test_AssertThrow_expected);

	Testcase(test_AssertNoThrow_nothrow)
	{
		ExpectNoThrow(int);
		AssertNoThrow(int);
	} TestcaseEnd(test_AssertNoThrow_nothrow);

	Testcase(test_AssertNoThrow_throw_unexpected)
	{
		ExpectNoThrow(int, throw "oops");
		ExpectNoThrow(char const *, throw 5);
		AssertNoThrow(int, throw "oops");
		AssertNoThrow(char const *, throw 5);
	} TestcaseEnd(test_AssertNoThrow_throw_unexpected);

	Testcase(test_AssertThrowAny_throw)
	{
		ExpectThrowAny(throw 5);
		ExpectThrowAny(throw "oops");
		AssertThrowAny(throw 5);
		AssertThrowAny(throw "oops");
	} TestcaseEnd(test_AssertThrowAny_throw);

	Testcase(test_AssertThrowNone_nothrow)
	{
		ExpectThrowNone(;);
		AssertThrowNone(;);
	} TestcaseEnd(test_AssertThrowNone_nothrow);

};

Test(Failing_Assertions_Test)
{
	TestInit(Failing_Assertions_Test);
	
	Testcase(test_AssertTrue_false)
	{
		ExpectTrue(false);
		AssertTrue(false);
	} TestcaseEnd(test_AssertTrue_false);

	Testcase(test_AssertFalse_true)
	{
		ExpectFalse(true);
		AssertFalse(true);
	} TestcaseEnd(test_AssertFalse_true);

	Testcase(test_AssertNull_valid)
	{
		int valid  = 5;
		ExpectNull(&valid);
		AssertNull(&valid);
	} TestcaseEnd(test_AssertNull_valid);

	Testcase(test_AssertNotNull_null)
	{
		ExpectNotNull(nullptr);
		AssertNotNull(nullptr);
	} TestcaseEnd(test_AssertNotNull_null);

	Testcase(test_AssertEQ_inequal)
	{
		ExpectEQ(2, 3);
		AssertEQ(2, 3);
	} TestcaseEnd(test_AssertEQ_inequal);

	Testcase(test_AssertNEQ_equal)
	{
		ExpectNEQ(3, 3);
		AssertNEQ(3, 3);
	} TestcaseEnd(test_AssertNEQ_equal);

	Testcase(test_AssertGT_equal)
	{
		ExpectGT(3, 3);
		AssertGT(3, 3);
	} TestcaseEnd(test_AssertGT_equal);

	Testcase(test_AssertGT_less)
	{
		ExpectGT(3, 3+1);
		AssertGT(3, 3+1);
	} TestcaseEnd(test_AssertGT_less);

	Testcase(test_AssertLT_equal)
	{
		ExpectLT(3, 3);
		AssertLT(3, 3);
	} TestcaseEnd(test_AssertLT_equal);

	Testcase(test_AssertLT_greater)
	{
		ExpectLT(4, 3);
		AssertLT(4, 3);
	} TestcaseEnd(test_AssertLT_greater);

	Testcase(test_AssertGE_less)
	{
		ExpectGE(3, 4);
		AssertGE(3, 4);
	} TestcaseEnd(test_AssertGE_less);

	Testcase(test_AssertLE_greater)
	{
		ExpectLE(3, 2);
		AssertLE(3, 2);
	} TestcaseEnd(test_AssertLE_greater);

	Testcase(test_AssertThrow_throw_unexpected)
	{
		ExpectThrow(char const *, throw 5);
		AssertThrow(char const *, throw 5);
	} TestcaseEnd(test_AssertThrow_throw_unexpected);

	Testcase(test_AssertThrow_nothrow)
	{
		AssertThrow(int);
	} TestcaseEnd(test_AssertThrow_nothrow);

	Testcase(test_AssertNoThrow_throw_expected)
	{
		ExpectNoThrow(int, throw 5);
		AssertNoThrow(int, throw 5);
	} TestcaseEnd(test_AssertNoThrow_throw_expected);

	Testcase(test_AssertThrowAny_nothrow)
	{
		ExpectThrowAny(;);
		AssertThrowAny(;);
	} TestcaseEnd(test_AssertThrowAny_nothrow);

	Testcase(test_AssertThrowNone_throw)
	{
		ExpectThrowNone(throw 5);
		AssertThrowNone(throw 5);
	} TestcaseEnd(test_AssertThrowNone_throw);

	Testcase(test_unhandled_exception_throw)
	{
		throw 5;
	} TestcaseEnd(test_unhandled_exception_throw);

};

TestRegistry(Passing_Assertions_Test)
{
	Register(test_AssertTrue_true)
	Register(test_AssertFalse_false)
	Register(test_AssertNull_null)
	Register(test_AssertNotNull_valid)
	Register(test_AssertEQ_equal)
	Register(test_AssertNEQ_inequal)
	Register(test_AssertGT_greater)
	Register(test_AssertLT_less)
	Register(test_AssertGE_equal)
	Register(test_AssertGE_greater)
	Register(test_AssertLE_equal)
	Register(test_AssertLE_less)
	Register(test_AssertThrow_expected)
	Register(test_AssertNoThrow_nothrow)
	Register(test_AssertNoThrow_throw_unexpected)
	Register(test_AssertThrowAny_throw)
	Register(test_AssertThrowNone_nothrow)
};

TestRegistry(Failing_Assertions_Test)
{
	Register(test_AssertTrue_false)
	Register(test_AssertFalse_true)
	Register(test_AssertNull_valid)
	Register(test_AssertNotNull_null)
	Register(test_AssertEQ_inequal)
	Register(test_AssertNEQ_equal)
	Register(test_AssertGT_equal)
	Register(test_AssertGT_less)
	Register(test_AssertLT_equal)
	Register(test_AssertLT_greater)
	Register(test_AssertGE_less)
	Register(test_AssertLE_greater)
	Register(test_AssertThrow_throw_unexpected)
	Register(test_AssertThrow_nothrow)
	Register(test_AssertNoThrow_throw_expected)
	Register(test_AssertThrowAny_nothrow)
	Register(test_AssertThrowNone_throw)
	Register(test_unhandled_exception_throw)
};

template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

Test(Assertions_Test)
{
	TestInit(Assertions_Test);

	Testcase(test_Passing_Assertions)
	{
		auto reporter                        = reporter_t<Passing_Assertions_Test>(pptest::only_failing);
		auto passing_assertions_test_summary = pptest::test_summary {};
		Passing_Assertions_Test().run_all(reporter, &passing_assertions_test_summary, 0);
		ExpectEQ(passing_assertions_test_summary.passing_assertions, 40);
		AssertEQ(passing_assertions_test_summary.failing_assertions, 0);
	} TestcaseEnd(test_Passing_Assertions);

	Testcase(test_Failing_Assertions)
	{
		auto reporter                        = reporter_t<Failing_Assertions_Test>(pptest::only_passing);
		auto failing_assertions_test_summary = pptest::test_summary {};
		Failing_Assertions_Test().run_all(reporter, &failing_assertions_test_summary, 0);
		ExpectEQ(failing_assertions_test_summary.failing_assertions, 34);
		AssertEQ(failing_assertions_test_summary.passing_assertions, 0);
	} TestcaseEnd(test_Failing_Assertions);

};

TestRegistry(Assertions_Test)
{
	Register(test_Passing_Assertions)
	Register(test_Failing_Assertions)
};


int main()
{
	return Assertions_Test().run_all(reporter_t<Assertions_Test>(pptest::normal));
}