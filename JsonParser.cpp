#include "JsonParser.h"
#include <iostream>
#include <fstream>
#include <string>

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

std::map<std::string, std::string> JsonParser::parser(const std::string& Filename){
    std::ifstream jsonFile;
    std::map<std::string, std::string> Map;
    jsonFile.open(Filename);
    if(jsonFile.is_open()){
        Map = JsonParser::parseFile(jsonFile);
        jsonFile.close();
        return Map;
    }else{
        throw std::runtime_error(Filename + " not exist.");
    }
    
}

const std::map<std::string, std::string> JsonParser::StringFinder(const std::string& Data){
    std::map<std::string, std::string> Map;
    std::string readline,name,hp,dmg,as  = "";
    bool ertek = false;
    
    for (unsigned int i = 0; i < Data.length(); i++) {
        
        if(Data[i] == ':'){
            ertek = true;
        }else if (Data[i] == ',' or Data[i] == '}'){
            ertek = false;
        }
        
        if (isalnum(Data[i]) or ertek == true) {
            if (readline == "name"){
                if(Data[i] !=':' and Data[i] !='"'){
                    name += Data[i];
                }
            }
            else if (readline == "hp"){
                if(Data[i] !=':' and Data[i] !='"'){
                    hp += Data[i];
                }
            }
            else if (readline == "dmg"){
                if(Data[i] !=':' and Data[i] !='"'){
                    dmg += Data[i];
                }
            }
            else if (readline == "attackcooldown"){
                if(Data[i] !=':' and Data[i] !='"'){
                    as += Data[i];
                }
            }
            else readline += Data[i];
        }
        if(Data[i] == ','){
            readline = "";
        }
    }
    
    Map["name"] = WhitespaceCleanerAndFormatChecker(name);
    Map["hp"] = WhitespaceCleanerAndFormatChecker(hp);
    Map["dmg"] = WhitespaceCleanerAndFormatChecker(dmg);
    Map["attackcooldown"] = WhitespaceCleanerAndFormatChecker(as);
    
    if(Map.find("name") != Map.end() && Map.find("hp") != Map.end() && Map.find("dmg") != Map.end() && Map.find("attackcooldown") != Map.end()){
        return Map;
    }else{
        throw std::runtime_error("Bad mapping");
    }
}

std::string JsonParser::WhitespaceCleanerAndFormatChecker(std::string& string){
    int wsc = 0;
    if(string != ""){
        for(unsigned i = 0; i < string.length(); i++){
            if(!isalnum(string[i])){
                if(iswspace(string[i])){
                    wsc++;
                }
            }else{
                break;
            }
        }
        string.erase(0, wsc);
    }else{
        throw std::runtime_error("Bad Mapping or bad json format.");
    }
    return string;
}
