#include <iostream>
#include "input_generator.h"
#include "read_input.h"
#include "exact_exponential.h"
#include "greedy_approximation.h"
#include "branch_and_bound.h"

using namespace std;

//numOfNodes is defined in read_input.h

vector<vector<int> >graph;
string filename = "input.txt";
int maxNodes = 9;

int main(int argc, char * argv[]) {
    /*int nodes = 8;
    generate_input_file(filename, nodes);
    read_input(filename, graph);
    exact_exponential(graph.size(), graph);
    branch_and_bound(graph.size(), graph);
    greedy_approximation(graph.size(), graph);*/
    clock_t t;
    float t1, t2, t3;
    ofstream output;
    output.open("output.csv");
    output << "Nodes,ExactExpo,BranchBound,GreedyAppro\n";
    for(int nodes = 3; nodes <= maxNodes; ++nodes) {
        cout << "Nodes : " << nodes << endl;
        generate_input_file(filename, nodes);

        read_input(filename, graph);

        t = clock();
        exact_exponential(graph.size(), graph);
        t1 = ((float)(clock() - t) / CLOCKS_PER_SEC);

        read_input(filename, graph);

        t = clock();
        branch_and_bound(graph.size(), graph);
        t2 = ((float)(clock() - t) / CLOCKS_PER_SEC);

        read_input(filename, graph);

        t = clock();
        greedy_approximation(graph.size(), graph);
        t3 = ((float)(clock() - t) / CLOCKS_PER_SEC);

        output << nodes << "," << t1 << "," << t2 << "," << t3 << "\n";
        cout << "\n\n";
    }
    output.close();
    return 0;
}
