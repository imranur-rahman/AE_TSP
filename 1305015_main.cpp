#include <iostream>
#include "1305015_input_generator.h"
#include "1305015_read_input.h"
#include "1305015_exact_exponential.h"
#include "1305015_greedy_approximation.h"
#include "1305015_branch_and_bound.h"

using namespace std;

//numOfNodes is defined in read_input.h

vector<vector<float> >graph;
string filename = "1305015_input.txt";
int maxNodes = 10;

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
    output.open("1305015_output.csv");
    output << "Nodes,ExactExpo,BranchBound,GreedyAppro,ApproRatioGreedy,ApproRatioBB\n";
    for(int nodes = 3; nodes <= maxNodes; ++nodes) {
        cout << "Nodes : " << nodes << endl;
        generate_input_file(filename, nodes);

        read_input(filename, graph);

        t = clock();
        float h1 = exact_exponential(graph.size(), graph);
        t1 = ((float)(clock() - t) / CLOCKS_PER_SEC);

        read_input(filename, graph);

        t = clock();
        float h2 = branch_and_bound(graph.size(), graph);
        t2 = ((float)(clock() - t) / CLOCKS_PER_SEC);

        read_input(filename, graph);

        t = clock();
        float h3 = greedy_approximation(graph.size(), graph);
        t3 = ((float)(clock() - t) / CLOCKS_PER_SEC);

        output << nodes << "," << t1 << "," << t2 << "," << t3 << "," << h3/h1 << "," << h2/h1 << "\n";
        cout << "\n\n";
    }
    output.close();
    return 0;
}
