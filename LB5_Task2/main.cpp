#include <iostream>
#include <Windows.h>
#include "../DynamicLib/header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "���������, ��� �������� ������������� �������� � ������ ����, ��������� ������������ ����� � ��������\n";
    cout << "�������� ������� ������, ������ 453502\n";
    HINSTANCE load;
    load = LoadLibrary(L"DynamicLib.dll");
    typedef int (*readInteger)();
    readInteger read1;
    read1 = (readInteger)GetProcAddress(load, "readIntegerInLine");
    typedef int (*readDouble)();
    readDouble read2;
    read2 = (readDouble)GetProcAddress(load, "readDoubleInLine");
    typedef long double (*COS)();
    COS read3;
    read3 = (COS)GetProcAddress(load, "COS");
    typedef int (*solve)();
    solve read4;
    read4 = (solve)GetProcAddress(load, "solveProblem");

    while (true) {
        cout << "������� 1, ���� ������ ��������� ���������, ��� 2, ���� ������ ��������� ������ ���������: ";
        int type = readIntegerInLine();
        while ((type != 1 && type != 2)) {
            cout << "������� ���� 1, ���� 2: ";
            type = readIntegerInLine();
        }
        if (type == 2)
            break;
        else if (type != 1 && type != 2)
            continue;

        cout << "������� N(����������� �����):";
        int N = readIntegerInLine();
        while (N < 1) {
            cout << "������������ ����! ������� ����������� �����: ";
            N = readIntegerInLine();
        }

        long double* arr = new long double[N];
        for (int i = 0; i < N; ++i) {
            cout << "������� ���������� ��� " << i + 1 << " ����������: ";
            arr[i] = readDoubleInLine();
            while (arr[i] == -INF) {
                cout << "������������ ����! ������� ��� ���: ";
                arr[i] = readDoubleInLine();
            }
        }

        long double res = solveProblem(arr, 0, N-1);

        cout << "������������ ���� ��������� �����: " << res << '\n';

        delete[] arr;
        arr = NULL;
    }
    FreeLibrary(load);
	return 0;
}