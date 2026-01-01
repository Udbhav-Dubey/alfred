#include "journal.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>
namespace journal {
    bool flag = true;
}
std::string journal::getDate(){
    using namespace std::chrono;
    auto now =system_clock::now();
    auto today=floor<days>(now);
    year_month_day ymd{today};
    static const char * month[]={
        "January","February","March","April","May","June","July","August","September","October","November","December"};
    std::stringstream ss;
    ss<<month[unsigned(ymd.month())-1]<<" " << unsigned(ymd.day()) <<", "<<int(ymd.year());
    return ss.str();
}
void journal::entry(){
    system("clear");
    std::string date=getDate();
    std::cout<<"═══════════════════════════════════\n";
    std::cout<<"\033[1m"<<date<<"\033[0m\n";
    std::cout<<"═══════════════════════════════════\n\n";
    std::string journal_text;
    std::string line;
    std::cout << "type :next to go to next section please \n";
    std::cout << "type :back to go back to menu\n";
    while(getline(std::cin,line)){
        if (line==":next"){
            break;
        }
        if (line==":back"){
            flag=0; 
            break;
        }
        journal_text+=line+"\n";
    }
    saveEntry(journal_text);
    std::cout << "\nEntry saved.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}
void journal::saveEntry(const std::string&text){
    std::ofstream file("data/journal.txt",std::ios::app);
    if (!file){
        std::cerr<<"Error : could not open journal file\n";
        return ;
    }
    std::string date=getDate();
    file<<"═══════════════════════════════════\n";
    file<<date<<"\n";
    file<<"═══════════════════════════════════\n\n";
    file<<text;
    file<<"\n\n";
    file.close();
}

