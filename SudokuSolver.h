#pragma once

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class SudokuSolver
{
	private:
		vector<vector<int>> field;

		vector<int> digitsPool;
		int miniSquareSize;

		tuple<int, int> findFreeCellCoords()
		{
			for (size_t i = 0; i < field.size(); i++) {
				for (size_t j = 0; j < field.size(); j++) {
					if (field[i][j] == 0) {
						return make_tuple(i, j);
					}
				}	
			}
			return make_tuple(-1, -1);
		}

		bool canInsert(int& digit, int& k, int& m)
		{
			for (size_t i = 0; i < field.size(); i++) {
				if (field[i][m] == digit && i != k) {
					return false;
				}
			}

			for (size_t j = 0; j < field.size(); j++) {
				if (field[k][j] == digit && j != m) {
					return false;
				}
			}

			if (miniSquareSize == 0) {
				return true;
			}

			auto upperBorder = (int) floor(k / miniSquareSize) * miniSquareSize;
			auto leftBorder = (int) floor(m / miniSquareSize) * miniSquareSize;

			for (size_t i = upperBorder; i < upperBorder + miniSquareSize; i++) {
				for (size_t j = leftBorder; j < leftBorder + miniSquareSize; j++) {
					if (field[i][j] == digit && i != k && j != m) {
						return false;
					}
				}
			}

			return true;
		}

		bool recursiveSolve()
		{
			auto [i, j] = findFreeCellCoords();

			if (i == -1) {
				return true;
			}

			for (auto digit : digitsPool) {
				if (canInsert(digit, i, j)) {
					field[i][j] = digit;
				
					if (recursiveSolve()) {
						return true;
					}

					field[i][j] = 0;
				}
			}

			return false;
		}

	public:
		vector<vector<int>> solve(vector<vector<int>>& field, vector<int>& digitsPool, int& miniSquareSize)
		{
			this->field = field;
			this->digitsPool = digitsPool;
			this->miniSquareSize = miniSquareSize;

			recursiveSolve();
			return this->field;
		}
};

