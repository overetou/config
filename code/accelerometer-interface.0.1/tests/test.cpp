#include <iostream>
#include <gtest/gtest.h>
#include "EMSGyro.hpp"

//Creates the test class and sets it up with a chosen script. Also opens the subprocess.
class	EMSGyroTest : public ::testing::Test, public EMSGyro
{
	protected:
	void	SetUp(void) override
	{
		testScript.setScriptName("tests/test.py");
		testScript.open(NULL);
	}

	EMSGyro	testScript;
};

//Tests that the subprocess can be launched and killed at will without problem.
TEST_F(EMSGyroTest, open_and_close)
{
	EXPECT_EQ(testScript.close(NULL), true);
	EXPECT_EQ(testScript.open(NULL), true);
}

//Tests function output and if the reading is correct. Make sure that the tested script acts in accordance with the tests.
TEST_F(EMSGyroTest, read)
{
	char	c;
	EXPECT_NE(testScript.read((void*)&c), '1');
	EXPECT_EQ(testScript.read((void*)&c), 1);
	EXPECT_NE(testScript.read((void*)&c), '8');
	EXPECT_NE(testScript.read((void*)&c), 2);
	testScript.read(&c);
	EXPECT_EQ(c, '1');
}

//Checks that the write returns 0. May be improved if needed.
TEST_F(EMSGyroTest, write)
{
	EXPECT_EQ(testScript.write(NULL), 0);
}

//A function used to test callbacks.
void	print_hello(void)
{
	std::cout << "Hello !" << std::endl;
}

//Captures output and check that the setReadHandler() func worked correctly by calling read.
TEST_F(EMSGyroTest, setReadHandler)
{
	char c;
	testing::internal::CaptureStdout();
	testScript.setReadHandler(print_hello);
	testScript.read(&c);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "Hello !\n");
}

//Captures the output of iocontrol and checks that it displays what is expected. Reminder : iocontrol is used for calibration with the gyro.
TEST_F(EMSGyroTest, iocontrol)
{
	testing::internal::CaptureStdout();
	testScript.iocontrol(NULL);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_STREQ(output.c_str(), "1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n");
}

//Calls every tests.
int	main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
