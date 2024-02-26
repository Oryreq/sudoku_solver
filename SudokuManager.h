#pragma once
#include <iostream>
#include <iomanip>
#include <tuple>
#include <vector>

#include "SudokuSolver.h"

using namespace std;

class SudokuManager
{
	private:
		vector<vector<int>> field;

		SudokuSolver solver;

		vector<int> fillDigitsPool()
		{
			vector<int> digitsPool;
			digitsPool.reserve(field.size());
			for (size_t i = 1; i <= field.size(); i++) {
				digitsPool.push_back(i);
			}
			return digitsPool;
		}

		int getMiniSquareSize()
		{
			auto miniSquareSize = sqrt(field.size());
			return miniSquareSize == floor(miniSquareSize) ? miniSquareSize : 0;
		}
	

	public:
		bool canCreateField(const int& size)
		{
			return size > 0;
		}

		void readFieldFromConsole(const int& size)
		{
			for (size_t i = 0; i < size; i++) {
				vector<int> line;
				int digit;
				size_t j = 0;
				while (cin >> digit) {
					line.push_back(digit);
					j++;
					if (j % size == 0) {
						break;
					}
				}
				field.push_back(line);
				j = 0;
			}
		}

		void printField()
		{
			for (auto& line : field) {
				for (auto& digit : line) {
					cout << digit << " ";
				}
				cout << endl;
			}
		}

		void solve()
		{
			vector<int> digitsPool = fillDigitsPool();
			int miniSquareSize = getMiniSquareSize();
			field = solver.solve(field, digitsPool, miniSquareSize);
		}

};

