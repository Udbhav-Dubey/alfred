#include "habits.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <map>
#include <limits>
#include <algorithm>
#include <cctype>
#include <optional>

std::string habits::getCurrentDate(){
    auto now=std::chrono::system_clock::now();
    auto today=std::chrono::floor<std::chrono::days>(now);
    std::chrono::year_month_day ymd{today};
    std::stringstream ss;
    ss<<int(ymd.year())<<"-" << std::setw(2) << std::setfill('0') << unsigned(ymd.month())<<"-" <<std::setw(2)<<std::setfill('0') <<unsigned(ymd.day());
    return ss.str();
}

void habitStore::ensureHabitFile(){
    std::ifstream in("data/habits.txt");
    if (!in){
        std::cout << "no habits file was found \n so i am creating one for you : named habits.txt \nhere you can store your habits : now to start the process enter atleast one habit write now so we can start and enter q to stop\n: ";
        std::ofstream out("data/habits.txt",std::ios::app);
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
std::string habitStore::computeHabitHash() const{
    std::vector<std::string> habitList=habitNames();
    std::vector<std::string> normalised;
    for (const auto &it : habitList){
        std::string s=trim(it);
        std::transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return std::tolower(c);});
        if (!s.empty()){
        normalised.push_back(s);
        }
    }
    std::sort(normalised.begin(),normalised.end());
    std::string x;
    for (const std::string &i:normalised){
        x+=i+"|";
    }
    std::hash<std::string>hasher;
    size_t h=hasher(x);
    return std::to_string(h);
}

std::vector<std::string> habitStore::habitNames() const {
    std::vector<std::string> result;
    std::ifstream in("data/habits.txt");
    std::string line;
    while(std::getline(in,line)){
        std::string cleaned=trim(line);
        if (!cleaned.empty()){
            result.push_back(cleaned);
        }
    }
    return result;
}
std::optional<std::string> habitStore::getLastSchemaHash() const {
    std::ifstream csv("data/habits_log.csv");
    if (!csv){
        return std::nullopt;
    }
    std::optional<std::string>lasthash;
    std::string line;
    const std::string prefix="# habits-hash:";
    while(std::getline(csv,line)){
        if (line.rfind(prefix,0)==0){
            std::string hash=line.substr(prefix.size());
            lasthash=trim(hash);
        }
    }
    return lasthash;
}

std::map<std::string,int> habits::date_to_habits(
    const std::string&date,
    const std::vector<std::string>&habit_names){
    std::map<std::string,int>result;
 //   const std::vector<std::string> &habitList=habit_names;
    for (auto i:habit_names){
        result[i]=0;
    }
    std::ifstream in("data/habits_log.csv");
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
    while(std::getline(in,line)){

    std::string cell;
    std::vector<std::string>cells;
    std::stringstream rowStream(line);
    while(std::getline(rowStream,cell,',')){
        cells.push_back(cell);
    }
    if (cell.empty()||cells[0].empty()){
        continue;
    }
    if (cells[0]==tday){
        for (const auto&habit:habit_names){
            auto it=columnIndex.find(habit);
            if (it!=columnIndex.end()){
                size_t col=it->second;
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
    system("clear");
    habitStore store1;
    store1.ensureHabitFile();
    std::cout << "OKAY now we will track your habits\nso for following habits just answer in 1 and 0 only please\n1 = yes\n0 = no\n";
    std::string date=getCurrentDate();
    habitStore store; // need to update this , is it relative cmake or where code is stored?
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
    store.saveData(date,mp,habitList);
    std::cout << "\nLogged.\n";
    std::cout << "Type :next to continue...\n";
    std::cin.ignore();
    std::string line;
    while(std::getline(std::cin,line)){
        if (line==":next"){
            break;
        }
    }
}    

void habitStore::saveData(
    const std::string&date,
    const std::map<std::string,int>&data,
    const std::vector<std::string>&habit_names ){
    std::string currentHash=computeHabitHash();
    auto last_hash=getLastSchemaHash();
    std::ofstream csv("data/habits_log.csv",std::ios::app);
    if (!csv){
        std::cerr<<"Failed to open habit log csv\n";
        return ;
    }
    if (!last_hash||*last_hash!=currentHash){
        csv<<"# habits-hash: " << currentHash << "\n";
        csv<<"date";
        for (const auto&h:habit_names){
            csv<<",\""<<h<<"\"";
        }
    csv<<"\n";
    }
    csv<<date;
    for (const auto&h:habit_names){
        auto it=data.find(h);
        int value=(it!=data.end())?it->second:0;
        csv<<","<<value;
    }
    csv<<"\n";
}
