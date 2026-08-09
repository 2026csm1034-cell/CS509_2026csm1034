#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include<vector>
#include<fstream>
#include<iostream>

using namespace std;
//input format of unweighted graph

/*
    V E
    node degree neigh1, neigh2, ...
    ....
    ...

    SOURCE src;
*/

struct AdjListUnweighted{
    int V=0;
    int E=0;
    vector<vector<int>> adj;
    int src=0;
};

//input formate of Weighted Graph

/*
    V E
    node degree neigh1 weight1 neigh2 weight2 ....
    .....
    ....
    SOURCE src
*/

struct AdjListWeighted{
    int V=0;
    int E=0;
    vector<vector<pair<int,int>>>adj;
    int src=0;
};


AdjListUnweighted readUnweightedGraph(const std::string &inputFile);

AdjListWeighted readWeightedGraph(const std::string &inputFile);

#endif //GRAPH_IO_H