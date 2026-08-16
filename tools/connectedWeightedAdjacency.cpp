#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class GraphGenerator {
private:
    mt19937 rng;

    long long getKey(int u, int v, int V) {
        if (u > v)
            swap(u, v);

        return 1LL * u * V + v;
    }

public:
    GraphGenerator() {
        random_device rd;
        rng.seed(rd());
    }

    vector<Edge> generateGraph(int V, int E) {

        if (E < V - 1) {
            cerr << "Error: E must be at least V-1 for a connected graph.\n";
            exit(1);
        }

        long long maxEdges = 1LL * V * (V - 1) / 2;

        if (E > maxEdges) {
            cerr << "Error: Too many edges for a simple graph.\n";
            exit(1);
        }

        vector<Edge> edges;
        edges.reserve(E);

        unordered_set<long long> usedEdges;

        usedEdges.reserve(2 * E);

        uniform_int_distribution<int> weightDist(1, 1000000);

        /*
         * ------------------------------------------------
         * STEP 1:
         * Generate a random spanning tree.
         *
         * This guarantees that the graph is connected.
         * ------------------------------------------------
         */

        for (int v = 1; v < V; v++) {

            // Choose any previous vertex as parent.
            uniform_int_distribution<int> parentDist(0, v - 1);

            int u = parentDist(rng);

            int weight = weightDist(rng);

            edges.push_back({
                u,
                v,
                weight
            });

            usedEdges.insert(
                getKey(u, v, V)
            );
        }

        /*
         * ------------------------------------------------
         * STEP 2:
         * Add random edges until we reach E edges.
         * ------------------------------------------------
         */

        uniform_int_distribution<int> vertexDist(0, V - 1);

        while ((int)edges.size() < E) {

            int u = vertexDist(rng);
            int v = vertexDist(rng);

            // No self loop.
            if (u == v)
                continue;

            long long key = getKey(u, v, V);

            // Don't add duplicate undirected edge.
            if (usedEdges.find(key) != usedEdges.end())
                continue;

            int weight = weightDist(rng);

            edges.push_back({
                u,
                v,
                weight
            });

            usedEdges.insert(key);
        }

        return edges;
    }

    void writeGraph(
        const string& filename,
        int V,
        int E,
        const vector<Edge>& edges
    ) {

        /*
         * Adjacency list.
         *
         * Since the graph is UNDIRECTED:
         *
         * u -> v
         * v -> u
         */

        vector<vector<pair<int, int>>> adj(V);

        for (const Edge& e : edges) {

            adj[e.u].push_back({
                e.v,
                e.weight
            });

            adj[e.v].push_back({
                e.u,
                e.weight
            });
        }

        /*
         * Sort neighbors.
         *
         * Not required by MST algorithms,
         * but makes the generated files easier
         * to inspect.
         */

        for (int u = 0; u < V; u++) {

            sort(
                adj[u].begin(),
                adj[u].end()
            );
        }

        ofstream out(filename);

        if (!out) {

            cerr << "Error opening file: "
                 << filename << '\n';

            exit(1);
        }

        /*
         * First line:
         *
         * V E
         */

        out << V << ' ' << E << '\n';

        /*
         * Each vertex:
         *
         * u degree neighbor1 weight1 neighbor2 weight2 ...
         */

        for (int u = 0; u < V; u++) {

            out << u << ' '
                << adj[u].size();

            for (auto [neighbor, weight] : adj[u]) {

                out << ' '
                    << neighbor
                    << ' '
                    << weight;
            }

            out << '\n';
        }

        out.close();
    }
};


int main() {

    GraphGenerator generator;

    /*
     * Required graph sizes.
     */

    vector<int> sizes = {
        10,
        100,
        10000,
        50000,
        100000
    };

    /*
     * We use E = 3V.
     *
     * This produces sparse graphs while still
     * providing enough edges to test Prim/Kruskal.
     */

    for (int V : sizes) {

        int E = 3 * V;

        string filename =
            "mst_" + to_string(V) + ".txt";

        cout << "Generating "
             << filename
             << "  (V = " << V
             << ", E = " << E << ")..."
             << endl;

        vector<Edge> edges =
            generator.generateGraph(V, E);

        generator.writeGraph(
            filename,
            V,
            E,
            edges
        );

        cout << "Done: "
             << filename
             << endl;
    }

    return 0;
}