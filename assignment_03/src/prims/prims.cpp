#include "prims.h"

PrimsResult prims(CSR & csr){
    PrimsResult result;
    //wt , vetex, parent
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

    pq.push({0,0,-1}); //pushed first node as every node must be in mst

    int V = csr.row_ptr.size() -1;
    vector<bool> visited(V,false);
    while(!pq.empty()){
        auto [wt,u,parent] = pq.top();
        pq.pop();

        if(visited[u]) {
            continue;
        }
        visited[u]=true;

        if(parent != -1){
            result.mst.push_back({parent,u,wt});
            result.mst_weight += wt;
        }


        for(int i=csr.row_ptr[u]; i<csr.row_ptr[u+1]; i++){
            int v = csr.col_idx[i];
            int edgewt = csr.values[i];
            if(!visited[v]){
                pq.push({edgewt,v,u});
            }
        }
    }
    return result;
}