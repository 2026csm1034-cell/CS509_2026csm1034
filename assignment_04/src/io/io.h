#ifndef IO4_H
#define IO4_H
#include<bits/stdc++.h>
#include "../../../assignment_01/src/csr/csr.h"
using namespace std;
// find the structure of graph pageRank


struct PageRankGraph {
    int V=0;
    int E=0;
    vector<vector<int>> adj;
    double d=0; //damping factor
    double  epsilon=0; // tolerance value
    int n=0; //maximum iteration

};

// find the structure of graph vertex coloring

struct UndirectedGraph {
    int V=0;
    int E=0;
    vector<vector<int>> adj;
};
template <typename T>
CSR build1CSR(T &g){
    CSR csr;
    int V = g.V;
    csr.row_ptr.assign(V + 1, 0);
    for (int u = 0; u < V; ++u) {
        csr.row_ptr[u + 1] = csr.row_ptr[u] + g.adj[u].size();
    }
    csr.col_idx.reserve(csr.row_ptr[V]);
    for (int u = 0; u < V; ++u) {
        for (int v : g.adj[u]) {
            csr.col_idx.push_back(v);
        }
    }
    return csr;
}

PageRankGraph readPageRankGraph(const string &inputFile);
UndirectedGraph readUndirectedGraph(const string &inputFile);


#endif //IO4_H