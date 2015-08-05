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

TEST(Basic_ParserTest, FloatingPointExponent) {
    std::string str = R"(
NAME : vm1084
COMMENT : truncated 1084-city problem (Reinelt)
TYPE : TSP
DIMENSION : 4
EDGE_WEIGHT_TYPE : EUC_2D

NODE_COORD_SECTION
1 4.08000e+03 5.23600e+03
2 4.68800e+03 6.46800e+03
3 5.29600e+03 9.21800e+03
4 9.39200e+03 1.09560e+04
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_EQ("vm1084", driver.get_instance().get_name());
    auto instance = driver.get_tsp_instance();

    EXPECT_EQ(6.46800e+03, instance.get_node_coordinate_section().at(2).at(1));
    EXPECT_EQ(9.39200e+03, instance.get_node_coordinate_section().at(4).at(0));

}

TEST(Basic_ParserTest, DataAfterSection) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 4
EDGE_WEIGHT_TYPE : EUC_2D

NODE_COORD_SECTION
1 4.08000e+03 5.23600e+03
2 4.68800e+03 6.46800e+03
3 5.29600e+03 9.21800e+03
4 9.39200e+03 1.09560e+04
NAME : vm1084
COMMENT : truncated 1084-city problem (Reinelt)
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_EQ("vm1084", driver.get_instance().get_name());
    auto instance = driver.get_tsp_instance();

    EXPECT_EQ(6.46800e+03, instance.get_node_coordinate_section().at(2).at(1));
    EXPECT_EQ(9.39200e+03, instance.get_node_coordinate_section().at(4).at(0));

}
