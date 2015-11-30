#include <stdio.h>
#include <stdlib.h>

void A_D(FILE * f);
void solve(int num);

int main()
{
    FILE * f;
    
    f = NULL;
    
    f = fopen("in.txt", "r");
    if(f == NULL)
    {
        fprintf(stderr, "Error: could not open input file!\n");
        return 0;
    }

    A_D(f);

    fclose(f);
    return 0;
}

void A_D(FILE * f)
{
    char c;
    char buffer[1000];
    int i;
    int num;

    c = 'a';
    i = 0;
    num = 0;


    for(i = 0; i < 1000; i++)
    {
        buffer[i] = 0;
    }

    while(!feof(f))
    {
        fgets(buffer, 1000, f);
        if(!feof(f))
        {
            num = atoi(buffer);
            solve(num);
        }
        for(i = 0; i < 1000; i++)
        {
            buffer[i] = 0;
        }
    }

    if(f == NULL)
    {
        return;
    }

}

void solve(int num)
{
    int defNum;
    int abNum;
    int diff;
    int i;

    defNum = 0;
    abNum = 0;
    diff = 0;
    i = 0;

    for(i = 1; i <= num; i++)
    {
        if(num % i == 0)
        {
            defNum += i;
        }
    }

    abNum = 2 * num;

    if(defNum < abNum)
    {
        printf("%d deficient\n", num);
    }
    else if(defNum == abNum)
    {
        printf("%d ~~neither~~\n", num);
    }
    else
    {
        diff = defNum - abNum;
        printf("%d abundant by %d\n", num, diff);
    }
}