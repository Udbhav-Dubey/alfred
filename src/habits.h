#pragma once 
#include <string>
#include <map>
#include <vector>
#include <optional>
class habitStore{
    public:
    habitStore()=default;
    void ensureHabitFile();
    std::vector<std::string> habitNames() const;
    void saveData(
    const std::string&date,
    const std::map<std::string,int>&data,
    const std::vector<std::string>&habit_names
    );
    std::string computeHabitHash() const;
    std::optional <std::string>getLastSchemaHash() const;
};
namespace habits {
    void getEntries();
    std::string getCurrentDate();
    std::map<std::string,int> date_to_habits(
    const std::string&date,
    const std::vector<std::string>&habit_names
    );
}
