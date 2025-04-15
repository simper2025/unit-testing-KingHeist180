#include "pch.h"
#include "Board.h"


void Board::SetBoard(char setup[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = setup[i][j];
		}
	}
}

char Board::GetSquare(int row, int col) const
{
	return grid[row][col];
}

bool Board::SetSquare(int row, int col, char player)
{
	if (grid[row][col] == ' ')
	{
		grid[row][col] = player;
		return true;
	}

	return false;
}

char Board::GameStatus()
{
	//Tie condition
	if (grid[0][0] != ' ' && grid[0][1] != ' ' && grid[0][2] != ' ' && grid[1][0] != ' ' && grid[1][1] != ' ' && grid[1][2] != ' ' && grid[2][0] != ' ' && grid[2][1] != ' ' && grid[2][2] != ' ')
		return 'T';

	//Win Conditions for diagonals
	//Forward diagonal
	if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
		if (grid[0][0] == 'O') {
			return 'O';
		}
		if (grid[0][0] == 'X') {
			return 'X';
		}
	}
	//Backwards diagonal
	if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) {
		if (grid[0][2] == 'O') {
			return 'O';
		}
		if (grid[0][2] == 'X') {
			return 'X';
		}
	}

	//Win conditions for straight lines
	for (int i = 0; i < 3; i++) {
		//Across
		if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) {
			if (grid[i][0] == 'O') {
				return 'O';
			}
			if (grid[i][0] == 'X') {
				return 'X';
			}
		}
		//Down
		if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) {
			if (grid[0][i] == 'O')
				return 'O';

			if (grid[0][i] == 'X')
				return 'X';
		}
	}

	return ' ';
}

