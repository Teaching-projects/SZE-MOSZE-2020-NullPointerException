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
    static std::string WhitespaceCleanerAndFormatChecker(std::string&);  ///< This method is used to check if the json file is in the correct format. Also it cleanes out the blank spaces.
public:
    const static std::map<std::string, std::string> StringFinder(const std::string&);  ///<  This method is used to find the hearo's attributes. It looks for the hero's name, health, damage and attackcooldown and maps them together.
    static std::map<std::string, std::string> parser(const std::string&);  ///< This method is responsible to open the json files.
    static std::map<std::string, std::string> parseFile(std::istream&);  ///<  This method is used to read in the json files data.
};

#endif /* JsonParser_h */
