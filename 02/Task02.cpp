//Хромой король.На квадратной доске расставлены монеты, достоинством от 1 до
//100. Хромой король, находящийся в правом нижнем углу, мечтает попасть в левый верхний.
//При этом он может передвигаться только в клетку слева или сверху и хочет, чтобы сумма всех
//монет, оказавшихся у него на пути, была бы максимальной.Определить эту сумму и путь, каким
//образом должен двигаться король, чтобы ее собрать.Ввод и вывод организовать при помощи
//текстовых файлов.Формат входных данных : в первой строке входного файла записано число 
//N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых содержит N целых чисел,
//представляющих доску.В первую строку выходного файл нужно вывести единственное число :
//максимальную сумму, а во второй строке вывести путь в виде строки символов, обозначив 
//символом L движение влево, а символом U - движение вверх.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//FIX_ME: ((нету включение библиотеки algorithm))
#include <algorithm>
//FIX_ME: (запрещено испольбзовать пространство имён std)
//using namespace std;

void Solve(const std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& board2, int n) {
    int i, j;
    board2[n - 1][n - 1] = board[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        board2[i][n - 1] = board2[i + 1][n - 1] + board[i][n - 1];
    }
    for (j = n - 2; j >= 0; j--) {
        board2[n - 1][j] = board2[n - 1][j + 1] + board[n - 1][j];
    }

    for (i = n - 2; i >= 0; i--) {
        for (j = n - 2; j >= 0; j--) {
            if (board2[i + 1][j] > board2[i][j + 1]) {
                board2[i][j] = board2[i + 1][j] + board[i][j];
            }
            else {
                board2[i][j] = board2[i][j + 1] + board[i][j];
            }
        }
    }
}

std::string Path(const std::vector<std::vector<int>>& board2, int n) {
    std::string s = "";
    int i = 0, j = 0;

    while (i < n - 1 || j < n - 1) {
        if (i < n - 1 && j < n - 1) {
            if (board2[i + 1][j] > board2[i][j + 1]) {
                s += "U";
                i++;
            }
            else {
                s += "L";
                j++;
            }
        }
        else if (i < n - 1) {
            s += "U";
            i++;
        }
        else {
            s += "L";
            j++;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    setlocale(0, "");
    std::fstream f1("f1.txt");
    if (!f1.is_open()) {
        std::cout << "Не удалось открыть файл f1.txt(" << std::endl;
        return 1;
    }

    std::fstream f2("f2.txt");
    if (!f2.is_open()) {
        std::cout << "Не удалось открыть файл f2.txt(" << std::endl;
        return 1;
    }

    int n;
    f1 >> n;

    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            f1 >> board[i][j];
        }
    }

    std::vector<std::vector<int>> board2(n, std::vector<int>(n, 0));

    Solve(board, board2, n);

    f2 << board2[0][0] << std::endl;    
    f2 << Path(board2, n);

    f1.close();
    f2.close();

    return 0;
}
