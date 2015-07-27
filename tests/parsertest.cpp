#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(BasicParserTest, Name) {
    std::string str = "NAME : This is a test";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}

TEST(BasicParserTest, NameKeywordInField) {
    std::string str = "NAME\t\t\t \t: \t \t NAME::NAME";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}


TEST(BasicParserTest2, Simple) {

}

