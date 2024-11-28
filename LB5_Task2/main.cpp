#include <iostream>
#include <Windows.h>
#include "../DynamicLib/header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "���������, ��� �������� ����������� �������, ��� ������ ������� ����� B^2 + cos(B)\n";
    cout << "�������� ������� ������, ������ 453502\n";
   // HINSTANCE LoadLibrary(L"DynamicLib.dll");
    //LoadLibrary(L"DynamicLib.dll") = LoadLibrary(L"DynamicLib.dll")Library(LoadLibrary(L"DynamicLib.dll"));
    typedef int (*readInteger)();
    readInteger read1;
    read1 = (readInteger)GetProcAddress(LoadLibrary(L"DynamicLib.dll"), "readIntegerInLine");
    typedef int (*readDouble)();
    readDouble read2;
    read2 = (readDouble)GetProcAddress(LoadLibrary(L"DynamicLib.dll"), "readDoubleInLine");
    typedef long double (*COS)(long double x);
    COS read3;
    read3 = (COS)GetProcAddress(LoadLibrary(L"DynamicLib.dll"), "COS");
    typedef int (*solve)(long double* arr, int start, int end);
    solve read4;
    read4 = (solve)GetProcAddress(LoadLibrary(L"DynamicLib.dll"), "solveProblem");

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
    //FreeLibrary(LoadLibrary(L"DynamicLib.dll"));
	return 0;
}