
#include <iostream>
#include <fstream>
#include "LogInit.h"
#include "BoneInfo.h"
#include "BoneConfig.h"
#include <string>

using std::string;

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

    BoneInfo* boneInfo = new BoneInfo();

    if(!boneInfo->setFile(string("definebone.qci")))return false;
    if(!boneInfo->setBoneList())return false;

    BoneConfig* boneConfig = new BoneConfig(boneInfo);
    if(!boneConfig->initTemplatePath())return false;

    if(!boneConfig->writeJigglebone())return false;


    JiggleBoneConfig* jiggleConfig = new JiggleBoneConfig();

    // boneConfig->writeJigglebone();
    delete boneInfo;
    system ("PAUSE ");
    return 0;
}


