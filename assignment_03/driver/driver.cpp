#include "driver.h"

void driverAssignment03(){

    while(true){
        int choice = Menu::showAlgorithm3Menu();
        switch(choice){
            case 1:
                driverMST();
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return;
}