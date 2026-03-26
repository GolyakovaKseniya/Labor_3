#pragma once

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <cctype>
#include <memory>

//FIX_ME: запрещено использовать using namespace std глобально 
//using namespace std;

// Структура для узлов дерева
//FIX_ME: неправильное положение фигурных скобок
struct TreeNode
{
    //FIX_ME: неправильное название полей структуры
    /*int value;
    TreeNode* left;
    TreeNode* right;*/
    int Value; // Для чисел или кодов операций
    TreeNode* Left;  // Левый дочерний узел
    TreeNode* Right; // Правый дочерний узел

    // Конструктор для узла
    //FIX_ME: неинформативное название параметра конструктора
    //TreeNode(int v) : Value(v)
    TreeNode(int InValue) : Value(InValue), Left(nullptr), Right(nullptr) {}
};

// Функция для построения дерева из префиксной записи
//FIX_ME: неправильное название функции
//FIX_ME: неинформативное название параметра функции
//TreeNode* buildTree(std::stack<TreeNode*>& st) 
TreeNode* BuildTree(std::stack<TreeNode*>& Stack);

// Функция для рекурсивного удаления дерева
//FIX_ME: отсутствовало удаление поддеревьев
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//void deleteTree(TreeNode* root) 
void DeleteTree(TreeNode* Root);

// Функция для преобразования дерева, удаляя операции сложения и вычитания
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//TreeNode* transformTree(TreeNode* root) 
TreeNode* TransformTree(TreeNode* Root);

// Функция для преобразования выражения в префиксной записи в дерево
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//TreeNode* parseExpression(const std::string& expression) 
TreeNode* ParseExpression(const std::string& Expression);

// Функция для вывода дерева в префиксной форме
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//void printTree(TreeNode* root)
void PrintTree(TreeNode* Root);

// Функция для вывода дерева с отступами (для наглядности)
//FIX_ME: добавлена функция для вывода дерева
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//void printTreeStructure(TreeNode* root, int level = 0)
void PrintTreeStructure(TreeNode* Root, int LevelTree = 0);

