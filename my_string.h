/****************************************************************************************************************
* @file: my_string.h
* @brief: This is a header file, contains all predefined as well as user-defined function prototypes
*         for string related function.
*
* @uthor: Amar G. Shinde
* Created: 13/03/2023.
****************************************************************************************************************/

#ifndef __MY_STRING_H
#define __MY_STRING_H

#include<stdio.h>

unsigned long int my_strlen( const char * str );
int ReplaceWord( char * dest, const char * str1, const char * str2 );
char * my_strstr(const char * buf, const char * std_name);
float my_atof( const char * mark_str );


#endif // _MY_STRING_H
