/*
 * removeAllchars.c
 *
 *  Created on: Nov 17, 2019
 */

void alphacheck(char *str, int a[])
{
    int i, index;

    for (i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
        index = str[i] - 'a';
        if (!a[index])
        {
            a[index] = 1;
        }
    }
    printf("\n");
}

void create(char str_rem[], char str[], int list[])
{
    int i, j = 0, index;

    for (i = 0; i < strlen(str); i++)
    {
        index = str[i] - 'a';
        if (!list[index])
        {
            str_rem[j++] = str[i];
        }
    }
    str_rem[j] = '\0';
}



