#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
//FIX_ME: «апрещено использовать using namespace std; глобально
//using namespace std;

//FIX_ME: добавлен вывод изначальной матрицы смежности
void PrintAdjacencyMatrix(const std::vector<std::vector<int>>& Matrix, int VertexCount);

//FIX_ME: вынесена логика с нахождением кратчайшего пути
std::vector<int> FindCitiesWithLayovers(
    const std::vector<std::vector<int>>& AdjacencyMatrix,
    int StartCity,
    int LayoversCount);

