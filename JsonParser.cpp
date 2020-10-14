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
    
    Map["name"] = WhitespaceCleaner(name);
    Map["hp"] = WhitespaceCleaner(hp);
    Map["dmg"] = WhitespaceCleaner(dmg);
    
    return Map;
}

std::string JsonParser::WhitespaceCleaner(std::string& string){
    int szamlalo = 0;
    do{
        if(iswspace(string[szamlalo])){
            string.erase(szamlalo, szamlalo+1);
        }
    }while(!isalnum(string[szamlalo]));
    
    return string;
}
