#include <iostream>
#include "../StaticLib/header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Программа, для составления новой матрицы из четных элементов главной диагонали матрицы NxK\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while (true) {
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы: \n";
        int type = readIntegerInLine();
        while ((type != 1 && type != 2)) {
            cout << "Введите либо 1, либо 2: ";
            type = readIntegerInLine();
        }
        if (type == 2)
            break;
        else if (type != 1 && type != 2)
            continue;

        cout << "Введите кол-во строк в матрице N(натуральное число): ";
        int N = readIntegerInLine();
        while (N < 1) {
            cout << "Некорректный ввод! Введите натральное число: ";
            N = readIntegerInLine();
        }

        cout << "Введите кол-во стобцов в матрице K(натуральное число): ";
        int K = readIntegerInLine();
        while (K < 1) {
            cout << "Некорректный ввод! Введите натральное число: ";
            K = readIntegerInLine();
        }

        int** arr = initMatrix(N, K);
        
        long double calc = solveProblem(N, K, arr);
        cout << "Результат произвдения: " << calc << '\n';

        free2DMatrix(arr, N);
    }

    return 0;
}