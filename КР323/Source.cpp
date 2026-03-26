#include "Header.h"

bool IsValidNumber(int InValue)
{
    return (InValue >= 0 && InValue <= 9);
}

bool IsValidOperation(int InValue)
{
    return (InValue >= kMinOperation && InValue <= kMaxOperation);
}

// Функция для построения дерева из префиксного выражения
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//std::shared_ptr<TreeNode> buildTree(const std::vector<int>& tokens, int& index) 
std::shared_ptr<TreeNode> BuildTree(const std::vector<int>& Tokens, int& Index)
{
    using namespace std;

    //FIX_ME: цикл if используется без фигурных скобок
    if (Index >= Tokens.size())
    {
        return nullptr;
    }

    //FIX_ME: неправильное название переменных
    /*int val = Tokens[Index++];
    auto node = make_shared<TreeNode>(val);*/
    int Value = Tokens[Index++];

    if (!IsValidOperation(Value) && !IsValidNumber(Value))
    {
        std::cout << "Ошибка: некорректное значение токена: " << Value << std::endl;
        return nullptr;
    }
    auto Node = make_shared<TreeNode>(Value);

    // Если это операция (отрицательное число), то у неё есть два операнда
    /*if (Value < 0)
    {
        Node->Left = BuildTree(Tokens, Index);
        Node->Right = BuildTree(Tokens, Index);
    }*/
    if (IsValidOperation(Value))
    {
        // Проверяем, что осталось достаточно токенов для операндов
        if (Index >= static_cast<int>(Tokens.size()))
        {
            std::cout << "Ошибка: недостаточно токенов для операндов операции" << std::endl;
            return nullptr;
        }

        Node->Left = BuildTree(Tokens, Index);
        if (!Node->Left)
        {
            std::cout << "Ошибка: не удалось построить левое поддерево" << std::endl;
            return nullptr;
        }

        Node->Right = BuildTree(Tokens, Index);
        if (!Node->Right)
        {
            std::cout << "Ошибка: не удалось построить правое поддерево" << std::endl;
            return nullptr;
        }
    }

    return Node;
}

// Функция для вычисления значения поддерева
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//int evaluate(TreeNode* root) 
int Evaluate(TreeNode* Root)
{
    //FIX_ME: цикл if используется без фигурных скобок
    if (!Root)
    {
        return 0;
    }
    // Если это число (0..9)
    if (Root->Value >= 0)
    {
        return Root->Value;
    }

    //FIX_ME: неправильное название переменных
    /*int leftVal = Evaluate(Root->Left.get());
    int rightVal = Evaluate(Root->Right.get());*/
    int LeftValue = Evaluate(Root->Left.get());
    int RightValue = Evaluate(Root->Right.get());

    switch (Root->Value)
    {
    case -1: return LeftValue + RightValue;      // сложение
    case -2: return LeftValue - RightValue;      // вычитание
    case -3: return LeftValue * RightValue;      // умножение
    case -4: return LeftValue / RightValue;      // деление нацело
    default: return 0;
    }
}

// Функция для замены поддеревьев со сложением/вычитанием на их значения
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//std::shared_ptr<TreeNode> simplifyTree(std::shared_ptr<TreeNode> root) 
std::shared_ptr<TreeNode> SimplifyTree(std::shared_ptr<TreeNode> Root)
{
    if (!Root)
    {
        return nullptr;
    }
    // Рекурсивно упрощаем левое и правое поддеревья
    Root->Left = SimplifyTree(Root->Left);
    Root->Right = SimplifyTree(Root->Right);

    // Если текущий узел — операция сложения или вычитания
    if (Root->Value == -1 || Root->Value == -2)
    {
        // Вычисляем значение этого поддерева
        //FIX_ME: неправильное название переменных
        // int result = Evaluate(Root.get());
        int Result = Evaluate(Root.get());
        // Заменяем узел на лист с результатом
        return std::make_shared<TreeNode>(Result);
    }

    // Для умножения и деления оставляем как есть
    return Root;
}

// Функция для вывода дерева (для отладки)
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметров функции
//void printTree(TreeNode* root, int depth = 0) 
void PrintTree(TreeNode* Root, int DepthTree)
{
    using namespace std;
    //FIX_ME: пустой цикл if
    if (Root)
    {
        for (int i = 0; i < DepthTree; i++)
        {
            cout << "  ";
        }
        if (Root->Value >= 0)
        {
            cout << "Число: " << Root->Value << endl;
        }
        else
        {
            //FIX_ME: неправильное название переменных
            //string op;
            string Operation;
            switch (Root->Value)
            {
            case -1: Operation = "+"; break;
            case -2: Operation = "-"; break;
            case -3: Operation = "*"; break;
            case -4: Operation = "/"; break;
            }
            cout << "Операция: " << Operation << endl;
        }

        PrintTree(Root->Left.get(), DepthTree + 1);
        PrintTree(Root->Right.get(), DepthTree + 1);
    }
}