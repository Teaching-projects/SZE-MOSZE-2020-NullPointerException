#include "JSON.h"
#include <iostream>
#include <fstream>
#include <string>
#include <any>


std::map<std::string, std::any> JSON::parseFile(std::istream& istream){
    std::string Data;
    if(istream.good()){
        std::string line = "";
        while(std::getline(istream, line)){
            Data += line;
        }
    }else{
        throw std::runtime_error("Wrong file.");
    }
    return JSON::StringFinder(Data);
}

std::map<std::string, std::any> JSON::parseFromFile(const std::string& Filename){
    std::ifstream jsonFile;
    std::map<std::string, std::any> Map;
    jsonFile.open(Filename);
    if(jsonFile.is_open()){
        Map = JSON::parseFile(jsonFile);
        jsonFile.close();
        return Map;
    }else{
        throw std::runtime_error(Filename + " not exist.");
    }
    
}

const std::map<std::string, std::any> JSON::StringFinder(const std::string& Data){
    std::map<std::string, std::any> Map;
    std::string readline,name,hp,dmg,as, key, value  = "";
    bool ertek = false;
    bool isStillKey = false;
    int idezojel = 0;
    int ertekidezo = 0;
    bool isStringValue = false;
    
    for (unsigned int i = 0; i < Data.length(); i++) {
        if(Data[i] == ':'){
            ertek = true;
        }else if ((Data[i] == ',' or Data[i] == '}') and isStringValue == false){
            ertek = false;
            //std::cout << WhitespaceCleanerAndFormatChecker(key) << std::endl << WhitespaceCleanerAndFormatChecker(value) << std::endl;
            Map.insert(std::pair<std::string, std::any>(WhitespaceCleanerAndFormatChecker(key),WhitespaceCleanerAndFormatChecker(value)));
            key = "";
            value = "";
        }else if((Data[i] == '"') and ertek == true){
            ertekidezo++;
            isStringValue = true;
            if(ertekidezo == 2){
                isStringValue = false;
                ertekidezo = 0;
            }
        }
        if((Data[i] == '"' or isStillKey == true) and ertek == false){
            isStillKey = true;
            if(Data[i] == '"') idezojel++;
            if(Data[i] != '"' and Data[i] != ','){
                key += Data[i];
            }
            if(isStillKey == true and idezojel == 2){
                isStillKey = false;
                idezojel = 0;
            }
        }
        if(ertek == true and Data[i] !=':' and Data[i] !='"'){
            value += Data[i];
        }
    }
    return Map;
}

std::string JSON::WhitespaceCleanerAndFormatChecker(std::string& string){
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
