#include<iostream>
#include "driver.h"
#include "../../common_wrapper/menu.h"

void assignment01Driver(){

    while(true){
        int choice = Menu::showAssignmentMenu();
        switch(choice){
            case 0:
                return;
            case 1:
                //call simple_gemm

                cout<<"Simple GEMM selected"<<endl;
                break;
            case 2:
                //call blocking_gemm
                cout<<"Blocking GEMM selected"<<endl;
                break;
            case 3:
                //call generate_CSR
                cout<<"CSR representation selected"<<endl;
                break;
            default:
                std::cout<<"\nInvalid choice.\n";
        }
    }