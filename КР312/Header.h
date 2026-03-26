#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
//FIX_ME: добавлена библиотека <windows.h> для русской конфигурации
#include <windows.h>
#include <algorithm>

//FIX_ME: запрещено использовать using namespace std глобально
//using namespace std;

// Функция для преобразования строки в код Морзе
//FIX_ME: неправильное положение фигурной скобки
//FIX_ME: неинформативное название функции
//FIX_ME: неправильное название параметра
//std::string toMorse(std::string message) 
std::string ConvertToMorse(std::string Message);