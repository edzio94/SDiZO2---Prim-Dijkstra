//
// Created by lukasz on 5/8/16.
//

#ifndef SDIZO_PROJEKT2_DJIKSTRA_LIST_STL_H
#define SDIZO_PROJEKT2_DJIKSTRA_LIST_STL_H
#include<bits/stdc++.h>
# define INF 0x3f3f3f3f

class Djikstra_list_STL {
public:
    int size_v;
    int src;

    std::list<std::pair<int,int>> * adj;

public:
    Djikstra_list_STL(int V,int src);
    void addEdge(int u , int v, int w);

    void ShortestPath(int s);

    int printSolution(std::vector<int> dist, int n, int parent[]);

    void printPath(int parent[], int j);

    void printList();


};


#endif //SDIZO_PROJEKT2_DJIKSTRA_LIST_STL_H
