//
// Created by lukasz on 5/8/16.
//

#include "PrimListSTL.h"

PrimListSTL::PrimListSTL(int V) {
    this->size_v = V;
    adj = new list<intPair> [V];
}

void PrimListSTL::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void PrimListSTL::primMst() {
    priority_queue< intPair, vector <intPair>, greater<intPair>> pq;

    int src = 0 ; //Początkowy wierzchołem

    //Wektor dla kluczy i inicjacja jako nieskonczoność

    vector<int> key (size_v,INF);

    // To store parent array which in turn store MST
    vector<int> parent(size_v,-1);

    //Utrzymywanie rodzica
    vector <bool> inMST (size_v, false);


    pq.push(make_pair(0,src));
    key[src]=0;


    while (!pq.empty())
    {

        /*  Pierwszy wierzchołek w parze jest kluczem minimalnych
         * */

        int u  = pq.top().second;
        pq.pop();

        inMST[u] = true;    //Włączamy węzeł w MST

        //'i' jest użyte by mieć wszystkie adjacent vertices of a vertex

        list< pair<int,int>>:: iterator i;

        for ( i = adj[u].begin(); i != adj[u].end();++i)
        {
                //Bierzemy oznaczenie wierzchołkój dla indexu u
                int v = (*i).first;
                int weight = (*i).second;

            //Jeśli v nie jest w MST i waga (u,v) jest mniejsza od teraźniejszego klucza dla v
            if(inMST[v] == false && key[v] > weight)
            {
                //Update klucza dla v
                key[v] = weight;
                pq.push(make_pair(key[v],v));
                parent[v] = u;
            }
        }


    }


    //Drukowanie krawędzi mst za pomocą rodzica
    printf("Edge   Weight\n");
    int w = 0;
    for (int i = 1; i < size_v; ++i) {
        printf("%d - %d \t %d\n", parent[i], i, key[i]);
        w+= key[i];
    }
    printf("MST = %d\n",w);

}


void PrimListSTL::printList() {
    int w = 0;
    list<pair<int, int>>::iterator i;
    for(int u = 0 ; u < adj->size();u++) {

        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            cout <<u << " -> " <<(*i).first << " = " << (*i).second << endl;
            w+=(*i).second;
        }
    }
    printf("MST = %d \n",w);
}







