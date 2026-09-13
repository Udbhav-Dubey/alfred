#include "intro.h"
#include "journal.h"
#include "habits.h"
#include <iostream>
#include "menu.h"
#include <ctime>
#include <cstdlib>
int main (){
    std::srand(std::time(nullptr));
    intro::show();
    menu::run();
 //   system("xdg-open ~/dev/alfred/data/images.jpg");
    //journal::entry();
    //habits::getEntries();
    //std::cout << "lets check intro \n";
    return 0;
}
