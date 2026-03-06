#pragma once

//FIX_ME: (лишнее включение библиотеки windows.h)
//# include <windows.h>
//FIX_ME: (нету включение библиотеки clocale, random)
#include <iostream>
#include <clocale>
#include <random>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>

//FIX_ME: (нет комментариев для функции)
void find(const std::vector<std::vector<int>>& a, int k, int s, const std::vector<int>& w, double& weight);// поиск коробки
