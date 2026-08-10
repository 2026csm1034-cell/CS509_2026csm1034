#include "bellman_ford.h"

BellmanFordResult bellman_ford(const CSR &csr, int src) {
    int V = csr.row_ptr.size() - 1;
    BellmanFordResult result;
    result.distances.assign(V, LLONG_MAX);
    result.distances[src] = 0;

    for(int itr =0; itr <V-1; itr++){
        bool change=false;
        for(int u=0; u<V; u++){
            if(result.distances[u] == LLONG_MAX) continue;
            for(int idx= csr.row_ptr[u]; idx<csr.row_ptr[u+1]; idx++){
                int v = csr.col_idx[idx];
                int wgt = csr.values[idx];
                //relaxing the node
                if(result.distances[u] + wgt < result.distances[v]){
                    result.distances[v] = result.distances[u] + wgt;
                    change = true;
                }
            }
        }
        if(!change) break;
    }

    //checking negating cycle;

    for(int u=0; u<V; u++){
        for(int idx=csr.row_ptr[u]; idx<csr.row_ptr[u+1]; idx++){
            int v = csr.col_idx[idx];
            int wgt = csr.values[idx];
            if(result.distances[u] != LLONG_MAX && result.distances[u] + wgt < result.distances[v]){
                result.isNegativeCycle = true;
                break;
            }
        }
        if(result.isNegativeCycle) break;
    }

    result.src = src;
    return result;
}
