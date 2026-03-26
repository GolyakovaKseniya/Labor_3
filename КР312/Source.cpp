#include "Header.h"

// Создаём словарь для русского алфавита в азбуке Морзе
//FIX_ME: неправильное название переменной
//std::unordered_map<char, std::string> morse_code
std::unordered_map<char, std::string> MorseCode =
{
    {'А', ".-"}, {'Б', "-..."}, {'В', ".--"}, {'Г', "--."}, {'Д', "-.."},
    {'Е', "."}, {'Ё', "."}, {'Ж', "...-"}, {'З', "--.."}, {'И', ".."},
    {'Й', ".---"}, {'К', "-.-"}, {'Л', ".-.."}, {'М', "--"}, {'Н', "-."},
    {'О', "---"}, {'П', ".--."}, {'Р', ".-."}, {'С', "..."}, {'Т', "-"},
    {'У', "..-"}, {'Ф', "..-."}, {'Х', "...."}, {'Ц', "-.-."}, {'Ч', "---."},
    {'Ш', "----"}, {'Щ', "--..-"}, {'Ь', "-..-"}, {'Ы', "-.--"}, {'Э', "..-.."},
    {'Ю', "..--"}, {'Я', ".-.-"}
};

// Функция для преобразования строки в код Морзе
//FIX_ME: неправильное положение фигурной скобки
//FIX_ME: неинформативное название функции
//FIX_ME: неправильное название параметра
//std::string toMorse(std::string message) 
std::string ConvertToMorse(std::string Message)
{
    //FIX_ME: добавлена проверка на пустое сообщение
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


    //FIX_ME: неправильное название переменной
    //std::stringstream morse_message;
    std::stringstream MorseMessage;

    int LettersFound = 0;

    // Преобразуем каждую букву в код Морзе
    for (char& Character : Message)
    {
        // Приводим символ к верхнему регистру
        Character = toupper(Character);

        // Если это буква или пробел, добавляем соответствующий код
        if (Character == ' ')
        {
            MorseMessage << "   ";  // Пробел в сообщении — это 3 пробела в Морзе
        }
        else if (MorseCode.find(Character) != MorseCode.end())
        {
            MorseMessage << MorseCode[Character] << " ";
            ++LettersFound;
        }
        //FIX_ME: добавлена проверка на неподходящие символы
        else
        {
            std::cout << "Предупреждение: символ '" << Character
                << "' пропущен (не поддерживается)" << std::endl;
        }
    }

    // Проверка, что хотя бы одна буква была преобразована
    if (LettersFound == 0)
    {
        std::cout << "Ошибка: не найдено поддерживаемых символов для преобразования" << std::endl;
        return "";
    }

    return MorseMessage.str();
}
