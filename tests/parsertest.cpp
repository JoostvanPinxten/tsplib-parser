#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(ParserTest, Name) {
    std::string str = "NAME : This is a test";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}

TEST(ParserTest, NameKeywordInField) {
    std::string str = "NAME\t\t\t \t: \t \t NAME::NAME";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}

TEST(ParserTest, IntegerArray1) {
    std::string str = "NODE_COORD_SECTION: 1 2 3";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}

TEST(ParserTest, IntegerArray2) {
    std::string str = "NODE_COORD_SECTION : 1 2 3 4 5 67";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}

TEST(ParserTest2, Simple) {

}

