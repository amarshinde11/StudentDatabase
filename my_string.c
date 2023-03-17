#include"my_string.h"
#include"database.h"

#define DEBUG(x) printf("DEBUG: opened file %s\n", #x);

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
                //DEBUG(STRSTR...SUCCESS)
                return mainstr;
            }
        }
        mainstr++;
    }
    //DEBUG(STRSTR...FAILED)
    return NULL;
}

float my_atof( const char * mark_str )
{
    int dig = 0;
    float num1 = 0, num2 = 0;
    while( mark_str[dig] != '.' ) {
        if( (mark_str[dig] != '.') && ((mark_str[dig] >= '0') && (mark_str[dig] <= '9')) )
            num1 = (num1 * 10) + (mark_str[dig] - 48);
            dig++;
    }
    dig++;
    while( dig < 8 ) {
        if( ((mark_str[dig] >= '0') && (mark_str[dig] <= '9')) )
            num2 = (num2 * 10) + (mark_str[dig] - 48);
        dig++;
    }
    return (num1 + (num2/100));
}

void EditFileDataWithCorrectInfo( void )
{
    int fields = 0;
    printf("Enter which field you want to edit\n");
    printf("1. Edit Student's Batch Id\n");
    printf("2. Edit the name of student\n");
    printf("3. Edit the avg marks\n");
    printf("4. Edit the assessment status\n");
    printf("5. Edit the date of birth\n");
    printf("6. Edit the date of joining\n");
    scanf(" %d", &fields);
    switch( fields )
    {
        case 1: /* edit the batch id of student */
                EditBatchId();
        break;
        case 2: /* edit the name of student */
                EditName();
        break;
        case 3: /* Edit the avg marks */
                EditAvgMarks();
        break;
        case 4: /* edit the assessment status */
                EditAssessmetSts();
        break;
        case 5: /* edit the date of birth */
                //EditDateOfBirth( ptr );
        break;
        case 6: /* edit the date of joining */
                //EditDateJoining( ptr );
        break;
        default: /* edit the name of student */
                printf("Enter the Student's batch id or name or DOB & DOB OR ALL edit into file: ");
                //GetStdDetailInfo(ptr);
        break;
    }
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
    return FAIL;
}

unsigned long int my_strlen( const char * str )
{
    unsigned long int len = 0;
    while( str[len] != '\0' )
        len++;
    return len;
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

void GetMarks( STD_DETAILS_S * info )
{
    float cwt1, cwt2, cmt, awt, amt, cppwt, cppmt;
    float TotalMarks = 600;
    printf("Enter the marks of CWT1: ");
    scanf("%f", &cwt1);
    printf("Enter the marks of CWT2: ");
    scanf("%f", &cwt2);
    printf("Enter the marks of CMT: ");
    scanf("%f", &cmt);
    printf("Enter the marks of AWT: ");
    scanf("%f", &awt);
    printf("Enter the marks of AMT: ");
    scanf("%f", &amt);
    printf("Enter the marks of CppWT: ");
    scanf("%f", &cppwt);
    printf("Enter the marks of CppMT: ");
    scanf("%f", &cppmt);

    info->aca_info.avg_marks = ((cwt1 + cwt2 + cmt + awt + amt + cppwt + cppmt)/TotalMarks)*100;
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

FILE * OpenFile( BatchId_e file )
{
  switch(file)
  {
    case Batch_Invalid: return NULL;
    case Batch_1: return fopen("v22be1.txt", "r+");
    case Batch_2: return fopen("v22be2.txt", "r+");
    case Batch_3: return fopen("v22be3.txt", "r+");
    case Batch_4: return fopen("v22be4.txt", "r+");
    case Batch_5: return fopen("v22be5.txt", "r+");
    case Batch_6: return fopen("v22be6.txt", "r+");
    case Batch_7: return fopen("v22be7.txt", "r+");
    case Batch_8: return fopen("v22be8.txt", "r+");
    case Batch_9: return fopen("v22be9.txt", "r+");
  }
}
