//
// Created by sabit on 4/8/2018.
//
#include <fstream>
#include "1305015_branch_and_bound.h"


int startnode = 0;
string tofile = "1305015_graph.txt";

void createInputForGraph(string from, string to, vector<int>&configuration) {
    ifstream in;
    in.open(from);
    if(in.is_open() == false) {
        cout << "could not open file\n";
        return;
    }
    int n = configuration.size();
    int x, y;
    float xid[n], yid[n];
    int node = 0;
    while(in >> x >> y) {
        xid[node] = x;
        yid[node] = y;
        node++;
    }
    in.close();

    ofstream out;
    out.open(to);
    if(out.is_open() == false) {
        cout << "could not open file\n";
        return;
    }
    for(int i = 0; i < n; ++i) {
        int node = configuration[i];
        out << xid[node] << " " << yid[node] << endl;
    }
    out << xid[configuration[0]] << " " << yid[configuration[0]] << endl;
    out.close();
}

float calculateCost(vector<int>&now_configuration, vector<vector<float>> &graph) {
    float total = 0.0;
    for(int i = 1; i < now_configuration.size(); ++i) {
        int x = now_configuration[i - 1];
        int y = now_configuration[i];

        total += graph[x][y];
    }
    //total cycle cost
    int start = now_configuration[0];
    int end = now_configuration.back();

    return total + graph[end][start];
}

void print_vector(vector<int>&v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

bool isCompleteSolution(int n, vector<int>&now_problem) {
    return now_problem.size() == n; //cost tuke baad diye
}

vector<int> calculate_VS(int n, vector<int>&now_problem) {
    set<int>set(now_problem.begin(), now_problem.end());
    //set.erase(set.find(now_problem[0])); //cost ta delete kore dicchi

    vector<int>ret;
    for(int i = 0; i < n; ++i) {
        if(set.find(i) == set.end()) {
            ret.push_back(i);
        }
    }
    /*vector<int>ret;
    int ar[n];
    for(int i = 1; i < now_problem.size(); ++i) {
        int nowNode = now_problem[i];
        ar[nowNode] = 1;
    }
    for(int i = 0; i < n; ++i)
        if(ar[i] == 0)
            ret.push_back(i);*/
    return ret;
}

float calculate_lightest_edge(int u, vector<int> &VS, int n, vector<vector<float>> &graph) {
    float ret = numeric_limits<float>::max();
    for(int i = 0; i < VS.size(); ++i) {
        int v = VS[i];
        ret = min(ret, graph[u][v]);
    }
    return ret;
}

float calculate_second_lighest_edge(int u, vector<int> &VS, int n, vector<vector<float>> &graph) {
    float min1 = numeric_limits<int>::max();
    float min2 = min1;
    for(int i = 0; i < VS.size(); ++i) {
        int v = VS[i];
        float cost = graph[u][v];
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

float lowerbound(int n, vector<int> &now_problem, vector<vector<float>> &graph) {
    vector<int>VS = calculate_VS(n, now_problem);
    //node kokhonoi 1 ta thaka obosthay ekhane asbe na
    int start = now_problem[1];
    int end = now_problem.back();

    Kruskal *kruskal = new Kruskal(n);
    kruskal->setValidEdge(n, VS);
    float mst = kruskal->findMST(graph);
    //cout << "mst : " << mst << endl;

    float ret1 = calculate_lightest_edge(start, VS, n, graph);
    float ret2 = calculate_lightest_edge(end, VS, n, graph);
    //cout << ret1 << " " << ret2 << endl;

    return ret1 + ret2 + mst;
}

float branch_and_bound(int n, vector<vector<float>> &graph) {

    queue<vector<int>>S;
    vector<int>v;
    //v[0] te costSoFar thakteche
    //v.push_back(-1);
    v.push_back(startnode);
    S.push(v);

    float bestSoFar = numeric_limits<float>::max();
    vector<int>bestSet;

    while(S.empty() == false) {
        vector<int>now_problem = S.front();
        S.pop();

        //startnode of this problem
        //int st = now_problem[1];

        //VS oi sob node er set jader ke add korte pari
        vector<int>VS = calculate_VS(n, now_problem);
        /*cout << "now_problem : ";
        print_vector(now_problem);
        cout << "VS : ";
        print_vector(VS);*/

        int lastNodeSoFar = now_problem.back();
        for(int i = 0; i < VS.size(); ++i) {
            int newNodeToAdd = VS[i];

            now_problem.push_back(newNodeToAdd);
            //now_problem[0] += graph[lastNodeSoFar][newNodeToAdd];

            //print_vector(now_problem);

            if(isCompleteSolution(n, now_problem)) {
                //int totalTourCost = now_problem[0] + graph[newNodeToAdd][now_problem[1]];

                float totalTourCost = calculateCost(now_problem, graph);

                if(totalTourCost < bestSoFar){
                    bestSoFar = totalTourCost;
                    bestSet = now_problem;
                    //print_vector(now_problem);
                    //cout << "bestSoFar updated" << endl;
                }
            }
            else if(lowerbound(n, now_problem, graph) < bestSoFar) {
                S.push(now_problem);
            }

            //now_problem[0] -= graph[lastNodeSoFar][newNodeToAdd];
            now_problem.pop_back();
        }
    }
    //cout << "bestSet size : " << bestSet.size() << endl;
    cout << "branch and bound : ";
    for(int i = 0; i < bestSet.size(); ++i)
        cout << bestSet[i] << " ";
    cout << endl << bestSoFar<< endl;
    return bestSoFar;
}
