#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//FIX_ME: запрещено использовать using namespace std; глобально 
//using namespace std;

//FIX_ME: неправильное положение фигурной скобки
// Структура узла дерева
struct TreeNode
{
    //FIX_ME: неправильное название полей структуры
    /*int value;
    TreeNode* left;
    TreeNode* right;*/
    int Value;
    TreeNode* Left;
    TreeNode* Right;

    //FIX_ME: неинформативное название параметра конструктора
    //TreeNode(int val) : value(val)
    TreeNode(int InValue) : Value(InValue), Left(nullptr), Right(nullptr) {}
};

// Коды операций
//FIX_ME: неправильное название констант
/*const int ADD = -1;
const int SUB = -2;
const int MUL = -3;
const int DIV = -4;*/
const int kAdd = -1;
const int kSub = -2;
const int kMul = -3;
const int kDiv = -4;

//FIX_ME: неинформативное название параметра функции
//bool IsOperation(int val) 
bool IsOperation(int InValue);

//FIX_ME: неинформативное название параметра функции
//bool IsAddOrSub(int val)
bool IsAddOrSub(int InValue);

//FIX_ME: неинформативное название параметров функции
//int Calculate(int op, int leftVal, int rightVal) 
int Calculate(int InOperation, int LeftValue, int RightValue);

//FIX_ME: неправильное название параметра функции
//void DeleteTree(TreeNode* root) 
void DeleteTree(TreeNode* Root);

// ГЛАВНАЯ ФУНКЦИЯ: рекурсивно упрощаем дерево
//FIX_ME: неправильное название параметра функции
//TreeNode* SimplifyTree(TreeNode* root) 
TreeNode* SimplifyTree(TreeNode* Root);

// Функция для удаления сложения и вычитания (вызывает SimplifyTree несколько раз)
//FIX_ME: неправильное название параметра функции
//TreeNode* RemoveAddSub(TreeNode* root);
TreeNode* RemoveAddSub(TreeNode* Root);

// Построение дерева из потока токенов
//FIX_ME: неинформативное название параметров функции
//TreeNode* BuildTree(std::vector<std::string>& tokens, size_t& pos) 
TreeNode* BuildTree(std::vector<std::string>& Tokens, size_t& Position);

// Функция для вывода дерева
//FIX_ME: неправильное название параметра функции
//void PrintTree(TreeNode* root, int level = 0) 
void PrintTree(TreeNode* Root, int Level = 0);

//FIX_ME: неправильное название параметра функции
//void PrintPrefix(TreeNode* root) 
void PrintPrefix(TreeNode* Root);

//FIX_ME: неправильное название параметра функции
//void PrintRootPointer(TreeNode* root) 
void PrintRootPointer(TreeNode* Root);

// Функция для проверки, есть ли в дереве операции сложения/вычитания
//FIX_ME: неправильное название параметра функции
//bool HasAddOrSub(TreeNode* root) 
bool HasAddOrSub(TreeNode* Root);

