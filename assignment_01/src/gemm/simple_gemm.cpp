#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<chrono>
#include "gemm.h"

void simple_gemm(const string &filename){
    ifstream inputFile(filename);
    if(!inputFile.is_open()){
        cerr<<"Error opening file: "<<filename<<endl;
        return;
    }
    int m , k, n;
    inputFile>>m>>k>>n;
    vector<vector<int>> mat1(m, vector<int>(k));
    vector<vector<int>> mat2(k, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            inputFile>>mat1[i][j];
        }
    }
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            inputFile>>mat2[i][j];
        }
    }

    vector<vector<int>> final_mat(m, vector<int>(n,0));
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int l=0; l<k; l++){
                final_mat[i][j] = (final_mat[i][j] + (mat1[i][l] * mat2[l][j])%mod)%mod;
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();

    std::string path = createOutputFile(filename, "simple");
    std::ofstream outputFile(path);

    cout<<"\nOutput: "<<endl;
    outputFile<<m<<" "<<n<<" "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            outputFile<<final_mat[i][j]<<" ";
        }
        outputFile<<endl;
    }
    cout<<"Resultant Matrix: "<<path<<endl;    
    std::chrono::duration<double,std::milli> duration = end-start;
    cout<<"Execution Time: "<<double(duration.count())<<" ms"<<endl;

    return;
}