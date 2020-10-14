#ifndef JsonParser_h
#define JsonParser_h
#include <map>

class JsonParser{
private:
    static std::string WhitespaceCleaner(std::string&);
    const static std::map<std::string, std::string> StringFinder(const std::string&);
public:
    static std::map<std::string, std::string> parser(const std::string&);
    static std::map<std::string, std::string> parseFile(std::istream&);
};

#endif /* JsonParser_h */
