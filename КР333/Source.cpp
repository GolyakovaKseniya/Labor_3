#include "Header.h"

// Функция для чтения матрицы смежности из файла
//FIX_ME: вынесена логика чтения матрицы из файла
std::vector<std::vector<int>> ReadGraphFromFile(const std::string& FileName, int& CountCity)
{
    using namespace std;

    //FIX_ME: неправильное название переменной
    //ifstream file(FileName);
    ifstream File(FileName);

    //FIX_ME: неправильное положение фигурной скобки
    if (!File.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        CountCity = 0;
        return {};
    }

    File >> CountCity;


    // Проверка на допустимость количества городов
    if (CountCity <= 0 || CountCity > 25)
    {
        cout << "Ошибка: некорректное количество городов" << endl;
        CountCity = 0;
        return {};
    }

    //FIX_ME: неправильное название переменной
    //vector<vector<int>> matrix
    vector<vector<int>> Matrix(CountCity, vector<int>(CountCity));

    //FIX_ME: постфиксный инкремент
    for (int i = 0; i < CountCity; ++i)
    {
        for (int j = 0; j < CountCity; ++j)
        {
            //FIX_ME: добавлена проверка на корректность считывания данных
            if (!(File >> Matrix[i][j]))
            {
                cout << "Ошибка: недостаточно данных в файле для матрицы смежности" << endl;
                return {};
            }
            // Проверка, что элемент матрицы - 0 или 1
            if (Matrix[i][j] != 0 && Matrix[i][j] != 1)
            {
                cout << "Ошибка: элементы матрицы смежности должны быть 0 или 1" << endl;
                return {};
            }
        }
    }

    //FIX_ME: добавлена проверка симметричности матрицы (для неориентированного графа)
    bool bSymmetric = true;
    for (int i = 0; i < CountCity && bSymmetric; ++i)
    {
        for (int j = 0; j < CountCity && bSymmetric; ++j)
        {
            if (Matrix[i][j] != Matrix[j][i])
            {
                bSymmetric = false;
            }
        }
    }
    if (!bSymmetric)
    {
        cout << "Предупреждение: матрица смежности несимметрична (граф ориентированный?)" << endl;
    }

    File.close();
    return Matrix;
}

// Функция для вывода матрицы смежности
//FIX_ME: добавлена функция вывода матрицы смежности
void PrintAdjacencyMatrix(const std::vector<std::vector<int>>& Matrix)
{
    using namespace std;

    int CountCity = Matrix.size();
    cout << "\nМатрица смежности:" << endl;
    cout << "   ";
    for (int j = 0; j < CountCity; ++j)
    {
        cout << j + 1 << " ";
    }
    cout << endl;
    cout << "   ";
    for (int j = 0; j < CountCity; ++j)
    {
        cout << "--";
    }
    cout << endl;

    for (int i = 0; i < CountCity; ++i)
    {
        cout << i + 1 << " | ";
        for (int j = 0; j < CountCity; ++j)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для поиска кратчайших расстояний с помощью BFS
//FIX_ME: вынесена логика поиска кратчайшего пути
std::vector<int> FindShortestDistances(const std::vector<std::vector<int>>& Matrix, int StartCity)
{
    using namespace std;

    int CountCity = Matrix.size();

    //FIX_ME: неправильное название переменных
    /*vector<int> dist(CountCity, -1);
    queue<int> q;*/
    vector<int> Distance(CountCity, -1);
    queue<int> Queue;

    Distance[StartCity] = 0;
    Queue.push(StartCity);

    while (!Queue.empty())
    {
        //FIX_ME: неправильное название переменной
        //int current = Queue.front();
        int СurrentCity = Queue.front();
        Queue.pop();

        //FIX_ME: неправильное название переменной
        // for (int neighbor = 0; neighbor < CountCity; neighbor++) 
        for (int Neighbor = 0; Neighbor < CountCity; ++Neighbor)
        {
            if (Matrix[СurrentCity][Neighbor] == 1 && Distance[Neighbor] == -1)
            {
                Distance[Neighbor] = Distance[СurrentCity] + 1;
                Queue.push(Neighbor);
            }
        }
    }

    return Distance;
}
