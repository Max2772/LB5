#include <iostream>
#include <Windows.h>
#include "../DynamicLib/header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Программа, для смещения максимального элемента к левому углу, используя перестановки строк и столбцов\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
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
    FreeLibrary(load);
	return 0;
}