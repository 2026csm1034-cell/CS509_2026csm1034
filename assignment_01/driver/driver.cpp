#include<iostream>
#include "driver.h"
#include "../../common_wrapper/menu.h"
#include "../src/gemm/gemm.h"
#include "../src/csr/csr.h"
#include "../../common_wrapper/utilities.h"
using namespace std;

// helper blocking gemm
void helperBlockingGemm(){
    cout<<"\nSelect input Block Size preferred power of 2: ";
    int blockSize;
    cin>>blockSize;
    int mode = Menu::chooseInputMenu();

    switch(mode){
        case 1:{
            string file = chooseTestFile("./assignment_01/tests/gemm");

            blocking_gemm(file, blockSize);

            break;
        }

        case 2:{
            vector<string> files = getTestFiles("./assignment_01/tests/gemm");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                blocking_gemm(file, blockSize);
            }

            break;
        }

        case 3:{
            string path;

            cout << "\nEnter file path : ";

            // cin >> path;
            cin>>ws;
            getline(cin, path);
            blocking_gemm(path, blockSize);

            break;
        }

        case 0:
            cout<<"Going back to main menu..."<<endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        break;
    }
}


//helper Simple gemm
void helperSimpleGemm(){
    int mode = Menu::chooseInputMenu();

    switch(mode){
        case 1:{
            string file = chooseTestFile("./assignment_01/tests/gemm");

            simple_gemm(file);

            break;
        }

        case 2:{
            vector<string> files = getTestFiles("./assignment_01/tests/gemm");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                simple_gemm(file);
            }

            break;
        }

        case 3:{
            string path;

            cout << "\nEnter file path : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, path);
            simple_gemm(path);

            break;
        }

        case 0:
            cout<<"Going back to main menu..."<<endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void helperGenerateCSR(){
    int mode = Menu::chooseInputMenu();

    switch(mode){
        case 1:{
            string file = chooseTestFile("./assignment_01/tests/csr");

            generateCSR(file);

            break;
            
        }

        case 2:{
            vector<string> files = getTestFiles("./assignment_01/tests/csr");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                generateCSR(file);
            }

            break;
        }

        case 3:{
            string path;

            cout << "\nEnter file path : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, path);
            generateCSR(path);

            break;
        }

        case 0:
            cout<<"Going back to main menu..."<<endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}
void assignment01Driver(){

    while(true){
        int choice = Menu::showAlgorithmMenu();
        switch(choice){
            case 0:
                return;
            case 1:
                //call simple_gemm

                cout<<"Simple GEMM selected"<<endl;
                helperSimpleGemm();
                
                break;
            case 2:
                //call blocking_gemm
                cout<<"Blocking GEMM selected"<<endl;
                helperBlockingGemm();
                break;
            case 3:
                cout<<"CSR representation selected"<<endl;
                // call generate_CSR
                helperGenerateCSR();

                break;
            default:
                std::cout<<"\nInvalid choice.\n";
        }
    }
    return;
}