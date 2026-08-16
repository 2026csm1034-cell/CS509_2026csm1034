#include<iostream>
#include "../assignment_01/driver/driver.h"
#include "../assignment_02/driver/driver.h"
#include "../assignment_03/driver/driver.h"
#include "menu.h"

using namespace std;
int main(){
    
    while(true){
        int assignChoice = Menu::showAssignmentMenu();

        switch(assignChoice){
            case 1:
                //call assignment01Driver
                assignment01Driver();
                break;
            case 2:
                driverAssignment02();
                break;
            case 3:
                driverAssignment03();
                break;
            case 0:
                cout<<"\n Exiting..."<<endl;
                return 0;
            default:
                cout<<"\nInvalid choice.\n";
        }  
    }

    return 0;
}