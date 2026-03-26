//Deepseek

//Юный путешественник решил изучить схему авиационного сообщения Схема авиацион ного сообщения задана в текстовом файле с именем FileName.в виде матрицы смежности.
// Первая строка файла содержит количество городов(n) n <= 25, связанных авиационным сообщением, а следующие n строк хранят матрицу(m), m[i][j] = 0, 
// если не имеется возможности перелета из го рода i в город j, иначе m[i][j] = 1. Определить номера городов, 
// в которые из города K можно доле теть ровно с L пересадками для самого короткого пути.Перечислите номера таких городов в по рядке возрастания.
// Нумерация городов начинается с 1. Если таких городов нет, выведите число(-1).

#include "Header.h"

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    string FileName;
    cout << "Введите имя файла: ";
    cin >> FileName;

    //FIX_ME: неинформативное название переменной
    //int n
    int CountCity = 0; // количество городов

    // Чтение матрицы смежности
    //FIX_ME: логика вынесена в отдельную функцию
    vector<vector<int>> Matrix = ReadGraphFromFile(FileName, CountCity);

    //FIX_ME: добавлена проверка на пустоту
    if (Matrix.empty())
    {
        return 1;
    }

    //FIX_ME: добавлен вывод матрицы
    PrintAdjacencyMatrix(Matrix, CountCity);

    //FIX_ME: неинформативное название переменных
    //int K, L
    int StartCity; // начальный город
    int LayoversCount; // количество пересадок

    cout << "Введите номер начального города K (1-" << CountCity << "): ";

    //FIX_ME: нет проверки на корректность ввода
    //cin >> StartCity;
    while (!(std::cin >> StartCity))
    {
        std::cout << "Ошибка: введите целое число" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    cout << "Введите количество пересадок L: ";

    //cin >> LayoversCount;
    while (!(std::cin >> LayoversCount))
    {
        std::cout << "Ошибка: введите целое число" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Проверка корректности ввода
    if (StartCity < 1 || StartCity > CountCity)
    {
        cout << "Ошибка: неверный номер города" << endl;
        return 1;
    }

    //FIX_ME: отсутствует проверка корректности для числа пересадок
    if (LayoversCount < 0)
    {
        cout << "Ошибка: неверное количество пересадок" << endl;
        return 1;
    }

    // Преобразуем к нумерации с 0
    //FIX_ME: неправильное название переменных
    //int start = StartCity - 1;
    //vector<int> distance
    //queue<int> q
    int StartVertexIndex = StartCity - 1;

    vector<int> Distances = FindShortestPath(Matrix, StartVertexIndex);

    // Собираем города, расстояние до которых равно L
    //FIX_ME: неправильное название переменной
    //vector<int> result;
    //FIX_ME: постфиксный инкремент
    //i++
    vector<int> Result;
    for (int i = 0; i < CountCity; ++i)
    {
        //FIX_ME: неверное условие для пересадок
        //if (Distances[i] == LayoversCount)
        if (Distances[i] == LayoversCount + 1 && i != StartVertexIndex)
        {
            Result.push_back(i + 1); // возвращаем к нумерации с 1
        }
    }

    // Сортируем результат по возрастанию
    sort(Result.begin(), Result.end());

    //FIX_ME: недостаточно дружественного интерфейса
    cout << "Города, в которые из города " << StartCity << " можно долететь ровно с " << LayoversCount
        << " пересадками: ";

    // Вывод результата
    if (Result.empty())
    {
        cout << "(-1)" << endl;
    }
    else
    {
        for (size_t i = 0; i < Result.size(); ++i)
        {
            cout << Result[i];
            if (i != Result.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}