#include "quotes.h"
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
size_t len{};
void quotes::showall(){
    while(true){
    showRandom();  
    std::this_thread::sleep_for(std::chrono::milliseconds(len*82));
    }
}
void quotes::showRandom(){
    std::ifstream in("data/quotes.txt");
    if (!in){
        std::cout << "GoodBye Sir!"; // instead of just failing just say this
        return ;
    }
    std::vector<std::string>quotes;
    std::string line;
    while(std::getline(in,line)){
        quotes.push_back(line);
    }
std::string text = R"(Preparing to do the thing isn’t doing the thing.

Scheduling time to do the thing isn’t doing the thing.

Making a to-do list for the thing isn’t doing the thing.

Telling people you’re going to do the thing isn’t doing the thing.

Messaging friends who may or may not be doing the thing isn’t doing the thing.

Writing a banger tweet about how you’re going to do the thing isn’t doing the thing.

Hating on yourself for not doing the thing isn’t doing the thing.

Hating on other people who have done the thing isn’t doing the thing.

Hating on the obstacles in the way of doing the thing isn’t doing the thing.

Fantasising about all of the adoration you’ll receive once you do the thing isn’t doing the thing.

Reading about how to do the thing isn’t doing the thing.

Reading about how other people did the thing isn’t doing the thing. Reading this essay isn’t doing the thing.

The only thing that is doing the thing is doing the thing.)";

if (quotes.empty()){
    std::cout << text << "\n";
}
system("clear");
int idx=std::rand()%quotes.size();
len=quotes[idx].size();
std::cout << "\n\n" << quotes[idx]<<"\n\n";
}
