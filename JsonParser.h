#ifndef JsonParser_h
#define JsonParser_h
#include <string>
#include <fstream>
#include <map>

class JsonParser{
private:
    static std::string WhitespaceCleaner(std::string& string);
    static std::map<std::string, std::string> StringFinder(std::string& stringToParse);
public:
    static std::map<std::string, std::string> parser(const std::string& input);
    static std::map<std::string, std::string> parseFile(std::istream& istream);
};

#endif /* JsonParser_h */
