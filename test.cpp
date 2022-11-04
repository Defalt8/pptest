#include <pptest>
#include <colored_printer>

Test(Passing_Assertions_Test)
{
	Testcase(Passing_Assertions_Test, test_AssertTrue_true)
	{
		ExpectTrue(true);
		AssertTrue(true);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertTrue_true);

	Testcase(Passing_Assertions_Test, test_AssertFalse_false)
	{
		ExpectFalse(false);
		AssertFalse(false);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertFalse_false);

	Testcase(Passing_Assertions_Test, test_AssertNull_null)
	{
		ExpectNull(nullptr);
		AssertNull(nullptr);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertNull_null);

	Testcase(Passing_Assertions_Test, test_AssertNotNull_valid)
	{
		int valid = 5;
		ExpectNotNull(&valid);
		AssertNotNull(&valid);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertNotNull_valid);

	Testcase(Passing_Assertions_Test, test_AssertEQ_equal)
	{
		ExpectEQ(3, 3);
		AssertEQ(3, 3);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertEQ_equal);

	Testcase(Passing_Assertions_Test, test_AssertNEQ_inequal)
	{
		ExpectNEQ(3, 2);
		AssertNEQ(3, 2);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertNEQ_inequal);

	Testcase(Passing_Assertions_Test, test_AssertGT_greater)
	{
		ExpectGT(3, 2);
		AssertGT(3, 2);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertGT_greater);

	Testcase(Passing_Assertions_Test, test_AssertLT_less)
	{
		ExpectLT(3, 5);
		AssertLT(3, 5);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertLT_less);

	Testcase(Passing_Assertions_Test, test_AssertGE_equal)
	{
		ExpectGE(3, 3);
		AssertGE(3, 3);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertGE_equal);

	Testcase(Passing_Assertions_Test, test_AssertGE_greater)
	{
		ExpectGE(3, 2);
		AssertGE(3, 2);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertGE_greater);

	Testcase(Passing_Assertions_Test, test_AssertLE_equal)
	{
		ExpectLE(3, 3);
		AssertLE(3, 3);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertLE_equal);

	Testcase(Passing_Assertions_Test, test_AssertLE_less)
	{
		ExpectLE(2, 3);
		AssertLE(2, 3);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertLE_less);

	Testcase(Passing_Assertions_Test, test_AssertThrow_expected)
	{
		ExpectThrow(int, throw 5);
		ExpectThrow(char const *, throw "oops");
		AssertThrow(int, throw 5);
		AssertThrow(char const *, throw "oops");
	} TestcaseEnd(Passing_Assertions_Test, test_AssertThrow_expected);

	Testcase(Passing_Assertions_Test, test_AssertNoThrow_nothrow)
	{
		ExpectNoThrow(int);
		AssertNoThrow(int);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertNoThrow_nothrow);

	Testcase(Passing_Assertions_Test, test_AssertNoThrow_throw_unexpected)
	{
		ExpectNoThrow(int, throw "oops");
		ExpectNoThrow(char const *, throw 5);
		AssertNoThrow(int, throw "oops");
		AssertNoThrow(char const *, throw 5);
	} TestcaseEnd(Passing_Assertions_Test, test_AssertNoThrow_throw_unexpected);

	Testcase(Passing_Assertions_Test, test_AssertThrowAny_throw)
	{
		ExpectThrowAny(throw 5);
		ExpectThrowAny(throw "oops");
		AssertThrowAny(throw 5);
		AssertThrowAny(throw "oops");
	} TestcaseEnd(Passing_Assertions_Test, test_AssertThrowAny_throw);

	Testcase(Passing_Assertions_Test, test_AssertThrowNone_nothrow)
	{
		ExpectThrowNone();
		AssertThrowNone();
	} TestcaseEnd(Passing_Assertions_Test, test_AssertThrowNone_nothrow);

	Registry(Passing_Assertions_Test)
	{
		Register(Passing_Assertions_Test, test_AssertTrue_true)
		Register(Passing_Assertions_Test, test_AssertFalse_false)
		Register(Passing_Assertions_Test, test_AssertNull_null)
		Register(Passing_Assertions_Test, test_AssertNotNull_valid)
		Register(Passing_Assertions_Test, test_AssertEQ_equal)
		Register(Passing_Assertions_Test, test_AssertNEQ_inequal)
		Register(Passing_Assertions_Test, test_AssertGT_greater)
		Register(Passing_Assertions_Test, test_AssertLT_less)
		Register(Passing_Assertions_Test, test_AssertGE_equal)
		Register(Passing_Assertions_Test, test_AssertGE_greater)
		Register(Passing_Assertions_Test, test_AssertLE_equal)
		Register(Passing_Assertions_Test, test_AssertLE_less)
		Register(Passing_Assertions_Test, test_AssertThrow_expected)
		Register(Passing_Assertions_Test, test_AssertNoThrow_nothrow)
		Register(Passing_Assertions_Test, test_AssertNoThrow_throw_unexpected)
		Register(Passing_Assertions_Test, test_AssertThrowAny_throw)
		Register(Passing_Assertions_Test, test_AssertThrowNone_nothrow)
	};

} TestEnd(Passing_Assertions_Test);


Test(Failing_Assertions_Test)
{
	Testcase(Failing_Assertions_Test, test_AssertTrue_false)
	{
		ExpectTrue(false);
		AssertTrue(false);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertTrue_false);

	Testcase(Failing_Assertions_Test, test_AssertFalse_true)
	{
		ExpectFalse(true);
		AssertFalse(true);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertFalse_true);

	Testcase(Failing_Assertions_Test, test_AssertNull_valid)
	{
		int valid  = 5;
		ExpectNull(&valid);
		AssertNull(&valid);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertNull_valid);

	Testcase(Failing_Assertions_Test, test_AssertNotNull_null)
	{
		ExpectNotNull(nullptr);
		AssertNotNull(nullptr);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertNotNull_null);

	Testcase(Failing_Assertions_Test, test_AssertEQ_inequal)
	{
		ExpectEQ(2, 3);
		AssertEQ(2, 3);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertEQ_inequal);

	Testcase(Failing_Assertions_Test, test_AssertNEQ_equal)
	{
		ExpectNEQ(3, 3);
		AssertNEQ(3, 3);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertNEQ_equal);

	Testcase(Failing_Assertions_Test, test_AssertGT_equal)
	{
		ExpectGT(3, 3);
		AssertGT(3, 3);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertGT_equal);

	Testcase(Failing_Assertions_Test, test_AssertGT_less)
	{
		ExpectGT(3, 3+1);
		AssertGT(3, 3+1);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertGT_less);

	Testcase(Failing_Assertions_Test, test_AssertLT_equal)
	{
		ExpectLT(3, 3);
		AssertLT(3, 3);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertLT_equal);

	Testcase(Failing_Assertions_Test, test_AssertLT_greater)
	{
		ExpectLT(4, 3);
		AssertLT(4, 3);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertLT_greater);

	Testcase(Failing_Assertions_Test, test_AssertGE_less)
	{
		ExpectGE(3, 4);
		AssertGE(3, 4);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertGE_less);

	Testcase(Failing_Assertions_Test, test_AssertLE_greater)
	{
		ExpectLE(3, 2);
		AssertLE(3, 2);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertLE_greater);

	Testcase(Failing_Assertions_Test, test_AssertThrow_throw_unexpected)
	{
		ExpectThrow(char const *, throw 5);
		AssertThrow(char const *, throw 5);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertThrow_throw_unexpected);

	Testcase(Failing_Assertions_Test, test_AssertThrow_nothrow)
	{
		AssertThrow(int);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertThrow_nothrow);

	Testcase(Failing_Assertions_Test, test_AssertNoThrow_throw_expected)
	{
		ExpectNoThrow(int, throw 5);
		AssertNoThrow(int, throw 5);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertNoThrow_throw_expected);

	Testcase(Failing_Assertions_Test, test_AssertThrowAny_nothrow)
	{
		ExpectThrowAny();
		AssertThrowAny();
	} TestcaseEnd(Failing_Assertions_Test, test_AssertThrowAny_nothrow);

	Testcase(Failing_Assertions_Test, test_AssertThrowNone_throw)
	{
		ExpectThrowNone(throw 5);
		AssertThrowNone(throw 5);
	} TestcaseEnd(Failing_Assertions_Test, test_AssertThrowNone_throw);

	Testcase(Failing_Assertions_Test, test_unhandled_exception_throw)
	{
		throw 5;
	} TestcaseEnd(Failing_Assertions_Test, test_unhandled_exception_throw);

	Registry(Failing_Assertions_Test)
	{
		Register(Failing_Assertions_Test, test_AssertTrue_false)
		Register(Failing_Assertions_Test, test_AssertFalse_true)
		Register(Failing_Assertions_Test, test_AssertNull_valid)
		Register(Failing_Assertions_Test, test_AssertNotNull_null)
		Register(Failing_Assertions_Test, test_AssertEQ_inequal)
		Register(Failing_Assertions_Test, test_AssertNEQ_equal)
		Register(Failing_Assertions_Test, test_AssertGT_equal)
		Register(Failing_Assertions_Test, test_AssertGT_less)
		Register(Failing_Assertions_Test, test_AssertLT_equal)
		Register(Failing_Assertions_Test, test_AssertLT_greater)
		Register(Failing_Assertions_Test, test_AssertGE_less)
		Register(Failing_Assertions_Test, test_AssertLE_greater)
		Register(Failing_Assertions_Test, test_AssertThrow_throw_unexpected)
		Register(Failing_Assertions_Test, test_AssertThrow_nothrow)
		Register(Failing_Assertions_Test, test_AssertNoThrow_throw_expected)
		Register(Failing_Assertions_Test, test_AssertThrowAny_nothrow)
		Register(Failing_Assertions_Test, test_AssertThrowNone_throw)
		Register(Failing_Assertions_Test, test_unhandled_exception_throw)
	};

} TestEnd(Failing_Assertions_Test);

template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

Test(Assertions_Test)
{
	Testcase(Assertions_Test, test_Passing_Assertions)
	{
		auto reporter                        = reporter_t<Passing_Assertions_Test>(pptest::only_failing);
		auto passing_assertions_test_summary = pptest::test_summary {};
		Passing_Assertions_Test().run_all(reporter, &passing_assertions_test_summary, 0);
		ExpectEQ(passing_assertions_test_summary.passing_assertions, 40);
		AssertEQ(passing_assertions_test_summary.failing_assertions, 0);
	} TestcaseEnd(Assertions_Test, test_Passing_Assertions);

	Testcase(Assertions_Test, test_Failing_Assertions)
	{
		auto reporter                        = reporter_t<Failing_Assertions_Test>(pptest::only_passing);
		auto failing_assertions_test_summary = pptest::test_summary {};
		Failing_Assertions_Test().run_all(reporter, &failing_assertions_test_summary, 0);
		ExpectEQ(failing_assertions_test_summary.failing_assertions, 34);
		AssertEQ(failing_assertions_test_summary.passing_assertions, 0);
	} TestcaseEnd(Assertions_Test, test_Failing_Assertions);

	Registry(Assertions_Test)
	{
		Register(Assertions_Test, test_Passing_Assertions)
		Register(Assertions_Test, test_Failing_Assertions)
	};

} TestEnd(Assertions_Test);


int main()
{
	return Assertions_Test().run_all(reporter_t<Assertions_Test>(pptest::normal));
}