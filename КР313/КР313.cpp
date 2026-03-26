//Gemini

//Напишите программу - телеграф, которая принимает от пользователя сообщение и выводит его на экран
// в виде последовательности точек и тире.

#include "Header.h"

int main() 
{
    using namespace std;
    // Устанавливаем кодировку для Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    //FIX_ME: неправильное название переменных
    /*wstring userMessage;
    wchar_t showTable;*/
    wstring UserMessage;
    wchar_t ShowTableMorse;

    // Приветствие
    wcout << L"========================================" << endl;
    wcout << L"        ПРОГРАММА-ТЕЛЕГРАФ" << endl;
    wcout << L"========================================" << endl;

    // Спрашиваем, нужно ли показать таблицу
    wcout << L"Показать таблицу азбуки Морзе? (y/n): ";
    wcin >> ShowTableMorse;
    wcin.ignore(); // Очищаем буфер

    if (ShowTableMorse == L'y' || ShowTableMorse == L'Y')
    {
        PrintMorseTable();
    }
    //FIX_ME: добавлено условие для неправильного ввода
    else
    {
        cout << "Ошибка, вы ввели не ту букву" << endl;
        return 1;
    }

    // Основной цикл программы
    while (true) 
    {
        wcout << L"\nВведите сообщение на русском языке (или 'exit' для выхода):" << endl;
        wcout << L"> ";

        getline(wcin, UserMessage);

        // Проверка на выход
        if (UserMessage == L"exit" || UserMessage == L"выход" || UserMessage == L"q")
        {
            wcout << L"До свидания!" << endl;
            break;
        }

        // Проверка на пустое сообщение
        if (UserMessage.empty())
        {
            wcout << L"Ошибка: Вы не ввели сообщение!" << endl;
            continue;
        }

        // Проверка, есть ли в сообщении хоть одна буква
        //FIX_ME: неправильное название переменных
        /*bool hasLetter = false;
        for (wchar_t ch : UserMessage)*/
        bool bHasLetter = false;
        for (wchar_t Charter : UserMessage) 
        {
            wchar_t UpperCh = towupper(Charter);
            if (MorseCode.find(UpperCh) != MorseCode.end()) 
            {
                bHasLetter = true;
                break;
            }
        }

        if (!bHasLetter) 
        {
            wcout << L"Ошибка: Сообщение не содержит допустимых символов!" << endl;
            continue;
        }

        // Преобразуем сообщение в азбуку Морзе
        //FIX_ME: неправильное название переменной
        //wstring morseResult = TextToMorse(UserMessage);
        wstring MorseResult = TextToMorse(UserMessage);

        // Выводим результат
        wcout << L"\n----------------------------------------" << endl;
        wcout << L"Исходное сообщение: " << UserMessage << endl;
        wcout << L"Азбука Морзе:" << endl;

        // Преобразуем wstring в string для вывода (если нужно)
        for (wchar_t Charter : MorseResult) 
        {
            if (Charter == L'/') 
            {
                cout << '/';
            }
            else if (Charter == L'.' || Charter == L'-') 
            {
                cout << (char)Charter;
            }
            else if (Charter == L' ')
            {
                cout << ' ';
            }
        }
        wcout << endl;
        wcout << L"----------------------------------------" << endl;

        // Статистика
        //FIX_ME: неправильное название переменной
        //int letterCount = 0;
        int LetterCount = 0;
        for (wchar_t Charter : UserMessage) 
        {
            if (Charter != L' ' && Charter != L'\t') 
            {
                wchar_t UpperChar = towupper(Charter);
                if (MorseCode.find(UpperChar) != MorseCode.end()) 
                {
                    LetterCount++;
                }
            }
        }
        wcout << L"Всего символов: " << UserMessage.length() << endl;
        wcout << L"Всего букв: " << LetterCount << endl;
    }

    return 0;
}