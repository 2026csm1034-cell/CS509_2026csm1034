#include "floyd_warshall.h"


FloydWarshallResult floydWarshall(vector<vector<long long>> adjMat){
    int n = adjMat.size();
    FloydWarshallResult result;
    result.dist = adjMat;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (result.dist[i][k] < INF && result.dist[k][j] < INF)
                    result.dist[i][j] = min(result.dist[i][j], result.dist[i][k] + result.dist[k][j]); 
            }
        }
    }

    for(int i=0; i<n; i++){
        if(result.dist[i][i] < 0){
            result.isNegativeCycle = true;
            break;
        }   
    }
    return result;
}