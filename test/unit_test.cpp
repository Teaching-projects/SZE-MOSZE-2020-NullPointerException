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
    
    jsontest = JSON::parseFromFile("test/test_warrior.json");
    
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
    ASSERT_THROW(JSON::parseFromFile("test/wrong_json.json"), std::runtime_error);
}

TEST(ParserTest, NotExistingFileHandling){
    std::ifstream file("nonexists.json");
    ASSERT_THROW(JSON::parseFile(file), std::runtime_error);
}

TEST(ParserTest, NotExistingFileNameHandling){
    ASSERT_THROW(JSON::parseFromFile("notexists.json"), std::runtime_error);
}


//Character TESTS
TEST(CharacterTest, isDeadTest){
    Character p1 = new Character(Character::parseUnit("units/capt.json"));
    Character p2 = new Character(Character::parseUnit("units/hulk.json"));
    p1->fightTilDeath(p2);
    
    ASSERT_TRUE(p1->getHealthPoints() <= 0 || p2->getHealthPoints() <= 0);
}

TEST(CharacterTest, BadParsingTest){
    ASSERT_THROW(Character::parseUnit("notexists.json"), std::runtime_error);
}

TEST(CharacterTest, NotExistingMapTest){
    ASSERT_THROW(Character::parseUnit("wrong_json.json"), std::runtime_error);
}

TEST(CharacterTest, NoThrowCheck){
    Character p1 = new Character(Character::parseUnit("units/capt.json"));
    Character p2 = new Character(Character::parseUnit("units/hulk.json"));
    
    EXPECT_NO_THROW(p1->fightTilDeath(p2));
}

//Hero TESTS

TEST(HeroTest, isHpNotNegative){
    Hero p1 = new Hero(Hero::parse("units/capt.json"));
    Hero p2 = new Hero(Hero::parse("units/hulk.json"));
    p1->fightTilDeath(p2);
    
    ASSERT_TRUE(p1->getHealthPoint() >= 0 and p2->getHealthPoint() >= 0);
}

TEST(HeroTest, isAdvancedHeroReallyLvlup){
    Hero p1 = new Hero(Hero::parse("units/capt.json"));
    Hero p2 = new Hero(Hero::parse("units/hulk.json"));
    for(int i=1; i<3; i++){
        p1->fightTilDeath(p2);
    }
    
    ASSERT_TRUE(p1->getLevel() > 1);
    
}

TEST(HeroTest, isAdvancedHeroReallyGetsXP){
    Hero p1 = new Hero(Hero::parse("units/capt.json"));
    Hero p2 = new Hero(Hero::parse("units/hulk.json"));
    p1->fightTilDeath(p2);
    p2->fightTilDeath(p1);
    
    ASSERT_TRUE(p1->getxp() > 0 and p2->getxp() > 0);
}

TEST(HeroTest, NoThrowCheck){
    Hero p1 = new Hero(Hero::parse("units/capt.json"));
    Hero p2 = new Hero(Hero::parse("units/hulk.json"));
    
    EXPECT_NO_THROW(p1->fightTilDeath(p2));
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
