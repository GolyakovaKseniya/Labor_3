#include "Header.h"

// Функция для построения дерева из префиксной записи
//FIX_ME: неправильное название функции
//FIX_ME: неинформативное название параметра функции
//TreeNode* buildTree(std::stack<TreeNode*>& st) 
TreeNode* BuildTree(std::stack<TreeNode*>& Stack)
{
    //FIX_ME: цикл if используется без фигурных скобок
    if (Stack.empty())
    {
        return nullptr;
    }

    //FIX_ME: неинформативное название переменной
    //TreeNode* node = Stack.top();
    TreeNode* Node = Stack.top();
    Stack.pop();

    // Если это оператор, рекурсивно строим поддеревья
    if (Node->Value < 0)
    {
        Node->Right = BuildTree(Stack);  // Сначала правый, потом левый (так как читаем справа налево)
        Node->Left = BuildTree(Stack);
    }
    return Node;
}

// Функция для рекурсивного удаления дерева
//FIX_ME: отсутствовало удаление поддеревьев
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//void deleteTree(TreeNode* root) 
void DeleteTree(TreeNode* Root)
{
    //FIX_ME: пустой return 
    if (Root)
    {
        DeleteTree(Root->Left);
        DeleteTree(Root->Right);
        delete Root;
    }
}

// Функция для преобразования дерева, удаляя операции сложения и вычитания
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//TreeNode* transformTree(TreeNode* root) 
TreeNode* TransformTree(TreeNode* Root)
{
    //FIX_ME: цикл используется без фигурных скобок
    if (!Root)
    {
        return nullptr;
    }

    // Рекурсивно преобразуем левое и правое поддеревья
    //FIX_ME: неправильное преобразование поддеревьев 
    Root->Left = TransformTree(Root->Left);
    Root->Right = TransformTree(Root->Right);

    // Если операция сложения или вычитания
    if (Root->Value == -1 || Root->Value == -2)
    {
        // Проверяем, что оба поддерева существуют и являются числами
        //FIX_ME: не было проверки на существование поддерева
        if (Root->Left && Root->Right &&
            Root->Left->Value >= 0 && Root->Right->Value >= 0)
        {

            //FIX_ME: неправильное название переменных
            /*int leftValue = Root->Left->Value;
            int rightValue = Root->Right->Value;*/
            int LeftValue = Root->Left->Value;
            int RightValue = Root->Right->Value;

            // Вычисляем результат
            if (Root->Value == -1)
            { // Сложение
                Root->Value = LeftValue + RightValue;
            }
            else
            { // Вычитание
                Root->Value = LeftValue - RightValue;
            }

            // Удаляем поддеревья
            //FIX_ME: отсутствовало удаление поддеревьев
            DeleteTree(Root->Left);
            DeleteTree(Root->Right);
            Root->Left = nullptr;
            Root->Right = nullptr;
        }
    }

    return Root;
}

// Функция для преобразования выражения в префиксной записи в дерево
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//TreeNode* parseExpression(const std::string& expression) 
TreeNode* ParseExpression(const std::string& Expression)
{
    //FIX_ME: неправильное название переменной
    //std::stack<TreeNode*> st;
    std::stack<TreeNode*> Stack;

    // Проходим по строке справа налево (для префиксной записи)
    for (int i = Expression.size() - 1; i >= 0; --i)
    {
        //FIX_ME: неправильное название переменной
        //char ch = Expression[i];
        char Charter = Expression[i];

        // Пропускаем пробелы
        //FIX_ME: добавлена проверка на пробелы
        if (isspace(Charter))
        {
            continue;
        }
        if (isdigit(Charter))
        {
            Stack.push(new TreeNode(Charter - '0'));  // Добавляем число в стек
        }
        else if (Charter == '+')
        {
            Stack.push(new TreeNode(-1));  // Сложение
        }
        else if (Charter == '-')
        {
            Stack.push(new TreeNode(-2));  // Вычитание
        }
        else if (Charter == '*')
        {
            Stack.push(new TreeNode(-3));  // Умножение
        }
        else if (Charter == '/')
        {
            Stack.push(new TreeNode(-4));  // Деление
        }
    }

    return BuildTree(Stack);
}

// Функция для вывода дерева в префиксной форме
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//void printTree(TreeNode* root)
void PrintTree(TreeNode* Root)
{
    using namespace std;
    //FIX_ME: пустой return 
    if (Root)
    {
        // Выводим значение узла
        if (Root->Value < 0)
        {
            // Если это операция, выводим соответствующий символ
            //FIX_ME: неправильный вывод операции
            /*cout << root->value << " ";
            printTree(root->left);
            printTree(root->right);*/
            switch (Root->Value)
            {
            case -1: cout << "+ "; break;
            case -2: cout << "- "; break;
            case -3: cout << "* "; break;
            case -4: cout << "/ "; break;
            }
        }
        else
        {
            // Если это число, выводим его
            cout << Root->Value << " ";
        }

        // Рекурсивно выводим левое и правое поддеревья
        PrintTree(Root->Left);
        PrintTree(Root->Right);


    }
}

// Функция для вывода дерева с отступами (для наглядности)
//FIX_ME: добавлена функция для вывода дерева
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//void printTreeStructure(TreeNode* root, int level = 0)
void PrintTreeStructure(TreeNode* Root, int LevelTree)
{
    using namespace std;
    if (Root)
    {
        for (int i = 0; i < LevelTree; ++i)
        {
            cout << "      ";
        }

        if (Root->Value < 0)
        {
            switch (Root->Value)
            {
            case -1: cout << "+" << endl; break;
            case -2: cout << "-" << endl; break;
            case -3: cout << "*" << endl; break;
            case -4: cout << "/" << endl; break;
            }
        }
        else
        {
            cout << Root->Value << endl;
        }

        PrintTreeStructure(Root->Left, LevelTree + 1);
        PrintTreeStructure(Root->Right, LevelTree + 1);
    }
}
