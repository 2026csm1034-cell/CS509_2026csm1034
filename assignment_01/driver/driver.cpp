#include<iostream>
#include "driver.h"
#include "../../common_wrapper/menu.h"
#include "../src/gemm/gemm.h"

using namespace std;
void assignment01Driver(){

    while(true){
        int choice = Menu::showAlgorithmMenu();
        switch(choice){
            case 0:
                return;
            case 1:
                //call simple_gemm

                cout<<"Simple GEMM selected"<<endl;
                
                simple_gemm("assignment_01/tests/gemm_test_01.txt");
                break;
            case 2:
                //call blocking_gemm
                cout<<"Blocking GEMM selected"<<endl;
                int block_size;
                cout<<"Enter block size: ";
                cin>>block_size;
                blocking_gemm("assignment_01/tests/gemm_test_01.txt", block_size);
                break;
            case 3:
                //call generate_CSR
                cout<<"CSR representation selected"<<endl;
                // generate_CSR("assignment_01/tests/csr_test_01.txt");
                break;
            default:
                std::cout<<"\nInvalid choice.\n";
        }
    }
    return;
}