//
// Created by lukasz on 5/8/16.
//

#include "DataGenerator.h"
#include "PrimListSTL.h"
#include "Dijkstra_array.h"
#include "Prim.h"
#include "Djikstra_list_STL.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

void DataGenerator::generateDataForMST(int v, int d) {
    v_v.clear();
    v_u.clear();
    v_w.clear();

    int vert = v;
    this->nodes = v;

    bool **check = new bool*[this->nodes];
    for (int i = 0 ; i < this->nodes;i++)
    {
        check[i] = new bool[this->nodes];
    }


    for (int i = 0; i < this->nodes; i++) {
        for (int j = 0; j < this->nodes; j++) {
            check[i][j] = false;
        }
    }







    bool build = false;
    int result = Newton(this->nodes, 2);

//    printf("result: %d \n", result);

    float percentage = (float) d / (float) 100;

//    printf("percentage = %f\n", percentage);

    int counter = edges = result * (float) percentage;

    if (edges < v - 1) {
     //   printf("Cannot build tree ");
        build = false;
    }
    else
        build = true;

    if (build) {
        srand(time(NULL));

        start_point = std::rand() % v;
        end_point = std::rand() % v;

        if (start_point > end_point)
            std::swap(start_point, end_point);
//        printf("========================\n");
//        printf("Number of edges: %d \n", edges);
//        printf("Start point: %d \n End point: %d \n", start_point, end_point);

        for (int i = 0; i < v - 1; i++) {
            int u = i;
            int v = i + 1;
            int w = rand() % 30 + 1;
            v_u.push_back(u);
            v_v.push_back(v);
            v_w.push_back(w);
            check[v][u] = check[u][v] = true;

       //     printf("%d -> %d = %d \n", u, v, w);

        }

        for (int i = 0; i < edges - (v - 1); ++i) {
            int u, v, w;
            do {
                    u = rand() % vert;
                    v = rand() % vert;
                    w = rand() % vert + 1;
                if (!check[u][v] && !check[v][u]) {
                    v_u.push_back(u);
                    v_v.push_back(v);
                    v_w.push_back(rand() % vert + 1);
                }
                else
                {
        //            printf("Already done [%d][%d]\n",u,v);
                }
            } while (u == v || check[u][v] || check[v][u]);
        //    printf("%d -> %d = %d \n", u, v, w);
            check[u][v] = check[v][u] = true;
        }
    }


}


unsigned long DataGenerator::Newton(unsigned int n, unsigned int k) {
    if (k == 0 || k == n)
        return 1;
    else {
        double result = 1;
        for (int i = 1; i <= k; i++) {
            result = result * (n - i + 1) / i;
        }
        return result;
    }
}

void DataGenerator::loadFromTextFile(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim,
                                     Djikstra_list_STL &dijkstra_stl, bool choice,string tmp) {
    fstream file;
    file.open(tmp, std::ios_base::in);
    if(file.good()) {
        int edges, vert, start_point, end_point, q;

        file >> edges;
        file >> vert;
        file >> start_point;
        file >> end_point;
        printf("Edges: %d\n",edges);
        printf("Vert: %d\n",vert);
        printf("start_point: %d\n",start_point)
        printf("end_point: %d\n",end_point);

        if (!choice) {
            stl = PrimListSTL(vert);
            prim = Prim(vert);
        }
        else {
            dijkstra_stl = Djikstra_list_STL(vert, start_point);
            dijkstra_array = Dijkstra_array(start_point, end_point, vert);
        }
        //TODO: END POINT FOR STL

        int tmp1, tmp2, tmp3;
        while (!file.eof()) {
            file >> tmp1;
            file >> tmp2;
            file >> tmp3;
            printf("%d -> %d = %d\n", tmp1, tmp2, tmp3);

            if (!choice) {
                stl.addEdge(tmp1, tmp2, tmp3);
                prim.add(tmp1, tmp2, tmp3);
            }
            else {
                dijkstra_array.add(tmp1, tmp2, tmp3);
                dijkstra_stl.addEdge(tmp1, tmp2, tmp3);
            }
        }
    }
    else{
        printf("Cannot open a file! \n");
    }

}

void DataGenerator::loadFromVectors(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim,
                                    Djikstra_list_STL &dijkstra_stl, bool choice) {


    if (!choice) {
//        printf("\nNodes: %d", this->nodes);
        stl = PrimListSTL(this->nodes);
        prim = Prim(this->nodes);
    }

    else {
        dijkstra_stl = Djikstra_list_STL(nodes, start_point);
        dijkstra_array = Dijkstra_array(start_point, end_point, nodes);
    }

    for (int i = 0; i < v_v.size(); i++) {
        if (!choice) {

                stl.addEdge(v_u[i], v_v[i], v_w[i]);
                prim.add(v_u[i], v_v[i], v_w[i]);

        }
        else {
                dijkstra_array.add(v_u[i], v_v[i], v_w[i]);
                dijkstra_stl.addEdge(v_u[i], v_v[i], v_w[i]);
        }

    }

}

void DataGenerator::generateDataForPath(int v, int d) {
    v_v.clear();
    v_u.clear();
    v_w.clear();

    int vert = v;

    this->nodes = v;

    bool **check = new bool*[this->nodes];
    for (int i = 0 ; i < this->nodes;i++)
    {
        check[i] = new bool[this->nodes];
    }


    for (int i = 0; i < this->nodes; i++) {
        for (int j = 0; j < this->nodes; j++) {
            check[i][j] = false;
        }
    }


    printf("\nNodes: %d", this->nodes);

    bool build = false;
    int result = vert * (vert - 1);

    printf("result: %d \n", result);

    float percentage = (float) d / (float) 100;

    printf("percentage = %f\n", percentage);

    int counter = edges = result * (float) percentage;

    if (edges < v - 1) {
        printf("Cannot build tree ");
        build = false;
    }
    else
        build = true;

    if (build) {
        srand(time(NULL));

        start_point = std::rand() % v;
        end_point = std::rand() % v;

        if (start_point > end_point)
            std::swap(start_point, end_point);
        printf("========================\n");
        printf("Number of edges: %d \n", edges);
        printf("Start point: %d \n End point: %d \n", start_point, end_point);

        for (int i = 0; i < v - 1; i++) {
            int u = i;
            int v = i + 1;
            int w = rand() % v + 1;
            v_u.push_back(u);
            v_v.push_back(v);
            v_w.push_back(w);
            check[u][v] = true;

            printf("%d -> %d = %d \n", u, v, w);

        }

        for (int i = 0; i < edges - (v - 1); ++i) {
            int u, v, w;
            do {
                u = rand() % vert;
                v = rand() % vert;
                w = rand() % 30 + 1;

                if(!check[u][v] && u != v) {
                    v_u.push_back(u);
                    v_v.push_back(v);
                    v_w.push_back(rand() % vert);
                }
                else
                {
                    printf("Already done [%d][%d]\n",u,v);
                }
            } while (u == v || check[u][v]);
            check[u][v] = true;
            printf("%d -> %d = %d \n", u, v, w);
        }
    }


}

void DataGenerator::measureTime(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim,
                                Djikstra_list_STL &dijkstra_stl) {

     start = std::chrono::system_clock::now();

    int counter = 10;

    for (int i = 0; i < 100; i++)
    {

        printf("Data for %d number \n",i);
        generateDataForMST(counter,25);
        loadFromVectors(stl,dijkstra_array,prim,dijkstra_stl,false);
        stl.primMst();

        counter++;
    }

     end = std::chrono::system_clock::now();

     elapsed_seconds = end - start;
    std::cout << "[PrimSTLList] operation time [25 d]: " << elapsed_seconds.count() << "s \n";


    /*======================================================================*/
    start = std::chrono::system_clock::now();

    counter = 10;

    for (int i = 0; i < 100; i++)
    {

        printf("Data for %d number \n",i);
        generateDataForMST(counter,50);
        loadFromVectors(stl,dijkstra_array,prim,dijkstra_stl,false);
        stl.primMst();

        counter++;
    }

    end = std::chrono::system_clock::now();

    elapsed_seconds = end - start;
    std::cout << "[PrimSTLList] operation time [50d]: " << elapsed_seconds.count() << "s \n";

    /*======================================================================*/
    start = std::chrono::system_clock::now();

    counter = 10;

    for (int i = 0; i < 100; i++)
    {

        printf("Data for %d number \n",i);
        generateDataForMST(counter,75);
        loadFromVectors(stl,dijkstra_array,prim,dijkstra_stl,false);
        stl.primMst();

        counter++;
    }

    end = std::chrono::system_clock::now();

    elapsed_seconds = end - start;
    std::cout << "[PrimSTLList] operation time [75d]: " << elapsed_seconds.count() << "s \n";

    /*======================================================================*/
    start = std::chrono::system_clock::now();

    counter = 10;

    for (int i = 0; i < 100; i++)
    {

        printf("Data for %d number \n",i);
        generateDataForMST(counter,99);
        loadFromVectors(stl,dijkstra_array,prim,dijkstra_stl,false);
        stl.primMst();


        counter++;
    }

    end = std::chrono::system_clock::now();

    elapsed_seconds = end - start;
    std::cout << "[PrimSTLList] operation time [99d]: " << elapsed_seconds.count() << "s \n";

}











