
#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>
#include <basetsplibinstance.h>

TEST(GTSP, Basic_instance) {
    std::string str = R"(
NAME : vm1084
COMMENT : truncated 1084-city problem (Reinelt)
TYPE : GTSP
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

TEST(GTSP, AGTSP_4br17) {
    std::string str = R"(
NAME:  4br17
TYPE: AGTSP
COMMENT: 17 city problem (Repetto)
DIMENSION:  17
EDGE_WEIGHT_TYPE: EXPLICIT
EDGE_WEIGHT_FORMAT: FULL_MATRIX
EDGE_WEIGHT_SECTION
 9999    3    5   48   48    8    8    5    5    3    3    0    3    5    8    8    5
    3 9999    3   48   48    8    8    5    5    0    0    3    0    3    8    8    5
    5    3 9999   72   72   48   48   24   24    3    3    5    3    0   48   48   24
   48   48   74 9999    0    6    6   12   12   48   48   48   48   74    6    6   12
   48   48   74    0 9999    6    6   12   12   48   48   48   48   74    6    6   12
    8    8   50    6    6 9999    0    8    8    8    8    8    8   50    0    0    8
    8    8   50    6    6    0 9999    8    8    8    8    8    8   50    0    0    8
    5    5   26   12   12    8    8 9999    0    5    5    5    5   26    8    8    0
    5    5   26   12   12    8    8    0 9999    5    5    5    5   26    8    8    0
    3    0    3   48   48    8    8    5    5 9999    0    3    0    3    8    8    5
    3    0    3   48   48    8    8    5    5    0 9999    3    0    3    8    8    5
    0    3    5   48   48    8    8    5    5    3    3 9999    3    5    8    8    5
    3    0    3   48   48    8    8    5    5    0    0    3 9999    3    8    8    5
    5    3    0   72   72   48   48   24   24    3    3    5    3 9999   48   48   24
    8    8   50    6    6    0    0    8    8    8    8    8    8   50 9999    0    8
    8    8   50    6    6    0    0    8    8    8    8    8    8   50    0 9999    8
    5    5   26   12   12    8    8    0    0    5    5    5    5   26    8    8 9999
GTSP_SETS: 4
GTSP_SET_SECTION :
1 4 5 -1
2 1 2 3 10 11 12 13 14 -1
3 8 9 17 -1
4 6 7 15 16 -1
EOF
)";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_EQ("4br17", driver.get_instance().get_name());
    auto instance = driver.get_gtsp_instance();
    auto clusters = instance.get_clusters();

    EXPECT_EQ(4u, clusters.size());
    ASSERT_EQ(2u, clusters[0].size());
    EXPECT_EQ(3u, clusters[0][0]);
    EXPECT_EQ(4u, clusters[0][1]);
}
