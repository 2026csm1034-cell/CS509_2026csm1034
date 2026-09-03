#include "io.h"

PageRankGraph readPageRankGraph(const string &filePath) {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw runtime_error("Could not find or open input file: " + filePath);
    }

    PageRankGraph graph;
    inputFile >> graph.V >> graph.E;
    if (!inputFile || graph.V < 0) {
        throw runtime_error("Invalid Header format in file: " + filePath);
    }

    graph.adj.assign(graph.V, {});  // initialise the adjacency list
    for (int i = 0; i < graph.V; ++i) {
        int u, degree;
        inputFile >> u >> degree;
        if (!inputFile || u < 0 || u >= graph.V) {
            throw runtime_error("Invalid adjacency line format in file: " + filePath);
        }
        graph.adj[u].reserve(degree);
        for (int k = 0; k < degree; ++k) {
            int negh;
            inputFile >> negh;
            if (!inputFile) {
                throw runtime_error("Invalid neighbor list in file: " + filePath);
            }
            graph.adj[u].push_back(negh);
        }
    }

    string tag;
    inputFile >> tag >> graph.d;;
    if (!inputFile || tag != "DAMPING") {
        throw runtime_error("Missing DAMPING line in file: " + filePath);
    }

    inputFile >> tag >> graph.epsilon;
    if (!inputFile || tag != "TOLERANCE") {
        throw runtime_error("Missing TOLERANCE line in file: " + filePath);
    }

    inputFile >> tag >> graph.n;
    if (!inputFile || tag != "MAX_ITERATIONS") {
        throw runtime_error("Missing MAX_ITERATIONS line in file: " + filePath);
    }

    return graph;
}


UndirectedGraph readUndirectedGraph(const string &filePath){
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw runtime_error("Could not find or open input file: " + filePath);
    }

    UndirectedGraph graph;
    inputFile >> graph.V >> graph.E;
    if (!inputFile || graph.V < 0) {
        throw runtime_error("Invalid Header format in file: " + filePath);
    }

    graph.adj.assign(graph.V, {});  // initialise the adjacency list
    for (int i = 0; i < graph.V; ++i) {
        int u, degree;
        inputFile >> u >> degree;
        if (!inputFile || u < 0 || u >= graph.V) {
            throw runtime_error("Invalid adjacency line format in file: " + filePath);
        }
        graph.adj[u].reserve(degree);
        for (int k = 0; k < degree; ++k) {
            int negh;
            inputFile >> negh;
            if (!inputFile) {
                throw runtime_error("Invalid neighbor list in file: " + filePath);
            }
            graph.adj[u].push_back(negh);
        }
    }
    return graph;
}



