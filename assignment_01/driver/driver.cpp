#include<iostream>
#include "driver.h"
#include "../../common_wrapper/menu.h"
#include "../src/gemm/gemm.h"
#include "../src/csr/csr.h"
#include "../../common_wrapper/utilities.h"
#include "../src/graph_io/graph_io.h"
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


//output file for CSR;
void writeCSR(const CSR& csr, const std::string& filename) {
    string path = createOutputFile(filename,"csr");
    std::ofstream outputFile(path);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    int V = csr.row_ptr.size() - 1;
    int E = csr.col_idx.size();

    outputFile << V << " " << E << "\n";
    for (int u = 0; u < V; ++u) {
        outputFile << csr.row_ptr[u] << " " << csr.row_ptr[u + 1] << "\n";
        for (int i = csr.row_ptr[u]; i < csr.row_ptr[u + 1]; ++i) {
            outputFile << csr.col_idx[i] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();
}

//helper to generate WeightedCSR
void helperGenerateCSR(){
    int mode = Menu::chooseInputMenu();

    switch(mode){
        case 1:{
            string file = chooseTestFile("./assignment_01/tests/csr");

           AdjListWeighted g = readWeightedGraph(file);
           CSR csr = buildCSR(g);

            writeCSR(csr, file);

            break;
            
        }

        case 2:{
            vector<string> files = getTestFiles("./assignment_01/tests/csr");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                AdjListWeighted g = readWeightedGraph(file);
                CSR csr = buildCSR(g);
                writeCSR(csr, file);
            }

            break;
        }

        case 3:{
            string path;

            cout << "\nEnter file path : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, path);
            AdjListWeighted g = readWeightedGraph(path);
            CSR csr = buildCSR(g);
            writeCSR(csr, path);
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
                cout<<"Weighted CSR representation selected"<<endl;
                // call generate_CSR
                helperGenerateCSR();

                break;
            default:
                std::cout<<"\nInvalid choice.\n";
        }
    }
    return;
}