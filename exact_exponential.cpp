#include "exact_exponential.h"

int calculate_cost_of_this_permutation(int n, int now_configuration[], vector<vector<int> > &graph) {
    int total = 0;
    for(int i = 1; i < n; ++i) {
        int x = now_configuration[i - 1];
        int y = now_configuration[i];

        total += graph[x][y];
    }

    //total cycle cost
    int start = now_configuration[0];
    int end = now_configuration[n - 1];

    return total + graph[end][start];
}

int exact_exponential(int n, vector<vector<int> > &graph){
    int now_configuration[n];
    for(int i = 0; i < n; ++i)
        now_configuration[i] = i;

    int best_tour[n];
    int best_cost = numeric_limits<int>::max();

    do{
        int now_cost = calculate_cost_of_this_permutation(n, now_configuration, graph);
        if(now_cost < best_cost) {
            best_cost = now_cost;
            copy(now_configuration, now_configuration + n, best_tour);
            //cout << "updated" << endl;
        }
    } while ( next_permutation(now_configuration, now_configuration + n) );

    cout << "exact exponential : ";
    for(int i = 0; i < n; ++i)
        cout << best_tour[i] << " ";
    cout << endl << best_cost << endl;
}
