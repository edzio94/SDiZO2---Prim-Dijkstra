//
// Created by lukasz on 5/8/16.
//

#ifndef SDIZO_PROJEKT2_DATAGENERATOR_H
#define SDIZO_PROJEKT2_DATAGENERATOR_H
#include <map>
#include <vector>
#include "PrimListSTL.h"
#include "Dijkstra_array.h"
#include "Prim.h"
#include "Djikstra_list_STL.h"

class DataGenerator {
    int nodes;
    int density;
public:
    int start_point;
    int end_point;
    int edges;
    std::vector<int> v_u;
    std::vector<int> v_v;
    std::vector<int> v_w;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;


public:
    void generateDataForMST(int v, int d);
    void generateDataForPath(int v, int d);
    unsigned long Newton( unsigned int n, unsigned int k);

    void loadFromTextFile(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim, Djikstra_list_STL &dijkstra_stl,bool choice,string tmp);
    void loadFromVectors(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim, Djikstra_list_STL &dijkstra_stl,bool choice);

    void measureTime(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim, Djikstra_list_STL &dijkstra_stl);

};


#endif //SDIZO_PROJEKT2_DATAGENERATOR_H
