#include "intro.h"
#include "journal.h"
#include "habits.h"
#include <iostream>
int main (){
    intro::show();
    journal::entry();
    habits::getEntries();
    //std::cout << "lets check intro \n";
    return 0;
}
