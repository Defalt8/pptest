#include <pptest>


Begin_Test(Sample_Test)

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


	Begin_Testcase_Registration(Sample_Test)
		Register_Testcase(Sample_Test, test_case_1)
		Register_Testcase(Sample_Test, test_case_2)
		Register_Testcase(Sample_Test, test_case_3)
		Register_Testcase(Sample_Test, test_case_4)
	End_Testcase_Registration(Sample_Test)
End_Test(Sample_Test)

int main()
{
	return Sample_Test().run_all(pptest::std_reporter<Sample_Test>({false}));
}