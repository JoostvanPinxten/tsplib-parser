#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(LexerTest, Name) {

    std::string str = "NAME : This is a test\n";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
//    std::cout << driver.result << std::endl;
}

TEST(LexerTest, Simple2) {

}

TEST(LexerTest, Simple3) {

}

TEST(LexerTest2, Simple) {

}

