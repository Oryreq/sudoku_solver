/*
������� 1. ���������� �������� ��������� �� ����� �/C++, ������� ������ ������ � ����� ������.
��������� ������������ ��������� ����������. ��������, ��� ������ - ��� ���������� �����������,
������� ������� �� ���������� ����� �������� 9x9 ������, ����������� �� ������ ������ ����������
������ �������� 3x3 ������. � ������ ������ ���������� ��������� ����� �� 1 �� 9 ����� �������,
����� ������ ������, ������ ������� � ������ ������ ��������� ��� ����� �� 1 �� 9 ��� ����������.
�������, ��� � ����� ������, ������ ���� ����� ���� �����, ��������, 4�4, 9�9 � �.�.
� �������� ������ ���������� ������������ ����� � ��������� ��������� � �������� ��������� �������,
� ����� ������ �� �������� ����������� GitHub (��� �����������) � ����� ������������� ���������
(���� ���������� ������� �� ����� ���� ���������� ����������� ���� ���������) ��� ���������
������ �� ����� � �����. ������� � ������������� ���������� ����������� ��� ��������������
����������.
������� ������:
������ ������ �������� ����� ����� n. �����, ���� ���������� ���� ��� ������ ������� n x n, ���� n
�����, � ������ �� ������� ����� ������ �������� n ����� �����. ������ ������ ������ ���� ���������
������� ����� 0 (��� ������� ��������� ���������� �������� ������).
�������� ������:
���� ���� ��� ������ �������� n x n �� ����������, �������� �Invalid field� � ��������� ���������.
���� ���� ����������, �������� ���, ������ ������ � �������� �����. ������� ��� ������ ��������
����������� ������� �������� n x n. ������ ����� ������ ������� ������ ���������� � ����� ������, �
����� � ������ ������ ��������� ��������. �������������, ��� ��� ������� ������� ����������
�������.
������:
����:
4
1 4 3 2
0 0 1 4
4 1 2 3
2 3 0 0
�����:
1 4 3 2
3 2 1 4
4 1 2 3
2 3 4 1
*/

#include <iostream>
#include <locale.h>

#include "SudokuManager.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ����� ����� n ��� ����������� ����: ";
	int n;
	cin >> n;

	SudokuManager sudokuManager;
	if (!sudokuManager.canCreateField(n)) {
		cout << "Invalid field" << endl;
		return -1;
	}

	cout << "������� ������ ����� ����� ����� ������:" << endl;
	sudokuManager.readFieldFromConsole(n);
	sudokuManager.solve();

	cout << "�������� ������� ������:" << endl;
	sudokuManager.printField();

	return 0;
}