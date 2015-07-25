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

TEST(BasicParserTest, IntegerArray1) {
    std::string str = R"(
DIMENSION : 1
NODE_COORD_TYPE: EUC_2D
NODE_COORD_SECTION: 1 2 3
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));

    auto coordinate_map = driver.get_instance().get_node_coordinate_section();
    ASSERT_FALSE(coordinate_map.empty());
    ASSERT_EQ(1u, coordinate_map.size());
}

TEST(BasicParserTest, IntegerArray2) {
    std::string str = R"(
DIMENSION : 2
NODE_COORD_TYPE : EUC_2D
NODE_COORD_SECTION : 1 102 103
2 105 106
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));

    auto coordinate_map = driver.get_instance().get_node_coordinate_section();
    ASSERT_EQ(2u, coordinate_map.size());

    ASSERT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());
}

TEST(BasicParserTest, IntegerArray3) {
    std::string str = R"(
DIMENSION : 2
NODE_COORD_TYPE : EUC_2D
NODE_COORD_SECTION : 1 102 103
2 105 106 107
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));

    auto coordinate_map = driver.get_instance().get_node_coordinate_section();
    ASSERT_EQ(2u, coordinate_map.size());

    ASSERT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(3u, coordinate_map.at(2).size());
    ASSERT_EQ(2u, coordinate_map.at(1).size());
}

TEST(BasicParserTest2, Simple) {

}

