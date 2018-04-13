//
// Created by sabit on 4/9/2018.
//

#ifndef AE_TSP_READ_INPUT_H
#define AE_TSP_READ_INPUT_H

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delim);
void print_vector(vector<vector<int> > &graph);
int read_input(string filename, vector<vector<int> > &graph);

#endif //AE_TSP_READ_INPUT_H
