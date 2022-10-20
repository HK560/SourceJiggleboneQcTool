
#include <iostream>
#include <fstream>
#include "LogInit.h"
#include "BoneInfo.h"
#include <string>

using std::string;

int main()
{
    std::cout << "JiggleboneQcTool\nByHK560\n";
    info("\nJiggleboneQcTool\nByHk560");

    BoneInfo* boneInfo = new BoneInfo();
    boneInfo->setFile(string("definebone.txt"));
    boneInfo->setBoneList();
    return 0;
}

