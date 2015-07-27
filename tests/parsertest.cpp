#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(Basic_ParserTest, Name) {
    std::string str = "NAME : This is a test";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_EQ("This is a test", driver.get_instance().get_name());
}

TEST(Basic_ParserTest, NameKeywordInField) {
    std::string str = "NAME\t\t\t \t: \t \t NAME::NAME";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_EQ("NAME::NAME", driver.get_instance().get_name());
}

TEST(Basic_ParserTest, CommentKeywordInField) {
    std::string str = "COMMENT\t\t\t \t: \t \t COMMENT: :COMMENT";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_EQ("COMMENT: :COMMENT", driver.get_instance().get_comment());
}
