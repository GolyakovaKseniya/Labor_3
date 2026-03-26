#include "Header.h"

//FIX_ME: вынесена логика поиска кратчайшего пути с пересадками
std::vector<int> FindShortestPath(const std::vector<std::vector<int>>& Matrix, int StartVertexIndex)
{
    using namespace std;
    //FIX_ME: неинформативное название переменной
    //int n
    int CountCity = Matrix.size();

    // BFS для поиска кратчайших расстояний
    vector<int> Distances(CountCity, -1); // -1 означает недостижимый город
    queue<int> Queue;

    Distances[StartVertexIndex] = 0; // расстояние до начального города = 0 (0 пересадок)
    Queue.push(StartVertexIndex);

    while (!Queue.empty())
    {
        //FIX_ME: неправильное название переменной
        // int current = Queue.front();
        int CurrentVertex = Queue.front();
        Queue.pop();

        // Проходим по всем соседним городам
        //FIX_ME: постфиксный инкремент
        //i++
        for (int i = 0; i < CountCity; ++i)
        {
            if (Matrix[CurrentVertex][i] == 1 && Distances[i] == -1)
            {
                Distances[i] = Distances[CurrentVertex] + 1;
                Queue.push(i);
            }
        }
    }
    return Distances;
}

//FIX_ME: вынесена логика чтения матрицы из файла
std::vector<std::vector<int>> ReadGraphFromFile(const std::string& FileName, int& CountCity)
{
    using namespace std;
    ifstream File(FileName);
    if (!File.is_open())
    {
        cout << "Ошибка: не удалось открыть файл " << FileName << endl;
        CountCity = 0;
        return {};
    }

    //FIX_ME: нет проверки на корректность считывания
    //File >> CountCity;
    if (!(File >> CountCity))
    {
        std::cout << "Ошибка: не удалось прочитать количество городов из файла" << std::endl;
        std::cout << "Первая строка файла должна содержать целое число от 1 до 25" << std::endl;
        File.close();
        CountCity = 0;
        return {};
    }

    // Проверка на допустимость количества городов
    if (CountCity <= 0 || CountCity > 25)
    {
        cout << "Ошибка: некорректное количество городов" << endl;
        CountCity = 0;
        return {};
    }

    std::vector<std::vector<int>> AdjacencyMatrix(CountCity, std::vector<int>(CountCity, 0));

    //FIX_ME: добавлена проверка на соответствие числа городов числу строк и столбцов
    int ActualRows = 0;
    int ActualCols = 0;

    for (int RowIndex = 0; RowIndex < CountCity; ++RowIndex)
    {
        for (int ColumnIndex = 0; ColumnIndex < CountCity; ++ColumnIndex)
        {
            if (!(File >> AdjacencyMatrix[RowIndex][ColumnIndex]))
            {
                std::cout << "Ошибка: недостаточно данных в файле для матрицы смежности" << std::endl;
                File.close();
                CountCity = 0;
                return {};
            }
            //File >> AdjacencyMatrix[RowIndex][ColumnIndex];

            // Проверка, что элемент матрицы - 0 или 1
            if (AdjacencyMatrix[RowIndex][ColumnIndex] != 0 && AdjacencyMatrix[RowIndex][ColumnIndex] != 1)
            {
                std::cout << "Ошибка: элементы матрицы смежности должны быть 0 или 1" << std::endl;
                File.close();
                CountCity = 0;
                return {};
            }
            ActualCols = ColumnIndex + 1;
        }
        ActualRows = RowIndex + 1;
    }

    // Проверка на количество городов соответствует размеру матрицы
    if (ActualRows != CountCity)
    {
        std::cout << "Ошибка: количество строк матрицы (" << ActualRows
            << ") не соответствует количеству городов (" << CountCity << ")" << std::endl;
        File.close();
        CountCity = 0;
        return {};
    }

    if (ActualCols != CountCity)
    {
        std::cout << "Ошибка: количество столбцов матрицы (" << ActualCols
            << ") не соответствует количеству городов (" << CountCity << ")" << std::endl;
        File.close();
        CountCity = 0;
        return {};
    }

    //FIX_ME: добавлена проверка симметричности матрицы (для неориентированного графа)
    bool bSymmetric = true;
    for (int i = 0; i < CountCity && bSymmetric; ++i)
    {
        for (int j = 0; j < CountCity && bSymmetric; ++j)
        {
            if (AdjacencyMatrix[i][j] != AdjacencyMatrix[j][i])
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
    return AdjacencyMatrix;

}
//FIX_ME: добавлен вывод исходной матрицы
void PrintAdjacencyMatrix(const std::vector<std::vector<int>>& Matrix, int VertexCount)
{
    std::cout << "\nМатрица смежности" << std::endl;
    std::cout << "    ";

    // Вывод заголовков столбцов (номера городов)
    for (int Column = 1; Column <= VertexCount; ++Column)
    {
        std::cout << Column << " ";
    }
    std::cout << std::endl;

    std::cout << "    ";
    for (int Column = 0; Column < VertexCount; ++Column)
    {
        std::cout << "--";
    }
    std::cout << std::endl;

    // Вывод строк матрицы
    for (int RowIndex = 0; RowIndex < VertexCount; ++RowIndex)
    {
        std::cout << RowIndex + 1 << " | ";
        for (int ColumnIndex = 0; ColumnIndex < VertexCount; ++ColumnIndex)
        {
            std::cout << Matrix[RowIndex][ColumnIndex] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
