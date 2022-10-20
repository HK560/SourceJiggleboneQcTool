#include "BoneInfo.h"
#include "LogInit.h"

#include <regex>

BoneInfo::BoneInfo() {
    file = nullptr;
    path = "";
    boneList = nullptr;
    info("BoneInfo Init finished");

};
bool BoneInfo::setFile(std::string path){

    this->file = new std::ifstream();
    if (file == nullptr)error("ifsteam error");
    this->path = path;
    info("Set DefineBone file path:{}", path);
    return true;
}
void BoneInfo::setBoneList(){

    file->open(path, std::ios::in);
    if (!file->is_open()) {
        // std::cout << "Error: Could not open " << path << std::endl;
        error("Error: Could not find {}", path);
        return ;
    }
    info("Found {} !", path);

    std::string line;
    int i = 0;
    while (i++,std::getline(*file, line)) {
        if (line.empty())continue;
        std::string boneName = getBoneName(line);

        info("ReadingLine:{},BoneName:{}", i, boneName);
        // info("BoneName:{}", boneName);
    };

    file->close();
    return;
}
std::list<std::string>* BoneInfo::getBoneList(){
    std::list<std::string> *list = nullptr;
    return list;
}

std::string BoneInfo::getBoneName(std::string line){
    using std::regex;
    // std::regex pattern("\\$ definebone[\\ ]+\"([^\"]*)\"");
    std::regex pattern("\\$definebone +\"([^\"]*)\"");

    std::smatch result;
    if(std::regex_search(line,result,pattern)){
        // for(auto value :result){
        //     info("Got {}",(std::string)value);
        // }
        return result[1];
    }
    warn("BoneName is empty");
    return NULL;
}