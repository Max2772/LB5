//#pragma once

extern "C" {
    __declspec(dllexport) const int INF = 666666666;
    __declspec(dllexport) const long double PI = 3.141592653589793238462643383279502884L;
    __declspec(dllexport) const long double TWO_PI = 2.0L * PI;
    __declspec(dllexport) int readIntegerInLine();
    __declspec(dllexport) long double readDoubleInLine();
    __declspec(dllexport) long double COS(long double x);
    __declspec(dllexport) long double solveProblem(long double* arr, int start, int end);
}