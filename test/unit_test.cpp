#include <string>
#include <map>
#include <fstream>
#include <gtest/gtest.h>
#include "../JsonParser.h"
#include "../Hero.h"
#include "../AdvancedHero.h"

//JSONPARSER TESTS
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

TEST(ParserTest, NotExistingFileHandling){
    std::ifstream file("nonexists.json");
    ASSERT_THROW(JsonParser::parseFile(file), std::runtime_error);
}

TEST(ParserTest, NotExistingFileNameHandling){
    ASSERT_THROW(JsonParser::parser("notexists.json"), std::runtime_error);
}


//HERO TESTS
TEST(HeroTest, isDeadTest){
    Hero* p1 = new Hero(Hero::parseUnit("units/capt.json"));
    Hero* p2 = new Hero(Hero::parseUnit("units/hulk.json"));
    p1->Battle(p2);
    
    ASSERT_TRUE(p1->getHP() <= 0 || p2->getHP() <= 0);
}

TEST(HeroTest, BadParsingTest){
    ASSERT_THROW(Hero::parseUnit("notexists.json"), std::runtime_error);
}

TEST(HeroTest, NotExistingMapTest){
    ASSERT_THROW(Hero::parseUnit("wrong_json.json"), std::runtime_error);
}

//ADVANCEDHERO TESTS
TEST(AdvancedHeroTest, parsingAdvancedHeroTest){
    Hero* p1 = new Hero(Hero::parseUnit("test/test_warrior.json"));
    AdvancedHero* p2 = new AdvancedHero(AdvancedHero::parseUnit("test_warrior.json"));
    
    ASSERT_EQ(p1, p2);
}


TEST(AdvancedHeroTest, isHpNotNegative){
    AdvancedHero* p1 = new AdvancedHero(AdvancedHero::parseUnit("units/capt.json"));
    AdvancedHero* p2 = new AdvancedHero(AdvancedHero::parseUnit("units/hulk.json"));
    p1->advancedBattle(p2);
    
    ASSERT_TRUE(p1->getHP() >= 0 and p2->getHP() >= 0);
}

TEST(AdvancedHeroTest, isAdvancedHeroReallyLvlup){
    AdvancedHero* p1 = new AdvancedHero(AdvancedHero::parseUnit("units/capt.json"));
    AdvancedHero* p2 = new AdvancedHero(AdvancedHero::parseUnit("units/hulk.json"));
    for(int i=1; i<3; i++){
        p1->advancedDamage(p2);
    }
    
    ASSERT_TRUE(p1->getLvl() > 1);
    
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
