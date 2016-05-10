//
// Created by lukasz on 5/8/16.
//

#include "Djikstra_list_STL.h"
#include "PrimListSTL.h"

using namespace std;


void Djikstra_list_STL::addEdge(int u, int v, int w) {
    adj[u].push_back(std::make_pair(v,w));
}

void Djikstra_list_STL::ShortestPath(int src) {

    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, int> > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(size_v, INF);

    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));


    int parent[size_v];

    for (int i = 0; i < size_v; i++) {
        parent[i] = -1;
    }

    dist[src] = 0;


    /*
     * Pętla dopóki wszystkie dystanse są sfinalizowane
     *  setd stanie się wtedyu pusty
     * */
    while (!setds.empty())
    {

        //
        // pierwszy wierzchołek w secie jest namniejsym dystanem/
        // wierzochołek wyciągnety z seta
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        //etykieta wierzchołka trzymana jest tako drugoi argument
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        // iteratora używamy bo wyciągnąc sąsiadujące wierzchłoki
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
        // Wyciąganie wartości
            int v = (*i).first;
            int weight = (*i).second;

            //Sprawdzenie, czy ścieżka jest krótsza
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                parent[v]  = u;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
 /*   printf("Vertex   Distance from Source\n");
    for (int i = 0; i < size_v; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

*/
    printSolution(dist, size_v, parent);

}

Djikstra_list_STL::Djikstra_list_STL(int V, int src) {
    this->size_v = V;


    adj = new list<intPair> [this->size_v];

    this->src = src;
}

int Djikstra_list_STL::printSolution(vector<int> dist, int n, int *parent) {


        int src = this->src;

        printf("\n End\t Dist\t Path");
        for (int i = src; i < size_v; i++)
        {

            printf("\n %d \t    | %d\t   | %d ",i,dist[i],src);
            printPath(parent, i);
        }

}

void Djikstra_list_STL::printPath(int *parent, int j) {

    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

void Djikstra_list_STL::printList() {


    // iterator do przechodzenia po wartościach
    list<pair<int, int>>::iterator i;
    for(int u = 0 ; u < this->size_v;u++) {
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {

            cout <<u << " -> " <<(*i).first << " = " << (*i).second << endl;
        }

    }
}
















