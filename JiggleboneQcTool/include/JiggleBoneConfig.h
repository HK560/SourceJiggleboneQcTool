#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "LogInit.h"
using std::string;

class JiggleBoneConfig {
    string templateName;
    string configStr;

   public:
    JiggleBoneConfig(){};
    JiggleBoneConfig(string tpName) : templateName(tpName), configStr("") {}

    bool setConfig();
    string getConfig();
};