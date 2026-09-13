#include "intro.h"
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
const char* batman_ascii=R"(                                                                                                   
                                                                      
                                                                      
                          oaaaaaaaaaaaaaaaa                           
                   #aaaaaaaaaaaaaaaaaaaaaaaaaaaa                      
                aaaaaaaaaa                 aaaaaaao                   
             aaaaaaa                           aaaaaa                 
           *aaaaa                                 aaaaa               
          aaaa#                                     aaaaa             
        Xaaaa                          #    ao        aaaaa           
        aaaa                          aaa# aaa          aaaa          
       aaaa      a#   aaa               aaaaa            oaaah        
       aaa       aa baao                 aaaa#             aaaa       
      aaaa        aaaa                  aaa aaaa            aaaa      
      aaaa        aaaa                  aa                   aaa      
      aaam       aaa aaa                a                    oaaa     
     oaaa        aa   aa                                      aaaa    
     aaak                                           aaaaao    #aaa    
    #aaa                                              aaaaa    aaa    
    aaao                                              aa       aaaa   
    aaa                                              aaa       aaaa   
   #aaa    aaaaa                                     aa#       aaaa   
   aaaa  aaaaa                                       aa        aaaa   
   aaaa #a  aao                                     aao        aaa    
   aaaa      aa                                    aaa#        aaa    
   oaaa      aaa                                  #aaaaaa     aaaa    
    aaa       aaaa#                              #aaaa paao   aaa     
    aaao        aaaaaaaaa                       oaaoaaaa aa  aaaa     
    aaaa               aaaa                    aaaaaaao  aa aaaa      
     aaaa                aaa                 aaa#   aaaaaaaaaaa       
     #aaao                haaa#       oaaaaaaaa       aaa aaaa        
      aaaaa                 #aaaaaaaaaaak                aaaa         
        aaaa#                    #b##                  aaaaa          
         *aaaaa                                     oaaaaa            
           ]aaaaaao                              aaaaaaa              
               aaaaaaaaah                   oaaaaaaaa                 
                   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa                    
                        #aaaaaaaaaaaaaaaaaaa#                         
                                                                      
                                                                      
                                                                                           
)";
void intro::clearscreen(){
    system("clear");
}
void intro::writingStyle(const std::string &text){
    for (char c : text){
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(70));
    }
    std::cout << "\n";
}
void intro::show(){
    clearscreen();
    std::cout << batman_ascii<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    writingStyle("better to burn out than fade away \n");
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::cout << "\npress enter to continue ";
    std::cin.ignore();
    clearscreen();
}
