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

long double readDoubleInLine() {
    long double number;
    if (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        return -INF;
    }

    return number;
}

long double** initMatrix(int N, int K) {
    long double** arr = new long double* [N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new long double[K];
    }

    cout << "������� �������� �������\n";
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " ������:\n";
        for (int j = 0; j < K; ++j) {
            cout << "������� " << j + 1 << " ������� �������: ";
            arr[i][j] = readDoubleInLine();
            while (arr[i][j] == -INF) {
                cout << "������������ ����! ������� ������: ";
                arr[i][j] = readDoubleInLine();
            }
        }
    }

    return arr;
}

void free2DMatrixInteger(int** arr, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
}

void free2DMatrixDouble(long double** arr, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
}

int findZeroesAmount(int N, int K, long double** arr) {
    int res = 0;
    for (int i = 0;i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (arr[i][j] == 0) res++;
        }
    }
    return res;
}

int** findZeroesLocation(int N, int K, long double** arr) {

    int size = findZeroesAmount(N, K, arr);

    if (size == 0)
        return 0;

    int** index = new int* [size];
    for (int i = 0; i < size; ++i) {
        index[i] = new int[2];
    }

    for (int i = 0, temp = 0;i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (arr[i][j] == 0) {
                index[temp][0] = i;
                index[temp][1] = j;
                temp++;
            }
        }
    }

    return index;
}