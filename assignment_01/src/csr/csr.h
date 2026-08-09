#ifndef CSR_H
#define CSR_H

#include "../graph_io/graph_io.h"
using namespace std;

struct CSR{
    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;
};

CSR buildCSR(const AdjListUnweighted& adjList);
CSR buildCSR(const AdjListWeighted& adjList);
#endif // CSR_H