#include <iostream>
#include <cmath>
using namespace std;
bool perfect_square(short n);
bool Not_found_in_row(char sud[9][9],short n,short row,char num);
bool Not_found_in_column(char sud[9][9], short n, short col, char num);
bool Not_found_in_subsquare(char sud[9][9],short n,short st_row,short st_col,char num);
void print_perfect(char sud[9][9], short n);
void print_Not_perfect(char sud[9][9], short n);
int main()
{
	short n,N, r, c, gaps=0,sol; bool solvable=true;
    char grid[9][9],num,temp;
	cout << "Enter the SUDOKU size\n";
	cin >> n;
	N = n;
	cout << "Enter the SUDOKU grid numbers (Enter '*' for gaps)\n\n";
	for (r = 0; r < n;r++)
	for (c = 0; c < n; c++)
	{
		cin >> grid[r][c];
		if (grid[r][c] == '*')
			gaps++;
	}
	if (perfect_square(n))
	{
		short sq = sqrt(n);
    	while (gaps>0 && solvable==true)
		{
			for (r = 0; r < n; r++)
			{
				for (c = 0; c < n; c++)
				{
				    sol = 0;
					if (grid[r][c] != '*')
						continue;
					for (num = '1'; num < (char)('1' + N); num++)
					{
						if (Not_found_in_row(grid, n, r, num) && Not_found_in_column(grid, n, c, num) && Not_found_in_subsquare(grid, n, r - r%sq, c - c%sq, num))
						{
							temp = num;
							sol++;
							if (sol > 1)
								break;
						}
					} //for(num)
					if (sol == 1)
					{
						grid[r][c] = temp;
						gaps--;
					}
					else if (sol == 0)
					{
						solvable = false;
						goto end_p;						
					}			
				}//for(c)
			}//for(r)
		}//while(gaps && solvable)
	   	
end_p:	if (solvable)
		{
			cout << "The solution is: \n\n";
			print_perfect(grid,n);
		}
		else
			cout << "No solution to that SUDOKU\n";
	}//if(perfect_square)
	else
	{
		while (gaps>0 && solvable==true)
		{
			for (r = 0; r < n ; r++)
			{
				for (c = 0; c < n ; c++)
				{
					sol = 0;
					if (grid[r][c] != '*')
						continue;
					for (num = '1'; num <(char)('1' + N); num++)
					{
						if (Not_found_in_row(grid, n, r, num) && Not_found_in_column(grid, n, c, num))
						{
							temp = num;
							sol++;
							if (sol > 1)
								break;
						}
					} //for(num)
					if (sol == 1)
					{
						grid[r][c] = temp;
						gaps--;
					}
					else if (sol == 0)
					{
						solvable = false;
						goto end;
					}
				}//for(c)
			}//for(r)
		}//while(gaps && solvable)
end:	if (solvable)
    	{
			cout << "The solution is: \n\n";
				print_Not_perfect(grid, n);
    	}
		else
			cout << "No solution for that SUDOKU\n";
	}//else perfectsquare

	system("pause");
	return 0;
}
bool perfect_square(short n)
{
	double sq = sqrt(n);
	while (sq >= 1)
		sq--;
	if (sq == 0)
		return true;
	else
		return false;
}
bool Not_found_in_row(char sud[9][9], short n, short row,char num)
{
	for (short c = 0; c < n;c++)
	if (sud[row][c] == num)
		return false;
	return true;
}
bool Not_found_in_column(char sud[9][9], short n, short col, char num)
{
	for (short r = 0; r < n;r++)
	if (sud[r][col] == num)
		return false;
	return true;
}
bool Not_found_in_subsquare(char sud[9][9], short n, short st_row, short st_col, char num)
{
	short sq = sqrt(n);
	for (short r = st_row; r < sq+st_row ; r++)
	{
		for (short c = st_col; c < sq+st_col ;c++)
		if (sud[r][c] == num)
			return false;
	}
	return true;
}
void print_perfect(char sud[9][9], short n)
{
	short r, c, i, sq;
	sq = sqrt(n);
	for (r = 0; r < n; r++)
	{
		if (r%sq == 0)
		{
			cout << " ";
			for (i = 1; i <= 2 * (n + sq) + 1; i++)
				cout << "-";
			cout << endl;
		}	
		for (c = 0; c < n; c++)
		{
			if (c%sq == 0)
				cout << " | " << sud[r][c];
			else
				cout << " " << sud[r][c];
		}
		cout << " |" << endl;
	}
	cout << " ";
	for (i = 1; i <= 2 * (n + sq) + 1; i++)
		cout << "-";
	cout << endl;
}
void print_Not_perfect(char sud[9][9], short n)
{
	short r, c, i;
	cout << " ";
	for (i = 1; i <= 2 * n + 3; i++)
		cout << "-";
	cout << endl;
	for (r = 0; r < n; r++)
	{
		cout << " | ";
		for (c = 0; c < n; c++)
			cout << sud[r][c] << " ";
		cout << "|" << endl;
	}
	cout << " ";
	for (i = 1; i <= 2 * n + 3; i++)
		cout << "-";
	cout << endl;
}