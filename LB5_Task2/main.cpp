#include <iostream>
#include <Windows.h>
#include "../DynamicLib/header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Программа, для подсчета произвдения массива, где каждый элемент равен B^2 + cos(B)\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
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
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы: ";
        int type = readIntegerInLine();
        while ((type != 1 && type != 2)) {
            cout << "Введите либо 1, либо 2: ";
            type = readIntegerInLine();
        }
        if (type == 2)
            break;
        else if (type != 1 && type != 2)
            continue;

        cout << "Введите N(натуральное число):";
        int N = readIntegerInLine();
        while (N < 1) {
            cout << "Некорректный ввод! Введите натуральное число: ";
            N = readIntegerInLine();
        }

        long double* arr = new long double[N];
        for (int i = 0; i < N; ++i) {
            cout << "Введите коэффицент для " << i + 1 << " многочлена: ";
            arr[i] = readDoubleInLine();
            while (arr[i] == -INF) {
                cout << "Некорректный ввод! Введите ещё раз: ";
                arr[i] = readDoubleInLine();
            }
        }

        long double res = solveProblem(arr, 0, N-1);

        cout << "Произведение всех элементов равно: " << res << '\n';

        delete[] arr;
        arr = NULL;
    }
    //FreeLibrary(LoadLibrary(L"DynamicLib.dll"));
	return 0;
}