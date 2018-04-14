//
// Created by sabit on 4/11/2018.
//

#include "1305015_Union_Find.h"

Union_Find::Union_Find(int n){
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        sz[i] = 1; // rank mean kore, or ei set er size
    }
}

int Union_Find::root(int i)
{
    while(i != parent[i])
    {
        parent[i] = parent[parent[i]];	//path Compression
        i = parent[i];
    }
    return i;
}
int Union_Find::find(int p, int q)
{
    return root(p)==root(q);
}
void Union_Find::unite(int p, int q)
{
    int i = root(p);
    int j = root(q);

    if(sz[i] < sz[j])
    {
        parent[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        parent[j] = i;
        sz[i] += sz[j];
    }
}

int Union_Find::numOfSets() {
    int cnt = 0;
    for(int i = 0; i < parent.size(); ++i)
        if(i != parent[i])
            cnt++;
    return cnt;
}
