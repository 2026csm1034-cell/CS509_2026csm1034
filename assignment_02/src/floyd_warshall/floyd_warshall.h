#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include<vector>
#include<iostream>
using namespace std;
const long long INF = 1e18;
struct FloydWarshallResult{
    vector<vector<long long>> dist;
    bool isNegativeCycle=false;
};

FloydWarshallResult floydWarshall(vector<vector<long long>> adjMat);

#endif // FLOYD_WARSHALL_H