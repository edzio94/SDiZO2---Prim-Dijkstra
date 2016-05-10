//
// Created by lukasz on 5/7/16.
//

#include <climits>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include "Dijkstra_array.h"

Dijkstra_array::Dijkstra_array(int start, int end,int size) {

    this->size = size;

    graph = new int* [size];

    for (int i = 0 ; i < size; ++i){
        graph[i] = new int [size];
        for(int j = 0 ; j < size;++j)
        {
            graph[i][j] = 0;
        }
    }



    this->srce_point = start;
    this->dst_point = end;


}

void Dijkstra_array::dijkstra(int src) {
    int dist [size];
    bool sptSet[size];

    int parent[size];

    for (int i = 0 ; i < size; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
        //parent[i] = -1;
        parent[this->srce_point] = -1;
    }

    dist[this->srce_point] = 0;

    for (int count = 0 ; count < size-1; count++)
    {
        int u = minDistance(dist,sptSet);

        sptSet[u] = true;

        for (int v = 0; v < size;v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v]) {


                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist,size,parent);

}
// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

int Dijkstra_array::printSolution(int dist[], int n, int parent[])
{
   // int src =this->srce_point ;
    int src = this->srce_point;
   // printf("Vertex\t  Distance\tPath");
    printf("\n End\t Dist\t Path");
    for (int i = src; i < size; i++)
    {
      //  printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printf("\n %d \t    | %d\t   | %d ",i,dist[i],src);
        printPath(parent, i);
    }
}



int Dijkstra_array::minDistance(int *dist, bool *sptSet) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void Dijkstra_array::add(int u, int v, int w) {
    graph[u][v] = w;

}

void Dijkstra_array::printArray() {

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










