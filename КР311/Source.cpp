#include "Header.h"

// Проверка, является ли символ русской буквой (для CP1251)
bool IsRussianLetter(char Char)
{
    unsigned char Charter = static_cast<unsigned char>(Char);

    // Русские буквы в CP1251: А-Я (192-223), а-я (224-255), Ё (168), ё (184)
    return (Charter >= 192 && Charter <= 255) || Charter == 168 || Charter == 184;
}

//FIX_ME: для эффективности вынесем преобразование строки в отдельную функцию
std::string ConvertToMorseCode(const std::string& Message)
{
    //FIX_ME: добавлена проверка на пустоту
    if (Message.empty())
    {
        std::cout << "Ошибка: сообщение не может быть пустым" << std::endl;
        return "";
    }

    //FIX_ME: добавлена проверка на пробелы
    bool bOnlySpaces = true;
    for (char Char : Message)
    {
        if (Char != ' ')
        {
            bOnlySpaces = false;
            break;
        }
    }

    if (bOnlySpaces)
    {
        std::cout << "Ошибка: сообщение не может состоять только из пробелов" << std::endl;
        return "";
    }

    //FIX_ME: неправильное название карты map
    // std::map<char, std::string> morseCode
    // Добавляем в словарь и заглавные, и строчные буквы
    std::map<char, std::string> MorseCode =
    {
        {'А', ".-"},    {'Б', "-..."},  {'В', ".--"},   {'Г', "--."},
        {'Д', "-.."},   {'Е', "."},     {'Ё', "."},     {'Ж', "..."},
        {'З', "--.."},  {'И', ".."},    {'Й', ".---"},  {'К', "-.-"},
        {'Л', ".-.."},  {'М', "--"},    {'Н', "-."},    {'О', "---"},
        {'П', ".--."},  {'Р', ".-."},   {'С', "..."},   {'Т', "-"},
        {'У', "..-"},   {'Ф', "..-."},  {'Х', "...."},  {'Ц', "-.-."},
        {'Ч', "---."},  {'Ш', "----"},  {'Щ', "--.-"},  {'Ъ', ".--.-."},
        {'Ы', "-.--"},  {'Ь', "-..-"},  {'Э', "..-.."}, {'Ю', "..--"},
        {'Я', ".-.-"}
    };

    //FIX_ME: неправильное название переменных
    //std::string result = "";
    std::string Result = "";

    //FIX_ME: добавлена проверка на символы не из русского алфавита
    int LettersFound = 0;

    //FIX_ME: неправильное название переменной
    //for (char ch : Message)
    for (char Char : Message)
    {
        if (Char == ' ')
        {
            Result += "   ";
        }
        else
        {
            //FIX_ME: неправильное название переменной
            //char upperChar = toupper(Char);
            char UpperChar = toupper(Char);

            // Проверка, является ли символ русской буквой
            if (!IsRussianLetter(UpperChar))
            {
                std::cout << "Предупреждение: символ '" << Char << "' пропущен (не русская буква)" << std::endl;
                continue;
            }

            // Проверяем, есть ли буква в словаре
            if (MorseCode.find(UpperChar) != MorseCode.end())
            {
                Result += MorseCode[UpperChar] + " ";
                ++LettersFound;
            }
        }
    }

    //FIX_ME: добавлена проверка, что хотя бы 1 буква преобразована
    if (LettersFound == 0)
    {
        std::cout << "Ошибка: не найдено русских букв для преобразования" << std::endl;
        return "";
    }

    if (!Result.empty() && Result.back() == ' ')
    {
        Result.pop_back();
    }

    return Result;
}