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

    cout << "������� �������� �������\n";
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " ������:\n";
        for (int j = 0; j < K; ++j) {
            cout << "������� " << j + 1 << " ������� �������: ";
            arr[i][j] = readIntegerInLine();
            while (arr[i][j] == -INF) {
                cout << "������������ ����! ������� ������: ";
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
    for (int i = 0; i < N && i < K; ++i) {
        if (arr[i][i] % 2 == 0)
            size++;
    }
    if (size == 0)
        return 0;

    int* res = new int[size];

    for (int i = 0, j = 0; i < N && i < K; ++i) {
        if (arr[i][i] % 2 == 0) { res[j] = arr[i][i]; ++j; }
    }


    long double calc = 1;
    cout << "���������� �������: ";
    for (int i = 0; i < size; ++i) {
        cout << res[i] << ' ';
        calc *= res[i];
    }

    delete[] res;
    res = NULL;

    return calc;

}