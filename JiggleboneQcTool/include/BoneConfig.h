#pragma once
#include <string>
#include "LogInit.h"
#include <iostream>
#include <list>
#include <fstream>
#include <istream>
#include "BoneInfo.h"
#include "JiggleBoneConfig.h"

#define TEMPLATES_MAX 5

using std::list;
using std::string;

typedef bool (*Func)(list<string> *bonelist);



class BoneConfig {

    string defaultPath;
    list<string> *templatesPath = nullptr; 

    BoneInfo *boneInfo = nullptr;
    // JiggleBoneConfig *jiggleBoneCfg = nullptr;

    list<Func> *writeBoneFunc = nullptr;


public:
    
    BoneConfig(BoneInfo *BoneInfo):boneInfo(BoneInfo){};
    bool initTemplatePath();
    bool writeJigglebone();
    bool addFunc(Func&f);

};
