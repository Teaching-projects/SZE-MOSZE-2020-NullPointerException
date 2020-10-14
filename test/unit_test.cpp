#include <string>
#include <map>
#include <fstream>
#include <gtest/gtest.h>
#include "../JsonParser.h"

TEST(ParserTest, FilenameInputTest){
    std::map<std::string, std::string> expected;
    std::map<std::string, std::string> jsontest;
    
    expected.insert(std::pair<std::string, std::string>("name", "Monster"));
    expected.insert(std::pair<std::string, std::string>("hp", "10000"));
    expected.insert(std::pair<std::string, std::string>("dmg", "100"));
    
    jsontest = JsonParser::parser("test/test_warrior.json");
    
    ASSERT_EQ(expected, jsontest);
    
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
