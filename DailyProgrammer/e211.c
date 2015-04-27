/*
Ryan Lafferty
=============
/r/DailyProgrammer - easy #211 - name game
http://www.reddit.com/r/dailyprogrammer/comments/338p28/20150420_challenge_211_easy_the_name_game
***********************************************************************************************************
See link for description.
***********************************************************************************************************
*/
#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char name[1000];
	char letter;
	int i;
	
	i = 0;
	letter = 0;
	
	for(i = 0; i < 1000; i++)
	{
		name[i] = 0;
	}
	
	printf("Please enter your name: ");
	while(!fgets(name, 1000, stdin));
	printf("\n");
	
	for(i = 0; i < 100; i++)
	{
		if(name[i] == '\n')
		{
			name[i] = 0;
		}
	}
	
	letter = name[0];
	printf("%s, %s ", name, name);
	
	name[0] = 'B';
	printf("bo %s,\n", name);
	
	name[0] = 'F';
	printf("Bonana fanna fo %s,\n", name);
	
	name[0] = 'M';
	printf("Fee fy mo %s,\n", name);
	
	name[0] = letter;
	printf("%s!", name);
}