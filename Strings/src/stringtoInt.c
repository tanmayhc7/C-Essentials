/*
 * stringtoInt.c
 *
 *  Created on: Nov 16, 2019
 */

int string_to_int(char *str)
{
  int i = 0;
  int number = 0;
  /* Loop till end of string */
  while (str[i] != '\0')
  {
    if(str[i] >= '0' && str[i] <= '9') //Check if value is between number 0 to 9
    {

/*
 * If it is between 0 to 9 then calculate its numeric value.
 * Below value of str[i] is substracted from '0' to get exact numeric value of that numeric character.
 */
      number = number*10 + str[i] - '0';
    }
    else
    {
      break;

    }
    i++;

  }
  return number;
}


