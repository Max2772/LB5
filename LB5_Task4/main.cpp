#include <iostream>
#include "../StaticLib/header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Программа, для опрделения нулевых элементов и создании обратной матрицы\n";
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
        int size = findZeroesAmount(N, K, arr);
        int** index = findZeroesLocation(N, K, arr);

        cout << "Общее количесвто нулевых элементов: " << size << '\n';
        cout << "Местоположения нулевых элементов в матрице:\n";
        int cnt = 1;
        for (int i = 0;i < size; ++i) {
                cout << cnt << " нулевой элемент: i = " << index[i][0] << ", j = " << index[i][1] << '\n';
                ++cnt;
        }

        free2DMatrix(arr, N);
        free2DMatrix(index, size);
    }

    return 0;
}