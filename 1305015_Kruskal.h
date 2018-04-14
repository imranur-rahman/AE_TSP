//
// Created by sabit on 4/12/2018.
//

#ifndef AE_TSP_KRUSKAL_H
#define AE_TSP_KRUSKAL_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Edge{
public:
    int from, to, weight;
    Edge(int x, int y, int cost){
        from = x;
        to = y;
        weight = cost;
    }
    bool operator < (const Edge &other) const {
        return weight < other.weight;
    }
};

class Kruskal {
private:
    vector<vector<bool>>isThisInMST;
    vector<vector<bool>>isThisValidEdge;
public:
    Kruskal(int n);
    int findMST(vector<vector<float> > &graph);
    const vector<vector<bool>> &getThisInMST() const;
    void setValidEdge(int n, vector<int>&validNodes);
    vector<Edge*> create_edges(vector<vector<float> > &graph);
};


#endif //AE_TSP_KRUSKAL_H
