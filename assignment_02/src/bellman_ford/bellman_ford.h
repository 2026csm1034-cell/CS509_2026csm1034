#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include<vector>
#include<iostream>
#include<bits/stdc++.h>
#include "../../../assignment_01/src/csr/csr.h"
using namespace std;
struct BellmanFordResult {
    std::vector<long long> distances;
    bool isNegativeCycle=false;
    int src=0;
};

BellmanFordResult bellman_ford(const CSR &csr, int src);

#endif
