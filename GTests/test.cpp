#include "pch.h"
#include "../StaticLib/header.h"
#include <sstream> 


auto cinBuf = std::cin.rdbuf();

// readIntegerInLine()
TEST(ReadIntegerTest, INT_ValidInput1) {
    std::istringstream input("777\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), 777);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_ValidInput2) {
    std::istringstream input("3.1415\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadIntegerTest, INT_ValidInput3) {
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readIntegerInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

TEST(solveProblemTests, solveProblemTest1) {
    int N = 2, K = 2;
    int** arr = new int*[N];
    for (int i = 0; i < N; ++i)
        arr[i] = new int[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 2;
        }
    }
    EXPECT_EQ(solveProblem(N, K, arr), 4);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}

TEST(solveProblemTests, solveProblemTest2) {
    int N = 1, K = 1;
    int** arr = new int* [N];
    for (int i = 0; i < N; ++i)
        arr[i] = new int[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 1;
        }
    }
    EXPECT_EQ(solveProblem(N, K, arr), 0);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}
TEST(solveProblemTests, solveProblemTest3) {
    int N = 30, K = 30;
    int** arr = new int* [N];
    for (int i = 0; i < N; ++i)
        arr[i] = new int[K];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            arr[i][j] = 2147483600;
        }
    }
    EXPECT_EQ(solveProblem(N, K, arr), 9.07602484958231015e+279);

    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
        arr[i] = NULL;
    }
    delete[] arr;
    arr = NULL;
}
