/*
Ryan Lafferty
=============
/r/ProgrammingPrompts - Breaking a stick to form a triangle
http://www.reddit.com/r/ProgrammingPrompts/comments/31gl36/easy_create_a_pyglatin_translator/
***********************************************************************************************************
For those of you who dont know, pyglatin is a fictional language, where the first letter of a word is moved 
to the end, and the suffix "ay" is added on...
For example, "program" would be "Rogrampay" "Human" would be "Umanhay" "Television" would be "Elevisiontay"
Im sure you get it :)
***********************************************************************************************************
*/

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char word[1000];
	int i;
	
	i = 0;
	
	for(i = 0; i < 1000; i++)
	{
		word[i] = 0;
	}
	
	printf("Please enter a word: ");
	while(!fgets(word, 1000, stdin));
	printf("\n");
	
	for(i = 0; i < 1000; i++)
	{
		if(word[i] == '\n')
		{
			word[i] = word[0];
			word[i+1] = 'a';
			word[i+2] = 'y';
			word[0] = 0;
			break;
		}
	}
	
	for(i = 0; i < 999; i++)
	{
		word[i] = word[i+1];
	}
	
	printf("Translated word = %s\n", word);
}