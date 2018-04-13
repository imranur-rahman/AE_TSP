cmake_minimum_required(VERSION 3.10)
project(AE_TSP)

set(CMAKE_CXX_STANDARD 11)

add_executable(AE_TSP main.cpp exact_exponential.cpp branch_and_bound.cpp input_generator.cpp input_generator.h read_input.h read_input.cpp exact_exponential.h branch_and_bound.h greedy_approximation.h greedy_approximation.cpp Union_Find.cpp Union_Find.h Kruskal.cpp Kruskal.h)