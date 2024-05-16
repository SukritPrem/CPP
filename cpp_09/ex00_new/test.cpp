#include <gtest/gtest.h>
#include "BitcoinExchange.hpp"
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(testing, CaseHaveAlphaInValue) {
    // Create an ostringstream to capture the output
    std::ostringstream oss;
    // Get the original buffer of std::cout
    std::streambuf* oldbuf = std::cout.rdbuf();
    // Redirect std::cout to the ostringstream buffer
    std::cout.rdbuf(oss.rdbuf());

    BitcoinExchange exchange("../test/errorValue.csv","../data.csv");
    // Restore the original buffer of std::cout
    std::cout.rdbuf(oldbuf);
    
    // Get the captured string from the ostringstream
    std::string capturedOutput = oss.str();
    
    // Print the captured string
    std::cout << "Captured output: " << capturedOutput;
    
    std::string expect = "Error: Bad input => 2011-01-03 | A\n";

    EXPECT_EQ(capturedOutput, expect);
}

TEST(testing, CaseHaveAlphaInDateYear) {
    std::ostringstream oss;
    
    std::streambuf* oldbuf = std::cout.rdbuf();

    std::cout.rdbuf(oss.rdbuf());

    BitcoinExchange exchange("../test/errorDateYear.csv","../data.csv");
    std::cout.rdbuf(oldbuf);

    std::string capturedOutput = oss.str();  
    
    std::string expect = "Error: Bad input => 201A-01-03 | 3\n";

    EXPECT_EQ(capturedOutput, expect);
}