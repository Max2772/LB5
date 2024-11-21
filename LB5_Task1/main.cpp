#include <iostream>
#include "../MyLib/header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
    cout << "Программа, для заполнения матриц А и B по инструкциям, а также подсчет элементов матриц, расположенных по периметру\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while (true) {
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        while ((type != 1 && type != 2)) {
            cout << "Введите либо 1, либо 2: ";
            type = readIntegerInLine();
        }
        if (type == 2)
            break;
        else if (type != 1 && type != 2)
            continue;

        cout << "Введите размерность массивов N(натуральное число): ";
        int N;
        while (true) {
            N = readIntegerInLine();
            if (N < 1) {
                cout << "Введите натуральное число!: ";
                continue;
            }
            else
                break;
        }

        solveProblem(N);
    }
	return 0;
}