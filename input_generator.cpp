#include "input_generator.h"

#define maxWeightOfEdge 100

int generate_input_file(string filename, int n){
    srand(time(NULL));
    ofstream fout;
    fout.open(filename);

    if(fout.is_open() == false) {
        cout << "could not open file for creating test case" << endl;
        return -1;
    }

    int m;
    m = n*n;
    fout << n << " " << m << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j){
                fout << i << " " << j << " " << numeric_limits<int>::max() << endl;
            }
            else if(i < j){
                int weight = (rand() % maxWeightOfEdge) + 1;
                fout << i << " " << j << " " << weight << endl;
                fout << j << " " << i << " " << weight << endl;
            }
        }
    }
    fout.close();
    return 0;
}
