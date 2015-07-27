#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(Parser_TSPTest, IntegerArray1) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 1
NODE_COORD_TYPE: EUC_2D
NODE_COORD_SECTION: 1 2 3
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));

    auto coordinate_map = driver.get_tsp_instance().get_node_coordinate_section();
    ASSERT_FALSE(coordinate_map.empty());
    ASSERT_EQ(1u, coordinate_map.size());
    auto value = coordinate_map[1];
    ASSERT_EQ(2u, value[0]);
    ASSERT_EQ(3u, value[1]);
}

TEST(Parser_TSPTest, IntegerArray2) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : EUC_2D
NODE_COORD_SECTION : 1 102 103
2 105 106
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));

    auto coordinate_map = driver.get_tsp_instance().get_node_coordinate_section();
    ASSERT_EQ(2u, coordinate_map.size());

    ASSERT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    ASSERT_EQ(102u, value[0]);
    ASSERT_EQ(103u, value[1]);

    value = coordinate_map[2];
    ASSERT_EQ(105u, value[0]);
    ASSERT_EQ(106u, value[1]);
}

TEST(Parser_TSPTest, IntegerArray3) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : EUC_2D
NODE_COORD_SECTION : 1 102 103
2 105 106
3 104 107
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
    auto instance = driver.get_tsp_instance();
    auto coordinate_map = instance.get_node_coordinate_section();
    ASSERT_EQ(3u, coordinate_map.size());

    ASSERT_THROW(coordinate_map.at(4), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(3));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    ASSERT_EQ(102u, value[0]);
    ASSERT_EQ(103u, value[1]);

    value = coordinate_map[2];
    ASSERT_EQ(105u, value[0]);
    ASSERT_EQ(106u, value[1]);

    value = coordinate_map[3];
    ASSERT_EQ(104u, value[0]);
    ASSERT_EQ(107u, value[1]);
}

TEST(Parser_TSPTest, RealArray1) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : EUC_2D
NODE_COORD_SECTION : 1 102.1 103.2
2 105.4 106.3)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
    auto instance = driver.get_tsp_instance();
    auto coordinate_map = instance.get_node_coordinate_section();
    ASSERT_EQ(2u, coordinate_map.size());

    ASSERT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    ASSERT_EQ(102.1, value[0]);
    ASSERT_EQ(103.2, value[1]);

    value = coordinate_map[2];
    ASSERT_EQ(105.4, value[0]);
    ASSERT_EQ(106.3, value[1]);
}


TEST(Parser_TSPTest, MixedArray1) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : EUC_2D
NODE_COORD_SECTION : 1 102.0 103
2 105 106.1
)";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
    auto instance = driver.get_tsp_instance();
    auto coordinate_map = instance.get_node_coordinate_section();
    ASSERT_EQ(2u, coordinate_map.size());

    ASSERT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    ASSERT_EQ(102, value[0]);
    ASSERT_EQ(103, value[1]);

    value = coordinate_map[2];
    ASSERT_EQ(105, value[0]);
    ASSERT_EQ(106.1, value[1]);
}
