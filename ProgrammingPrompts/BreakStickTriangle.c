/*
Ryan Lafferty
=============
/r/ProgrammingPrompts - Breaking a stick to form a triangle
http://www.reddit.com/r/ProgrammingPrompts/comments/2zgj48/easymathematical_simulation_breaking_a_stick_to/
***********************************************************************************************************
Another Monte Carlo simulation.
A stick of a given length is twice broken at random places along it's length.
Calculate the probability that a triangle can be formed with the pieces.
Definition:
It is possible to form a triangle if none of the pieces are larger than half the length of the stick.
Assignment:
Create a program in a language of your choice that:
Asks the user for the length of the stick
Asks the user how many tries should be carried out
Simulate the breaking of the stick (each try has a new stick of length)
Count the successful tries
Print the probability as a percentage
Hint: The expected result should be around 23%
Have fun!
***********************************************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int length;
	int r1;
	int valid;
	int i;
	int j;
	int k;
	int suc;
	int tries;
	int sucT;
	int ct;
	double per;
	char buffer[1000];
	
	length = 0;
	r1 = 0;
	valid = 0;
	i =0;
	j = 0;
	k = 0;
	suc = 0;
	tries = 0;
	sucT = 0;
	ct = 0;
	per = 0;
	
	for(i = 0; i < 1000; i++)
	{
		buffer[i] = 0;
	}
	
	while(suc == 0)
	{
		printf("Please enter the length of the stick: ");
		fgets(buffer, 1000, stdin);
		length = atoi(buffer);
		if(length >= 3)
		{
			suc = 1;
		}
	}
	suc = 0;
	printf("\n");
	
	while(suc == 0)
	{
		printf("Please enter the number of tries: ");
		fgets(buffer, 1000, stdin);
		tries = atoi(buffer);
		if(length >= 3)
		{
			suc = 1;
		}
	}
	suc = 0;
	printf("\n");
	
	valid = (length / 2);
	
	while(ct < tries)
	{
		ct++;
		i = rand() % (length - 2);
		r1 = length - i;
		j = rand() % (r1 - 1);
		k = r1 - j;
		if(i <= valid && j <= valid && k <= valid)
		{
			sucT++;
			printf("Valid: Side1 = %d, Side2 =  %d, Side3 =  %d\n", i, j, k);
		}
	}
	
	per = (((double) sucT) / ((double) tries)) * 100;
	printf("Probability: %d/%d = %.2f percent\n", sucT, tries, per);
}