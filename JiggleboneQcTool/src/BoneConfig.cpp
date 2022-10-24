#include "BoneConfig.h"

bool BoneConfig::initTemplatePath() {


    this->templatesPath = new list<string>();
    this->writeBoneFunc = new list<Func>();

    if (this->templatesPath == nullptr) {
        error("templatePath == nullptr");
        return false;
    }

    list<string> *templateslist = this->templatesPath;
    // static_assert(templateslist,"templatesPathisnullptr");

    info("set the maximum number of templates to 5");
    string path = this->defaultPath;
    string templateNameF = "template_";
    for (int i = 0; i < TEMPLATES_MAX; ++i) {
        string templateNamePath =
            path + templateNameF + std::to_string(i) + ".txt";

        std::ifstream file;
        file.open(templateNamePath, std::ios::in);
        if (!file.is_open()) {
            std::ofstream err;
            err.open(templateNamePath, std::ios::out);
            warn(
                "Could not find template_{}.txt. Created it, please run "
                "again. ",
                i);
            file.open(templateNamePath, std::ios::in);
            if (!file.is_open()) {
                error("Could not create template_{}.txt", i);
                return false;
            }
            file.close();
        }
        info("Found template_{}.txt", i);
        file.close();
    }
    return true;
}

// unfinish
bool BoneConfig::writeJigglebone() {
    if (this->templatesPath == nullptr || this->writeBoneFunc == nullptr ||
        this->boneInfo == nullptr) {
        error("templatesPath/writeBoneFunc/boneInfo cannot be null");
        return false;
    }

    list<string> *bonelist = this->boneInfo->getBoneList();
    if(writeBoneFunc->size()<=0){
        warn("writeBoneFunc.size() must be >0");
        return false;
    }
    for(auto i =this->writeBoneFunc->begin(); i != this->writeBoneFunc->end();++i){
        if(!(*i)(bonelist)){
            error("try to write bone failed");
            return false; 
        };//write
    }
    return true;
}

bool BoneConfig::addFunc(Func &f) {
    if (this->writeBoneFunc == nullptr) {
        error("writeBoneFunc cannot be null");
        return false;
    }
    this->writeBoneFunc->push_back(f);
    return true;
}
