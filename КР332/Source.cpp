#include "Header.h"

//FIX_ME: добавлен вывод изначальной матрицы смежности
void PrintAdjacencyMatrix(const std::vector<std::vector<int>>& Matrix, int VertexCount)
{
    std::cout << "ћатрица смежности" << std::endl;
    std::cout << "    ";

    // ¬ывод заголовков столбцов (номера городов)
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

    // ¬ывод строк матрицы
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

//FIX_ME: вынесена логика с нахождением кратчайшего пути
std::vector<int> FindCitiesWithLayovers(
    const std::vector<std::vector<int>>& AdjacencyMatrix,
    int StartCity,
    int LayoversCount)
{
    using namespace std;
    int CityCount = AdjacencyMatrix.size();

    // BFS с отслеживанием количества пересадок
    //FIX_ME: неинформативное название переменной
    //queue <pair<int, int>> q;
    queue <pair<int, int>> Queue;  // ќчередь хранит пару (город, количество пересадок)

    //FIX_ME: неправильное название переменных
    /*vector<bool> visited(n, false);
    vector<bool> reached(n, false);*/
    //vector<bool> Visited(CityCount, false);
    vector<int> MinFlight(CityCount, -1);
    vector<bool> Reached(CityCount, false); // ћассив дл€ достижени€ города с L пересадками
    Queue.push({ StartCity, 0 });
    MinFlight[StartCity] = 0;
    //Visited[StartCity] = true;

    while (!Queue.empty())
    {
        //FIX_ME: неправильное название переменных
        /*int city = Queue.front().first;
        int transfers = Queue.front().second;*/
        int CurrentCity = Queue.front().first;
        int CurrentFlight = Queue.front().second;
        Queue.pop();

        //FIX_ME: неверное условие дл€ пересадок
        if (CurrentFlight > MinFlight[CurrentCity])
        {
            continue;
        }
        int CurrentLayovers = (CurrentFlight == 0) ? 0 : CurrentFlight - 1;

        //FIX_ME: неверное условие дл€ пересадок
        //if (CurrentLayovers == LayoversCount)
        if (CurrentLayovers == LayoversCount)
        {
            Reached[CurrentCity] = true;
        }
        if (CurrentLayovers >= LayoversCount + 1)
        {
            continue;
        }

        // ќбходим всех соседей
        for (int i = 0; i < CityCount; ++i)
        {
            if (AdjacencyMatrix[CurrentCity][i] == 1)
            {
                if (i == StartCity && CurrentFlight + 1 < LayoversCount)
                {
                    continue;
                }
                int NewFlight = CurrentFlight + 1;
                if (MinFlight[i] == -1 || NewFlight < MinFlight[i])
                {
                    MinFlight[i] = NewFlight;
                    Queue.push({ i, NewFlight });
                }
                //Visited[i] = true;
                /*if (CurrentLayovers + 1 <= LayoversCount)
                {
                    Queue.push({ i, CurrentLayovers + 1 });
                }*/
                //Queue.push({ i, CurrentLayovers + 1 });
            }
        }
    }
    // ¬ыводим результат
    //FIX_ME: неправильное название переменной
    //vector<int> result;
    vector<int> ResultCities;
    for (int i = 0; i < CityCount; ++i)
    {
        //FIX_ME: неверное условие дл€ пересадок
        //if (Reached[i])
        if (Reached[i] && i != StartCity)
        {
            ResultCities.push_back(i + 1);  // Ќумераци€ с 1
        }
    }
    sort(ResultCities.begin(), ResultCities.end());
    return ResultCities;
}