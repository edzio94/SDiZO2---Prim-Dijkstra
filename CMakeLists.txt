cmake_minimum_required(VERSION 3.4)
project(SDiZO_Projekt2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Classes/Prim.cpp Classes/Prim.h Classes/Dijkstra_array.cpp Classes/Dijkstra_array.h Classes/Djikstra_list_STL.cpp Classes/Djikstra_list_STL.h Classes/PrimListSTL.cpp Classes/PrimListSTL.h Classes/DataGenerator.cpp Classes/DataGenerator.h Classes/Menu.cpp Classes/Menu.cpp Classes/Menu.h)
add_executable(SDiZO_Projekt2 ${SOURCE_FILES})