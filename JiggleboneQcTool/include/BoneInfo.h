#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include<string>
class BoneInfo
{
	std::ifstream *file;
	std::list<std::string> *boneList;

public:
	bool init();
	bool setFile(std::string);
	void setBoneList();
	std::list<std::string>* getBoneList();
	

};

