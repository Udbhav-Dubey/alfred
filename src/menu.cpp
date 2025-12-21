#include "journal.h"
#include "habits.h"
#include "intro.h"
#include "menu.h"
#include "quotes.h"
#include <iostream>
// for now let editHabits stay here in future we will make it better currently just opens my editor;
// might make funcion to let people open theirs or make it nano 
// or open best case open default
void editHabits(){
    system("nvim data/habits.txt");
}
void menu::ui(){
    system("clear");
    std::cout << "What would you like to do today : \n";
    std::cout << 
        "1: Journal->habit Logging\n"
        "2: Edit Habits\n"
        "3: Exit \n";
}
void menu::run(){
    while(true){
        int flag=1;
        ui();
        int x;
        std::cin >>x;
        switch(x){
            case 1 : journal::entry();
                     habits::getEntries();
                     break;
            case 2 : editHabits();
                     break;
            case 3 : flag=0;
                     quotes::showRandom();
                     break;
            default: std::cout << "invalid , are you dumb or something\n";
        }
        if (flag==0){break;}
    }
}
