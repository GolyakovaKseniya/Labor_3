//Gemini

//Юный путешественник решил изучить схему авиационного сообщения Схема авиацион ного сообщения задана в текстовом файле с именем FileName.в виде матрицы смежности.
// Первая строка файла содержит количество городов(n) n <= 25, связанных авиационным сообщением, а следующие n строк хранят матрицу(m), m[i][j] = 0, 
// если не имеется возможности перелета из го рода i в город j, иначе m[i][j] = 1. Определить номера городов, 
// в которые из города K можно доле теть ровно с L пересадками для самого короткого пути.Перечислите номера таких городов в по рядке возрастания.Нумерация городов начинается с 1. 
// Если таких городов нет, выведите число(-1).

#include "Header.h"
//FIX_ME: неправильное положение фигурной скобки
int main() 
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    //FIX_ME: неправильное название переменной
    //string fileName;
    string FileName;

    //FIX_ME: неинформативное название переменной
    //int K, L;
    int NumberCity, Transfer;

    cout << "Введите имя файла: ";
    cin >> FileName;
    cout << "Введите номер города K (нумерация с 1): ";
    cin >> NumberCity;

    //FIX_ME: добавлена проверка на корректность ввода
    if (cin.fail()) 
    {
        cout << "Ошибка: введено некорректное значение" << endl;
        cout << -1 << endl;
        return 1;
    }

    cout << "Введите количество пересадок L: ";
    cin >> Transfer;

    if (cin.fail()) 
    {
        cout << "Ошибка: введено некорректное значение" << endl;
        cout << -1 << endl;
        return 1;
    }

    //FIX_ME: отсутствует проверка на корректность числа пересадок
    if (Transfer < 0)
    {
        cout << "Ошибка: неверное количество пересадок" << endl;
        return 1;
    }

    //FIX_ME: неинформативное название переменной
    //int n
    int CountCity;

    //FIX_ME: неправильное название переменной
    //vector<vector<int>> matrix
    vector<vector<int>> Matrix = ReadGraphFromFile(FileName, CountCity);

    if (Matrix.empty())
    {
        cout << -1 << endl;
        return 1;
    }

    // Вывод матрицы смежности
    PrintAdjacencyMatrix(Matrix);

    // Приводим K к индексу от 0
    //FIX_ME: неправильное название переменной
    //int start = NumberCity - 1;
    int StartCity = NumberCity - 1;

    // Проверка корректности номера города
    if (StartCity < 0 || StartCity >= CountCity)
    {
        cout << "Ошибка: неверный номер города" << endl;
        return 1;
    }

    // Поиск кратчайших расстояний
    //FIX_ME: неправильное название переменной
    //vector<int> distances
    vector<int> Distances = FindShortestDistances(Matrix, StartCity);

    // Собираем города, расстояние до которых = L + 1
    // (L пересадок = L+1 рёбер)
    //FIX_ME: неправильное название переменных
    /*vector<int> result;
    int targetDistance = Transfer + 1;*/
    vector<int> Result;
    int TargetDistance = Transfer + 1;

    for (int i = 0; i < CountCity; i++)
    {
        if (i != StartCity && Distances[i] == TargetDistance) 
        {
            Result.push_back(i + 1);
        }
    }

    // Сортируем результат по возрастанию
    sort(Result.begin(), Result.end());

    ++StartCity;
    // Вывод
    //FIX_ME: непонятный вывод
    cout << "Города, в которые из города " << StartCity << " можно долететь ровно с " << Transfer << " пересадками: ";
    if (Result.empty()) 
    {
        cout << -1 << endl;
    }
    else 
    {
        for (size_t i = 0; i < Result.size(); i++) 
        {
            cout << Result[i];
            if (i != Result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}