#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <memory>

//FIX_ME: запрещено использовать локально
//using namespace std;

const int kMinOperation = -4;
const int kMaxOperation = -1;

// Структура узла дерева
//FIX_ME: неправильное положение фигурных скобок
struct TreeNode
{
    //FIX_ME: неправильное название полей структуры
    //int value;          // значение: -1..-4 для операций, 0..9 для чисел
    //shared_ptr<TreeNode> left;
    //shared_ptr<TreeNode> right;
    int Value;          // значение: -1..-4 для операций, 0..9 для чисел
    std::shared_ptr<TreeNode> Left;
    std::shared_ptr<TreeNode> Right;

    //FIX_ME: неинформативное название параметра конструктора
    TreeNode(int InValue) : Value(InValue), Left(nullptr), Right(nullptr) {}
};

// Функция для построения дерева из префиксного выражения
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//std::shared_ptr<TreeNode> buildTree(const std::vector<int>& tokens, int& index) 
std::shared_ptr<TreeNode> BuildTree(const std::vector<int>& Tokens, int& Index);

// Функция для вычисления значения поддерева
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//int evaluate(TreeNode* root) 
int Evaluate(TreeNode* Root);

// Функция для замены поддеревьев со сложением/вычитанием на их значения
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//std::shared_ptr<TreeNode> simplifyTree(std::shared_ptr<TreeNode> root) 
std::shared_ptr<TreeNode> SimplifyTree(std::shared_ptr<TreeNode> Root);

// Функция для вывода дерева (для отладки)
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//void printTree(TreeNode* root, int depth = 0) 
void PrintTree(TreeNode* Root, int DepthTree = 0);

