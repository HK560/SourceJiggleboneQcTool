#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <list>
#include <regex>
#include <string>

#include "BoneInfo.h"
#include "JiggleBoneConfig.h"
#include "LogInit.h"

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
    BoneConfig(BoneInfo *BoneInfo) : boneInfo(BoneInfo){};
    bool initTemplatePath();
    bool writeJigglebone();
    bool addFunc(Func &f);
    string getJiggleboneConfig(const string &filepath);
    bool writeConfigToFile(const string config,
                                       const list<string> *bonelist,
                                       const string &filename);
};

std::string subreplace(std::string &dst_str, std::string sub_str,
                       std::string new_str);