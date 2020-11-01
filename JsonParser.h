/**
 * \class JsonParser
 *
 * \brief JsonParser class
 *
 * This class declares the JsonParser object, which is used to correctly read the heroes attributes.
 *
 * \author NullPointerException
 *
 * \version 1.0
 *
 * \date 2020/11/01 11:00
 *
 */

#ifndef JsonParser_h
#define JsonParser_h
#include <map>

//This is the class of the JsonParser
class JsonParser{
private:
    
    /**
     * \brief Json file format checking, and cleaning out the blank spaces
     *
     * \return Returns a string that has the json files data
     */
    static std::string WhitespaceCleanerAndFormatChecker(std::string&);

public:

    /**
     * \brief This method is used to find the hearo's attributes. It looks for the hero's name, health, damage and attackcooldown and maps them together.
     *
     * \return Returns the correct Map file of a hero if everythings good. If there's a problem we get a "Bad mapping" warning.
     */
    const static std::map<std::string, std::string> StringFinder(const std::string&);
    
    /**
     * \brief This method is responsible to open the json files.
     *
     * \return Returns a Map if the json file exist. If there's a problem, we get a "not exist" warning.
     */
    static std::map<std::string, std::string> parser(const std::string&);
    
    /**
     * \brief This method is used to read in the json files data.
     *
     * \return Returns with the data of the json file.
     */
    static std::map<std::string, std::string> parseFile(std::istream&);
};

#endif /* JsonParser_h */
