//
// Created by lukasz on 5/8/16.
//

#ifndef SDIZO_PROJEKT2_MENU_H
#define SDIZO_PROJEKT2_MENU_H


#include "Djikstra_list_STL.h"
#include "Prim.h"
#include "PrimListSTL.h"
#include "Dijkstra_array.h"
#include "DataGenerator.h"

class Menu {

    Djikstra_list_STL dijkstra_stl = Djikstra_list_STL(2, 2);
    Prim prim = Prim(2);
    PrimListSTL primListSTL = PrimListSTL(2);
    Dijkstra_array dijkstra_array = Dijkstra_array(2, 2, 2);

    DataGenerator dataGenerator;

public:
    Menu();
    int decision;

    void showMenu1();
    void showMenuMST();
    void showMenuPath();


};


#endif //SDIZO_PROJEKT2_MENU_H
