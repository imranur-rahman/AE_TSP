//
// Created by sabit on 4/8/2018.
//
#include "branch_and_bound.h"

int startnode = 0;

bool isCompleteSolution(int n, vector<int>&now_problem) {
    return (now_problem.size() - 1) == n; //cost tuke baad diye
}

vector<int> calculate_VS(int n, vector<int>&now_problem) {
    set<int>set(now_problem.begin(), now_problem.end());
    set.erase(now_problem[0]); //cost ta delete kore dicchi

    vector<int>ret;
    for(int i = 0; i < n; ++i) {
        if(set.find(i) == set.end()) {
            ret.push_back(i);
        }
    }
    return ret;
}

int calculate_lightest_edge(int u, vector<int> &VS, int n, vector<vector<int>> &graph) {
    int ret = numeric_limits<int>::max();
    for(int i = 0; i < VS.size(); ++i) {
        int v = VS[i];
        ret = min(ret, graph[u][v]);
    }
    return ret;
}

int calculate_second_lighest_edge(int u, vector<int> &VS, int n, vector<vector<int>> &graph) {
    int min1 = numeric_limits<int>::max();
    int min2 = min1;
    for(int i = 0; i < VS.size(); ++i) {
        int v = VS[i];
        int cost = graph[u][v];
        if(cost < min1) {
            min2 = min1;
            min1 = cost;
        }
        else if(cost < min2) {
            min2 = cost;
        }
    }
    return min2;
}

int lowerbound(int n, vector<int> &now_problem) {
    vector<int>VS = calculate_VS(n, now_problem);

    return 0;
}

int branch_and_bound(int n, vector<vector<int>> &graph) {

    queue<vector<int>>S;
    vector<int>v;
    //v[0] te costSoFar thakteche
    v.push_back(0);
    v.push_back(startnode);
    S.push(v);

    int bestSoFar = numeric_limits<int>::max();

    while(S.empty() == false) {
        vector<int>now_problem = S.front();
        S.pop();

        //startnode of this problem
        int st = now_problem[1];

        //VS oi sob node er set jader ke add korte pari
        vector<int>VS = calculate_VS(n, now_problem);

        int lastNodeSoFar = now_problem.back();
        for(int i = 0; i < VS.size(); ++i) {
            int newNodeToAdd = VS[i];

            now_problem.push_back(newNodeToAdd);
            now_problem[0] += graph[lastNodeSoFar][newNodeToAdd];

            if(isCompleteSolution(n, now_problem)) {
                bestSoFar = min(bestSoFar, now_problem[0]);
            }
            else if(lowerbound(n, now_problem) < bestSoFar) {
                S.push(now_problem);
            }

            now_problem[0] -= graph[lastNodeSoFar][newNodeToAdd];
            now_problem.pop_back();
        }
    }
    return bestSoFar;
}
