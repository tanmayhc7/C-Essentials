/*
 * printAllPermutations.c
 *
 *  Created on: Nov 17, 2019
 */
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string.
*/

void permute(char *a, int l, int r)
{
   if (l == r)
     printf("\n%s", a);
   else
   {
       for (int i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}



