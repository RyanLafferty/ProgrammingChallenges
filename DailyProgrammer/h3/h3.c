#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char buffer[100];
    char * word;
    char * eof;
    FILE * f;
    int i;
    int moreToDo;
    int digit1;
    int digit2;

    word = NULL;
    f = NULL;
    eof = NULL;
    i = 0;
    moreToDo = 1;
    digit1 = 0;
    digit2 = 0;

    for(i = 0; i < 100; i++)
    {
        buffer[i] = 0;
    }

    f = fopen("words.txt", "r");
    if(f == NULL)
    {
        fprintf(stderr, "Error: Could not open words file!!\n");
        return 1;
    }

    printf("Please enter a word to descramble: ");
    fgets(buffer, 100, stdin);
    printf("\n");

    word = malloc(sizeof(char) * (strlen(buffer) + 1));
    if(word == NULL)
    {
        fprintf(stderr, "Error: Out of memory!!!\n");
        return 1;
    }
    strncpy(word, buffer, (strlen(buffer) + 1));

    /*Calculate number of digits in supplied word*/
    for(i = 0; i < strlen(word); i++)
    {
        if(isdigit(word[i]) != 0)
        {
            digit1++;
        }
    }

    while(moreToDo)
    {
        eof = fgets(buffer, 100, f);
        if(eof == NULL)
        {
            moreToDo = 0;
            break;
        }

        /*Filter out words without matching lengths*/
        if(strlen(word) == strlen(buffer))
        {
            /*printf("%s\n", buffer)*/
            /*Filter out words based on number of digits*/
            digit2 = 0;
            for(i = 0; i < strlen(word); i++)
            {
                if(digit2 > digit1)
                {
                    break;
                }
                if(isdigit(buffer[i]) != 0)
                {
                    digit2++;
                }
            }
            if(digit1 == digit2)
            {
                printf("%s\n", buffer);
                /*find out if the word is a match using an efficient algorithm*/
            }
        }
    }

    free(word);
    return 0;
}
