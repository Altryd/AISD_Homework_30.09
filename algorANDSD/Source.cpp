#include <iostream>
int Mass[8][2];
bool ChessBoard[8][8];

void FillMass()
{
	for (int i = 0; i < 8; i++)
	{
		Mass[i][0] = -1;
		Mass[i][1] = -1;
	}
}

void FillChessBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ChessBoard[i][j] = true;
		}
	}
}

void PrintFigures()
{
	std::cout << "Figure array:";
	for (int i = 0; i < 8; i++)
	{
		std::cout << Mass[i][0] << " , " << Mass[i][1] << std::endl;
	}
	std::cout << std::endl;
}

void PrintChessBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (ChessBoard[i][j]) std::cout << "   1   ";
			else std::cout << "   0   ";
		}
		std::cout << std::endl;
	}
}

bool IsAttackedByRook(const int validate_position_x, const int validate_position_y,
	const int rook_position_x, const int rook_position_y)
{
	return (validate_position_x == rook_position_x || validate_position_y == rook_position_y);
}
bool IsAttackedByQueen(const int validate_position_x, const int validate_position_y,
	const int queen_position_x, const int queen_position_y)
{
	const int dx = validate_position_x - queen_position_x;
	const int dy = validate_position_y - queen_position_y;
	return (dx == 0 || dy == 0 || dx == dy);
}

void FillBoardWithRooks(int count, int first_x, int first_y)
{
	Mass[0][0] = first_x;
	Mass[0][1] = first_y;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int figure_number = 0; figure_number < 8; figure_number++)
			{
				if ((Mass[figure_number][0] == i || Mass[figure_number][1] == j))
				{
					ChessBoard[i][j] = false;
				}
			}
			if (ChessBoard[i][j])
			{
				Mass[count][0] = i;
				Mass[count][1] = j;
				count -= 1;
			}
		}
	}
	ChessBoard[first_x][first_y] = true;
}

int check(int row, int col)
{
	for (int cols_check = 0; cols_check < col; cols_check++)
	{
		if (ChessBoard[row][cols_check]) return 0;

		//Рассмотрим пример ситуации
		// c_c = 1
		// r = 4
		// c = 3
		// (2,2) = (r - c + c_c  , c_c)
		// (6,2) = (r + c - c_c, c_c)
		// r - c + c_c = 2
		// (r + c - c_c, c_c)
		// 
		//	0      0      0      0      0      0      0      0
		//	0	   0      0      0      0      0      0      0
		//	0     (2,2)   0      0      0      0      0      0
		//	0      0      0      0      0      0      0      0
		//	0      0      0     (r,c)   0      0      0      0
		//	0      0      0      0      0      0      0      0
		//	0     (6,2)   0      0      0      0      0      0
		//	0      0      0      0      0      0      0      0

		//восходящая диагональ от нижнего левого угла
		if (row + col - cols_check < 8) if (ChessBoard[row + col - cols_check][cols_check]) return 0;
		//нисходящая диагональ от верхнего левого угла
		if (row - col + cols_check >= 0) if (ChessBoard[row - col + cols_check][cols_check]) return 0;
	}
	return 1;
}


int FillWithQueens(int count = 0, int all_figures_to_be_filled = 8)
{
	if (count == all_figures_to_be_filled) return 1;
	for (int i = 0; i < 8; i++)
	{
		if (check(i, count))
		{
			ChessBoard[i][count] = 1;
			if (FillWithQueens(count + 1)) return 1;
			ChessBoard[i][count] = 0;
		}
	}
	return 0;
}



int main()
{
	//FillChessBoard();
	//FillMass();
	//PrintChessBoard();
	//PrintFigures();

	//FillBoardWithRooks(3, 5, 1);
	//PrintFigures();
	//PrintChessBoard();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ChessBoard[i][j] = 0;
		}
	}
	FillWithQueens();
	PrintChessBoard();
}