#include "prims.h"

PrimsResult prims(CSR & csr){
    PrimsResult result;
    //wt , node
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0}); //pushed first node as every node must be in mst

    int V = csr.row_ptr.size() -1;
    vector<bool> visited(V,false);
    visited[0]=true;
    while(!pq.empty()){
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        result.mst_weight += wt;

        for(int i=csr.row_ptr[u]; i<csr.row_ptr[u+1]; i++){
            int v = csr.col_idx[i];
            int wt = csr.values[i];
            if(!visited[v]){
                result.mst.push_back({u,v,wt});
                visited[v]=true;
                pq.push({wt,v});
            }
        }
    }
    return result;
}