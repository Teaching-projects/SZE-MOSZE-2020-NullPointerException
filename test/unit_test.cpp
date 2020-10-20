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
    expected.insert(std::pair<std::string, std::string>("attackcooldown", "2"));
    
    jsontest = JsonParser::parser("test/test_warrior.json");
    
    ASSERT_EQ(expected, jsontest);
    
}

TEST(ParserTest, FileInputTest){
    std::map<std::string, std::string> expected;
    std::map<std::string, std::string> jsontest;
    
    expected.insert(std::pair<std::string, std::string>("name", "Monster"));
    expected.insert(std::pair<std::string, std::string>("hp", "10000"));
    expected.insert(std::pair<std::string, std::string>("dmg", "100"));
    expected.insert(std::pair<std::string, std::string>("attackcooldown", "2"));
    
    std::string filename("test/test_warrior.json");
    
    std::ifstream fileinput(filename);
    
    jsontest = JsonParser::parseFile(fileinput);
    
    ASSERT_EQ(expected, jsontest);
    
}

TEST(ParserTest, StringInputTest){
    std::map<std::string, std::string> expected;
    std::string stringjson =
    "{\n\t\"name\"  :  \"Monster\",\n\t\"hp\":10000,\n\t\"dmg\":100,\n\t\"attackcooldown\":2, \n}";
    
    expected.insert(std::pair<std::string, std::string>("name", "Monster"));
    expected.insert(std::pair<std::string, std::string>("hp", "10000"));
    expected.insert(std::pair<std::string, std::string>("dmg", "100"));
    expected.insert(std::pair<std::string, std::string>("attackcooldown", "2"));
    
    std::map<std::string, std::string> jsontest = JsonParser::StringFinder(stringjson);
    
    ASSERT_EQ(expected, jsontest);
    
}

TEST(ParserTest, JsonParserFailTest){
    ASSERT_THROW(JsonParser::parser("test/wrong_json.json"), std::runtime_error);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
