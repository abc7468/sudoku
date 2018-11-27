#include "SudokuBoard.h"
#include <random>
#include <vector>
#include <array>

using namespace std;

SudokuBoard::SudokuBoard()
{
}


SudokuBoard::~SudokuBoard()
{
}

void SudokuBoard::Create()
{
	vector<int>		v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	array<int, 8>	s = { 3, 3, 1, 3, 3, 1, 3, 3 };		// 좌로 시프트 칸의 수

	// Mersenne Twister 알고리즘 std::mt19937에 기반한 난수 생성 
	random_device rd;
	mt19937 g(rd());

	// vector v의 요소를 섞는다(경우의 수는 9!=362880)
	shuffle(v.begin(), v.end(), g);
	// board row 0 생성
	CreateRow(0, v);

	// board row 1 ~ 8까지 생성
	for (size_t i = 0; i < s.size(); i++)
	{
		// vecotor v, s[i]만큼 좌로 쉬프트
		rotate(v.begin(), v.begin() + s[i], v.end());
		// board i+1 생성
		CreateRow(i + 1, v);
	}

	//// col,row 0~2, 3~5, 6~8에서 2열씩 swap한다 (보완코드)
	array<int, 3> sw = { 0, 1, 2 };	// swap 

	// col swap
	int c1, c2, inc = 0;
	for (int i = 0; i < sw.size(); i++, inc += 3)
	{
		shuffle(sw.begin(), sw.end(), g);
		c1 = sw[0] + inc;
		c2 = sw[1] + inc;
		for (int ir = 0; ir < MAX_XY; ir++)
			std::swap(board[c1][ir], board[c2][ir]);
	}

	// row swap
	int r1, r2;
	inc = 0;
	for (int i = 0; i < sw.size(); i++, inc += 3)
	{
		// row 
		shuffle(sw.begin(), sw.end(), g);
		r1 = sw[0] + inc;
		r2 = sw[1] + inc;
		for (int ic = 0; ic < MAX_XY; ic++)
			std::swap(board[ic][r1], board[ic][r2]);
	}
}

void SudokuBoard::CreateRow(int row, std::vector<int>& v)
{
	for (int col = 0; col < MAX_XY; col++)
	{
		board[row][col] = v[col];
	}
}
