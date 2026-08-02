#include<bits/stdc++.h>
#include<chrono>
void simple_gemm(ifstream &inputFile){

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
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int l=0; l<k; l++){
                final_mat[i][j] += mat1[i][l] * mat2[l][j];
            }
        }
    }
    return 0;
}