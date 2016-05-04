/*
#include <iostream>

using namespace std;
*/
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
	if (sr == er && sc == ec) //if starting location is ending location
		return true;
	maze[sr][sc] = 'v';

	if (maze[sr - 1][sc] == '.')//north
	{
		bool temp = pathExists(maze, sr - 1, sc, er, ec);
		if (temp == true)
			return true;
	}

	if (maze[sr][sc + 1] == '.')//east
	{
		bool temp = pathExists(maze, sr, sc+1, er, ec);
		if (temp == true)
			return true;
	}

	if (maze[sr + 1][sc] == '.')//South
	{
		bool temp = pathExists(maze, sr + 1, sc, er, ec);
		if (temp == true)
			return true;
	}

	if (maze[sr][sc - 1] == '.')
	{
		bool temp = pathExists(maze, sr, sc - 1, er, ec);
		if (temp == true)
			return true;
	}

	return false;
}
/*
int main()
{
	char maze[10][10] = {
		{ 'X','X','X','X','X','X','X','X','X','X' },
		{ 'X','.','.','.','.','.','.','.','.','X' },
		{ 'X','X','.','X','.','X','X','X','X','X' },
		{ 'X','.','.','X','.','X','.','.','.','X' },
		{ 'X','.','.','X','.','.','.','X','.','X' },
		{ 'X','X','X','X','.','X','X','X','.','X' },
		{ 'X','.','X','.','.','.','.','X','X','X' },
		{ 'X','.','.','X','X','.','X','X','.','X' },
		{ 'X','.','.','.','X','.','.','.','.','X' },
		{ 'X','X','X','X','X','X','X','X','X','X' }
	};

	if (pathExists(maze, 6, 4, 1, 1))
		cout << "Solvable!" << endl;
	else
		cout << "Out of luck!" << endl;
	cin.ignore(1000, '\n');
	return 1;
}

/*