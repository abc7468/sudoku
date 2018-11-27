#pragma once
#include <vector>

#define MAX_XY 9

class SudokuBoard
{
public:
	SudokuBoard();
	~SudokuBoard();

	void Create();
	bool IsSudokuRule();


private:

	bool IsRowCol(std::vector<int>& rowcol);
	void CreateRow(int row, std::vector<int>& v);
	int board[MAX_XY][MAX_XY]={0,};
	int XBoard[MAX_XY][MAX_XY] = { 0, };

};

