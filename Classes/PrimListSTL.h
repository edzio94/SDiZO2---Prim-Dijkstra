//
// Created by lukasz on 5/8/16.
//
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
#ifndef SDIZO_PROJEKT2_PRIMLISTSTL_H
#define SDIZO_PROJEKT2_PRIMLISTSTL_H
typedef pair<int,int> intPair;

class PrimListSTL {
public:
    int size_v;
    list <pair<int,int>> * adj;

    PrimListSTL(int V);

    void addEdge (int u, int v, int w);

    void primMst();
    void printList();


};


#endif //SDIZO_PROJEKT2_PRIMLISTSTL_H
