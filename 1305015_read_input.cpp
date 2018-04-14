//
// Created by sabit on 4/9/2018.
//
#include "1305015_read_input.h"

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

void print_vector(vector<vector<int> > &graph) {
    cout << "printing vector" << endl;
    for(int i = 0; i < graph.size(); ++i) {
        for(int j = 0; j < graph[i].size(); ++j) {
            cout << i << " " << j << " " << graph[i][j] << endl;
        }
    }
}

void array_init(int **graph, int n) {
    graph = new int*[n];
    for(int i = 0; i < n; ++i)
        graph[i] = new int[n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            graph[i][j] = 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

float calculateDistance(float xi, float yi, float xj, float yj) {
    return sqrt((xi-xj)*(xi-xj) + (yi-yj)*(yi-yj));
}

int read_input(string filename, vector<vector<float> > &graph) {
    ifstream myfile (filename);
    string line;
    int n, m, weight;
    float x, y;
    if (myfile){
        myfile >> n >> m;
        graph.clear();
        graph.resize(n);
        for(int i = 0; i < n; ++i)
            graph[i].resize(n);
        //cout << n << " " << m << endl;
        /*while(myfile >> x >> y >> weight){
            //cout << x << " " << y << " " << weight << endl;
            //graph[x].push_back(make_pair(y, weight));
            graph[x][y] = weight;
        }*/
        float xid[n], yid[n];
        int node = 0;
        while(myfile >> x >> y) {
            xid[node] = x;
            yid[node] = y;
            node++;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                float dist = calculateDistance(xid[i], yid[i], xid[j], yid[j]);
                graph[i][j] = graph[j][i] = dist;
            }
        }
        for(int i = 0; i < n; ++i)
            graph[i][i] = numeric_limits<float>::max();
        //print_vector(graph);
        myfile.close();
    }
    else{
        cout << "unable to open file" << endl;
        return -1;
    }
    return 0;
}
