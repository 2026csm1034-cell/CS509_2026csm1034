#include<chrono>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

void generate_csr(vector<vector<pair<int,int>>> &adj_list){
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
    cout<<"Execution Time: "<<duration<<" ms"<<endl;

    return;
}


void generateCSR(const std::string& file) {
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

    generate_csr(adjList);
    return;
}