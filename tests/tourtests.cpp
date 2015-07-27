#include <string>

#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <parser/exceptions/exceptions.h>

TEST(Parser_TourTest, Basic) {
    std::string str = "TYPE : TOUR";
    TSPLIB::Driver driver;
    ASSERT_TRUE(driver.parse_string(str, "Test"));

}

TEST(Parser_TourTest, IncorrectType) {
    std::string str = "TYPE : TOUR";
    TSPLIB::Driver driver;

    ASSERT_TRUE(driver.parse_string(str, "Test"));

    EXPECT_THROW(driver.get_tsp_instance(), TSP::PARSER::Inconsistent_definition_exception);
}
