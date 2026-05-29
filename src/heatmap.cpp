#include "heatmap.h"
#include "habits.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
struct habits_to_dates{
    std::vector<std::string>habits;
    std::map<std::string,std::map<std::string,int>>data;
};
habits_to_dates loadData(const std::string &target_hash){
    habits_to_dates result;
    std::ifstream in ("data/habits_log.csv");
    if (!in){
        std::cout << "habits file not found \n";
        return result;
    }
    bool last_hash=false;
    bool reading_block=false;
    std::string line;
    while(std::getline(in,line)){
        if (line.empty()){continue;}
        if (line[0]=='#'){
            std::string prefix="# habits-hash:";
            if (line.rfind(prefix,0)==0){
                std::string hash=line.substr(prefix.size());
                std::string trimmed_hash=habits::trim(hash);
                if (trimmed_hash==target_hash){
                    last_hash=true;
                    reading_block=true;
                    continue;
                }
                else if (reading_block){
                    break;
                }
            }
        }
        if (!reading_block){continue;}
        if (line.rfind("date",0)==0){
            std::stringstream ss(line);
            std::string col;
            std::getline(ss,col,',');
            while(std::getline(ss,col,',')){
                if (!col.empty()&&col.front()=='"'){
                    col=col.substr(1,col.size()-2);
                }
                result.habits.push_back(col);
            }
            continue;
        }
        std::stringstream ss(line);
        std::string date;
        std::getline(ss,date,',');
        for(size_t i=0;i<result.habits.size();i++){
            std::string val_str;
            if (std::getline(ss,val_str,',')){
                int val=std::stoi(val_str);
                result.data[date][result.habits[i]]=val;
            }
        }
    }
    in.close();
    return result;
}
void heatmap::display(){
    system("clear");
    std::cout << "HEATMAPS::";
    habitStore store;
    auto last_hash=store.getLastSchemaHash();
    if (!last_hash){
        std::cout << "log data to get heatmap , now not available as not last_hashing value\n";
        std::cout << "press key to return \n";
        std::cin.ignore();
        std::cin.get();
        return ;
    }
    habits_to_dates block=loadData(*last_hash);
    if (block.habits.empty()||block.data.empty()){
        std::cout <<"Could not load up data from current block\n";
        std::cout << "press key to return\n";
        std::cin.ignore();
        std::cin.get();
        return ;
    }
    for (const std::string&habit:block.habits){
        std::cout << "\n\n"<< habit << ":\n ";
        int count=0;
        for (const auto&[data,habits]:block.data){
            auto it =habits.find(habit);
            if (it!=habits.end()){
                std::cout << (it->second==1?"■" : "□");
                count++;
               /* if (count%7==0){
                    std::cout << "\n";
                }*/
            }
        }
        std::cout << "\n";
    }
    std::cout << " ■ = 1  □ = 0 \n";
    std::cout << "Days logged : " << block.data.size() << "\n\n";
    std::cout << "type :menu to go back \n";
    std::string men;
    std::cin>>men;
    if (men==":menu"){return ;}
    else {std::cout << "people like you uhhh \n";}
}
