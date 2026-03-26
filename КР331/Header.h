#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

//FIX_ME: вынесена логика поиска кратчайшего пути с пересадками
std::vector<int> FindShortestPath(const std::vector<std::vector<int>>& Matrix, int StartVertexIndex);

//FIX_ME: вынесена логика чтения матрицы из файла
std::vector<std::vector<int>> ReadGraphFromFile(const std::string& FileName, int& CountCity);

//FIX_ME: добавлен вывод исходной матрицы
void PrintAdjacencyMatrix(const std::vector<std::vector<int>>& Matrix, int VertexCount);

