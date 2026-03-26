//ChatGPT

//В текстовом файле с именем filename дано арифметическое выражение в префиксной форме.Операндами в выражении являются целые числа из промежутка от 0 до 9. 
// Используемые операции : сложение(+), вычитание(-), умножение(*) и деление нацело(/ ).Постройте дерево, со ответствующее данному выражению.
// Знаки операций кодируйте числами : сложение(-1), вычита ние(-2), умножение(-3), деление(-4).Преобразуйте дерево так, 
// чтобы в нем не было операций сло жения и вычитания.Иными словами, замените поддеревья, в которых есть сложение или вычита ние значением данного поддерева.
// Выведите указатель на корень полученного дерева.

#include "Header.h"

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    // Открытие файла
    //FIX_ME: неправильное название переменной
    //ifstream inputFile("filename.txt");
    ifstream InputFile("filename.txt");

    if (!InputFile.is_open()) 
    {
        cout << "Ошибка при открытии файла." << endl;
        return 1;
    }

    //FIX_ME: неправильное название переменной
    //string expression;
    string Expression;

    //FIX_ME: добавлена проверка на корректность считывания
    //getline(InputFile, Expression); // Чтение выражения из файла
    if (!getline(InputFile, Expression))
    {
        cout << "Ошибка: не удалось прочитать выражение из файла" << endl;
        InputFile.close();
        return 1;
    }
    InputFile.close();

    //FIX_ME: добавлена проверка на пустоту
    if (Expression.empty())
    {
        std::cout << "Ошибка: файл не содержит выражения" << std::endl;
        return 1;
    }

    cout << "Исходное выражение: " << Expression << endl;

    // //FIX_ME: добавлена проверка корректности выражения (подсчет чисел и операций)
    int NumberCount = 0;
    int OperationCount = 0;
    bool bValidExpression = true;

    for (char Char : Expression)
    {
        if (isspace(static_cast<unsigned char>(Char)))
        {
            continue;
        }
        if (isdigit(static_cast<unsigned char>(Char)))
        {
            NumberCount++;
        }
        else if (Char == '+' || Char == '-' || Char == '*' || Char == '/')
        {
            OperationCount++;
        }
        else
        {
            std::cout << "Ошибка: недопустимый символ '" << Char << "' в выражении" << std::endl;
            bValidExpression = false;
            break;
        }
    }

    if (!bValidExpression)
    {
        return 1;
    }

    // Для префиксной записи чисел должно быть на 1 больше, чем операций
    if (NumberCount != OperationCount + 1)
    {
        std::cout << "Ошибка: некорректное выражение" << std::endl;
        return 1;
    }

    // Удаляем пробелы из выражения (если нужно)
    Expression.erase(remove(Expression.begin(), Expression.end(), ' '), Expression.end());

    // Строим дерево из префиксной записи
    //FIX_ME: неправильное название переменной
    // TreeNode* root
    TreeNode* Root = ParseExpression(Expression);

    cout << "\nИсходное дерево (структура):" << endl;
    PrintTreeStructure(Root);

    cout << endl;

    // Преобразуем дерево, удаляя операции сложения и вычитания
    Root = TransformTree(Root);

    cout << "\nПреобразованное дерево (структура):" << endl;
    PrintTreeStructure(Root);

    cout << "\nПреобразованное дерево (префиксная форма): ";
    PrintTree(Root);
    cout << endl;

    // Освобождаем память
    DeleteTree(Root);

    return 0;
}