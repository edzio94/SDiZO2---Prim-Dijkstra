//
// Created by lukasz on 5/7/16.
//

#ifndef SDIZO_PROJEKT2_DJIKSTRA_ARRAY_H
#define SDIZO_PROJEKT2_DJIKSTRA_ARRAY_H


class Dijkstra_array {
public:
    int ** graph;
    int size;
    int srce_point;
    int dst_point;

    void dijkstra(int src);

    int minDistance(int dist[], bool sptSet[]);

    int printSolution(int dist[], int n, int parent[]);

    void add(int u ,int v,int w);

    void printArray();


    Dijkstra_array(int start, int end,int size);
};


#endif //SDIZO_PROJEKT2_DJIKSTRA_ARRAY_H
