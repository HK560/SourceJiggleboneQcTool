#include "BoneInfo.h"

#include <regex>

#include "LogInit.h"

BoneInfo::BoneInfo() {
    file = nullptr;
    path = "";
    boneList = nullptr;
    info("BoneInfo Init finished");
};
bool BoneInfo::setFile(std::string path) {
    this->file = new std::ifstream();
    if (file == nullptr) {
        error("ifsteam error");
        return false;
    };
    this->path = path;
    info("Set DefineBone file path:{}", path);
    return true;
}
bool BoneInfo::setBoneList() {
    file->open(path, std::ios::in);
    boneList = new std::list<std::string>();

    if (!file->is_open()) {
        // std::cout << "Error: Could not open " << path << std::endl;
        error("Error: Could not find {}", path);
        return false;
    }
    info("Found {} !", path);

    std::string line;
    int i = 0;
    while (i++, std::getline(*file, line)) {
        if (line.empty()) {
            info("Reading Line {}, Empty line skipped", i);
            continue;
        };

        std::string boneName = getBoneName(line);

        if (boneName.empty()) {
            warn("BoneName wrong! Skipped!");
            continue;
        };

        boneList->push_back(boneName);

        info("Reading Line {},BoneName:{}", i, boneName);
        // info("BoneName:{}", boneName);
    };

    info("Number of bones:{}", boneList->size());
    if(boneList->size()==0){
        warn("Found 0 bones! Please check the definebone.qci file!");
    }
    file->close();
    return true;
}
std::list<std::string>* BoneInfo::getBoneList() {
    std::list<std::string>* list = this->boneList;
    return list;
}

std::string BoneInfo::getBoneName(std::string line) {
    using std::regex;
    // std::regex pattern("\\$ definebone[\\ ]+\"([^\"]*)\"");
    std::regex pattern("\\$definebone +\"([^\"]*)\"");

    std::smatch result;
    if (std::regex_search(line, result, pattern)) {
        // for(auto value :result){
        //     info("Got {}",(std::string)value);
        // }
        return result[1];
    }
    warn("BoneName is empty");
    return NULL;
}

BoneInfo::~BoneInfo() {
    if (this->file != NULL && this->file != nullptr) {
        delete this->file;
    }
    if (this->boneList != NULL && this->boneList != nullptr) {
        delete this->boneList;
    }
}