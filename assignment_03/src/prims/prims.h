#ifndef PRIMS
#define PRIMS

#include "../../../assignment_01/src/csr/csr.h"
#include "../kruskal/kruskal.h"
#include <vector>
#include<queue>
using namespace std;
struct PrimsResult{
    int mst_weight=0;
    vector<Edges> mst;

};

PrimsResult prims(CSR & csr);

#endif //PRIMS