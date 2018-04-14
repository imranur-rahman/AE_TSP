#include "1305015_input_generator.h"

#define maxWeightOfEdge 100
#define LO -100.00
#define HI 100.00

int generate_input_file(string filename, int n){
    //srand(time(NULL));
    srand (static_cast <unsigned> (time(0)));
    ofstream fout;
    fout.open(filename);

    if(fout.is_open() == false) {
        cout << "could not open file for creating test case" << endl;
        return -1;
    }

    int m;
    m = n*n;
    fout << n << " " << m << endl;
    /*for(int i = 0; i < n; ++i){
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
    }*/
    for(int i = 0; i < n; ++i) {
        float x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        float y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        fout << x << " " << y << endl;
    }
    fout.close();
    return 0;
}
