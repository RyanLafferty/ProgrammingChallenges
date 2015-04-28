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
//TODO add visited flag to spaces and if both spaces have been visited do not add them to the queue

typedef struct space
{
	char value;
	int editable;
	int openSpace[4];
	int dis;
}space;

void initGrid(space puzzle[10][10]);
void copyGrid(space puzzle[10][10]);
void detectOpenSpace(space puzzle[10][10]);
void solve(space puzzle[10][10]);

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
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf("i = %d j = %d open values = %d %d %d %d\n", i, j, 
			puzzle[i][j].openSpace[0], puzzle[i][j].openSpace[1], puzzle[i][j].openSpace[2], puzzle[i][j].openSpace[3]);
		}
		printf("\n");
	}
	
	
	solve(puzzle);
	
	printf("\n\nSolved\n======\n\n");
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			printf("%c", puzzle[i][j].value);
		}
		printf("\n");
	}
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
			puzzle[i][j].dis = 0;
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
				puzzle[i][j].openSpace[1] = 0;
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
				puzzle[i][j].openSpace[2] = 0;
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
				puzzle[i][j].openSpace[3] = 0;
			}
		}
	}
}

void solve(space puzzle[10][10])
{
	char stack[10000];
	char prev[10000];
	char dir;
	int i;
	int dollar;
	int found;
	int solved;
	int empty;
	int blocked;
	int fall;
	int p1[2];
	int p2[2];
	int p3[2];
	int p4[2];
	
	i = 0;
	dollar = 0;
	found = 0;
	solved = 0;
	empty = 0;
	dir = 0;
	blocked = 0;
	fall = 0;
	
	//add finding starting location method
	
	//p1p2
	//p3p4
	
	p1[0] = 0;
	p1[1] = 0;
	p2[0] = 0;
	p2[1] = 1;
	p3[0] = 1;
	p3[1] = 0;
	p4[0] = 1;
	p4[1] = 1;
	
	/*p1[0] = 8;
	p1[1] = 8;
	p2[0] = 8;
	p2[1] = 9;
	p3[0] = 9;
	p3[1] = 8;
	p4[0] = 9;
	p4[1] = 9;*/
	
	/*p1[0] = 0;
	p1[1] = 1;
	p2[0] = 0;
	p2[1] = 2;
	p3[0] = 1;
	p3[1] = 1;
	p4[0] = 1;
	p4[1] = 2;*/
	
	//mark init locations as visited
	
	for(i = 0; i < 10000; i++)
	{
		stack[i] = 0;
		prev[i] = 0;
	}
	
	while(empty == 0 && solved == 0)
	{
		printf("p1 = %d %d p2 =  %d %d p3 = %d %d p4 = %d %d\n",
		p1[0], p1[1], p2[0], p2[1], p3[0], p3[1], p4[0], p4[1]);
		blocked = 1;
		//check directions
		if((p1[0] - 1) >= 0 && (p2[0] - 1) >= 0)
		{
			if(puzzle[p1[0] - 1][p1[1]].value != 'O' && puzzle[p2[0] - 1][p2[1]].value != 'O'
			&& (puzzle[p1[0] - 1][p1[1]].dis == 0 || puzzle[p2[0] - 1][p2[1]].dis == 0))
			{
				for(i = 9999; i > 0; i--)
				{
					stack[i] = stack[i-1];
				}
				stack[0] = 'u';
				prev[0] = dir;
				blocked = 0;
			}
		}
		if((p3[0] + 1) < 10 && (p4[0] + 1) < 10)
		{
			if(puzzle[p3[0] + 1][p3[1]].value != 'O' && puzzle[p4[0] + 1][p4[1]].value != 'O'
			&& (puzzle[p3[0] + 1][p3[1]].dis == 0 || puzzle[p4[0] + 1][p4[1]].dis == 0))
			{
				for(i = 9999; i > 0; i--)
				{
					stack[i] = stack[i-1];
				}
				stack[0] = 'd';
				prev[0] = dir;
				blocked = 0;
			}
		}
		if((p1[1] - 1) >= 0 && (p3[1] - 1) >= 0)
		{
			if(puzzle[p1[0]][p1[1] - 1].value != 'O' && puzzle[p3[0]][p3[1] - 1].value != 'O'
			&& (puzzle[p1[0]][p1[1] - 1].dis == 0 || puzzle[p3[0]][p3[1] - 1].dis == 0))
			{
				for(i = 9999; i > 0; i--)
				{
					stack[i] = stack[i-1];
				}
				stack[0] = 'l';
				prev[0] = dir;
				blocked = 0;
			}
		}
		if((p4[1] + 1) < 10 && (p2[1] + 1) < 10)
		{
			if(puzzle[p4[0]][p4[1] + 1].value != 'O' && puzzle[p2[0]][p2[1] + 1].value != 'O'
			&& (puzzle[p4[0]][p4[1] + 1].dis == 0 || puzzle[p2[0]][p2[1] + 1].dis == 0))
			{
				for(i = 9999; i > 0; i--)
				{
					stack[i] = stack[i-1];
				}
				stack[0] = 'r';
				prev[0] = dir;
				blocked = 0;
			}
		}
		
		/*if(puzzle[p1[0]][p1[1]].openSpace[0] == 1 && puzzle[p2[0]][p2[1]].openSpace[0] == 1)
		{
			for(i = 9999; i > 0; i--)
			{
				stack[i] = stack[i-1];
			}
			stack[0] = 'u';
			prev[0] = dir;
			blocked = 0;
		}
		if(puzzle[p3[0]][p3[1]].openSpace[1] == 1 && puzzle[p4[0]][p4[1]].openSpace[1] == 1)
		{
			for(i = 9999; i > 0; i--)
			{
				stack[i] = stack[i-1];
			}
			stack[0] = 'd';
			prev[0] = dir;
			blocked = 0;
		}
		if(puzzle[p1[0]][p1[1]].openSpace[2] == 1 && puzzle[p3[0]][p3[1]].openSpace[2] == 1)
		{
			for(i = 9999; i > 0; i--)
			{
				stack[i] = stack[i-1];
			}
			stack[0] = 'l';
			prev[0] = dir;
			blocked = 0;
		}
		if(puzzle[p4[0]][p4[1]].openSpace[3] == 1 && puzzle[p2[0]][p2[1]].openSpace[3] == 1)
		{
			for(i = 9999; i > 0; i--)
			{
				stack[i] = stack[i-1];
			}
			stack[0] = 'r';
			prev[0] = dir;
			blocked = 0;
		}*/

		printf("Stack0 = %c\n", stack[0]);
		
		if(stack[0] == 0)
		{
			empty = 1;
		}
		else
		{
			if(prev[0] != 0 && blocked == 1)
			{
				fall++;
				//reverse direction
				switch(prev[0])
				{
					case 'u':
					{
						puzzle[p1[0]][p1[1]].value = '.';
						puzzle[p2[0]][p2[1]].value = '.';
						p1[0]++;
						p2[0]++;
						p3[0]++;
						p4[0]++;
						break;
					}
					case 'd':
					{
						puzzle[p3[0]][p3[1]].value = '.';
						puzzle[p4[0]][p4[1]].value = '.';
						p1[0]--;
						p2[0]--;
						p3[0]--;
						p4[0]--;
						break;
					}
					case 'l':
					{
						puzzle[p1[0]][p1[1]].value = '.';
						puzzle[p3[0]][p3[1]].value = '.';
						p1[1]++;
						p2[1]++;
						p3[1]++;
						p4[1]++;
						break;
					}
					case 'r':
					{
						puzzle[p2[0]][p2[1]].value = '.';
						puzzle[p4[0]][p4[1]].value = '.';
						p1[1]--;
						p2[1]--;
						p3[1]--;
						p4[1]--;
						break;
					}
					default:
					{
						break;
					}
				}
			}
			else
			{
				fall = 0;
			}
			switch(stack[0])
			{
				case 'u':
				{
					if(puzzle[p1[0] - 1][p1[1]].value != 'O' && puzzle[p2[0] - 1][p2[1]].value != 'O')
					{
						dir = 'u';
						p1[0]--;
						p2[0]--;
						p3[0]--;
						p4[0]--;
					}
					else
					{
						blocked = 1;
					}
					if(puzzle[p1[0]][p1[1]].value == '$' || puzzle[p2[0]][p2[1]].value == '$')
					{
						dollar = 1;
					}
					puzzle[p1[0]][p1[1]].value = '&';
					puzzle[p2[0]][p2[1]].value = '&';
					
					puzzle[p1[0]][p1[1]].dis = 1;
					puzzle[p2[0]][p2[1]].dis = 1;
					break;	
				}
				case 'd':
				{
					if(puzzle[p3[0] + 1][p3[1]].value != 'O' && puzzle[p4[0] + 1][p4[1]].value != 'O')
					{
						dir = 'd';
						p1[0]++;
						p2[0]++;
						p3[0]++;
						p4[0]++;
					}
					else
					{
						blocked = 1;
					}
					if(puzzle[p3[0]][p3[1]].value == '$' || puzzle[p4[0]][p4[1]].value == '$')
					{
						dollar = 1;
					}
					puzzle[p3[0]][p3[1]].value = '&';
					puzzle[p4[0]][p4[1]].value = '&';
					
					puzzle[p3[0]][p3[1]].dis = 1;
					puzzle[p4[0]][p4[1]].dis = 1;
					break;	
				}
				case 'l':
				{
					if(puzzle[p1[0]][p1[1] - 1].value != 'O' && puzzle[p3[0]][p3[1] - 1].value != 'O')
					{
						dir = 'l';
						p1[1]--;
						p2[1]--;
						p3[1]--;
						p4[1]--;
					}
					else
					{
						blocked = 1;
					}
					if(puzzle[p1[0]][p1[1]].value == '$' || puzzle[p3[0]][p3[1]].value == '$')
					{
						dollar = 1;
					}
					puzzle[p1[0]][p1[1]].value = '&';
					puzzle[p3[0]][p3[1]].value = '&';
					
					puzzle[p1[0]][p1[1]].dis = 1;
					puzzle[p3[0]][p3[1]].dis = 1;
					break;	
				}
				case 'r':
				{
					if(puzzle[p4[0]][p4[1] + 1].value != 'O' && puzzle[p2[0]][p2[1] + 1].value != 'O')
					{
						dir = 'r';
						p1[1]++;
						p2[1]++;
						p3[1]++;
						p4[1]++;
					}
					else
					{
						blocked = 1;
					}
					if(puzzle[p2[0]][p2[1]].value == '$' || puzzle[p4[0]][p4[1]].value == '$')
					{
						dollar = 1;
					}
					puzzle[p4[0]][p4[1]].value = '&';
					puzzle[p2[0]][p2[1]].value = '&';
					
					puzzle[p4[0]][p4[1]].dis = 1;
					puzzle[p2[0]][p2[1]].dis = 1;
					break;	
				}
				
				default:
				{
					empty = 1;
					break;		
				}
			}
			for(i = 0; i < 9999; i++)
			{
				stack[i] = stack[i+1];
				prev[i] = prev[i+1];
			}
		}
		
		if(dollar == 1)
		{
			solved = 1;
		}	
		
		printf("Stack = %s\n", stack);
		
		int r, y;
		for(r = 0; r < 10; r++)
		{
			for(y = 0; y < 10; y++)
			{
				printf("%c", puzzle[r][y].value);
			}
			printf("\n");
		}	
	}
}