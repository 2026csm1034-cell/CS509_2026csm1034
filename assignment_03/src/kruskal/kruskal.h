#ifndef KRUSKAL
#define KRUSKAL

#include "../../../assignment_01/src/csr/csr.h"
#include <vector>
using namespace std;
struct Edges{
    int u;
    int v;
    int w;
};
struct KruskalResult{
    int mst_weight=0;
    vector<Edges> mst;
};
KruskalResult kruskal(CSR &csr);

#endif //Kruskal