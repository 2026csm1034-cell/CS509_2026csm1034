#ifndef KRUSKAL
#define KRUSKAL

#include "../../../assignment_01/src/csr/csr.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct Edges{
    int u;
    int v;
    int w;
};
struct KruskalResult{
    long long mst_weight=0;
    vector<Edges> mst;
};
KruskalResult kruskal(CSR &csr);

#endif //Kruskal
