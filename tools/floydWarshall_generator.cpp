#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

int main()
{
    // Required test cases
    int sizes[] = {
        10,
        100,
        500,
        1000,
        2000
    };

    // Random number generator
    random_device rd;
    mt19937 gen(rd());

    // Edge probability
    // 30% chance of an edge
    uniform_real_distribution<double> probability(0.0, 1.0);

    // Positive edge weights
    uniform_int_distribution<int> weightDist(-1, 20);

    for(int s = 0; s < 5; s++)
    {
        int V = sizes[s];

        string filename =
            "fw_" + to_string(V) + ".txt";

        ofstream file(filename);

        if(!file)
        {
            cout << "Error creating "
                 << filename << endl;

            return 1;
        }

        // ----------------------------------
        // First line = number of vertices
        // ----------------------------------

        file << V << "\n";

        // ----------------------------------
        // Generate V x V matrix
        // ----------------------------------

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                // Diagonal must always be 0
                if(i == j)
                {
                    file << "0";
                }
                else
                {
                    // 30% chance of an edge
                    if(probability(gen) < 0.30)
                    {
                        int weight = weightDist(gen);

                        file << weight;
                    }
                    else
                    {
                        file << "INF";
                    }
                }

                // Space between entries
                if(j < V - 1)
                {
                    file << " ";
                }
            }

            file << "\n";
        }

        file.close();

        cout << "Created "
             << filename
             << "  V = "
             << V
             << endl;
    }

    cout << "\nAll Floyd-Warshall test cases generated.\n";

    return 0;
}