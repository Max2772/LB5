#include "pch.h"
#include "../DynamicLib/header.h"
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

// readDoubleInLine()
TEST(ReadDoubleTest, DOUBLE_ValidInput1) {
    std::istringstream input("777\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readDoubleInLine(), 777);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_ValidInput2) {
    std::istringstream input("3.1415\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readDoubleInLine(), 3.1415);
    std::cin.rdbuf(cinBuf);
}

TEST(ReadDoubleTest, DOUBLE_InvalidInput3) {
    std::istringstream input("abc\nkdskosmgomsongonsdgn\n");
    std::cin.rdbuf(input.rdbuf());
    EXPECT_EQ(readDoubleInLine(), -INF);
    std::cin.rdbuf(cinBuf);
}

//COS()
TEST(CosineTest, CosineTest1) {
    long double x = 3.1415;
    EXPECT_NEAR(COS(x), -1, 0.00001);
}

TEST(CosineTest, CosineTest2) {
    long double x = 0;
    EXPECT_NEAR(COS(x), 1, 0.00001);
    x = 6.2831853;
    EXPECT_NEAR(COS(x), 1, 0.00001);
}

TEST(CosineTest, CosineTest3) {
    long double x = 1e15;
    EXPECT_NEAR(COS(x), -0.526266, 0.00001);
}

TEST(CosineTest, CosineTest4) {
    long double x = -1e15;
    EXPECT_NEAR(COS(x), -0.526266, 0.00001);
}

//solveProblem()
TEST(solveProblemTest, solveProblemTest1) {
    long double* arr = new long double[2] {0, 3.1415};
    long double res = 8.86902;
    EXPECT_NEAR(solveProblem(arr, 0, 1), res, 0.00001);
    delete[] arr;
    arr = NULL;
}

TEST(solveProblemTest, solveProblemTest2) {
    long double* arr = new long double[8] {1, 2, 3, 4, 5, 6, 7, 8};
    long double res = 2014591396.589694;
    EXPECT_NEAR(solveProblem(arr, 0, 7), res, 0.00001);
    delete[] arr;
    arr = NULL;
}
