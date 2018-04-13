//
// Created by sabit on 4/11/2018.
//
#include <iostream>
#include "greedy_approximation.h"
#include "Kruskal.h"


vector<bool>visited;
vector<int>preorder_walk;

int dfs(int u, int n, const vector<vector<bool>> &isInMST) {
    visited[u] = true;
    preorder_walk.push_back(u);

    for(int i = 0; i < n; ++i)
        if(isInMST[u][i] == true  &&  visited[i] == false)
            dfs(i, n, isInMST);
}

int greedy_approximation(int n, vector<vector<int> > &graph) {
    Kruskal *kruskal = new Kruskal(n);
    kruskal->findMST(graph);

    visited.clear();
    preorder_walk.clear();

    visited.resize(n);
    int startnode = rand() % n;
    dfs(startnode, n, kruskal->getThisInMST());

    cout << "greedy approximation : ";

    //print hamiltonian cycle
    //cout << "preorder walk size : " << preorder_walk.size() << endl;
    for(int i = 0; i < preorder_walk.size(); ++i){
        cout << preorder_walk[i] << " ";
    }
    cout << endl;

    //cost calculation
    int cost_of_this_hamiltonian_cycle = 0;
    for(int i = 1; i < preorder_walk.size(); ++i) {
        int u = preorder_walk[i - 1];
        int v = preorder_walk[i];

        cost_of_this_hamiltonian_cycle += graph[u][v];
    }

    cost_of_this_hamiltonian_cycle += graph[ preorder_walk.back() ][startnode];
    cout << cost_of_this_hamiltonian_cycle << endl;
    return cost_of_this_hamiltonian_cycle;
}
