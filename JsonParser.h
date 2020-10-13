#ifndef JsonParser_h
#define JsonParser_h
#include <string>
#include <fstream>
#include <map>

class JsonParser{
private:
    
public:
    static std::map<std::string, std::string> parser(const std::string& input);
    static std::map<std::string, std::string> parser(std::istream& istream);
};

#endif /* JsonParser_h */
