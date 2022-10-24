#include "JiggleBoneConfig.h"

bool JiggleBoneConfig::setConfig(){
    if(templateName.empty()){
        error("templateName is required!");
        return false;
    }
    info("TemplateName is {}",templateName);

    std::ifstream file;
    file.open(templateName,std::ios::in);
    if(file.is_open()){

        std::ostringstream tmp;
        tmp << file.rdbuf();
        configStr = tmp.str();

        std::cout<<configStr<<std::endl;


        return true;
    }else{
        error("Couldn't open {}",templateName);
        return false;
    }

}