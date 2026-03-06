//К - ичные числа.Среди чисел в системе счисления с основанием K(2≤K≤10) определить сколько 
//имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи не содержится более 
//трех подряд идущих нулей.Для того, чтобы избежать переполнения, ответ
//представьте в виде вещественного числа.

#include <iostream>
#include <cmath>
#include <string>
#include <Windows.h>
//using namespace std; //FIX_ME: (запрещено испольбзовать пространство имён std)

//bool NoThreeZeros(std::string &num)//FIX_ME: (некорректное название функций)
bool no_ThreeZeros(std::string& num)
{
    int count = 0;
    for (char ch : num)
    {
        if (ch == '0')
        {
            count++;
            if (count > 3)
                return false;
        }
        else
            count = 0;
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int k, n;

    while (true)
    {
        std::cout << "Введите основание системы счисления K(2 <= K <= 10): ";
        std::cin >> k;
        if (k >= 2 && k <= 10)
        {
            break;
        }
        else
        {
            std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Введите кол-во разрядов N(1 < N < 20): ";
        std::cin >> n;
        if (n > 1 && n < 20 && (n + k) < 26)
        {
            break;
        }
        else
        {
            std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
        }
    }

    double total = 0;
    for (int i = pow(k, n - 1); i < pow(k, n); i++)
    {
        std::string num = "";
        int temp = i;

        if (k != 10)
        {
            for (int j = 0; j < n; j++)
            {
                num = std::to_string(temp % k) + num;
                temp = temp / k;
            }
        }

        if (num[0] != '0' && no_ThreeZeros(num))
        {
            total++;
        }
    }

    std::cout << "Количество чисел: " << total << std::endl;
    return 0;
}