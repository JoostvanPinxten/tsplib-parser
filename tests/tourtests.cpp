
#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(Parser_TourTest, Basic) {
    std::string str = "TYPE : TOUR";
    TSPLIB::Driver driver;
    std::stringstream stream(str);
    ASSERT_TRUE(driver.parse_stream(stream, "Test"));
}
