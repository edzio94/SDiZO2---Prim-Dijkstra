//
// Created by lukasz on 4/19/16.
//

#include <iomanip>
#include <iostream>
#include "Prim.h"

int Prim::minKey(int *key, bool *mstSet)     {
    //Inicjacja minimalną wartością
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;

}

int Prim::printMST(int *parent, int n)    {
    int w = 0;
        printf("Edge   Weight\n");
        for (int i = 1; i < size; i++) {
            printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
            w += graph[i][parent[i]];
        }

        printf("MST = %d\n",w);
    }

void Prim::primMST()  {
    int parent[size];
    int key[size];
    bool mstSet[size];

    //Init keys as infinite
    for (int i = 0 ; i < size ;i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0]  = -1;

    //The MST will have V vertices
    for (int count = 0 ; count < size - 1;count++) {

        int u = minKey(key, mstSet);


        mstSet[u] = true;

        for (int v = 0 ; v< size; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }

    printMST(parent,size);
}

Prim::Prim(int size) {
    this->size = size;

    graph = new int* [size];

    for (int i = 0 ; i < size; ++i){
        graph[i] = new int [size];
        for(int j = 0 ; j < size;++j)
        {
            graph[i][j] = 0;
        }
    }
}

void Prim::add(int u, int v, int w) {
    graph[u][v] = graph[v][u] = w;
}

void Prim::printArray() {
    std::cout << std::setw(5);
for (int i = 0 ; i < this->size;++i)
{
    for (int j = 0 ; j < this->size;++j)
    {
        std::cout << "|" <<std::setw(5) << graph[i][j] << std::setw(5) ;
    }
    printf("\n");
}


}







