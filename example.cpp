#include <pptest>
#include <colored_reporter>

// NOTE: colored_reporter implementations has only been implemented for windows.
//   implementations for linux will come soon.

Begin_Test(Sample_Test)

	Pre_Run(Sample_Test)
	{
		// printf("\nbefore run %s...", this->name());
	}

	Post_Run(Sample_Test)
	{
		// printf("\nafter run... %s %d,%d", this->name(), _passed_, _failed_);
	}

	Pre_Testcase_Run(Sample_Test)
	{
		// printf("\n before run %s...", _testcase_.name());
	}

	Post_Testcase_Run(Sample_Test)
	{
		// printf("\n after run... %s %d,%d", _testcase_.name(), _passed_, _failed_);
	}

	Begin_Testcase(Sample_Test, test_case_1)
	{
		Assert_True(true);
		Assert_False(false);
		Assert_True(false);
		Assert_True(1);
	}
	End_Testcase(Sample_Test, test_case_1)

	Begin_Testcase(Sample_Test, test_case_2)
	{
		Check_True(true);
		Check_True(false);
		Check_False(true);
		Check_False(false);
		throw 5;
		Assert_True(2);
	}
	End_Testcase(Sample_Test, test_case_2)


	Begin_Testcase(Sample_Test, test_case_3)
	{
		Check_Null(nullptr);
		Check_NotNull(1);
		Check_EQ(1,1);
		Check_NEQ(2,3);
		Check_GT(5,3);
		Check_LT(3,5);
		Check_GE(5,5);
		Check_GE(5,3);
		Check_LE(3,3);
		Check_LE(3,5);
		Assert_Null(nullptr);
		Assert_NotNull(1);
		Assert_EQ(1,1);
		Assert_NEQ(2,3);
		Assert_GT(5,3);
		Assert_LT(3,5);
		Assert_GE(5,5);
		Assert_GE(5,3);
		Assert_LE(3,3);
		Assert_LE(3,5);
		Check_Throw(...,int i = 1);
		Check_Throw(..., throw 5);
		Check_NoThrow(...,int i = 3);
		Check_NoThrow(..., throw 5);
		Assert_Throw(..., throw 5);
		Assert_Throw(...,int i = 2);
		Assert_True(3);
	}
	End_Testcase(Sample_Test, test_case_3)

	Begin_Testcase(Sample_Test, test_case_4)
	{
		[&]()
		{
			Assert_NoThrow(..., int j = 0);
			Assert_NoThrow(..., throw 5);
		}();
		Assert_True(4);
	}
	End_Testcase(Sample_Test, test_case_4)

	Begin_Testcase(Sample_Test, test_case_5)
	{
		int i = 5;
		Assert_EQ(i, 5);
		Assert_EQ(i, i);
	}
	End_Testcase(Sample_Test, test_case_5)


	Begin_Testcase_Registration(Sample_Test)
		Register_Testcase(Sample_Test, test_case_1)
		Register_Testcase(Sample_Test, test_case_2)
		Register_Testcase(Sample_Test, test_case_3)
		Register_Testcase(Sample_Test, test_case_4)
		Register_Testcase(Sample_Test, test_case_5)
	End_Testcase_Registration(Sample_Test)
End_Test(Sample_Test)

int main()
{
	Sample_Test test;
	// try out the different options
	// using reporter_t = pptest::std_reporter<Sample_Test>;
	using reporter_t = pptest::colored_reporter<Sample_Test>;
	return test.run_all(reporter_t(pptest::normal));
// 	return test.run_all(reporter_t(pptest::verbose));
// 	return test.run_all(reporter_t(pptest::minimal));
// 	return test.run_all(reporter_t(pptest::minimal1));
// 	return test.run_all(reporter_t(pptest::quiet));
}