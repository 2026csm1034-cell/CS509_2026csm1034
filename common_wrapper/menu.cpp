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
    cout<<"0. Go Back"<<endl;

    int choice;
    cin>>choice;

    return choice;
}

int Menu::chooseInputMenu(){
    cout<<"\n======================================="<<endl;
    cout<<"             Input Options             "<<endl;
    cout<<"======================================="<<endl;

    cout<<"1. Run Selected Test"<<endl;
    cout<<"2. Run All Tests"<<endl;
    cout<<"3. Enter Custom Input File"<<endl;
    cout<<"0. Go Back"<<endl;

    int choice;
    cin>>choice;

    return choice;
}
