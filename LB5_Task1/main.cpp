#include <iostream>
#include "../MyLib/header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
    cout << "���������, ��� ���������� ������ � � B �� �����������, � ����� ������� ��������� ������, ������������� �� ���������\n";
    cout << "�������� ������� ������, ������ 453502\n";
    while (true) {
        cout << "������� 1, ���� ������ ��������� ���������, ��� 2, ���� ������ ��������� ������ ���������\n";
        int type = readIntegerInLine();
        while ((type != 1 && type != 2)) {
            cout << "������� ���� 1, ���� 2: ";
            type = readIntegerInLine();
        }
        if (type == 2)
            break;
        else if (type != 1 && type != 2)
            continue;

        cout << "������� ����������� �������� N(����������� �����): ";
        int N;
        while (true) {
            N = readIntegerInLine();
            if (N < 1) {
                cout << "������� ����������� �����!: ";
                continue;
            }
            else
                break;
        }

        solveProblem(N);
    }
	return 0;
}