#include <iostream>
#include "input_generator.h"
#include "read_input.h"
#include "exact_exponential.h"
#include "greedy_approximation.h"

using namespace std;

//numOfNodes is defined in read_input.h

vector<vector<int> >graph;
string filename = "input.txt";

void calculate_time() {
    //Time calculation Start
    clock_t t;
    t = clock();
    ////////////////////////

    // main work

    //Time calculation End
    t = clock() - t;
    printf ("It took %f second(s).\n",((float)t)/CLOCKS_PER_SEC);
    ////////////////////////
}

int main(int argc, char * argv[]) {
    generate_input_file(filename, numOfNodes);
    read_input(filename, graph);
    //exact_exponential(graph.size(), graph);
    greedy_approximation(graph.size(), graph);
    return 0;
}