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
	Testcase(to_hex_char_test, test_0_to_9)
	{
		for(int i = 0; i < 10; ++i)
			AssertEQ(to_hex_char(i), char('0' + i));
	} TestcaseEnd(to_hex_char_test, test_0_to_9);

	Testcase(to_hex_char_test, test_A_to_F)
	{
		for(int i = 0xA; i <= 0xF; ++i)
			AssertEQ(to_hex_char(i), char('A' + (i - 0xA)));
	} TestcaseEnd(to_hex_char_test, test_A_to_F);

	Testcase(to_hex_char_test, test_invalid_positive_ret_0)
	{
		for(int i = 0x10; i <= 0x12; ++i)
			AssertEQ(to_hex_char(i), '0');
	} TestcaseEnd(to_hex_char_test, test_invalid_positive_ret_0);

	Testcase(to_hex_char_test, test_invalid_negative_ret_0)
	{
		for(int i = -2; i < 0; ++i)
			AssertEQ(to_hex_char(i), '0');
	} TestcaseEnd(to_hex_char_test, test_invalid_negative_ret_0);

	Testcase(to_hex_char_test, test_never_throw)
	{
		ExpectThrowNone(to_hex_char(0));
		ExpectThrowNone(to_hex_char(0xF));
		ExpectThrowNone(to_hex_char(-1));
		ExpectThrowNone(to_hex_char(0x10));
	} TestcaseEnd(to_hex_char_test, test_never_throw);

	Registry(to_hex_char_test)
	{
		Register(to_hex_char_test, test_0_to_9)
		Register(to_hex_char_test, test_A_to_F)
		Register(to_hex_char_test, test_invalid_positive_ret_0)
		Register(to_hex_char_test, test_invalid_negative_ret_0)
		Register(to_hex_char_test, test_never_throw)
	};

} TestEnd(to_hex_char_test);


template <typename T> using reporter_t = pptest::colored_printer<T>;
// template <typename T> using reporter_t = pptest::std_printer<T>;

int main()
{
	return to_hex_char_test().run_all(reporter_t<to_hex_char_test>(pptest::normal));
}

