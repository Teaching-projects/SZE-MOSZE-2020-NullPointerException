#include <string>
#include <map>
#include <fstream>
#include <gtest/gtest.h>
#include "../JSON.h"
#include "../Character.h"
#include "../Hero.h"

//JSON TESTS
TEST(ParserTest, FilenameInputTest){
    std::map<std::string, std::string> expected;
    std::map<std::string, std::string> jsontest;
    
    expected.insert(std::pair<std::string, std::string>("name", "Monster"));
    expected.insert(std::pair<std::string, std::string>("hp", "10000"));
    expected.insert(std::pair<std::string, std::string>("dmg", "100"));
    expected.insert(std::pair<std::string, std::string>("attackcooldown", "2"));
    
    jsontest = JSON::parser("test/test_warrior.json");
    
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
    
    jsontest = JSON::parseFile(fileinput);
    
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
    
    std::map<std::string, std::string> jsontest = JSON::StringFinder(stringjson);
    
    ASSERT_EQ(expected, jsontest);
    
}

TEST(ParserTest, JsonParserFailTest){
    ASSERT_THROW(JSON::parser("test/wrong_json.json"), std::runtime_error);
}

TEST(ParserTest, NotExistingFileHandling){
    std::ifstream file("nonexists.json");
    ASSERT_THROW(JSON::parseFile(file), std::runtime_error);
}

TEST(ParserTest, NotExistingFileNameHandling){
    ASSERT_THROW(JSON::parser("notexists.json"), std::runtime_error);
}


//Character TESTS
TEST(HeroTest, isDeadTest){
    Character* p1 = new Character(Character::parseUnit("units/capt.json"));
    Character* p2 = new Character(Character::parseUnit("units/hulk.json"));
    p1->Battle(p2);
    
    ASSERT_TRUE(p1->getHP() <= 0 || p2->getHP() <= 0);
}

TEST(HeroTest, BadParsingTest){
    ASSERT_THROW(Character::parseUnit("notexists.json"), std::runtime_error);
}

TEST(HeroTest, NotExistingMapTest){
    ASSERT_THROW(Character::parseUnit("wrong_json.json"), std::runtime_error);
}

TEST(HeroTest, NoThrowCheck){
    Character* p1 = new Character(Character::parseUnit("units/capt.json"));
    Character* p2 = new Character(Character::parseUnit("units/hulk.json"));
    
    EXPECT_NO_THROW(p1->Battle(p2));
}

//Hero TESTS

TEST(AdvancedHeroTest, isHpNotNegative){
    Hero* p1 = new Hero(Hero::parseUnit("units/capt.json"));
    Hero* p2 = new Hero(Hero::parseUnit("units/hulk.json"));
    p1->advancedBattle(p2);
    
    ASSERT_TRUE(p1->getHP() >= 0 and p2->getHP() >= 0);
}

TEST(AdvancedHeroTest, isAdvancedHeroReallyLvlup){
    Hero* p1 = new Hero(Hero::parseUnit("units/capt.json"));
    Hero* p2 = new Hero(Hero::parseUnit("units/hulk.json"));
    for(int i=1; i<3; i++){
        p1->advancedDamage(p2);
    }
    
    ASSERT_TRUE(p1->getLvl() > 1);
    
}

TEST(AdvancedHeroTest, isAdvancedHeroReallyGetsXP){
    Hero* p1 = new Hero(Hero::parseUnit("units/capt.json"));
    Hero* p2 = new Hero(Hero::parseUnit("units/hulk.json"));
    p1->advancedDamage(p2);
    p2->advancedDamage(p1);
    
    ASSERT_TRUE(p1->getxp() > 0 and p2->getxp() > 0);
}

TEST(AdvancedHeroTest, NoThrowCheck){
    Hero* p1 = new Hero(Hero::parseUnit("units/capt.json"));
    Hero* p2 = new Hero(Hero::parseUnit("units/hulk.json"));
    
    EXPECT_NO_THROW(p1->advancedBattle(p2));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
