#ifndef PAGERANK_H
#define PAGERANK_H

#include<bits/stdc++.h>
#include "../io/io.h"
#include "../../../assignment_01/src/csr/csr.h"
using namespace std;

struct PageRankResult{
    double d=0;
    double totalRank=0;
    int itration=0;
    bool isConverged = false;

    vector<pair<int,double>> rank;
};

PageRankResult pageRank(CSR &csr, double d, int it, double e);

#endif // PAGERANK_H