#pragma once 
#include <string>
#include <map>
#include <vector>
class habitStore{
    private:
        std::string path;
    public:
    explicit habitStore(const std::string& filePath);
    void ensureHabitFile();
    std::vector<std::string> habitNames() const;
    void saveData(
    const std::string&date,
    const std::map<std::string,int>&data
    );
};
namespace habits {
    void getEntries();
    std::string getCurrentDate();
    std::map<std::string,int> date_to_habits(
    const std::string&date,
    const std::vector<std::string>&habit_names
    );
}
