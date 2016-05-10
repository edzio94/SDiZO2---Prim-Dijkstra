//
// Created by lukasz on 5/8/16.
//

#include "Menu.h"

void Menu::showMenu1() {
for(;;) {
    printf("\n 1.Problem MST \n"
                   "2. Problem najkrótszej drogi\n"
                   "3. Wyjdź z programu\n");
    cin >> decision;

    switch (decision) {
        case 1: {
            showMenuMST();
            break;
        }
        case 2: {
            showMenuPath();

            break;
        }
        case 3: {
            exit(0);

        }
        default: {
            showMenu1();
            break;
        }
    }
}

}
void Menu::showMenuMST() {

    printf("\n 1. Wczytaj graf z pliku \n"
                   "2. Wygeneruj graf losowo \n"
                   "3. Wyświetl graf macierzowo i listowo \n"
                   "4. Wyświetlenie wyników macierzowo i listowo \n"
                   "5. Wróć \n");
    cin >> decision;

    switch(decision)
    {
        case 1:
        {
            string tmp;
            printf("Podaj ścieżke do pliku: ");
            cin >> tmp;
            dataGenerator.loadFromTextFile(primListSTL,dijkstra_array,prim,dijkstra_stl,false,tmp);
            break;
        }
        case 2:
        {
            int v, d;
            printf("\n Podaj ilość węzłóœ: ");
            cin >> v;
            printf("\n Podaj gęstość: ");
            cin >> d;
            dataGenerator.generateDataForMST(v,d);
            dataGenerator.loadFromVectors(primListSTL,dijkstra_array,prim,dijkstra_stl,false);
            break;
        }
        case 3:
        {

            prim.printArray();
            printf("=============\n");
            primListSTL.printList();
            break;
        }
        case 4:
        {
            prim.primMST();
            printf("=======\n");
            primListSTL.primMst();
        }
        case 5:{
           // showMenu1();
            break;
        }

    }


}
void Menu::showMenuPath() {

        printf("\n 1. Wczytaj graf z pliku \n"
                       "2. Wygeneruj graf losowo \n"
                       "3. Wyświetl graf macierzowo i listowo \n"
                       "4. Wyświetlenie wyników macierzowo i listowo \n"
                       "5. Wróć \n");

        cin >> decision;

        switch (decision) {
            case 1: {
                string tmp;
                printf("Podaj ścieżke do pliku: ");
                cin >> tmp;
                dataGenerator.loadFromTextFile(primListSTL, dijkstra_array, prim, dijkstra_stl, true,tmp);
                break;
            }
            case 2: {
                int v, d;
                printf("\n Podaj ilość węzłóœ: ");
                cin >> v;
                printf("\n Podaj gęstość: ");
                cin >> d;
                dataGenerator.generateDataForPath(v, d);
                dataGenerator.loadFromVectors(primListSTL, dijkstra_array, prim, dijkstra_stl, true);
                break;
            }
            case 3: {
                printf("PRINTING DATA FOR DIJKSTRA\n");
                dijkstra_array.printArray();
                printf("===========\n");
                dijkstra_stl.printList();

                break;
            }
            case 4: {
               dijkstra_array.dijkstra(dijkstra_array.srce_point);
                dijkstra_stl.ShortestPath(dijkstra_stl.src);
                break;
            }
            case 5: {
              //  showMenu1();
                break;
            }

        }




}

Menu::Menu() {

}



