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
                "Could not find template_{}.txt. Created it, please edit this "
                "file to add JiggleboneConfig and run this program again. ",
                i);
            file.open(templateNamePath, std::ios::in);
            if (!file.is_open()) {
                error("Could not create template_{}.txt", i);
                return false;
            }
            file.close();
        }

        templateslist->push_back(templateNamePath);  // add filepath to list

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

    // this is for custom func
    // if (writeBoneFunc->size() <= 0) {
    //     warn("writeBoneFunc.size() must be >0");
    //     return false;
    // }
    list<string> *bonelist = this->boneInfo->getBoneList();

    list<string> *templatePathList = this->templatesPath;
    // if(templatePathList->size()<=0)
    info("bonelistSize: {}", bonelist->size());
    info("templatesPathListSize: {}", templatePathList->size());

    for (auto i = templatePathList->begin(); i != templatePathList->end();
         ++i) {
        string orgConfigStr = getJiggleboneConfig(*i);
        if (!orgConfigStr.empty()) {
                // write
                string filename = "DefineJiggleBone_"+*i;
                subreplace(filename,string(".txt"),string(".qci"));
                if(!writeConfigToFile(orgConfigStr,bonelist,filename)){
                    warn("Func: writeConfigToFile failed with {}, skipped this file.",filename);
                };
        } else
            warn("Func: getJiggleboneConfig failed with {}, skipped this file.", *i);
        // need to check
    }
    // ! these code is for custom func !
    // for (auto i = this->writeBoneFunc->begin(); i !=
    // this->writeBoneFunc->end();
    //      ++i) {
    //     if (!(*i)(bonelist)) {
    //         error("try to write bone failed");
    //         return false;
    //     };  // write
    // }
    info("DefineJiggleBone file built!");
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

string BoneConfig::getJiggleboneConfig(const string &filepath) {
    if (filepath.empty()) return string("");  // need to check whether it work
    std::ifstream file;
    file.open(filepath, std::ios::in);
    if (!file.is_open()) {
        // std::cout << "Error: Could not open " << path << std::endl;
        error("Cant open {}", filepath);
        return string("");
    }
    std::ostringstream tmp;
    tmp << file.rdbuf();
    string configStr = tmp.str();

    // std::cout << configStr << std::endl;
    info("Reading template: {}", filepath);
    try{
        std::regex pattern1("(\\$jigglebone[\\s]*\"T_BONENAME\"[\\s]*\\{[\\s\\S]*\\})");
         std::smatch result1;
    if (std::regex_search(configStr,result1, pattern1)) {
        // std::cout << result1[1] << std::endl;

        // std::regex pattern2()

        string orgConfigStr = (string)result1[1];
        info("Get $Jigglebone Config:\n{}\n", orgConfigStr);

        // string nowbonename;
        // list<std::string> *boneList = this->boneInfo->getBoneList();

        // for (auto i = boneList->begin(); i != boneList->end(); i++) {
        //     nowbonename = *i;
        //     subreplace(orgConfigStr, BONENAME_TEMPLATE, nowbonename);
        //     info("Going to write:{}", orgConfigStr);
        // }
        // info("Write {} finished",filepath);

        return orgConfigStr;
        // string(result1[1]).copy(orgConfigStr,sizeof(result1[1]));
        // return result[1];
    }
    }
    catch(std::regex_error e){
        error("{},{}",e.code(),e.what());
        return string("");
    }

    
    warn("Jigglebone template is empty");
    return string("");
    //  \$jigglebone\s*?"T_BONENAME"\s*?{[\s\S]*}
}

std::string subreplace(std::string &dst_str, std::string sub_str,
                       std::string new_str) {
    // std::string dst_str = resource_str;
    std::string::size_type pos = 0;
    while ((pos = dst_str.find(sub_str)) !=
           std::string::npos)  // 替换所有指定子串
    {
        dst_str.replace(pos, sub_str.length(), new_str);
    }
    return dst_str;
}

bool BoneConfig::writeConfigToFile(const string config,
                                   const list<string> *bonelist,
                                   const string &filename) {
    string orgConfigStr;
    string writeStream = "";
    string nowbonename;
    std::ofstream file;
    file.open(filename, std::ios::out);
    if (!file.is_open()) {
        error("{} open failed", filename);
        return false;
    }
    for (auto i = bonelist->begin(); i != bonelist->end(); ++i) {
        nowbonename = *i;
        orgConfigStr = config;

        subreplace(orgConfigStr, BONENAME_TEMPLATE, nowbonename);
        // info("Going to add to writeStream: {}", orgConfigStr);
        writeStream.append(orgConfigStr).append("\n");
        info("Defined {} using template: {}.",*i,filename);
    }

    // info("writeStream ALL : {}", writeStream);
    // file.write(writeStream.c_str(),writeStream.size())
    file << writeStream;
    file.close();
    info("Written to {}.",filename);
    return true;
    // write
}