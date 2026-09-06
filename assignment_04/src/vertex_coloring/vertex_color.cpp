#include "vertex_color.h"


VertexColorResult colorVertices(CSR &csr) {
    int V = csr.row_ptr.size() - 1;
 
    VertexColorResult result;
    result.colors.assign(V, -1);
 
    for (int u = 0; u < V; ++u) {
        // Colors currently used by u's already-colored neighbors.
        // Sized V since that's the worst-case number of distinct colors.
        vector<bool> usedByNeighbor(V, false);
 
        int start = csr.row_ptr[u];
        int end = csr.row_ptr[u + 1];
        for (int idx = start; idx < end; ++idx) {
            int v = csr.col_idx[idx];
            if (result.colors[v] != -1) {
                usedByNeighbor[result.colors[v]] = true;
            }
        }
 
        // Smallest color not used by any already-colored neighbor.
        // An isolated vertex (no neighbors, or none colored yet) gets 0.
        int c = 0;
        while (c < V && usedByNeighbor[c]) {
            ++c;
        }
        result.colors[u] = c;
    }
 
    int maxColor = -1;
    for (int c : result.colors) {
        maxColor = max(maxColor, c);
    }
    result.numColors = maxColor + 1; // colors are 0-indexed
 
    return result;
}