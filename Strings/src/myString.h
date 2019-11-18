/*
 * myString.h
 *
 *  Created on: Nov 16, 2019
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void reverse_str(char *s);
void reverse_words_in_string(char *s);
char* last_word_in_string(char *s);
int string_to_int(char *str);
int Anagram(char *str1, char *str2);
void string_Lib();
void reverse_every_word();
void permute(char *a, int l, int r);
void swap(char *x, char *y);
void check_substring_occurrences();
void check_freq_of_every_word();
void alphacheck(char *, int []);
void create(char [], char [], int[]);

#endif /* MYSTRING_H_ */
