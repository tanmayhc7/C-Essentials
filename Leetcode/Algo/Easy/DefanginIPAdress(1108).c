/*
1108. Defanging an IP Address
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
*/
char * defangIPaddr(char * address){
    char *result=malloc((strlen(address)+7)*sizeof(char));
    int k=0;
    for(int i=0;i<strlen(address);i++)
    {
        if(address[i]=='.')
        {
            result[k++]='[';
            result[k++]='.';
            result[k++]=']';
        }
        else
        {
            result[k++]=address[i];
        }
    }
    result[k]='\0';
    return result;
}
