#include<chrono>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include "../../../common_wrapper/utilities.h"
using namespace std;

std::string path;
void generate_weighted_csr(vector<vector<pair<int,int>>> &adj_list){
    std::sort(adj_list.begin(), adj_list.end());
    int V = adj_list.size();
    vector<int> row_ptr(V+1);
    vector<int> col_idx;
    vector<int> values;
    row_ptr[0]=0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<V; i++){
        for(auto neigh: adj_list[i]){
            int node = neigh.first;
            int val = neigh.second;
            col_idx.push_back(node);
            values.push_back(val);
        }
        row_ptr[i+1] = row_ptr[i] + adj_list[i].size();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(start-end).count();

    std::ofstream outputFile(path);
    outputFile<<"row_ptr: "<<endl;
    for(int i=0; i<row_ptr.size(); i++){
        outputFile<<row_ptr[i]<<" ";
    }
    outputFile<<endl;

    outputFile<<"col_idx: "<<endl;
    for(int i=0; i<col_idx.size(); i++){
        outputFile<<col_idx[i]<<" ";
    }
    outputFile<<endl;

    outputFile<<"values: "<<endl;
    for(int i=0; i<values.size(); i++){
        outputFile<<values[i]<<" ";
    }
    outputFile<<endl;

    cout<<"\nOutput: "<<path<<endl;
    cout<<"Execution Time: "<<duration<<" ms"<<endl;

    return;
}


void generateWeightedCSR(const std::string& file) {
    vector<vector<pair<int,int>>> adjList;
    ifstream inputFile(file);
    if(!inputFile.is_open()){
        cout<<"Error opening file: "<<file<<endl;
        return;
    }
    int V, E;
    inputFile>>V>>E;
    
    adjList.resize(V);
    for(int i=0; i<V; i++){
        int u, degree;
        inputFile>>u>>degree;
        
        for(int d=0; d<degree; d++){
            int v, weight;
            inputFile>>v>>weight;
            adjList[u].push_back({v,weight});
        }
    }
    
    path = createOutputFile(file,"weighted_csr");
    generate_weighted_csr(adjList);
    return;
}

//generate unweighted CSR
void generate_csr(vector<vector<int>> &adj_list){
    sort(adj_list.begin(),adj_list.end());

    int V = adj_list.size();

    vector<int> row_ptr(V+1);
    vector<int> col_idx;
    vector<int> values;
    row_ptr[0]=0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0; i<V; i++){
        for(auto neigh: adj_list[i]){
            col_idx.push_back(neigh);
            values.push_back(1);
        }
        row_ptr[i+1] = row_ptr[i] + adj_list[i].size();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(start-end).count();

    std::ofstream outputFile(path);

    outputFile<<"row_ptr: "<<endl;
    for(int i=0; i<row_ptr.size(); i++){
        outputFile<<row_ptr[i]<<" ";
    }
    outputFile<<endl;

    outputFile<<"col_idx: "<<endl;
    for(int i=0; i<col_idx.size(); i++){
        outputFile<<col_idx[i]<<" ";
    }
    outputFile<<endl;

    outputFile<<"values: "<<endl;
    for(int i=0; i<values.size(); i++){
        outputFile<<values[i]<<" ";
    }
    outputFile<<endl;

    cout<<"\nOutput: "<<path<<endl;

    cout<<"Execution Time: "<<duration<<" ms"<<endl;


}

//calling function for input;
void generateCSR(const std::string& file) {
    vector<vector<int>> adjList;

    ifstream inputFile(file);
    if(!inputFile.is_open()){
        cout<<"Error opening file: "<<file<<endl;
        return;
    }
    int V, E;
    inputFile>>V>>E;

    adjList.resize(V);
    for(int i=0; i<V; i++){
        int u, degree;
        inputFile>>u>>degree;

        for(int d=0; d<degree; d++){
            int v;
            inputFile>>v;
            adjList[u].push_back(v);
        }
    }
    path = createOutputFile(file, "unweighted_csr");
    generate_csr(adjList);
    return;
}