
#include <iostream>
#include <fstream>
#include "LogInit.h"
#include "BoneInfo.h"
#include "BoneConfig.h"
#include <string>

using std::string;

bool runTool(){
    BoneInfo* boneInfo = new BoneInfo();

    if(!boneInfo->setFile(string("DefineBones.qci")))return false;
    if(!boneInfo->setBoneList())return false;

    BoneConfig* boneConfig = new BoneConfig(boneInfo);
    if(!boneConfig->initTemplatePath())return false;

    if(!boneConfig->writeJigglebone())return false;else info("ALL DONE!");


    // JiggleBoneConfig* jiggleConfig = new JiggleBoneConfig();

    // boneConfig->writeJigglebone();
    delete boneConfig;
    delete boneInfo;
    return true;
}

int main()
{
    // std::cout << "JiggleboneQcTool\nByHK560\n";
    std::cout << "    /$$$$$ /$$                     /$$           /$$$$$$$                             /$$$$$$$$                  /$$\n";
    std::cout << "   |__  $$|__/                    | $$          | $$__  $$                           |__  $$__/                 | $$\n";
    std::cout << "      | $$ /$$  /$$$$$$   /$$$$$$ | $$  /$$$$$$ | $$  \\ $$  /$$$$$$  /$$$$$$$   /$$$$$$ | $$  /$$$$$$   /$$$$$$ | $$\n";
    std::cout << "      | $$| $$ /$$__  $$ /$$__  $$| $$ /$$__  $$| $$$$$$$  /$$__  $$| $$__  $$ /$$__  $$| $$ /$$__  $$ /$$__  $$| $$\n";
    std::cout << " /$$  | $$| $$| $$  \\ $$| $$  \\ $$| $$| $$$$$$$$| $$__  $$| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$| $$  \\ $$| $$  \\ $$| $$\n";
    std::cout << "| $$  | $$| $$| $$  | $$| $$  | $$| $$| $$_____/| $$  \\ $$| $$  | $$| $$  | $$| $$_____/| $$| $$  | $$| $$  | $$| $$\n";
    std::cout << "|  $$$$$$/| $$|  $$$$$$$|  $$$$$$$| $$|  $$$$$$$| $$$$$$$/|  $$$$$$/| $$  | $$|  $$$$$$$| $$|  $$$$$$/|  $$$$$$/| $$\n";
    std::cout << " \\______/ |__/ \\____  $$ \\____  $$|__/ \\_______/|_______/  \\______/ |__/  |__/ \\_______/|__/ \\______/  \\______/ |__/\n";
    std::cout << "               /$$  \\ $$ /$$  \\ $$                                                                                  \n";
    std::cout << "              |  $$$$$$/|  $$$$$$/                                                                                  \n";
    std::cout << "               \\______/  \\______/                                                                   By HK560        \n";
    // info("\nJiggleboneQcTool\nByHk560");
    info("version: v0.0.1");
    info("PLEASE READ THE DOCUMENTATION FIRST");
    system ("PAUSE");

    if(!runTool()){
        error("BAD RESULT");
    };

    system ("PAUSE ");
    return 0;
}


