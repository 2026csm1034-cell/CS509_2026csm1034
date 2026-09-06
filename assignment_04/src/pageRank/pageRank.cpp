#include "pageRank.h"

PageRankResult pageRank(CSR &csr, double d, int it, double e) {
    int V = csr.row_ptr.size()-1;
 
    PageRankResult result;
    result.d = d;
 
    // Out-degree of every vertex, from the CSR row pointers.
    vector<int> outDeg(V, 0);
    for (int u = 0; u < V; ++u) {
        outDeg[u] = csr.row_ptr[u + 1] - csr.row_ptr[u];
    }
 
    vector<double> pr(V, 1.0 / V);
    vector<double> newPr(V, 0.0);
 
    int iterationsRun = 0;
    bool converged = false;
 
    for (int iter = 0; iter < it; ++iter) {
        iterationsRun = iter + 1;
 
        // Rank held by dangling nodes (out-degree 0) has nowhere to flow;
        // redistribute it evenly across all vertices so total rank stays 1.0.
        double danglingSum = 0.0;
        for (int u = 0; u < V; ++u) {
            if (outDeg[u] == 0) {
                danglingSum += pr[u];
            }
        }
 
        double base = (1.0 - d) / V + d * danglingSum / V;
        fill(newPr.begin(), newPr.end(), base);
 
        for (int u = 0; u < V; ++u) {
            if (outDeg[u] == 0) continue;
            double share = d * pr[u] / outDeg[u];
            int start = csr.row_ptr[u];
            int end = csr.row_ptr[u + 1];
            for (int idx = start; idx < end; ++idx) {
                int v = csr.col_idx[idx];
                newPr[v] += share;
            }
        }
 
        // Total change in rank across all vertices (L1 norm).
        double totalChange = 0.0;
        for (int i = 0; i < V; ++i) {
            totalChange += fabs(newPr[i] - pr[i]);
        }
 
        pr.swap(newPr);
 
        if (totalChange <= e) {
            converged = true;
            break;
        }
    }
 
    double sumRanks = 0.0;
    for (int i = 0; i < V; ++i) {
        sumRanks += pr[i];
    }
 
    result.itration = iterationsRun;
    result.isConverged = converged;
    result.totalRank = sumRanks;
 
    result.rank.reserve(V);
    for (int i = 0; i < V; ++i) {
        result.rank.push_back({i, pr[i]});
    }
 
    return result;
}