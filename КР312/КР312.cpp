//ChatGPT

//Напишите программу - телеграф, которая принимает от пользователя сообщение и выводит его на экран
// в виде последовательности точек и тире.

#include <iostream>
#include "Header.h"

int main() 
{
    using namespace std;

    //FIX_ME: нет поддержки русского языка
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Ввод сообщения
    //FIX_ME: неправильное название переменной
    //string message;
    string InputMessage;
    cout << "Введите сообщение: ";

    //FIX_ME: ввод без проверки
    //getline(cin, InputMessage);
    if (!std::getline(std::cin, InputMessage))
    {
        std::cout << "Ошибка при чтении ввода" << std::endl;
        return 1;
    }

    // Преобразуем сообщение в код Морзе
    //FIX_ME: неправильное название переменной
    //string morse_message
    string MorseMessage = ConvertToMorse(InputMessage);

    // Выводим результат
    cout << "Сообщение в коде Морзе: " << endl;
    cout << MorseMessage << endl;

    return 0;
}