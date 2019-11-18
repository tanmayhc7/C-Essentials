/*
 * checkSubstring.c
 *
 *  Created on: Nov 17, 2019
 */
void check_substring_occurrences()
{
	int count = 0, count1 = 0;

	int i, j, l, l1, l2;

	char str[100]="Avengers:Infinity war was better than Avengers:Endgame";
    l1 = strlen(str);

    char sub[100]="Avengers";
    l2 = strlen(sub);

    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while ((str[i] == sub[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;
            count = 0;
        }
        else
            i++;
    }
    printf("\n%s occurs %d times in %s", sub, count1, str);
}



