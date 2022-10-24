#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include<string>
class BoneInfo
{
	std::ifstream *file;
	std::string path;
	std::list<std::string> *boneList;

public:
	BoneInfo();
	bool setFile(std::string);
	bool setBoneList();
	std::list<std::string>* getBoneList();
	~BoneInfo();
private:
	std::string getBoneName(std::string line);
};

