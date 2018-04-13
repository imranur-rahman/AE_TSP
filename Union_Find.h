//
// Created by sabit on 4/11/2018.
//

#ifndef AE_TSP_UNION_FIND_H
#define AE_TSP_UNION_FIND_H

#include <vector>

using namespace std;

class Union_Find {
private:
    vector<int>parent, sz;
public:
    Union_Find(int n);
    int root(int i);
    int find(int p, int q);
    void unite(int p, int q);
    int numOfSets();
};


#endif //AE_TSP_UNION_FIND_H
