#pragma once
#include <iostream>
#include <map>
//FIX_ME: добавлена библиотека windows.h для русской кодировки
#include <windows.h>
#include <string>
#include <locale>
//FIX_ME: запрещено использование using namespace std глобально
//using namespace std;

//FIX_ME: для эффективности вынесем преобразование строки в отдельную функцию
std::string ConvertToMorseCode(const std::string& Message);

// Проверка, является ли символ русской буквой (для CP1251)
bool IsRussianLetter(char Char);
