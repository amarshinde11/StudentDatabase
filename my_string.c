/*****************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*
* @file: my_string.c
* @brief: This is library file contains the functions to manipulate string operations
*
* @uthor  : Amar G. Shinde
* @Created: 13/03/2023.
*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
******************************************************************************************************************************/
#include"database.h"

/* This is debug technique to track the flow of program execution */
#define DEBUG(FUN_NAME) printf("DEBUG: opened file %s\n", #FUN_NAME);

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
*   unsigned long int my_strlen( const char * str ): This is function to find out the length
*   of given string.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
unsigned long int my_strlen( const char * str )
{
    unsigned long int len = 0;
    while( str[len] != '\0' )
        len++;
    return len;
}

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* char * my_strstr(const char * mainstr, const char * substr ): This is function to find
*   whether the substring if present in main string, if available the return the address
*   where the substring is present in main string. If not found the return NULL
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
char * my_strstr(const char * mainstr, const char * substr )
{
    const char *p, *q;
    while( *mainstr != '\0' )
    {
        if( *mainstr == *substr )
        {
            p = mainstr;
            q = substr;
            while( *p == *q )
            {
                p++, q++;
            }
            if( *q == '\0' )
            {
                return mainstr;
            }
        }
        mainstr++;
    }
    return NULL;
}

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* int ReplaceWord( char * dest, const char * str1, const char * str2 ): This is function to
* replace word from given string by another word.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
int ReplaceWord( char * dest, const char * str1, const char * str2 )
{
    char * p;
    int len1, len2;
    len1 = my_strlen(str1);
    len2 = my_strlen(str2);

    if( (p = my_strstr( dest, str1 )) != NULL )
    {
        if( len1 == len2 )
        {
            while( *str2 != '\0' )
            {
                *p = *str2;
                p++;
                str2++;
            }
            return SUCCESS;
        } /* len1 == len2 */

        else if( len1 > len2 )
        {
            while( *str2 != '\0' ) {
                *p = *str2;
                p++;
                str2++;
            }
            while( *p != ' ' ){
                *p = ' ';
                p++;
            }
            return SUCCESS;
        } /* len1 > len2 */

        else if(len1 < len2) {
            while( (*str2 != '\0') ) {
                *p = *str2;
                p++;
                str2++;
            }
            return SUCCESS;
        } /* len1 < len2 */
    } /* find the place at which the replacement word is present */
    return FAIL; /* if replacement word not found return FAILED */
}

