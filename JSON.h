/**
 * \class JsonParser
 *
 * \brief JsonParser class
 *
 * This class declares the JsonParser object, which is used to correctly read the heroes attributes.
 *
 * \author NullPointerException
 *
 * \version 2.0
 *
 * \date 2020/11/01 11:00
 *
 */

#ifndef JSON_h
#define JSON_h
#include <map>
#include <any>
#include <fstream>
#include <streambuf>
#include <unordered_set>
#include <variant>

//This is the class of the JsonParser
class JSON{
private:
    
    std::map<std::string, std::any> map; ///< This is the default value (map) of the JSON class
    
    /**s
     * \brief After the json files data goes through the stringfinder method, the given string is then analized in this method. This method deletes the unnecessary spaces from the beginning. Also it looks if the string has any value.
     * 
     * \param This gets a string from the stringfinder method
     * 
     * \return Returns a string that has the json files data, without blank spaces
     */
    static std::string WhitespaceCleanerAndFormatChecker(std::string& inputValue);

public:
    
    JSON(std::map<std::string, std::any> map_) : map(map_) {} ///< This is the contrustor. The constructor sets the map parameter of the JSON
    
    /**
     * \brief This method is used to find the hero's attributes. It looks for the hero's name, health, damage and attackcooldown and maps them together.
     *
     * \return Returns the correct Map file of a hero if everythings good. If there's a problem we get a "Bad mapping" runtime error.
     */
    const static std::map<std::string, std::any> StringFinder(const std::string&);
    
    /**
     * \brief This method is responsible to open the json files.
     *
     * \return Returns a Map if the json file exist. If there's a problem, we get a "not exist" runtime error.
     */
    static std::map<std::string, std::any> parseFromFile(const std::string&);
    
    /**
     * \brief This method is used to read in the json files data.
     *
     * \return Returns with the data of the json file.
     */
    static std::map<std::string, std::any> parseFile(std::istream&);
    
    
    class ParseException : public std::exception {}; ///< It is an inherit from std::exception
    
    /**
     * \brief This counts the JSON map datakeys
     *
     * \param Gets a string key of the map
     *
     * \return Returns with the count of the map.
     */
    const unsigned long count(const std::string& key) const { return map.count(key); }
    
    /**
     * \brief This is a converter to get a value from the map. It can convert to string, int, double.
     *
     * \param Gets a string key of the map
     *
     * \return Returns with the converted type value.
     */
    /*template <typename T>
    T get(const std::string& key){
        std::string value = std::any_cast<std::string>(map[key]);
        std::variant<int, double, std::string> converted;
        if (std::is_same<T, int>::value){
            converted=(std::stoi(value));
        }else if(std::is_same<T, double>::value){
            converted=(std::stod(value));
        }else if(std::is_same<T, std::string>::value){
            converted=value;
        }
        
        return std::get<T>(converted);
    }*/
    template <typename T>
    T get(const std::string& key){
        return std::any_cast<T>(map[key]);
    }
};

#endif /* JSON_h */
