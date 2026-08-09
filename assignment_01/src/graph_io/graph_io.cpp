#include "graph_io.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

AdjListUnweighted readUnweightedGraph(const string& filepath) {
    ifstream inputFile(filepath);
    if (!inputFile.is_open()) {
        throw runtime_error("Could not find or open input file: " + filepath);
    }

    AdjListUnweighted graph;
    inputFile >> graph.V >> graph.E;
    if (!inputFile || graph.V < 0) {
        throw runtime_error("Invalid Header format in file: " + filepath);
    }

    graph.adj.assign(graph.V, {});  // initialise the adjacency list
    for (int i = 0; i < graph.V; ++i) {
        int u, degree;
        inputFile >> u >> degree;
        if (!inputFile || u < 0 || u >= graph.V) {
            throw runtime_error("Invalid adjacency line format in file: " + filepath);
        }
        graph.adj[u].reserve(degree);
        for (int k = 0; k < degree; ++k) {
            int negh;
            inputFile >> negh;
            if (!inputFile) {
                throw runtime_error("Invalid neighbor list in file: " + filepath);
            }
            graph.adj[u].push_back(negh);
        }
    }

    string tag;
    inputFile >> tag >> graph.src;
    if (!inputFile || tag != "SOURCE") {
        throw runtime_error("Missing SOURCE line in file: " + filepath);
    }

    return graph;
}

AdjListWeighted readWeightedGraph(const std::string& filepath) {
    ifstream inputFile(filepath);
    if (!inputFile.is_open()) {
        throw runtime_error("Could not find or open input file: " + filepath);
    }

    AdjListWeighted graph;
    inputFile >> graph.V >> graph.E;
    if (!inputFile || graph.V < 0) {
        throw runtime_error("Invalid Header format in file: " + filepath);
    }

    graph.adj.assign(graph.V, {});
    for (int i = 0; i < graph.V; ++i) {
        int u, degree;
        inputFile >> u >> degree;
        if (!inputFile || u < 0 || u >= graph.V) {
            throw runtime_error("Invalid adjacency line format in file: " + filepath);
        }
        graph.adj[u].reserve(degree);
        for (int k = 0; k < degree; ++k) {
            int negh, weight;
            inputFile >> negh >> weight;
            if (!inputFile) {
                throw runtime_error("Invalid neighbor/weight list in file: " + filepath);
            }
            graph.adj[u].push_back({negh, weight});
        }
    }

    string tag;
    inputFile >> tag >> graph.src;
    if (!inputFile || tag != "SOURCE") {
        throw runtime_error("Missing SOURCE line in file: " + filepath);
    }

    return graph;
}
