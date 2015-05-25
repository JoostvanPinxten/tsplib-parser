#include <gtest/gtest.h>
#include <tsplib_driver.h>
#include <string>

TEST(LexerTest, Simple) {

    std::string str = "This is a test";
    tsplib_driver driver;
    driver.parse(str);
    std::cout << driver.result << std::endl;
}

TEST(LexerTest, Simple2) {

}

TEST(LexerTest, Simple3) {

}

TEST(LexerTest2, Simple) {

}

