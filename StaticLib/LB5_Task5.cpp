#include <iostream>
#include "header.h"

using namespace std;

int readIntegerInLine() {
    int number;
    if (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        return -INF;
    }

    return number;
}

int** initMatrix(int N, int K) {
    int** arr = new int* [N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int[K];
    }

    cout << "Введите элементы матрицы\n";
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " строка:\n";
        for (int j = 0; j < K; ++j) {
            cout << "Введите " << j + 1 << " элемент матрицы: ";
            arr[i][j] = readIntegerInLine();
            while (arr[i][j] == -INF) {
                cout << "Некорректный ввод! Введите заново: ";
                arr[i][j] = readIntegerInLine();
            }
        }
    }

    return arr;
}

void free2DMatrix(int** arr, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
}


long double solveProblem(int N, int K, int** arr) {
    int size = 0;
    for (int j = 0; j < K; j += 2) {
        for (int i = 0; i < N; ++i) {
            if (arr[i][j] % 2 != 0)
                size++;
        }
    }

    if (size == 0)
        return 0;

    int* res = new int[size];
    for (int j = 0, cnt = 0; j < K; j += 2) {
        for (int i = 0; i < N; ++i) {
            if (arr[i][j] % 2 != 0) {
                res[cnt] = arr[i][j];
                cnt++;
            }
        }
    }

    long double calc = 0;
    cout << "Элементы новой матрицы: ";
    for (int i = 0; i < size; ++i) {
        cout << res[i] << ' ';
        calc += res[i];
    }

    calc /= size;

    delete[] res;
    res = NULL;

    return calc;
}