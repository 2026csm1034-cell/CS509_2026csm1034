#ifndef COLOR_H
#define COLOR_H

#include<bits/stdc++.h>
#include "../../../assignment_01/src/csr/csr.h"
using namespace std;
struct VertexColorResult{
    std::vector<int> colors;
    int numColors=0;
};

VertexColorResult colorVertices(CSR &csr);
#endif //color_h