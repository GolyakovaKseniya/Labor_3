#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

//FIX_ME: запрещено использовать using namespace std; глобально
//using namespace std;

// Функция для чтения матрицы смежности из файла
//FIX_ME: вынесена логика чтения матрицы из файла
std::vector<std::vector<int>> ReadGraphFromFile(const std::string& FileName, int& CountCity);

// Функция для вывода матрицы смежности
//FIX_ME: добавлена функция вывода матрицы смежности
void PrintAdjacencyMatrix(const std::vector<std::vector<int>>& Matrix);

// Функция для поиска кратчайших расстояний с помощью BFS
//FIX_ME: вынесена логика поиска кратчайшего пути
std::vector<int> FindShortestDistances(const std::vector<std::vector<int>>& Matrix, int StartCity);

