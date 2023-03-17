/*****************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*
* @file: my_string.c
* @brief: This is library file contains all the functions to manipulate string operations
*
* @uthor  : Amar G. Shinde
* @Created: 13/03/2023.
*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
******************************************************************************************************************************/
#include<stdio.h>
#include"database.h"

#define DEBUG(x) printf("DEBUG: opened file %s\n", #x);

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









void EditAssessmetSts( void )
{
    STD_DETAILS_S * info;
    int d, m, y, i = 1, done = 0;
    FILE * fp;
    printf("\nTo Edit Assessment Status,\n");
    printf("Enter the batch id: ");
    scanf(" %s",info->aca_info.batch_id);
    printf("Enter Student's Name: ");
    scanf(" %[^\n]",info->aca_info.std_name);

    while( (i <= Batch_9) && (done != SUCCESS) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            DEBUG(FILE_OPEND...)
            done = SearchBatchIdNameToEditAsmntSts(fp, info);
            fclose(fp);
        }
        i++;
    }
    if( done == FAIL )
        printf("No info found for \"%s %s\" student in database\n", info->aca_info.batch_id, info->aca_info.std_name);
    else
        printf("The assessment status updated to %s for student %s\n", info->aca_info.assmt_status, info->aca_info.batch_id);
}

int SearchBatchIdNameToEditAsmntSts( FILE * fp, STD_DETAILS_S * info )
{
    char sts[12]; /* local string */
    char * buf;
    int length = 0;
    int done = 0;
    if ( (buf = malloc(150*sizeof(char)))== NULL ) {
        printf("Memory not allocated for buffer.\n");
        return 0;
    }
    fscanf(fp, " %[^\n]", buf);
    while( fscanf(fp, " %[^\n]", buf) != EOF )
    {
            if( my_strstr(buf, info->aca_info.batch_id) != NULL ) {
                if( my_strstr(buf, info->aca_info.std_name) != NULL )
                {
                        length = my_strlen(buf);
                        printf("Enter the current status want to update: ");
                        scanf(" %[^\n]", sts);

                        if ( (done = ReplaceWord( buf, "not recomm", sts)) == FAIL )
                               done = ReplaceWord( buf, "not recom", sts );

                        if( (done != SUCCESS) ) {
                            if( (done = ReplaceWord( buf, "recom", sts )) == FAIL )
                                done = ReplaceWord( buf, "rec", sts );
                        }

                        if( done == SUCCESS ) {
                            fseek(fp, -length, SEEK_CUR);
                            fprintf(fp, "%s", buf);
                            //printf("%s", buf);
                            free(buf);
                            return SUCCESS;
                        }/* status */
                }/* student's name matched */
            }/* student id matched */
    }
    free(buf);
    return FAIL;
}



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

void EditAvgMarks( void )
{
    STD_DETAILS_S * info;
    int d, m, y, i = 1, done = 0;
    FILE * fp;
    printf("\nTo Edit Name,\n");
    printf("Enter the batch id: ");
    scanf(" %s",info->aca_info.batch_id);
    printf("Enter Student's Name: ");
    scanf(" %[^\n]",info->aca_info.std_name);

    while( (i <= Batch_9) && (done != SUCCESS) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            done = SearchBatchIdNameToEditMarks(fp, info);
            fclose(fp);
        }
        i++;
    }
    if( done != SUCCESS )
        printf("The info about %s is not found in database\n", info->aca_info.batch_id);
    else
        printf("Updated Marks is: %f\n", info->aca_info.avg_marks);
}

int SearchBatchIdNameToEditMarks( FILE * fp, STD_DETAILS_S * info )
{
    char * buf, * buf1;
    char *begin, *p, *q;
    int match = 0;
    if( (buf = malloc(150*sizeof(char))) == NULL )
        return FAIL;
    if( (buf1 = malloc(10*sizeof(char))) == NULL )
        return FAIL;
    fscanf(fp, " %[^\n]", buf);
    while( fscanf(fp, " %[^\n]", buf) != EOF )
    {
        if( my_strstr(buf, info->aca_info.batch_id) != NULL )
        {
            if( my_strstr(buf, info->aca_info.std_name) != NULL )
            {
                printf("This is information present in file,\n%s\n", buf);
                GetMarks(info);

                sprintf(buf1, "%5.2f", info->aca_info.avg_marks);
                //printf("marks = %s\n", buf1);
                p = buf + 25;
                q = buf1;

                while( *p == ' ' )
                    p++;
                while( *q != '\0' )
                {
                        *p = *q;
                        p++;
                        q++;
                }
                begin = buf;
                while( *begin != '\0' )
                {
                    fseek(fp, -1, SEEK_CUR);    /*bring current position indicator
                                                to begning of the same line */
                    begin++;
                }
                //fscanf(fp, " %[^\n]", buf);

                fprintf(fp, "%s", buf);

                //printf("%s\n", buf);
                free(buf);
                free(buf1);
                return SUCCESS;
            }
        }//if
    }//while
    free(buf);
    free(buf1);
    return FAIL;
}



void EditName( void )
{
    STD_DETAILS_S * info;
    int d, m, y, i = 1, done = 0;
    FILE * fp;
    printf("\nTo Edit Name,\n");
    printf("Enter the batch id: ");
    scanf(" %s",info->aca_info.batch_id);
    printf("Enter DoB(dd:mm:yyyy): ");
    scanf("%d%d%d", &d, &m, &y );
    info->d_birth.dd    = d;
    info->d_birth.mm    = m;
    info->d_birth.yyyy  = y;
    while( (i <= Batch_9) && (done != SUCCESS) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            done = SearchBatchIdDoBToEditName(fp, info);
            fclose(fp);
        }
        i++;
    }
    if( done != SUCCESS )
        printf("The info about %s is not found in database\n", info->aca_info.batch_id);
    else
        printf("Updated name is: %s\n", info->aca_info.std_name);
}

int SearchBatchIdDoBToEditName(FILE * fp, STD_DETAILS_S * info )
{
    char * buf, *buf1;
    char *p, *q, *begin;
    int match = 0, i = 0;
    if( (buf = malloc(150*sizeof(char))) == NULL )
        return FAIL;
    if( (buf1 = malloc(100*sizeof(char))) == NULL )
        return FAIL;
    fscanf(fp, " %[^\n]", buf);
    while( fscanf(fp, " %[^\n]", buf) != EOF )
    {
        if( my_strstr(buf, info->aca_info.batch_id) != NULL )
        {
            fseek(fp, -23, SEEK_CUR);
            fscanf(fp, " %[^\n]", buf1);
            //printf("%s\n", buf1);
            match = ConvertAndCompareDate(buf1, info->d_birth.dd, info->d_birth.mm, info->d_birth.yyyy);
        } //if
        if( match == SUCCESS )
        {
            printf("This is information present in file,\n%s\n", buf);
            printf("Enter the New Name: ");
            scanf(" %[^\n]", info->aca_info.std_name);

            p = buf+12;
            q = info->aca_info.std_name;
            while( *p == ' ' )
                p++;

            i = 0;
            while( (*q != '\0') && (i <= 12) )
            {
                *p = *q;
                p++;
                q++;
                i++;
            }

            while( *p != ' ' ) {
                *p = ' ';
                p++;
            }

            begin = buf;
            while( *begin != '\0' )
            {
                fseek(fp, -1, SEEK_CUR);    /*bring current position indicator
                                                to begning of the same line */
                begin++;
            }
            fprintf(fp, "%s", buf);
            //printf("%s\n", buf);
            free(buf);
            free(buf1);
            return SUCCESS;
        }//if
    }//while
    free(buf);
    free(buf1);
    return FAIL;
}

void EditBatchId( void )
{
    STD_DETAILS_S * info;
    int d, m, y, i = 1, done = 0;
    FILE * fp;
    printf("\nTo Edit the batch Id\n");
    printf("Enter the name & Date of birth of student:");
    scanf(" %[^\n]",info->aca_info.std_name);
    scanf("%d%d%d", &d, &m, &y );
    info->d_birth.dd    = d;
    info->d_birth.mm    = m;
    info->d_birth.yyyy  = y;
    while( (i <= Batch_9) && (done != 1) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            done = SearchNameDoBToEditBatchId(fp, info);
            fclose(fp);
        }
        i++;
    }
    if( done != SUCCESS  )
        printf("The info about %s is not found in database\n", info->aca_info.std_name);
    else
        printf("Edited Batch Id is: %s\n", info->aca_info.batch_id);
}

int SearchNameDoBToEditBatchId( FILE * fp, STD_DETAILS_S * info )
{
        char * buf, *buf1;
        int match = 0;
        if( (buf = malloc(150*sizeof(char))) == NULL )
            return 0;
        if( (buf1 = malloc(100*sizeof(char))) == NULL )
            return 0;
        fscanf(fp, " %[^\n]", buf);
        while( fscanf(fp, " %[^\n]", buf) != EOF )
        {
            if( my_strstr(buf, info->aca_info.std_name) != NULL )
            {
                fseek(fp, -23, SEEK_CUR);
                fscanf(fp, " %[^\n]", buf1);
                //printf("%s\n", buf1);
                match = ConvertAndCompareDate(buf1, info->d_birth.dd, info->d_birth.mm, info->d_birth.yyyy);
            }
            if( match == SUCCESS )
            {
                printf("This is information present in file,\n%s\n", buf);
                printf("Enter the New Batch Id: ");
                scanf(" %s", info->aca_info.batch_id);
                char *p, *q;
                p = buf;
                q = info->aca_info.batch_id;
                while( *q != '\0' )
                {
                    *p = *q;
                    p++;
                    q++;
                }
                if ( *p != ' ')
                    *p = ' ';

                p = buf;
                while( *p != '\0' )
                {
                    fseek(fp, -1, SEEK_CUR);
                    p++;
                }
                fprintf(fp,"%s", buf);
                free(buf);
                free(buf1);
                return SUCCESS;
            }
        }
    free(buf);
    free(buf1);
    return FAIL;
}

