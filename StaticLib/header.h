#pragma once
const int INF = 666666666;
int readIntegerInLine();
int** initMatrix(int, int);
void free2DMatrix(int**, int);
long double solveProblem(int N, int K, int** arr);