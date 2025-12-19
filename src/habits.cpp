#include "habits.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <map>
#include <limits>

std::string habits::getCurrentDate(){
    auto now=std::chrono::system_clock::now();
    auto today=std::chrono::floor<std::chrono::days>(now);
    std::chrono::year_month_day ymd{today};
    std::stringstream ss;
    ss<<unsigned(ymd.year())<<"-" << std::setw(2) << std::setfill('0') << unsigned(ymd.month())<<"-" <<std::setw(2)<<std::setfill('0') <<unsigned(ymd.day());
    return ss.str();
}

void habitStore::ensureHabitFile(){
    std::ifstream in("habits.txt");
    if (!in){
        std::cout << "no habits file was found \n so i am creating one for you : named habits.txt \nhere you can store your habits : now to start the process enter atleast one habit write now so we can start and enter q to stop\n: ";
        std::ofstream out("habits.txt",std::ios::app);
        std::string habit;
        while(true){
            std::getline(std::cin,habit);
            if (habit=="q"){
                break;
            }
            out << habit <<"\n";
        }
    }
}
static std::string trim(const std::string&s){
    const std::string whitespace =" \t\r\n";
    size_t start=s.find_first_not_of(whitespace);
    if (start==std::string::npos){
        return "";
    }
    size_t end=s.find_last_not_of(whitespace);
    return s.substr(start,end-start+1);
}   
std::vector<std::string> habitStore::habitNames() const {
    std::vector<std::string> result;
    std::ifstream in("habits.txt");
    std::string line;
    while(std::getline(in,line)){
        std::string cleaned=trim(line);
        if (!cleaned.empty()){
            result.push_back(cleaned);
        }
    }
    return result;
}
std::map<std::string,int> habits::date_to_habits(
    const std::string&date,
    const std::vector<std::string>&habit_names){
    std::map<std::string,int>result;
 //   const std::vector<std::string> &habitList=habit_names;
    for (auto i:habit_names){
        result[i]=0;
    }
    std::ifstream in("habitslog.csv");
    if (!in){
        std::cerr<<"failed to open habitslog.csv";
        return result;
    }
    std::string headerLine;
    if (!std::getline(in,headerLine)){
        return result;
    }
    std::stringstream ss(headerLine);
    std::map<std::string,int>columnIndex;
    std::string column;
    int index=0;
    while(std::getline(ss,column,',')){
        if (index!=0){
            columnIndex[column]=index;
        }
        index++;
    }
    std::string line;
    std::string tday=getCurrentDate();
    while(std::getline(ss,line)){
    std::string cell;
    std::vector<std::string>cells;
    std::stringstream rowStream(line);
    while(std::getline(rowStream,cell,',')){
        cells.push_back(cell);
    }
    if (cell.empty()){
        continue;
    }
    if (cells[0]==tday){
        for (const auto&habit:habit_names){
            auto it=columnIndex.find(habit);
            if (it!=columnIndex.end()){
                int col=it->second;
                if (col<cells.size()){
                    result[habit]=std::stoi(cells[col]);
                }
            }
        }
        return result;
    }
    }
    return result;
}
void habits::getEntries(){
    std::cout << "OKAY now we will track your habits\nso for following habits just answer in 1 and 0 only please\n1 = yes\n2 = no\n";
    std::string date=getCurrentDate();
    habitStore store("../data/habits.txt");
    const std::vector<std::string> habitList=store.habitNames();
    std::map<std::string,int> mp=date_to_habits(date,habitList);
    for (const auto&habit : habitList){
        int x;
        while(true){
        std::cout << habit << " : ";
            if (std::cin>>x&&(x==0||x==1)){
                break;
            }
            std::cout << "cmon pal only 1 or 0 how hard it is to understand it \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        mp[habit]=x;
    }
}    
//}
