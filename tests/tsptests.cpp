#include <string>

#include <gtest/gtest.h>

#include <tsplib_driver.h>
#include <parser/exceptions/exceptions.h>

TEST(Parser_TSPTest, IntegerArray1) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 1
NODE_COORD_TYPE: TWOD_COORDS
NODE_COORD_SECTION: 1 2 3
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    auto coordinate_map = driver.get_tsp_instance().get_node_coordinate_section();
    ASSERT_FALSE(coordinate_map.empty());
    EXPECT_EQ(1u, coordinate_map.size());
    auto value = coordinate_map[1];
    EXPECT_EQ(2u, value[0]);
    EXPECT_EQ(3u, value[1]);
}

TEST(Parser_TSPTest, IntegerArray2) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : TWOD_COORDS
NODE_COORD_SECTION : 1 102 103
2 105 106
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    auto coordinate_map = driver.get_tsp_instance().get_node_coordinate_section();
    EXPECT_EQ(2u, coordinate_map.size());

    EXPECT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    EXPECT_EQ(102u, value[0]);
    EXPECT_EQ(103u, value[1]);

    value = coordinate_map[2];
    EXPECT_EQ(105u, value[0]);
    EXPECT_EQ(106u, value[1]);
}

TEST(Parser_TSPTest, IntegerArray3) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : TWOD_COORDS
NODE_COORD_SECTION : 1 102 103
2 105 106
3 104 107
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));
    auto instance = driver.get_tsp_instance();
    auto coordinate_map = instance.get_node_coordinate_section();
    ASSERT_EQ(3u, coordinate_map.size());

    EXPECT_THROW(coordinate_map.at(4), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(3));

    ASSERT_EQ(2u, coordinate_map.at(1).size());
    ASSERT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    EXPECT_EQ(102u, value[0]);
    EXPECT_EQ(103u, value[1]);

    value = coordinate_map[2];
    EXPECT_EQ(105u, value[0]);
    EXPECT_EQ(106u, value[1]);

    value = coordinate_map[3];
    EXPECT_EQ(104u, value[0]);
    EXPECT_EQ(107u, value[1]);
}

TEST(Parser_TSPTest, RealArray1) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : TWOD_COORDS
NODE_COORD_SECTION : 1 102.1 103.2
2 105.4 106.3)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));
    auto instance = driver.get_tsp_instance();
    auto coordinate_map = instance.get_node_coordinate_section();
    ASSERT_EQ(2u, coordinate_map.size());

    EXPECT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    EXPECT_EQ(2u, coordinate_map.at(1).size());
    EXPECT_EQ(2u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    EXPECT_EQ(102.1, value[0]);
    EXPECT_EQ(103.2, value[1]);

    value = coordinate_map[2];
    EXPECT_EQ(105.4, value[0]);
    EXPECT_EQ(106.3, value[1]);
}


TEST(Parser_TSPTest, MixedArray1) {
    std::string str = R"(
TYPE : TSP
DIMENSION : 2
NODE_COORD_TYPE : THREED_COORDS
NODE_COORD_SECTION : 1 102.0 103 104.0
2 105 106.1 107.0
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));
    auto instance = driver.get_tsp_instance();
    auto coordinate_map = instance.get_node_coordinate_section();
    EXPECT_EQ(2u, coordinate_map.size());

    EXPECT_THROW(coordinate_map.at(3), std::out_of_range);
    ASSERT_NO_THROW(coordinate_map.at(2));

    ASSERT_EQ(3u, coordinate_map.at(1).size());
    ASSERT_EQ(3u, coordinate_map.at(2).size());

    auto value = coordinate_map[1];
    EXPECT_EQ(102, value[0]);
    EXPECT_EQ(103, value[1]);
    EXPECT_EQ(104, value[2]);

    value = coordinate_map[2];
    EXPECT_EQ(105, value[0]);
    EXPECT_EQ(106.1, value[1]);
    EXPECT_EQ(107, value[2]);
}

TEST(Parser_TSPTest, IncorrectType) {
    std::string str = "TYPE : TSP";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_THROW(driver.get_tour_instance(), TSP::PARSER::Inconsistent_definition_exception);
}

TEST(Parser_TSPEdgeTest, EUC_2D) {
    std::string str = R"(
TYPE : TSP
COMMENT : This is a test for the Euclidean 2D space edge weight type
NAME : Euclidean test
EDGE_WEIGHT_TYPE: EUC_2D
DIMENSION : 3
NODE_COORD_SECTION : 1 0 0
2 4 0
3 0 4
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_THROW(driver.get_tour_instance(), TSP::PARSER::Inconsistent_definition_exception);

    auto instance = driver.get_tsp_instance();
    EXPECT_EQ(TSP::NODE_COORD_TYPE::TWO_D, instance.get_node_coordinate_type());

    auto matrix = instance.get_edge_weight_matrix();

    ASSERT_EQ(instance.get_dimension(), matrix.size());
    ASSERT_EQ(instance.get_dimension(), matrix[0].size());

    EXPECT_EQ(4, matrix[0][1]);
    EXPECT_EQ(4, matrix[0][2]);
    EXPECT_EQ(4, matrix[2][0]);
}

TEST(Parser_TSPEdgeTest, EXPLICIT_FULL_MATRIX_WRONG_DIMENSION) {
    std::string str = R"(
TYPE : TSP
COMMENT : This is a test for the Euclidean 2D space edge weight type
NAME : Euclidean test
EDGE_WEIGHT_TYPE: EXPLICIT
EDGE_WEIGHT_FORMAT FULL_MATRIX
DIMENSION : 2
EDGE_DATA_SECTION : 1 0 0
2 4 0
3 0 4
)";
    TSPLIB::Driver driver;
    ASSERT_THROW(driver.parse_string(str, "Test"), TSP::PARSER::Inconsistent_definition_exception);
}

TEST(Parser_TSPEdgeTest, EXPLICIT_FULL_MATRIX) {
    std::string str = R"(
TYPE : TSP
COMMENT : This is a test for the Euclidean 2D space edge weight type
NAME : Euclidean test
EDGE_WEIGHT_TYPE: EXPLICIT
EDGE_WEIGHT_FORMAT FULL_MATRIX
DIMENSION : 3
EDGE_DATA_SECTION : 1 0 0
2 4 0
3 0 4
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_THROW(driver.get_tour_instance(), TSP::PARSER::Inconsistent_definition_exception);

    auto instance = driver.get_tsp_instance();
    EXPECT_EQ(TSP::NODE_COORD_TYPE::NONE, instance.get_node_coordinate_type());
    ASSERT_EQ(TSP::EDGE_WEIGHT_TYPE::EXPLICIT, instance.get_edge_weight_type());

    auto matrix = instance.get_edge_weight_matrix();

    ASSERT_EQ(instance.get_dimension(), matrix.size());
    ASSERT_EQ(instance.get_dimension(), matrix[0].size());

    TSPLIB::Matrix<int> val = {
        {1,0,0},
        {2,4,0},
        {3,0,4}
       };
    ASSERT_EQ(val, matrix);
}
