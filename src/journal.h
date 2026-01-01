#pragma once 
#include <string>
namespace journal{
    extern bool flag;
    void entry();
    void saveEntry(const std::string&text);
    std::string getDate();
};
