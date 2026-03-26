#include "Header.h"

//FIX_ME: неинформативное название параметра функции
//bool IsOperation(int val) 
bool IsOperation(int InValue)
{
    return InValue == kAdd || InValue == kSub || InValue == kMul || InValue == kDiv;
}

//FIX_ME: неинформативное название параметра функции
//bool IsAddOrSub(int val)
bool IsAddOrSub(int InValue)
{
    return InValue == kAdd || InValue == kSub;
}

//FIX_ME: неинформативное название параметров функции
//int Calculate(int op, int leftVal, int rightVal) 
int Calculate(int InOperation, int LeftValue, int RightValue)
{
    switch (InOperation)
    {
    case kAdd: return LeftValue + RightValue;
    case kSub: return LeftValue - RightValue;
    case kMul: return LeftValue * RightValue;
    case kDiv:
        //FIX_ME: нет проверки на деление на 0
        if (RightValue == 0)
        {
            //FIX_ME: использование cerr
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return 0;
        }
        return LeftValue / RightValue;
    default: return 0;
    }
}

//FIX_ME: неправильное название параметра функции
//void DeleteTree(TreeNode* root) 
void DeleteTree(TreeNode* Root)
{
    //FIX_ME: пустой return
    //if (!Root) return;
    if (Root)
    {
        DeleteTree(Root->Left);
        DeleteTree(Root->Right);
        delete Root;
    }
}

// ГЛАВНАЯ ФУНКЦИЯ: рекурсивно упрощаем дерево
//FIX_ME: неправильное название параметра функции
//TreeNode* SimplifyTree(TreeNode* root) 
TreeNode* SimplifyTree(TreeNode* Root)
{
    //FIX_ME: цикл if используется без фигурных скобок
    if (!Root)
    {
        return nullptr;
    }

    // Сначала рекурсивно упрощаем левое и правое поддеревья
    Root->Left = SimplifyTree(Root->Left);
    Root->Right = SimplifyTree(Root->Right);

    // Если текущий узел - операция
    if (IsAddOrSub(Root->Value))
    {
        // Проверяем, можем ли мы вычислить этот узел
        // Узел можно вычислить, если оба поддерева существуют и они НЕ операции (то есть числа)
        if (Root->Left && Root->Right &&
            !IsOperation(Root->Left->Value) &&
            !IsOperation(Root->Right->Value))
        {

            // Вычисляем значение
            //FIX_ME: неправильное название параметра функции
            //int result = Calculate
            int Result = Calculate(Root->Value, Root->Left->Value, Root->Right->Value);

            // Удаляем поддеревья
            delete Root->Left;
            delete Root->Right;

            // Превращаем узел в число
            Root->Value = Result;
            Root->Left = nullptr;
            Root->Right = nullptr;
        }
    }

    return Root;
}

// Функция для удаления сложения и вычитания (вызывает SimplifyTree несколько раз)
//FIX_ME: неправильное название параметра функции
//TreeNode* RemoveAddSub(TreeNode* root)
TreeNode* RemoveAddSub(TreeNode* Root)
{
    if (!Root)
    {
        return nullptr;
    }

    //FIX_ME: неправильное название переменных
    /*TreeNode* previous = nullptr;
    TreeNode* current = Root;*/
    TreeNode* Previous = nullptr;
    TreeNode* Current = Root;

    // Повторяем упрощение, пока дерево меняется
    //FIX_ME: неправильное название логической переменной
    //bool changed = true;
    bool bChanged = true;
    while (bChanged)
    {
        bChanged = false;

        // Создаем копию для сравнения (упрощенно - просто проверяем, изменилось ли что-то)
        // Проще: вызываем SimplifyTree и проверяем, есть ли еще операции сложения/вычитания

        Current = SimplifyTree(Current);

        // Проверяем, остались ли операции сложения/вычитания
        // Для этого нужно обойти дерево
        bChanged = false;
        // Простой способ: если в дереве есть ADD или SUB, то changed = true
        // Но проще вызвать SimplifyTree еще раз
    }

    return Current;
}

// Построение дерева из потока токенов
//FIX_ME: неинформативное название параметров функции
//TreeNode* BuildTree(std::vector<std::string>& tokens, size_t& pos) 
TreeNode* BuildTree(std::vector<std::string>& Tokens, size_t& Position)
{
    if (Position >= Tokens.size())
    {
        return nullptr;
    }

    //FIX_ME: неправильное название переменной
    //std::string token = Tokens[Position++];
    std::string Token = Tokens[Position++];

    if (Token == "+")
    {
        //FIX_ME: неправильное название переменной
        //TreeNode* node = new TreeNode(ADD);
        TreeNode* Node = new TreeNode(kAdd);
        Node->Left = BuildTree(Tokens, Position);
        Node->Right = BuildTree(Tokens, Position);
        return Node;
    }
    else if (Token == "-")
    {
        TreeNode* Node = new TreeNode(kSub);
        Node->Left = BuildTree(Tokens, Position);
        Node->Right = BuildTree(Tokens, Position);
        return Node;
    }
    else if (Token == "*")
    {
        TreeNode* Node = new TreeNode(kMul);
        Node->Left = BuildTree(Tokens, Position);
        Node->Right = BuildTree(Tokens, Position);
        return Node;
    }
    else if (Token == "/")
    {
        TreeNode* Node = new TreeNode(kDiv);
        Node->Left = BuildTree(Tokens, Position);
        Node->Right = BuildTree(Tokens, Position);
        return Node;
    }
    else
    {
        //FIX_ME: неинформативное название переменной
        //int num = stoi(Token);
        int Number = stoi(Token);
        return new TreeNode(Number);
    }
}

// Функция для вывода дерева
//FIX_ME: неправильное название параметра функции
//void PrintTree(TreeNode* root, int level = 0) 
void PrintTree(TreeNode* Root, int Level)
{
    if (Root)
    {
        //FIX_ME: цикл for используется без фигурных скобок
        for (int i = 0; i < Level; i++)
        {
            std::cout << "  ";
        }

        if (!IsOperation(Root->Value))
        {
            std::cout << Root->Value << std::endl;
        }
        else
        {
            //FIX_ME: неправильное название переменной
            // std::string op;
            std::string Operation;
            switch (Root->Value)
            {
            case kAdd: Operation = "+"; break;
            case kSub: Operation = "-"; break;
            case kMul: Operation = "*"; break;
            case kDiv: Operation = "/"; break;
            }
            std::cout << Operation << std::endl;
            PrintTree(Root->Left, Level + 1);
            PrintTree(Root->Right, Level + 1);
        }
    }
}

//FIX_ME: неправильное название параметра функции
//void PrintPrefix(TreeNode* root) 
void PrintPrefix(TreeNode* Root)
{
    if (Root)
    {
        if (!IsOperation(Root->Value))
        {
            std::cout << Root->Value << " ";
        }
        else
        {
            //FIX_ME: неправильное название переменной
            // std::string op;
            std::string Operation;
            switch (Root->Value)
            {
            case kAdd: Operation = "+"; break;
            case kSub: Operation = "-"; break;
            case kMul: Operation = "*"; break;
            case kDiv: Operation = "/"; break;
            }
            std::cout << Operation << " ";
            PrintPrefix(Root->Left);
            PrintPrefix(Root->Right);
        }
    }
}

//FIX_ME: неправильное название параметра функции
//void PrintRootPointer(TreeNode* root) 
void PrintRootPointer(TreeNode* Root)
{
    std::cout << "Указатель на корень: " << Root << std::endl;
}

// Функция для проверки, есть ли в дереве операции сложения/вычитания
//FIX_ME: неправильное название
//bool HasAddOrSub(TreeNode* root) 
bool HasAddOrSub(TreeNode* Root)
{
    if (!Root)
    {
        return false;
    }
    if (IsAddOrSub(Root->Value))
    {
        return true;
    }
    return HasAddOrSub(Root->Left) || HasAddOrSub(Root->Right);
}
