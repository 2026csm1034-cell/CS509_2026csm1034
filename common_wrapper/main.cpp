#include<iostream>
#include "../assignment_01/driver/driver.h"
#include "menu.h"

using namespace std;
int main(){
    
    while(true){
        int assignChoice = Menu::showAssignmentMenu();

        switch(assignChoice){
            case 0:
                cout<<"\n Exiting..."<<endl;
                return 0;
            case 1:
                //call assignment01Driver
                assignment01Driver();
                break;
            default:
                cout<<"\nInvalid choice.\n";
        }  
    }

    return 0;
}