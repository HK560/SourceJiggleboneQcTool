#include "BoneInfo.h"
#include "LogInit.h"

bool BoneInfo::init() {
    file = nullptr;
    boneList = nullptr;
    return true;
}
bool BoneInfo::setFile(std::string path){

    file = new std::ifstream();
    file->open(path,std::ios::in);
    if(!file->is_open()){
        std::cout << "Error: Could not open " << path << std::endl;
        return false;
    }
    std::string line;
    while(std::getline(*file,line)){
        
    }


    return true;
}
void BoneInfo::setBoneList(){
    return;
}
std::list<std::string>* BoneInfo::getBoneList(){
    std::list<std::string> *list = nullptr;
    return list;
}