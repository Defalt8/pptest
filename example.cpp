#include <pptest>


Begin_Test(Sample_Test)

	Begin_Testcase(Sample_Test, test_case_1)
	{
		Assert_True(true);
		Assert_False(false);
		Assert_True(false);
		Assert_False(true);
	}
	End_Testcase(Sample_Test, test_case_1)

	Begin_Testcase(Sample_Test, test_case_2)
	{
		Check_True(true);
		Check_True(false);
		Check_False(true);
		Check_False(false);
		throw 5;
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
	return test.run_all(pptest::std_reporter<Sample_Test>());
}