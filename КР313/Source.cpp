#include "Header.h"

// Словарь азбуки Морзе для букв русского алфавита
//FIX_ME: неправильное название переменной
//FIX_ME: неправильное положение фигурных скобок
//std::map<wchar_t, std::wstring> morse
const std::map<wchar_t, std::string> MorseCode =
{
    {L'А', ".-"},    {L'Б', "-..."},  {L'В', ".--"},   {L'Г', "--."},
    {L'Д', "-.."},   {L'Е', "."},     {L'Ё', "."},     {L'Ж', "...-"},
    {L'З', "--.."},  {L'И', ".."},    {L'Й', ".---"},  {L'К', "-.-"},
    {L'Л', ".-.."},  {L'М', "--"},    {L'Н', "-."},    {L'О', "---"},
    {L'П', ".--."},  {L'Р', ".-."},   {L'С', "..."},   {L'Т', "-"},
    {L'У', "..-"},   {L'Ф', "..-."},  {L'Х', "...."},  {L'Ц', "-.-."},
    {L'Ч', "---."},  {L'Ш', "----"},  {L'Щ', "--.-"},  {L'Ъ', "--.--"},
    {L'Ы', "-.--"},  {L'Ь', "-..-"},  {L'Э', "..-.."}, {L'Ю', "..--"},
    {L'Я', ".-.-"}
};

// Функция для преобразования сообщения в азбуку Морзе (работает с широкими строками)
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//std::wstring textToMorse(const std::wstring& message) 
std::wstring TextToMorse(const std::wstring& Message)
{
    using namespace std;

    //FIX_ME: неправильное название переменной
    //wstring result;
    wstring Result;

    //FIX_ME: неправильное название переменной
    // for (wchar_t ch : Message)
    for (wchar_t Charter : Message)
    {
        if (Charter == L' ')
        {
            // Пробел между словами обозначается как /
            if (!Result.empty() && Result.back() != L'/')
            {
                Result += L" / ";
            }
        }
        else
        {
            // Преобразуем букву в верхний регистр
            //FIX_ME: неправильное название переменных
            /*wchar_t upperChar = towupper(Charter);
            auto it = MorseCode.find(upperChar);*/
            wchar_t UpperChar = towupper(Charter);
            auto Iterator = MorseCode.find(UpperChar);

            if (Iterator != MorseCode.end())
            {
                if (!Result.empty() && Result.back() != L'/' && Result.back() != L' ') {
                    Result += L" ";
                }
                // Преобразуем string в wstring
                //FIX_ME: неправильное название переменной
                // string morse = Iterator->second;
                string Morse = Iterator->second;
                Result += wstring(Morse.begin(), Morse.end());
            }
        }
    }

    return Result;
}

// Функция для вывода таблицы азбуки Морзе
//FIX_ME: неправильное название функции
//void printMorseTable()
void PrintMorseTable()
{
    using namespace std;
    wcout << L"\nТаблица азбуки Морзе:" << endl;
    wcout << L"----------------------------------------" << endl;

    //FIX_ME: неправильное название переменной
    //int count = 0;
    int CountElement = 0;

    //FIX_ME: неправильное название переменной
    //for (const auto& pair : MorseCode) 
    for (const auto& PairCode : MorseCode)
    {
        wcout << L"  " << PairCode.first << L" ? " << PairCode.second.c_str();

        //FIX_ME: постфиксный инкремент
        //CountElement++;
        ++CountElement;
        if (CountElement % 4 == 0)
        {
            wcout << endl;
        }
        else
        {
            wcout << L"   ";
        }
    }
    wcout << L"\n----------------------------------------" << endl;
}