#include"kruskal.h"
class Union{
    int n;
    vector<int> parent;
    vector<int> size;
    public:
        Union(int n){
            this->n = n;
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUpar(int u){
            if(parent[u] == u) return u;

            return parent[u] = findUpar(parent[u]);
        }


        void unite(int u, int v){
            int upar_u = findUpar(u);
            int upar_v = findUpar(v);

            if(upar_u == upar_v) return;

            if(size[upar_u] > size[upar_v]){
                parent[upar_v] = upar_u;
                size[upar_u] += size[upar_v];
            }else{
                parent[upar_u] = upar_v;
                size[upar_v] +=size[upar_u];
            }
        }
};
KruskalResult kruskal(CSR &csr){
    KruskalResult result;

    vector<Edges> edges;

    int V = csr.row_ptr.size() -1;

    Union uf(V);

    for(int u=0; u<V; u++){
        for(int idx = csr.row_ptr[u]; idx<csr.row_ptr[u+1]; idx++){
             int v = csr.col_idx[idx];
             int wt = csr.values[idx];
             edges.push_back({u,v,wt});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edges e1, const Edges e2){
        if(e1.w <= e2.w) return true;
        return false;
    });

    for(auto e:edges){
        if(uf.findUpar(e.u) != uf.findUpar(e.v)){
            uf.unite(e.u,e.v);
            result.mst.push_back({e.u,e.v,e.w});
            result.mst_weight +=e.w;
        }
    }

    return result;
}