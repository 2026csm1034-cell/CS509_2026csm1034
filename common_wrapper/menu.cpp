#include<iostream>
#include "menu.h"

using namespace std;

int Menu::showAssignmentMenu(){
    cout<<"\n======================================="<<endl;
    cout<< "        CS509 Lab Assignments            "<<endl;
    cout<< "======================================="<<endl;

    cout<<"1. Assignment_01"<<endl;
    cout<<"0. Exit"<<endl;

    cout<<"\n Choice: ";

    int choice;

    cin>>choice;
    return choice;
}

int Menu::showAlgorithmMenu(){
    cout<<"\n======================================="<<endl;
    cout<<"             Algorithms                "<<endl;
    cout<<"======================================="<<endl;


    cout<<"1. simple GEMM"<<endl;
    cout<<"2. blocking GEMM"<<endl;
    cout<<"3. CSR Representation"<<endl;
    cout<<"0. Exit"<<endl;

    int choice;
    cin>>choice;

    return choice;
}

