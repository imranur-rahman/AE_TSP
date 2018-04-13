//
// Created by sabit on 4/12/2018.
//

#include "Kruskal.h"
#include "Union_Find.h"

using namespace std;

Kruskal::Kruskal(int n){
    isThisInMST.resize(n);
    for(int i = 0; i < n; ++i)
        isThisInMST[i].resize(n);
}

vector<Edge*> create_edges(vector<vector<int> > &graph){
    vector<Edge*>ret;
    int n = graph.size();
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            ret.push_back(new Edge(i, j, graph[i][j]));
        }
    }
    return ret;
}

int Kruskal::findMST(vector<vector<int> > &graph) {
    vector<Edge*>edges = create_edges(graph);
    sort(edges.begin(), edges.end());
    //cout << "edges vector size : " << edges.size() << endl;

    Union_Find UF(graph.size());

    int total_cost = 0;
    for(int i = 0; i < edges.size(); ++i) {

        int x = UF.root(edges[i]->from);
        int y = UF.root(edges[i]->to);

        if(x != y) { // not in the same set
            UF.unite(x, y);
            isThisInMST[edges[i]->from][edges[i]->to] = true;
            isThisInMST[edges[i]->to][edges[i]->from] = true;
            total_cost += edges[i]->weight;
        }
    }
    //cout << "number of different sets after MST using union find : " << UF.numOfSets() << endl;
    return total_cost;
}

const vector<vector<bool>> &Kruskal::getThisInMST() const {
    return isThisInMST;
}
