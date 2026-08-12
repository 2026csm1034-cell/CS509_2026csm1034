#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <set>
#include <string>

using namespace std;

int main()
{
    int sizes[] = {10, 100, 10000, 50000, 100000};

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> weightDist(-3, 20);

    for(int s = 0; s < 5; s++)
    {
        int V = sizes[s];
        
        // E = 3V
        int E = 3 * V;

        vector<vector<pair<int, int>>> graph(V);

        set<pair<int, int>> usedEdges;

        uniform_int_distribution<int> vertexDist(0, V - 1);

        while((int)usedEdges.size() < E)
        {
            int u = vertexDist(gen);
            int v = vertexDist(gen);

            if(u == v)
                continue;

            if(usedEdges.count({u, v}))
                continue;

            usedEdges.insert({u, v});

            int weight = weightDist(gen);

            graph[u].push_back({v, weight});
        }

        string filename =
            "bf_" + to_string(V) + ".txt";

        ofstream file(filename);

        if(!file)
        {
            cout << "Error creating "<< filename << endl;

            return 1;
        }

        // V E
        file << V << " " << E << "\n";

        // adjacency list
        for(int u = 0; u < V; u++)
        {
            file << u << " "<< graph[u].size();

            for(auto edge : graph[u])
            {
                int v = edge.first;
                int w = edge.second;

                file << " "<< v << " "<< w;
            }

            file << "\n";
        }

        // Source
        file << "SOURCE 0\n";

        file.close();

        cout << "Created "<< filename<< "  V=" << V<< " E=" << E<< endl;
    }

    return 0;
}