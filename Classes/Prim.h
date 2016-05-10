//
// Created by lukasz on 4/19/16.
//

#ifndef SDIZO_PROJEKT2_PRIM_H
#define SDIZO_PROJEKT2_PRIM_H
#

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>

//const int size = 5;
class Prim {
public:
        int size;
        int ** graph;

    Prim(int size);
    int minKey(int key[], bool mstSet[]);



    int printMST(int parent[], int n);
    void add(int u, int v, int w);
    void printArray();
    void primMST();

};



#endif //SDIZO_PROJEKT2_PRIM_H
