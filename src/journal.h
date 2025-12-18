#pragma once 
#include <string>
namespace journal{
    void entry();
    void saveEntry(const std::string&text);
    std::string getDate();
};
