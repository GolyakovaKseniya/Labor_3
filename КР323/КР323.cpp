//Gemini

//В текстовом файле с именем filename дано арифметическое выражение в префиксной форме.Операндами в выражении являются целые числа из промежутка от 0 до 9.
// Используемые операции : сложение(+), вычитание(-), умножение(*) и деление нацело(/ ).Постройте дерево, со ответствующее данному выражению.
// Знаки операций кодируйте числами : сложение(-1), вычита ние(-2), умножение(-3), деление(-4).Преобразуйте дерево так, чтобы в нем не было операций сло жения и вычитания.
// Иными словами, замените поддеревья, в которых есть сложение или вычита ние значением данного поддерева.Выведите указатель на корень полученного дерева.

#include "Header.h"

int main() 
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    //FIX_ME: неправильное название переменных
    // string filename;
    string Filename;
    cout << "Введите имя файла: ";
    cin >> Filename;

    ifstream File(Filename);
    if (!File.is_open())
    {
        cout << "Ошибка: не удалось открыть файл" << endl;
        return 1;
    }

    // Читаем выражение из файла
    //FIX_ME: неправильное название переменных
    //string line;
    string UserLine;

    //FIX_ME: добавлена проверка на корректность чтения
    //getline(File, UserLine);
    if (!getline(File, UserLine))
    {
        cout << "Ошибка: не удалось прочитать выражение из файла" << endl;
        File.close();
        return 1;
    }
    File.close();

    //FIX_ME: добавлена проверка на пустоту
    if (UserLine.empty())
    {
        std::cout << "Ошибка: файл не содержит выражения" << std::endl;
        return 1;
    }

    // Парсим строку в вектор токенов
    //FIX_ME: неправильное название переменных
    /*vector<int> tokens;
    istringstream iss(UserLine);
    string token;*/
    vector<int> Tokens;
    istringstream Stream(UserLine);
    string Token;

    int NumberCount = 0;
    int OperationCount = 0;
    bool bValidExpression = true;

    while (Stream >> Token) 
    {
        if (Token == "+") 
        {
            Tokens.push_back(-1);
            ++OperationCount;
        }
        else if (Token == "-") 
        {
            Tokens.push_back(-2);
            ++OperationCount;
        }
        else if (Token == "*") 
        {
            Tokens.push_back(-3);
            ++OperationCount;
        }
        else if (Token == "/")
        {
            Tokens.push_back(-4);
            ++OperationCount;
        }
        else 
        {
            // //FIX_ME: добавлена проверка, что токен является числом
            bool bIsNumber = true;
            for (char ch : Token)
            {
                if (!isdigit(static_cast<unsigned char>(ch)))
                {
                    bIsNumber = false;
                    break;
                }
            }

            if (!bIsNumber)
            {
                std::cout << "Ошибка: недопустимый токен '" << Token << "'" << std::endl;
                bValidExpression = false;
                break;
            }
            // Это число
            //FIX_ME: неправильное название переменных
            //int num = stoi(Token);
            int Number = stoi(Token);
            if (Number < 0 || Number > 9)
            {
                cout << "Ошибка: число вне допустимого диапазона (0-9)" << endl;
                bValidExpression = false;
                return 1;
            }
            Tokens.push_back(Number);
            ++NumberCount;
        }
    }

    if (!bValidExpression)
    {
        return 1;
    }

    if (Tokens.empty()) 
    {
        cout << "Ошибка: файл пуст" << endl;
        return 1;
    }

    // //FIX_ME: добавлена проверка корректности выражения (для префиксной записи чисел должно быть на 1 больше, чем операций)
    if (NumberCount != OperationCount + 1)
    {
        std::cout << "Ошибка: некорректное выражение" << std::endl;
        return 1;
    }

    // Строим дерево
    //FIX_ME: неправильное название переменных
    /*int index = 0;
    auto root = BuildTree(Tokens, index);*/
    int Index = 0;
    auto Root = BuildTree(Tokens, Index);

    if (!Root)
    {
        cout << "Ошибка: не удалось построить дерево" << endl;
        return 1;
    }

    cout << "\nИсходное дерево:" << endl;
    PrintTree(Root.get());

    // Упрощаем дерево (заменяем сложение и вычитание на значения)
    //FIX_ME: неправильное название переменных
    //auto simplifiedRoot = SimplifyTree(Root);
    auto SimplifiedRoot = SimplifyTree(Root);

    cout << "\nУпрощённое дерево:" << endl;
    PrintTree(SimplifiedRoot.get());

    cout << "\nУказатель на корень полученного дерева: " << SimplifiedRoot.get() << endl;

    return 0;
}