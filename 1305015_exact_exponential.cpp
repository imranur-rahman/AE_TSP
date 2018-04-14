#include "1305015_exact_exponential.h"

float calculate_cost_of_this_permutation(int n, int now_configuration[], vector<vector<float> > &graph) {
    float total = 0.0;
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

float exact_exponential(int n, vector<vector<float> > &graph){
    int now_configuration[n];
    for(int i = 0; i < n; ++i)
        now_configuration[i] = i;

    int best_tour[n];
    float best_cost = numeric_limits<float>::max();

    do{
        float now_cost = calculate_cost_of_this_permutation(n, now_configuration, graph);
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
    return best_cost;
}
