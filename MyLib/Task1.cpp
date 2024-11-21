#include <iostream>
#include "header.h"

using std::cout;
using std::cin;

int readIntegerInLine() {
    int number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "������ �����. ������� ������: ";
        return -INF;
    }

    return number;
}

long long solveProblem(int N) {

    long double** arrA = new long double* [N];
    for (int i = 0; i < N; i++) {
        arrA[i] = new long double[N];
    }

    long double** arrB = new long double* [N];
    for (int i = 0; i < N; i++) {
        arrB[i] = new long double[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i <= 5) {
                arrA[i][j] = 3 * i * j - 3;
            }
            else {
                arrA[i][j] = 2 * i * j - 2;
            }
        }
        for (int j = 0; j < N; j++) {
            if (i > 7) {
                arrB[i][j] = 4 * i * j - 5;
            }
            else {
                arrB[i][j] = 5 * i * j - 4;
            }
        }
    }

    long double perimeterSumA = 0, perimeterSumB = 0;
    if (N == 1) {
        perimeterSumA += arrA[0][0];
        perimeterSumB += arrB[0][0];
    }
    else {
        for (int j = 0; j < N; j++) { // ������� ����� ������ � ��������� ������
            perimeterSumA += arrA[0][j] + arrA[N - 1][j];
            perimeterSumB += arrB[0][j] + arrB[N - 1][j];
        }
    }


    for (int i = 1; i < N - 1; i++) { // ������� ����� ��������� ������ � ������� �������
        perimeterSumA += arrA[i][0] + arrA[i][N - 1];
        perimeterSumB += arrB[i][0] + arrB[i][N - 1];
    }

    cout << "���������� ������ A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "   " << arrA[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "����� ��������� �� ���������: " << perimeterSumA << '\n';
    cout << '\n';

    cout << "���������� ������ B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "   " << arrB[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "����� ��������� �� ���������: " << perimeterSumB << '\n';
    cout << '\n';



    for (int i = 0; i < N; i++) {
        delete arrA[i];
        delete arrB[i];
    }

    delete[] arrA;
    delete[] arrB;

    return perimeterSumA + perimeterSumB;
}