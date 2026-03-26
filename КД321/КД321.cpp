//Deepseek

//В текстовом файле с именем filename дано арифметическое выражение в префиксной форме.Операндами в выражении являются целые числа из промежутка от 0 до 9.
// Используемые операции : сложение(+), вычитание(-), умножение(*) и деление нацело(/ ).Постройте дерево, со ответствующее данному выражению.Знаки операций кодируйте числами : 
// сложение(-1), вычита ние(-2), умножение(-3), деление(-4).Преобразуйте дерево так, чтобы в нем не было операций сло жения и вычитания.Иными словами, замените поддеревья,
// в которых есть сложение или вычита ние значением данного поддерева.Выведите указатель на корень полученного дерева.

#include "Header.h"

int main() 
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    //FIX_ME: неправильное название переменной
    //string filename;
    string Filename;
    cout << "Введите имя файла: ";
    cin >> Filename;

    //FIX_ME: неправильное название переменной
    //ifstream file(Filename);
    ifstream File(Filename);
    if (!File.is_open()) 
    {
        //FIX_ME: использование cerr
        cout << "Ошибка: не удалось открыть файл " << Filename << endl;
        return 1;
    }

    //FIX_ME: неправильное название переменной
    //stringstream buffer;
    stringstream Buffer;
    Buffer << File.rdbuf();

    //FIX_ME: неправильное название переменной
    //string content = Buffer.str();
    string Content = Buffer.str();
    File.close();

    //FIX_ME: добавлена проверка на пустоту
    if (Content.empty() || Content.find_first_not_of(" \t\n\r") == std::string::npos)
    {
        std::cout << "Ошибка: файл не содержит данных" << std::endl;
        return 1;
    }

    vector<string> Tokens;
    stringstream Stream(Content);
    string Token;
    while (Stream >> Token)
    {
        //FIX_ME: добавлена проверка на пустоту
        if (!Token.empty())
        {
            Tokens.push_back(Token);
        }
    }

    if (Tokens.empty())
    {
        cout << "Ошибка: файл пуст" << endl;
        return 1;
    }

    ////FIX_ME: добавлена проверка, что количество токенов нечетное (для префиксной записи)
    // Простая проверка: для n чисел нужно n-1 операций
    int NumberCount = 0;
    int OperationCount = 0;
    for (const auto& TokenItem : Tokens)
    {
        if (TokenItem == "+" || TokenItem == "-" || TokenItem == "*" || TokenItem == "/")
        {
            OperationCount++;
        }
        else
        {
            // Проверка, что число в диапазоне 0-9
            try
            {
                int Number = std::stoi(TokenItem);
                if (Number < 0 || Number > 9)
                {
                    std::cout << "Предупреждение: число " << Number << " вне диапазона 0-9" << std::endl;
                    return 1;
                }
                NumberCount++;
            }
            catch (const std::exception&)
            {
                std::cout << "Ошибка: недопустимый токен '" << TokenItem << "'" << std::endl;
                return 1;
            }
        }
    }

    if (NumberCount != OperationCount + 1)
    {
        std::cout << "Ошибка: некорректное выражение" << std::endl;
        std::cout << "Для префиксной записи чисел должно быть на 1 больше, чем операций" << std::endl;
        return 1;
    }


    cout << "\nПрочитаны токены: ";
    for (const auto& Token : Tokens) 
    {
        cout << Token << " ";
    }
    cout << endl;

    size_t Position = 0;
    TreeNode* Root = BuildTree(Tokens, Position);

    cout << "\n=== Исходное дерево ===" << endl;
    cout << "Структура дерева:" << endl;
    PrintTree(Root);

    cout << "\nПрефиксная форма: ";
    PrintPrefix(Root);
    cout << endl;

    // ПРОСТОЕ РЕШЕНИЕ: вызываем SimplifyTree рекурсивно, пока есть изменения
    TreeNode* TransformedRoot = Root;

    // Повторяем упрощение, пока в дереве есть операции сложения или вычитания
    while (HasAddOrSub(TransformedRoot)) 
    {
        TransformedRoot = SimplifyTree(TransformedRoot);
    }

    cout << "\n=== Дерево после преобразования ===" << endl;
    cout << "Структура дерева:" << endl;
    PrintTree(TransformedRoot);

    cout << "\nПрефиксная форма: ";
    PrintPrefix(TransformedRoot);
    cout << endl;

    cout << "\n";
    PrintRootPointer(TransformedRoot);

    DeleteTree(TransformedRoot);

    return 0;
}