#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <Windows.h>
//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

// Словарь азбуки Морзе для букв русского алфавита
//FIX_ME: неправильное название переменной
//FIX_ME: неправильное положение фигурных скобок
//std::map<wchar_t, std::wstring> morse
extern const std::map<wchar_t, std::string> MorseCode;

// Функция для преобразования сообщения в азбуку Морзе (работает с широкими строками)
//FIX_ME: неправильное название функции
//FIX_ME: неправильное название параметра функции
//std::wstring textToMorse(const std::wstring& message) 
std::wstring TextToMorse(const std::wstring& Message);

// Функция для вывода таблицы азбуки Морзе
//FIX_ME: неправильное название функции
//void printMorseTable()
void PrintMorseTable();
