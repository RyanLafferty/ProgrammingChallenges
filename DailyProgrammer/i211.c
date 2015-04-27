/*
Ryan Lafferty
=============
/r/DailyProgrammer - Intermediate #211 - Ogre Maze
http://www.reddit.com/r/dailyprogrammer/comments/33hwwf/20150422_challenge_211_intermediate_ogre_maze
***********************************************************************************************************
See link for description.
***********************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//openspace values
//u,d,l,r

typedef struct space
{
	int value;
	int editable;
	int openSpace[4];
}space;

void initGrid(space puzzle[10][10]);
void copyGrid(space puzzle[10][10]);
void detectOpenSpace(space puzzle[10][10]);


int main(int argc, char *argv[]) 
{
	int i;
	int j;
	space puzzle[10][10];
	
	i = 0;
	j = 0;
	
	initGrid(puzzle);
	copyGrid(puzzle);
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf("%c", puzzle[i][j].value);
		}
		printf("\n");
	}
	
	detectOpenSpace(puzzle);
}

/*
Desc: Initialize the puzzle grid.
Args: Puzzle grid.
Return: Nothing.
*/
void initGrid(space puzzle[10][10])
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			for(k = 0; k < 4; k++)
			{
				puzzle[i][j].openSpace[k] = 1;
			}
			puzzle[i][j].editable = 1;
			puzzle[i][j].value = 0;
		}
	}

}

/*
Desc: Copies the sudoku puzzle to solve.
Args: Puzzle grid.
Return: Nothing.
*/
void copyGrid(space puzzle[10][10])
{
	int i;
	int j;
	int num;
	char * token;
	char buffer[1000];
	FILE * f;

	i = 0;
	j = 0;
	num = 0;
	token = NULL;
	f = NULL;

	f = fopen("input.puzzle", "r");
	if(f == NULL)
	{
		printf("Failed to open file.\n");
		return;
	}

	for(i = 0; i < 10; i++)
	{
		fgets(buffer, 999, f);
		for(j = 0; j < 10; j ++)
		{
			puzzle[i][j].value = buffer[j];
			if(buffer[j] == 'O')
			{
				puzzle[i][j].editable = 0;
			}
		}
	}

	fclose(f);
}

/*
Desc: Detect valid spaces on the puzzle grid
Args: Puzzle grid.
Return: Nothing.
*/
void detectOpenSpace(space puzzle[10][10])
{
	int i;
	int j;
	int k;
	
	i = 0;
	j = 0;
	k = 0;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			if((i - 1) >= 0)
			{
				if(puzzle[i-1][j].value == 'O')
				{
					puzzle[i][j].openSpace[0] = 0;
				}
				else
				{
					puzzle[i][j].openSpace[0] = 1;
				}
			}
			else
			{
				puzzle[i][j].openSpace[0] = 0;
			}
			
			if((i + 1) < 10)
			{
				if(puzzle[i+1][j] .value == 'O')
				{
					puzzle[i][j].openSpace[1] = 0;
				}
				else
				{
					puzzle[i][j].openSpace[1] = 1;
				}
			}
			else
			{
				puzzle[i][j].openSpace[0] = 0;
			}
			
			if((j - 1) >= 0)
			{
				if(puzzle[i][j-1].value == 'O')
				{
					puzzle[i][j].openSpace[2] = 0;
				}
				else
				{
					puzzle[i][j].openSpace[2] = 1;
				}
			}
			else
			{
				puzzle[i][j].openSpace[0] = 0;
			}
			
			if((j + 1) < 10)
			{
				if(puzzle[i][j+1].value == 'O')
				{
					puzzle[i][j].openSpace[3] = 0;
				}
				else
				{
					puzzle[i][j].openSpace[3] = 1;
				}
			}
			else
			{
				puzzle[i][j].openSpace[0] = 0;
			}
		}
	}
}