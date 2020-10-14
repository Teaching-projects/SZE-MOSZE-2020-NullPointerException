#include "JsonParser.h"

std::map<std::string, std::string> JsonParser::parseFile(std::istream& istream){
    std::string Data;
    if(istream.good()){
        std::string line = "";
        while(std::getline(istream, line)){
            Data += line;
        }
    }
    
    return JsonParser::StringFinder(Data);
}

std::map<std::string, std::string> JsonParser::StringFinder(std::string& Data){
    std::map<std::string, std::string> Map;
    std::string readline = "";
    
    for (int i = 0; i < Data.size(); i++) {
        if (isalnum(Data[i])) {
            if (readline == "name"){
                Map["name"] += Data[i];
            }
            else if (readline == "hp"){
                Map["hp"] += Data[i];
            }
            else if (readline == "dmg"){
                Map["dmg"] += Data[i];
            }
            else readline += Data[i];
        }
    }
    readline = "";
    
    return Map;
}
