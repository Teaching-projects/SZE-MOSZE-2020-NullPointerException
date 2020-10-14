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
    std::string readline,name,hp,dmg  = "";
    bool ertek = false;
    
    for (int i = 0; i < Data.length(); i++) {
        
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
            else readline += Data[i];
        }
        if(Data[i] == ','){
            readline = "";
        }
    }
    
    Map["name"] = WhitespaceCleanerAndFormatChecker(name);
    Map["hp"] = WhitespaceCleanerAndFormatChecker(hp);
    Map["dmg"] = WhitespaceCleanerAndFormatChecker(dmg);
    
    if(Map.find("name") != Map.end() or Map.find("hp") != Map.end() or Map.find("dmg") != Map.end()){
        return Map;
    }else{
        throw std::runtime_error("Bad mapping");
    }
}

std::string JsonParser::WhitespaceCleanerAndFormatChecker(std::string& string){
    int szamlalo = 0;
    
    if(string != ""){
        do{
            if(string[szamlalo] != ' '){
                break;
            }
            if(iswspace(string[szamlalo])){
                string.erase(szamlalo, szamlalo+1);
            }
        }while(!isalnum(string[szamlalo]));
    }else{
        throw std::runtime_error("The json format is bad.");
    }

    for(int i=0; i<string.length(); i++){
        if(isspace(string[i]) and (isspace(string[i+1]) or isspace(string[i-1]))){
            throw std::runtime_error("Bad Mapping..");
        }
    }
    return string;
}
