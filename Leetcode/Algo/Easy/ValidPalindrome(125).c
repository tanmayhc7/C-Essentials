/******************************************
 125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*****************************************/
bool isPalindrome(char* s)
{
  if(s==NULL || !strcmp(s,"")) return true;

  for(char* p = s + strlen(s) -1; p>s;)
    if(isalnum(*s) && isalnum(*p) && tolower(*(s++)) != tolower(*(p--))) return false;            
    else if(!isalnum(*s))  s++;
    else if(!isalnum(*p))  p--;

  return true;
}
