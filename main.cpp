#include <iostream>
#include <fstream>
#include "Classes/Prim.h"
#include "Classes/PrimListSTL.h"
#include "Classes/Dijkstra_array.h"
#include "Classes/Djikstra_list_STL.h"
#include "Classes/DataGenerator.h"
#include "Classes/Menu.h"

using namespace std;

void loadFromTextFile(PrimListSTL &stl,Dijkstra_array &dijkstra_array, Prim &prim, Djikstra_list_STL &dijkstra_stl);

int main() {
//      Djikstra_list_STL dijkstra_stl(NULL,NULL);
//         Prim prim = NULL;
//           PrimListSTL primListSTL= NULL;
//        Dijkstra_array dijkstra_array(NULL,NULL,NULL);
//
//        DataGenerator dataGenerator;
//
//        //dataGenerator.generateData(100,75);
//
//        //for(int i = 0 ; i < dataGenerator.v_u.size();i++)
//        //{
//
//        //}
//
//    loadFromTextFile(primListSTL,dijkstra_array,prim,dijkstra_stl);
//
//       // primListSTL.primMst();
//        dijkstra_array.dijkstra(0);
//        printf("\n");
//       // prim.primMST();
//        printf("\n");
//        dijkstra_stl.ShortestPath(dijkstra_stl.src);

    Menu menu;

    menu.showMenu1();
   // DataGenerator dataGenerator;
   // dataGenerator.measureTime(primListSTL,dijkstra_array,prim,dijkstra_stl);



return 0;
}


void loadFromTextFile(PrimListSTL &stl, Dijkstra_array &dijkstra_array, Prim &prim, Djikstra_list_STL &dijkstra_stl)
{
    fstream file;
    file.open("textFile.txt", std::ios_base::in);
    int edges,vert,start_point,end_point,q;

    file >> edges;
    file >> vert;
    file >> start_point;
    file >> end_point;
    printf("%d.%d.%d.%d,%d\n",edges,vert,start_point,end_point,q);
    stl = PrimListSTL(vert);
    dijkstra_array = Dijkstra_array(start_point,end_point,vert);
    prim = Prim(vert);
    //TODO: END POINT FOR STL
    dijkstra_stl = Djikstra_list_STL(vert,start_point);
    int tmp1,tmp2,tmp3;
    while(!file.eof())
    {
        file >> tmp1;
        file >> tmp2;
        file >> tmp3;
        printf("%d | %d | %d\n",tmp1,tmp2,tmp3);
        stl.addEdge(tmp1,tmp2,tmp3);
        dijkstra_array.add(tmp1,tmp2,tmp3);
        prim.add(tmp1,tmp2,tmp3);
        dijkstra_stl.addEdge(tmp1,tmp2,tmp3);
    }




}