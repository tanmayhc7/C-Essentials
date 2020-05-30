/*
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 */
char * toLowerCase(char * str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>64 && str[i]<91)
        {
            str[i]=str[i]+32;
        }
    }
    return str;
}
