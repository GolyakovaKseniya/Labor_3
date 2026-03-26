//Deepseek

//Напишите программу - телеграф, которая принимает от пользователя сообщение и выводит его на экран
// в виде последовательности точек и тире.

#include "Header.h"
//FIX_ME: неправильное положение фигурной скобки
int main()
{
    //FIX_ME: нет поддержки русского языка и кодировки
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    //FIX_ME: неправильное название переменных
    //std::string message;
    std::string Message;

    std::cout << "Введите сообщение на русском языке: ";

    //FIX_ME: ввод осуществлен без проверки
    //std::getline(std::cin, Message);
    if (!std::getline(std::cin, Message))
    {
        std::cout << "Ошибка при чтении ввода" << std::endl;
        return 1;
    }

    //FIX_ME: вызываем функцию для преобразования
    std::cout << "Азбука Морзе: " << std::endl;
    std::string Result = ConvertToMorseCode(Message);
    std::cout << Result << std::endl;

    return 0;
}
