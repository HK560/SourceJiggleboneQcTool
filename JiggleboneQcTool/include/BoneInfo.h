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
	void setBoneList();
	std::list<std::string>* getBoneList();
	
private:
	std::string getBoneName(std::string line);
};

