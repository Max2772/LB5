#include <iostream>
#include "header.h"

using namespace std;

extern "C" {
    __declspec(dllexport) int readIntegerInLine() {
        int number;
        if (!(cin >> number) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "ќшибка ввода. ¬ведите заново: ";
            return -INF;
        }

        return number;
    }

    __declspec(dllexport) long double readDoubleInLine() {
        long double number;
        if (!(cin >> number) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "ќшибка ввода. ¬ведите заново: ";
            return -INF;
        }

        return number;
    }

    __declspec(dllexport) long double COS(long double x) {
        if (x > 1e20) {
            return 0;
        }

        if (x >= 0) {
            unsigned long long quotient = static_cast<unsigned long long>(x / TWO_PI);
            x -= quotient * TWO_PI;
        }
        else {
            signed long long quotient = static_cast<signed long long>(x / TWO_PI);
            x -= quotient * TWO_PI;
        }

        if (x > PI)
            x -= TWO_PI;
        else if (x < -PI)
            x += TWO_PI;

        long double sum = 0.0;
        long double term = 1;
        long double x_square = x * x;
        int sign = 1;

        for (int n = 0; n <= 25; ++n) {
            sum += sign * term;
            term *= x_square / ((2 * n + 1) * (2 * n + 2));
            sign *= -1;
        }

        return sum;
    }

    __declspec(dllexport) long double solveProblem(long double* arr, int start, int end) {
        if (start == end)
            return (arr[start] * arr[start] + COS(arr[start]));
        int mid = (start + end) / 2;
        long double leftarr = solveProblem(arr, start, mid);
        long double rightarr = solveProblem(arr, mid + 1, end);

        return leftarr * rightarr;
    }
}