//ChatGPT

//Юный путешественник решил изучить схему авиационного сообщения Схема авиацион ного сообщения задана в текстовом файле с именем FileName.в виде матрицы смежности.
// Первая строка файла содержит количество городов(n) n <= 25, связанных авиационным сообщением, а следующие n строк хранят матрицу(m), m[i][j] = 0,
// если не имеется возможности перелета из го рода i в город j, иначе m[i][j] = 1. Определить номера городов, 
// в которые из города K можно доле теть ровно с L пересадками для самого короткого пути.Перечислите номера таких городов в по рядке возрастания.
// Нумерация городов начинается с 1. Если таких городов нет, выведите число(-1).

#include "Header.h"

//FIX_ME: неправильное положение фигурной скобки
int main()
{
    using namespace std;

    //FIX_ME: нет поддержки русского языка
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

    //FIX_ME: неинформативное название переменной
    //int n
    int CityCount;

    //FIX_ME: отсутствует проверка на корректность считывания
    //InputFile >> CityCount;  // Количество городов
    if (!(InputFile >> CityCount))
    {
        std::cout << "Ошибка: не удалось прочитать количество городов из файла" << std::endl;
        InputFile.close();
        return 1;
    }

    //FIX_ME: отсутствует проверка корректности количества городов
    if (CityCount <= 0 || CityCount > 25)
    {
        std::cout << "Ошибка: некорректное количество городов" << std::endl;
        return 1;
    }

    //FIX_ME: неинформативное название переменной
    //vector <vector<int>> adjMatrix
    vector <vector<int>> Matrix(CityCount, vector<int>(CityCount, 0));

    //FIX_ME: добавлена проверка на соответствие данных
    // Сохраняем позицию перед чтением матрицы
    std::streampos PosBeforeMatrix = InputFile.tellg();

    // Подсчитываем количество чисел в матрице
    int NumbersCount = 0;
    int TempValue;
    while (InputFile >> TempValue)
    {
        NumbersCount++;
    }

    // Ожидаемое количество чисел
    int ExpectedNumbers = CityCount * CityCount;

    // Проверка, что количество чисел соответствует размеру матрицы
    if (NumbersCount != ExpectedNumbers)
    {
        std::cout << "Ошибка: количество городов (" << CityCount <<
            ") не соответствует размеру матрицы" << std::endl;
        InputFile.close();
        return 1;
    }
    // Возвращаемся к началу матрицы
    InputFile.clear();
    InputFile.seekg(PosBeforeMatrix);

    // Чтение матрицы смежности
    for (int i = 0; i < CityCount; ++i)
    {
        for (int j = 0; j < CityCount; ++j) 
        {
            //FIX_ME: отсутствует проверка на корректность считывания
            if (!(InputFile >> Matrix[i][j]))
            {
                std::cout << "Ошибка: недостаточно данных в файле для матрицы смежности" << std::endl;
                std::cout << "Ожидается " << CityCount << "x" << CityCount << " элементов" << std::endl;
                InputFile.close();
                return 1;
            }

            // Проверка, что элемент матрицы - 0 или 1
            if (Matrix[i][j] != 0 && Matrix[i][j] != 1)
            {
                std::cout << "Ошибка: элементы матрицы смежности должны быть 0 или 1" << std::endl;
                std::cout << "На позиции (" << i + 1 << "," << j + 1 << ") найдено значение: " << Matrix[i][j] << std::endl;
                InputFile.close();
                return 1;
            }
        }
    }

    //FIX_ME: добавлена проверка симметричности матрицы (для неориентированного графа)
    bool bSymmetric = true;
    for (int i = 0; i < CityCount && bSymmetric; ++i)
    {
        for (int j = 0; j < CityCount && bSymmetric; ++j)
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
    InputFile.close();

    PrintAdjacencyMatrix(Matrix, CityCount);

    //FIX_ME: неинформативное название переменной
    //int K, L;
    int StartCity, LayoversCount;
    cout << "Введите город K и количество пересадок L: ";

    //cin >> StartCity >> LayoversCount;

    while (!(std::cin >> StartCity >> LayoversCount))
    {
        std::cout << "Ошибка: введите целое число" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите снова: ";
    }

    //FIX_ME: отсутствует проверка корректности ввода
    if (StartCity < 1 || StartCity > CityCount)
    {
        std::cout << "Ошибка: неверный номер города" << std::endl;
        return 1;
    }

    if (LayoversCount < 0)
    {
        std::cout << "Ошибка: количество пересадок не может быть отрицательным" << std::endl;
        return 1;
    }

    StartCity--; // Переводим в 0-индексацию
    
    //FIX_ME: неправильное название переменной
    //vector<int> result;
    vector<int> ResultCities = FindCitiesWithLayovers(Matrix,
        StartCity,
        LayoversCount);


    //FIX_ME: непонятный вывод, бех дружественного интерфейса
    StartCity++;
    cout << "Города, в которые из города " << StartCity << " можно долететь ровно с " << LayoversCount << " пересадками: ";
    if (ResultCities.empty())
    {
        cout << -1 << endl;
    }
    else 
    {
        for (int city : ResultCities)
        {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}