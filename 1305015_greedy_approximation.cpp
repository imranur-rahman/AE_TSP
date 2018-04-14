//
// Created by sabit on 4/11/2018.
//
#include <iostream>
#include "1305015_greedy_approximation.h"
#include "1305015_Kruskal.h"
#include "1305015_read_input.h"


vector<bool>visited;
vector<int>preorder_walk;

void createInputForGraph(string from, string to, vector<int>configuration) {
    //ifstream in;
    //in.open(from);
    /*if(in.is_open() == false) {
        cout << "could not open file\n";
        return;
    }
    int n = configuration.size();
    int x, y;
    float xid[n], yid[n];
    int node = 0;
    in >> x >> y;//n and m
    while(in >> x >> y) {
        xid[node] = x;
        yid[node] = y;
        node++;
    }
    in.close();*/
    /*int n, m, x, y;
    vector<float>xid, yid;
    if(in) {
        in >> n >> m;
        xid.resize(n);
        yid.resize(n);
        int node = 0;
        while(in >> x >> y) {
            xid[node] = x;
            yid[node] = y;
            node++;
        }
        in.close();
    }*/

    ofstream out;
    out.open(to);
    if(out.is_open() == false) {
        cout << "could not open file\n";
        return;
    }
    configuration.push_back(configuration.front());
    for(int i = 0; i < configuration.size(); ++i) {
        int node = configuration[i];
        //cout << node << endl;
        out << xid[node] << " " << yid[node] << endl;
    }
    //out << xid[configuration[0]] << " " << yid[configuration[0]] << endl;
    out.close();
}

int dfs(int u, int n, const vector<vector<bool>> &isInMST) {
    visited[u] = true;
    preorder_walk.push_back(u);

    for(int i = 0; i < n; ++i)
        if(isInMST[u][i] == true  &&  visited[i] == false)
            dfs(i, n, isInMST);
}

float greedy_approximation(int n, vector<vector<float> > &graph) {
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
    float cost_of_this_hamiltonian_cycle = 0.0;
    for(int i = 1; i < preorder_walk.size(); ++i) {
        int u = preorder_walk[i - 1];
        int v = preorder_walk[i];

        cost_of_this_hamiltonian_cycle += graph[u][v];
    }

    cost_of_this_hamiltonian_cycle += graph[ preorder_walk.back() ][startnode];
    cout << cost_of_this_hamiltonian_cycle << endl;
    createInputForGraph("1305015_input.txt", "1305015_graph.plt", preorder_walk);
    return cost_of_this_hamiltonian_cycle;
}
