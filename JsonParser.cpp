#include "JsonParser.h"
#include <iostream>

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
    bool ertek = false;
    std::string chars = ":\"";
    
    for (int i = 0; i < Data.length(); i++) {
        
        if(Data[i] == ':'){
            ertek = true;
        }else if (Data[i] == ','){
            ertek = false;
        }
        
        if (isalnum(Data[i]) or ertek == true) {
            
            if (readline == "name"){
                if(Data[i] !=':' and Data[i] !='"'){
                    Map["name"] += Data[i];
                }
            }
            else if (readline == "hp"){
                if(Data[i] !=':' and Data[i] !='"'){
                    Map["hp"] += Data[i];
                }
            }
            else if (readline == "dmg"){
                if(Data[i] !=':' and Data[i] !='"'){
                    Map["dmg"] += Data[i];
                }
            }
            else readline += Data[i];
        }
        if(Data[i] == ','){
            readline = "";
        }
    }

    std::cout << Data << std::endl << Map["hp"] << std::endl;
    
    return Map;
}
