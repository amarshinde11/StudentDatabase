/*****************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*
* @file: database.c
* @brief: This is file contains all the functions to scan the student data, validate the data, print the data on screen,
*           write the scanned data into appropriate file, read the data from file to print on screen, search the details
*           of students by provided info like, student name, batch id, marks range, assessment status, date of birth,
*           date of join the institute.
*
* @uthor  : Amar G. Shinde
* @Created: 13/03/2023.
*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
******************************************************************************************************************************/

#include"database.h"
#include"my_string.h"


/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* AllocateMemory(): allocate memory dynamically to hold the address
* of structure. If memory is already allocated then no need to allocate
* further.
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
void AllocateMemory( STD_DETAILS_S ** p )
{
    if( *p == NULL ) { /* check if the memory is already allocated or not */
        if( ( *p = malloc(sizeof(STD_DETAILS_S)) ) == NULL )
            printf("Memory not allocated.\n");
    }
    else {/* memory is already allocated */
        printf("Memory is already allocated.\n");
    }
}


/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* void InitializeFiles(void): This function initialize the
* files with index titles and if file is not available
* then it first creates the file & initializes.
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
void InitializeFiles( void )
{
    FILE * fp;

    if( (fp = fopen("v22be1.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be1.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be1.txt is already initialized\n");
    }

    if( (fp = fopen("v22be2.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be2.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be2.txt is already initialized\n");
    }
    if( (fp = fopen("v22be3.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be3.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be3.txt is already initialized\n");
    }
    if( (fp = fopen("v22be4.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be4.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be4.txt is already initialized\n");
    }

    if( (fp = fopen("v22be5.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be5.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be5.txt is already initialized\n");
    }

    if( (fp = fopen("v22be6.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be6.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be6.txt is already initialized\n");
    }
    if( (fp = fopen("v22be7.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be7.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be7.txt is already initialized\n");
    }

    if( (fp = fopen("v22be8.txt", "r")) == NULL ) {/*if file is not opened then create new file init. */
        fp = fopen("v22be8.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be8.txt is already initialized\n");
    }
    if( (fp = fopen("v22be9.txt", "r")) == NULL ) { /*if file is not opened then create new file init. */
        fp = fopen("v22be9.txt", "w");
        fprintf(fp, "Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
        fclose(fp);
    }
    else { /*if file is already initialized then don't init. */
        printf("File v22be9.txt is already initialized\n");
    }
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* GetStdDetailInfo(): scan all the academic details
* i.e. Batch id, name of student, all subject marks
* and assessment status, also scan the personal info.
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
void GetStdDetailInfo( STD_DETAILS_S * info )
{
    float cwt1, cwt2, cmt, awt, amt, cppwt, cppmt;
    float TotalMarks = 600;

    printf("Enter the batch id: ");
    scanf(" %s", info->aca_info.batch_id);

    printf("Enter the name of student: ");
    scanf(" %[^\n]", info->aca_info.std_name);

    GetMarks(info);

    printf("Enter the assessment status: ");
    scanf(" %s", info->aca_info.assmt_status);

    GetPersonalDetails(info);

}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
*  void GetMarks( STD_DETAILS_S * info ):This is function to gate all
*  subject marks and fund the average to save in the file.
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
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

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
*  GetPersonalDetails(): Scan the personal information
* i.e. date of birth and date of joining.
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
void GetPersonalDetails( STD_DETAILS_S * info )
{
    GetDOB(info);
    GetDOJ(info);
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* GetDOJ(): This function in to Scan The date of joining the institute.
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
void GetDOJ( STD_DETAILS_S * info )
{
    int dd,mm,yyyy;
    printf("Enter the date of joining: ");
    scanf("%d%d%d", &dd, &mm, &yyyy);
    info->d_join.dd = dd, info->d_join.mm = mm, info->d_join.yyyy = yyyy;
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* GetDOB(): This function in to Scan The date of Birth of student
*
//////////////////////////////////////////////////////////////////////////
**************************************************************************/
void GetDOB( STD_DETAILS_S * info )
{
    int dd,mm,yyyy;
    printf("Enter the date of birth: ");
    scanf("%d%d%d", &dd, &mm, &yyyy);
    info->d_birth.dd = dd, info->d_birth.mm = mm, info->d_birth.yyyy = yyyy;
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* PrintStdDetailInfo(): print the scanned info on to screen
* before writing into file to check any mistake is made.
*
//////////////////////////////////////////////////////////////////////////
*************************************************************************/
void PrintStdDetailInfo( STD_DETAILS_S * info )
{
    printf("Batch Id    Std Name       Avg_Marks   Assessment Sts DateOfBirth DateOfJoining\n");
    printf("%s   %12s    %5.2f    %10s       ",info->aca_info.batch_id, info->aca_info.std_name, info->aca_info.avg_marks, info->aca_info.assmt_status);
    printf("%2d:%2d:%4d   ", info->d_birth.dd, info->d_birth.mm, info->d_birth.yyyy);
    printf("%2d:%2d:%4d\n", info->d_join.dd, info->d_join.mm, info->d_join.yyyy);
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* BatchId_e ValidateStdDataFile( STD_DETAILS_S * info ):
* This function validates the data with respect to batch
* to write into or read from the file for that perticuler batch.
*
//////////////////////////////////////////////////////////////////////////
*************************************************************************/
BatchId_e ValidateStdDataFile( const char * batch_id )
{
    if( batch_id[5] == '1' )
        return Batch_1;
    else if( batch_id[5] == '2' )
        return Batch_2;
    else if( batch_id[5] == '3' )
        return Batch_3;
    else if( batch_id[5] == '4' )
        return Batch_4;
    else if( batch_id[5] == '5' )
        return Batch_5;
    else if( batch_id[5] == '6' )
        return Batch_6;
    else if( batch_id[5] == '7' )
        return Batch_7;
    else if( batch_id[5] == '8' )
        return Batch_8;
    else if( batch_id[5] == '9' )
        return Batch_9;
    else return Batch_Invalid;
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* void WriteStdDetailInfo( info ): this function writes the scanned
* student's data into validated batch file.
* Before writing into file it need to find out the batch of student
* to which the student is belongs to.
*
//////////////////////////////////////////////////////////////////////////
*************************************************************************/
void WriteStdDetailInfo( STD_DETAILS_S * info )
{
    BatchId_e file;
    FILE * fp;
    file = ValidateStdDataFile(info->aca_info.batch_id);

    switch( file ) {
        case Batch_1:   if( (fp = fopen("v22be1.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_2:   if( (fp = fopen("v22be2.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_3:   if( (fp = fopen("v22be3.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_4:   if( (fp = fopen("v22be4.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_5:   if( (fp = fopen("v22be5.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_6:   if( (fp = fopen("v22be6.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_7:   if( (fp = fopen("v22be7.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_8:   if( (fp = fopen("v22be8.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_9:   if( (fp = fopen("v22be9.txt", "a")) == NULL  ) {
                            printf("Unable to open file.\n");
                            return;
                        }
        break;
        case Batch_Invalid: printf("Invalid batch Id\n");
                    return;
        break;
        default:    return;
        break;
    }
    printf("Writing into v22be%d.txt\n", file);
    WriteIntoFile( fp, info );
    fclose(fp);
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* WriteIntoFile(FILE *, STD_DETAILS_S *):
* this fun write / save the data into a file permanently as one of the
* argument is file pointer and other contains a data to be saved.
*
//////////////////////////////////////////////////////////////////////////
*************************************************************************/
void WriteIntoFile( FILE * fp, STD_DETAILS_S * info )
{
    fprintf(fp, "%s   %12s    %5.2f    %10s        ",info->aca_info.batch_id, info->aca_info.std_name, info->aca_info.avg_marks, info->aca_info.assmt_status);
    fprintf(fp, "%2d:%2d:%4d   ", info->d_birth.dd, info->d_birth.mm, info->d_birth.yyyy);
    fprintf(fp, "%2d:%2d:%4d\n", info->d_join.dd, info->d_join.mm, info->d_join.yyyy);
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* void ReadStdInfoFromFile( STD_DETAILS_S *, const char * ):
* This is a fun to open the appropriate file asked by the user
* i.e. batchid file. After opening file call the which reads
* the data from file display onto screen.
*
//////////////////////////////////////////////////////////////////////////
*************************************************************************/
void ReadStdInfoFromFile( STD_DETAILS_S * info, const char * batchid )
{
    FILE * fp;
    BatchId_e file;
    file = ValidateStdDataFile(batchid);
    switch(file)
    {
        case Batch_1: if( (fp = fopen("v22be1.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_2: if( (fp = fopen("v22be2.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_3: if( (fp = fopen("v22be3.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_4: if( (fp = fopen("v22be4.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_5: if( (fp = fopen("v22be5.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_6: if( (fp = fopen("v22be6.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_7: if( (fp = fopen("v22be7.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_8: if( (fp = fopen("v22be8.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_9: if( (fp = fopen("v22be9.txt", "r")) == NULL  ) {
                        printf("Unable to open file.\n");
                        return;
                    }
        break;
        case Batch_Invalid: printf("Invalid batch Id\n");
                    return;
        break;
        default:
                    return;
        break;
    }
    ReadFromFile(fp);
    fclose(fp);
}

/*************************************************************************
//////////////////////////////////////////////////////////////////////////
*
* void ReadFromFile( FILE * ):
* This is function read all the data line-by-line and
* print onto screen. File pointer is argument used to read
* data as appropriate file is opened already.
*
/////////////////////////////////////////////////////////////////////////
*************************************************************************/
void ReadFromFile( FILE * fp )
{
    char * buf;
    if( (buf = malloc(150*sizeof(char))) == NULL )
    {
        char buf1[150]; /* if dynamic memory failed then use static memory */
        while( fscanf(fp, " %[^\n]", buf1 ) != EOF ) {
            printf("%s\n", buf1);
        }
        return;
    }

    while( fscanf(fp, " %[^\n]", buf ) != EOF ) {
        printf("%s\n", buf);
    }
    free(buf);
}


/***************************************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*
* void SearchDetailsByNameOrAssessmentSts( int (*FunPtr)(const char *, const char *), const char *)
* This is fun to select the files one-by-one, to be opened to search the records of all students by
* Name Or Assessment status. This fun calls one of the function to search name or assessment sts
*
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*****************************************************************************************************************/
void SearchDetailsByNameOrAssessmentSts( int (*FunPtr)(const char *, const char *), const char * Asmnt_Sts )
{
    int files = 1, records = 0, count = 0;
    while( files <= Batch_9 )
    {
       switch( files )
       {
           case Batch_1: records = FunPtr("v22be1.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_2: records = FunPtr("v22be2.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_3: records = FunPtr("v22be3.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_4: records = FunPtr("v22be4.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_5: records = FunPtr("v22be5.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_6: records = FunPtr("v22be6.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_7: records = FunPtr("v22be7.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_8: records = FunPtr("v22be8.txt", Asmnt_Sts);
                        count += records;
           break;
           case Batch_9: records = FunPtr("v22be9.txt", Asmnt_Sts);
                        count += records;
           break;
       }
       files++;
    }
    if( count <= 0 )
        printf("Student data not found in database for \"%s\"\n", Asmnt_Sts);
}

/************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////
*
* int PrintAssessmentSts(const char * filename, const char * Asmnt_Sts):
* This fun opens file as one of the parameter is filename, reads data line-line
* search the records for all students on basis of assessment status.
*
/////////////////////////////////////////////////////////////////////////////////////
*************************************************************************************/
int PrintAssessmentSts(const char * filename, const char * Asmnt_Sts)
{
    FILE *fp;
    char * buf_sts;
    int count = 0;

    if( (fp = fopen(filename, "r")) == NULL ) { /* check if file is available or not */
        printf("File is not available.\n");
        return FILE_NOT_OPENED;
    }

    buf_sts = malloc(100 * sizeof(char));

    fscanf(fp, " %[^\n]", buf_sts);

    while( fscanf(fp, " %[^\n]", buf_sts) != EOF ) {

        if( my_strstr(buf_sts, Asmnt_Sts) != NULL )
        {
            if( count <= 0 )
                printf("Batch Id    Std Name       Avg_Marks   Assessment_Sts DateOfBirth DateOfJoining\n");
                printf("%s\n", buf_sts);
                count++;
        }
    }
    free(buf_sts);
    fclose(fp);
    if( count <= 0 )
        return 0;
    return count;
}

/*******************************************************************************
////////////////////////////////////////////////////////////////////////////////
*
* int ReadFileToFindName(const char * filename, const char * std_name):
* This is fun to open the file with filename as one of the parameter
* Read data line-by-line and search the name of student in that line,
* if name is found in line then print the details of that student.
* If found in multiple lines, print that many times.
* If not found in file, return 0( i.e. not found in file1 )
*
/////////////////////////////////////////////////////////////////////////////
*****************************************************************************/
int ReadFileToFindName( const char * filename, const char * std_name )
{
    FILE * fp;
    char * buf;
    int count = 0;

    if( (fp = fopen(filename, "r")) == NULL ) {
        printf("File is not available\n");
        return FILE_NOT_OPENED;
    }

    buf = malloc(100*sizeof(char));
    if( buf == NULL ) {
        printf("Memory not allocated to buffer.\n");
        return NULL;
    }
    while( fscanf(fp, " %[^\n]", buf) != EOF )
    {
        if( my_strstr(buf, std_name) != NULL )
        {
            if( count <= 0 )
                printf("Batch Id    Std Name       Avg_Marks   Assessment_Sts DateOfBirth DateOfJoining\n");
            printf("%s\n",buf);
            count++;
        }
    }
    free(buf);
    fclose(fp);
    if( count <= 0 )
        return 0;
    return count;
}

/********************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////
*
* void SearchStdDetailsByDate(int (*FunPtr)(const char *, int, int, int), int dd, int mm, int yyyy ):
* This is function to select all file to open and search student's records, Function pointer takes
* inputs filename, day, month, year as parameter and return result int 1 or 0.
* Select files one-by-one & pass to function pointer to open & read.
*
//////////////////////////////////////////////////////////////////////////////////////////////////////////
*********************************************************************************************************/
void SearchStdDetailsByDate( int (*FunPtr)(const char *, int, int, int), int dd, int mm, int yyyy )
{
    int files = 1, records = 0, count = 0;
    while( files <= Batch_9 )
    {
       switch( files )
       {
           case Batch_1: records = FunPtr("v22be1.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_2: records = FunPtr("v22be2.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_3: records = FunPtr("v22be3.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_4: records = FunPtr("v22be4.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_5: records = FunPtr("v22be5.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_6: records = FunPtr("v22be6.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_7: records = FunPtr("v22be7.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_8: records = FunPtr("v22be8.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_9: records = FunPtr("v22be9.txt", dd, mm, yyyy);
                        count += records;
           break;
       }
       files++;
    }
    if( count <= 0 )
        printf("Student data not found in database.\n");
}

/**************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////
*
* int ReadFileToFindDOB(filename, day, month, year):
* This is fun to open the file by filename provided, read the data line-by-line
* search for the date of Birth given by user.
* If Date of Birth matched multiple times the print data that many times.
*
//////////////////////////////////////////////////////////////////////////////////////
**************************************************************************************/
int ReadFileToFindDOB(const char * filename, int dd, int mm, int yyyy)
{
    FILE *fp;
    int match, cnt = 0;
    char * buf, * buf1;

    if( (fp = fopen(filename, "r")) == NULL ) { /* if file is not available, don't try to read, just return back */
        printf("File not available\n");
        return FILE_NOT_OPENED;
    }
    buf = malloc(100*sizeof(char)); /* allocate the buffer(mem) to hold the line from file */
    buf1 = malloc(50*sizeof(char)); /* allocate the buffer(mem) to hold the date of birth string */

    fscanf(fp," %[^\n]",buf); /* read the first line of file which is just index line */

    while( fscanf(fp," %[^\n]",buf) != EOF )
    {
        fseek(fp, -23, SEEK_CUR);   /* data of birth is available 23 char backward from end of line */
        fscanf(fp, " %[^\n]", buf1);    /* read the date of birth string into one buffer */
        match = ConvertAndCompareDate(buf1, dd, mm, yyyy); /* send the buffer to convert date string into integer
                                                              and compare with user given date of birth */
        if( match == 1 )    /* if date of birth is match(1), print the details of that student */
        {
            cnt++;          /* count in each file how many date of birth matches */
            printf("%s\n",buf);
        }
    }
    free(buf);  /* after use of dynamic memory, free it */
    free(buf1); /* after use of dynamic memory, free it */
    fclose(fp); /* after over the reading of file, close it */
    return cnt; /* return the count of how many DOB matched */
}

/**************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////
*
* int ReadFileToFindDOJ( const char * filename, int dd, int mm, int yyyy ):
* This is a fun to open the file as given by one of the parameter,
* read the file data line-line and search for date of joining in that line,
* if match found print all the details.
*
////////////////////////////////////////////////////////////////////////////////////////
***************************************************************************************/
int ReadFileToFindDOJ( const char * filename, int dd, int mm, int yyyy )
{
    FILE *fp;
    int match, cnt = 0;
    char * buf, * buf1;

    if( (fp = fopen(filename, "r")) == NULL ) { /* if file is not available, don't try to read, just return back */
        printf("File not available\n");
        return FILE_NOT_OPENED;
    }
    buf = malloc(100*sizeof(char)); /* allocate the buffer(mem) to hold the line from file */
    buf1 = malloc(50*sizeof(char)); /* allocate the buffer(mem) to hold the date of joining string */

    fscanf(fp," %[^\n]",buf); /* read the first line of file which is just index line */

    while( fscanf(fp," %[^\n]",buf) != EOF )
    {
        fseek(fp, -10, SEEK_CUR);       /* data of joining is available 10 char backward from end of line */
        fscanf(fp, " %[^\n]", buf1);    /* read the date of joining string into one buffer */
        match = ConvertAndCompareDate(buf1, dd, mm, yyyy); /* send the buffer to convert date string into integer
                                                              and compare with user given date of joining */
        if( match == 1 )    /* if date of joining is match(1), print the details of that student */
        {
            cnt++;          /* count in each file how many date of joining matches */
            printf("%s\n",buf);
        }
    }
    free(buf);  /* after use of dynamic memory, free it */
    free(buf1); /* after use of dynamic memory, free it */
    fclose(fp); /* after over the reading of file, close it */
    return cnt; /* return the count of how many DOJ matched */
}

/***************************************************************************
////////////////////////////////////////////////////////////////////////////
*
* int ConvertAndCompareDate(date_string, day, month, year):
* This is function to convert the date of Birth / joining, which is available
* in the form of string into integers(dd,mm,yyyy) and compare with
* the date given by user which is in the form of intergers.
*
////////////////////////////////////////////////////////////////////////////
***************************************************************************/
int ConvertAndCompareDate( const char * date, int dd, int mm, int yyyy )
{
    int i = 0, d = 0, m = 0, y = 0;

    for( i = 0; i < 10; i++ )   /* convert the string into integer numbers (dd,mm,yyyy) */
    {
        if( date[i] >= '0' && date[i] <= '9' )
        {
            if( i < 2 ) /* convert the day (2 digits) */
                d = (d * 10) + (date[i]-48);
            else if( i >= 2 && i < 5) /* convert the month (2 digits) */
                m = (m * 10) + (date[i]-48);
            else  /* convert the year (4 digits) */
                y = (y * 10) + (date[i]-48);
        }
    }

    if( (d == dd) && /* compare the day */
        (m == mm) && /* compare the month */
       (y == yyyy) ) /* compare the year */
       {    /* if all three compared and matched successfully then only return 1, else return 0 */
        return SUCCESS;
       }
    return FAIL;
}

/********************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////
*
* void SearchStdDetailsByStdBatchId( std_batchid ):
* This is a function to open a appropriate file as per student's batch Id
* given as one of the parameter. Calls a function which read the data line-line
* and compare with each student's batch id in the file.
*
/////////////////////////////////////////////////////////////////////////////////////////////
********************************************************************************************/
void SearchStdDetailsByStdBatchId( const char * std_batchid )
{
    FILE * fp;
    BatchId_e file = ValidateStdDataFile(std_batchid);
    switch(file)
    {
        case Batch_1: printf("searching in file \"v22be1.txt\"\n");
                        if( (fp = fopen("v22be1.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_2: printf("searching in file \"v22be2.txt\"\n");
                        if( (fp = fopen("v22be2.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_3: printf("searching in file \"v22be3.txt\"\n");
                        if( (fp = fopen("v22be3.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_4: printf("searching in file \"v22be4.txt\"\n");
                        if( (fp = fopen("v22be4.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_5: printf("searching in file \"v22be5.txt\"\n");
                        if( (fp = fopen("v22be5.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_6: printf("searching in file \"v22be6.txt\"\n");
                        if( (fp = fopen("v22be6.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_7: printf("searching in file \"v22be7.txt\"\n");
                        if( (fp = fopen("v22be7.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_8: printf("searching in file \"v22be8.txt\"\n");
                        if( (fp = fopen("v22be8.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        case Batch_9: printf("searching in file \"v22be9.txt\"\n");
                        if( (fp = fopen("v22be9.txt", "r")) == NULL ) {
                            printf("Unable to open the file\n");
                            return;
                        }
        break;
        default: printf("Enter the student's valid batch id\n");
            return;
        break;
    }
    ReadFileStdBatchId(fp, std_batchid);
    fclose(fp);
}

/******************************************************************************************
///////////////////////////////////////////////////////////////////////////////////////////
*
* void ReadFileStdBatchId( FILE * fp, const char * std_batchid ):
* This fun reads data line-by-line from a file already opened to read.
* search for student's batch id, if found in file, prints the details
* of that student.
*
///////////////////////////////////////////////////////////////////////////////////////////
******************************************************************************************/
void ReadFileStdBatchId( FILE * fp, const char * std_batchid )
{
    char *buf_id;
    buf_id = malloc(100 * sizeof(char));
    while( fscanf( fp, " %[^\n]", buf_id ) != EOF )
    {
        if( MatchBatchId(buf_id, std_batchid) != NULL ) {
         printf("Batch Id    Std Name       Avg_Marks   Assessment_Sts DateOfBirth DateOfJoining\n");
         printf("%s\n", buf_id);
         free(buf_id);
         return;
        }
    }
    printf("No Record found for the student id: %s\n", std_batchid);
}

/****************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////
*
* char* MatchBatchId( const char * buf_id, const char * std_batchid ):
* This is fun to match the student's batch id with the id read from
* the file. If found return non-NULL address of line, else NULL.
*
/////////////////////////////////////////////////////////////////////////////////////////
****************************************************************************************/
char * MatchBatchId( const char * buf_id, const char * std_batchid )
{
    int i = 0;
    while( std_batchid[i] != '\0' )
    {
        if( std_batchid[i] != buf_id[i] )
            break;
        i++;
    }
    if( (std_batchid[i] == '\0') && (buf_id[i] == ' ') )
        return buf_id;
    else
        return NULL;
}


/*****************************************************************************************
//////////////////////////////////////////////////////////////////////////////////////////
*
* void SearchStdDetailsByRangeOfMarks( float min_marks, float max_marks ):
* This is fun to select the file one-by-one to read data of students
* between given range of marks.
*
///////////////////////////////////////////////////////////////////////////////////////////
******************************************************************************************/
void SearchStdDetailsByRangeOfMarks( float min_marks, float max_marks )
{
    int files = 1, records = 0, count = 0;
    while( files <= Batch_9 )
    {
       switch( files )
       {
           case Batch_1: records = ReadFileToFindRangeMarks("v22be1.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_2: records = ReadFileToFindRangeMarks("v22be2.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_3: records = ReadFileToFindRangeMarks("v22be3.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_4: records = ReadFileToFindRangeMarks("v22be4.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_5: records = ReadFileToFindRangeMarks("v22be5.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_6: records = ReadFileToFindRangeMarks("v22be6.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_7: records = ReadFileToFindRangeMarks("v22be7.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_8: records = ReadFileToFindRangeMarks("v22be8.txt", min_marks, max_marks);
                        count += records;
           break;
           case Batch_9: records = ReadFileToFindRangeMarks("v22be9.txt", min_marks, max_marks);
                        count += records;
           break;
       }
       files++;
    }
    if( count <= 0 )
        printf("Student data not found in database.\n");
}

/*********************************************************************************************
//////////////////////////////////////////////////////////////////////////////////////////////
*
* int ReadFileToFindRangeMarks(const char * filename, float min_marks, float max_marks):
* This is function to open the file as one of the parameter is filename, read data
* line-by-line, Call a function which converts the string into float values and
* compare the values the given range of marks. If record found bet given range of marks,
* print all the student's data who lies bet the range.
*
//////////////////////////////////////////////////////////////////////////////////////////////
*********************************************************************************************/
int ReadFileToFindRangeMarks( const char * filename, float min_marks, float max_marks )
{
    char * buf_marks, *buf_line;
    FILE * fp;
    float avg_marks = 0;
    int count = 0;

    if( (fp = fopen(filename, "r")) == NULL ){
            printf("File is not available.\n");
            return FILE_NOT_OPENED;
    }

    if( (buf_marks = malloc(10*sizeof(char))) == NULL ) {
        printf("Memory is not allocated to buffer\n");
        return FAIL;
    }
    if( (buf_line = malloc(100*sizeof(char))) == NULL ) {
        printf("Memory is not allocated to buffer\n");
        return FAIL;
    }
    fscanf(fp, " %[^\n]", buf_line);

    while( fscanf(fp, " %[^\n]", buf_line) != EOF )
    {
        fseek(fp, -51, SEEK_CUR);

        fscanf(fp, " %s", buf_marks);

        avg_marks = my_atof( buf_marks );

        if( (avg_marks >= min_marks) && (avg_marks <= max_marks) )
        {
            if( count <= 0 )
                printf("Batch Id    Std Name       Avg_Marks   Assessment_Sts DateOfBirth DateOfJoining\n");
            count++;
            printf("%s\n", buf_line);
        }
        fscanf(fp, " %[^\n]", buf_line);
    }

    fclose(fp);
    free(buf_marks);
    free(buf_line);

    if( count <= 0 )
        return FAIL;
    return count;
}

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* float my_atof( const char * mark_str ): This is function to convert the string into float value
* with precision of 2 digits after decimal point.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
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

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* void EditFileDataWithCorrectInfo(void): This is function called when we want to edit previously
* saved data with some modification OR if any data saved in-correctly that need to be edited and
* rewritten into file with right information.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
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
        case Edit_ID: /* edit the batch id of student */
                EditBatchId();
        break;
        case Edit_Name: /* edit the name of student */
                EditName();
        break;
        case Edit_Marks: /* Edit the avg marks */
                EditAvgMarks();
        break;
        case Edit_ASts: /* edit the assessment status */
                EditAssessmetSts();
        break;
        case Edit_DoB: /* edit the date of birth */
                EditDates( SearchBatchIdNameToEditDate, Edit_DoB );
        break;
        case Edit_DoJ: /* edit the date of joining */
                EditDates( SearchBatchIdNameToEditDate, Edit_DoJ );
        break;
        default: /* edit the name of student */
                printf("Invalid Choice\n");
        break;
    }
}

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* FILE * OpenFile( BatchId_e file ): This function opens file in read-write mode to
*       search & match any two verification fields (e.g. name & batch id) before modifying data.
*       This function return the file pointer to the file opened.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
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

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* void EditDates( int (*FunPtr)( FILE *, STD_DETAILS_S *), int field  ): This is function to
* modify the date of birth as well as  date of joining.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
void EditDates( int (*FunPtr)( FILE *, STD_DETAILS_S *, EditField ), EditField field  )
{
    STD_DETAILS_S * info;
    FILE * fp;
    int i = 0, done = 0;

    if( field == Edit_DoB )
        printf("\nTo Edit Date of Birth,\n");
    else
        printf("\nTo Edit Date of Joining,\n");

    info = malloc( sizeof(STD_DETAILS_S) );

    printf("Enter the batch id: ");
    scanf(" %s",info->aca_info.batch_id);
    printf("Enter Student's Name: ");
    scanf(" %[^\n]",info->aca_info.std_name);

    while( (i <= Batch_9) && (done != SUCCESS) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            done = FunPtr(fp, info, field);
            fclose(fp);
        }
        i++;
    }
    if( done == FAIL )
        printf("No info found for \"%s %s\" student in database\n", info->aca_info.batch_id, info->aca_info.std_name);
    else {
        if( field == Edit_DoB )
            printf("The Date of Birth updated for student %s\n", info->aca_info.batch_id);
        else
            printf("The Date of Joining updated for student %s\n", info->aca_info.batch_id);
    }
    free(info);
}

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
*   int SearchBatchIdNameToEditDate( FILE * fp, STD_DETAILS_S * info ): This function will verify
*   the name and batch id before modifying the dates, to confirm that modification taken place
*   to write persons data or not. Once verified, then this function also modify the dates
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
int SearchBatchIdNameToEditDate( FILE * fp, STD_DETAILS_S * info, EditField field)
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

                        if( field == Edit_DoB )
                        {
                            GetDOB(info);
                            EditDOB(buf, info);
                        }
                        else if( field == Edit_DoB )
                        {
                            GetDOJ(info);
                            EditDOJ(buf, info);
                        }
                        fseek(fp, -length, SEEK_CUR);
                        fprintf(fp, "%s", buf);

                        free(buf);
                        return SUCCESS;
                }/* student's name matched */
            }/* student id matched */
    }
    return FAIL;
}



/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* void EditDOJ( char * buf, STD_DETAILS_S * info ): This is function to edit the buffer read
*   from file with correct date of joining.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
void EditDOJ( char * buf, STD_DETAILS_S * info )
{
    while( *(buf+10) != '\0' )
        buf++;

    buf[0] = ((info->d_join.dd/10) + '0');
    buf[1] = ((info->d_join.dd%10) + '0');
    buf[3] = ((info->d_join.mm/10) + '0');
    buf[4] = ((info->d_join.mm%10) + '0');

    buf[6] = ( ((info->d_join.yyyy)/1000)      + '0' );
    buf[7] = ( (((info->d_join.yyyy)/100)%10)  + '0' );
    buf[8] = ( (((info->d_join.yyyy)/10)%10)   + '0' );
    buf[9] = ( ((info->d_join.yyyy)%10)        + '0' );

}

/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
* void EditDOB( char * buf, STD_DETAILS_S * info ): This is function to edit the buffer read
*   from file with correct date of birth.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
void EditDOB( char * buf, STD_DETAILS_S * info )
{
    while( *(buf+23) != '\0' )
        buf++;
    buf[0] = ((info->d_birth.dd/10) + '0');
    buf[1] = ((info->d_birth.dd%10) + '0');
    buf[3] = ((info->d_birth.mm/10) + '0');
    buf[4] = ((info->d_birth.mm%10) + '0');

    buf[6] = ( ((info->d_birth.yyyy)/1000)      + '0' );
    buf[7] = ( (((info->d_birth.yyyy)/100)%10)  + '0' );
    buf[8] = ( (((info->d_birth.yyyy)/10)%10)   + '0' );
    buf[9] = ( ((info->d_birth.yyyy)%10)        + '0' );

}


/*******************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
//    The following functions are redundant, They are used when required.                 //
//    The alternative function are implemented instead of these.                          //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////
********************************************************************************************/

#if(EXPERIMENT == 1)
/*******************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////
*
* void SearchStdDetailsByDoB(day, month, year):
* This is function to select all file to open and search student's
* records by date of Birth.
* Select files one-by-one & pass to function to open & read.
*
////////////////////////////////////////////////////////////////////////////////////////////
********************************************************************************************/
void SearchStdDetailsByDoB(int dd, int mm, int yyyy)
{
    int files = 1, records = 0, count = 0;
    while( files <= Batch_9 )
    {
       switch( files )
       {
           case Batch_1: records = ReadFileToFindDOB("v22be1.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_2: records = ReadFileToFindDOB("v22be2.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_3: records = ReadFileToFindDOB("v22be3.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_4: records = ReadFileToFindDOB("v22be4.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_5: records = ReadFileToFindDOB("v22be5.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_6: records = ReadFileToFindDOB("v22be6.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_7: records = ReadFileToFindDOB("v22be7.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_8: records = ReadFileToFindDOB("v22be8.txt", dd, mm, yyyy);
                        count += records;
           break;
           case Batch_9: records = ReadFileToFindDOB("v22be9.txt", dd, mm, yyyy);
                        count += records;
           break;
       }
       files++;
    }
    if( count <= 0 )
        printf("Student data not found in database.\n");
}
#endif //EXPERIMENT


#if (EXPERIMENT == 1)
/************************************************************************************
//////////////////////////////////////////////////////////////////////////////////////
*
* void SearchStdDetailsByName( const char * ): This is fun to call to a
* fun which opens a file to find out name of student is present or not.
* search the details of student from all databse files
* by provided name of student.
*
/////////////////////////////////////////////////////////////////////////////////////
*************************************************************************************/
void SearchStdDetailsByName( const char * name )
{
    int files = 1, records = 0, count = 0;
    while( files <= Batch_9 )
    {
       switch( files )
       {
           case Batch_1: records = ReadFileToFindName("v22be1.txt", name);
                        count += records;
           break;
           case Batch_2: records = ReadFileToFindName("v22be2.txt", name);
                        count += records;
           break;
           case Batch_3: records = ReadFileToFindName("v22be3.txt", name);
                        count += records;
           break;
           case Batch_4: records = ReadFileToFindName("v22be4.txt", name);
                        count += records;
           break;
           case Batch_5: records = ReadFileToFindName("v22be5.txt", name);
                        count += records;
           break;
           case Batch_6: records = ReadFileToFindName("v22be6.txt", name);
                        count += records;
           break;
           case Batch_7: records = ReadFileToFindName("v22be7.txt", name);
                        count += records;
           break;
           case Batch_8: records = ReadFileToFindName("v22be8.txt", name);
                        count += records;
           break;
           case Batch_9: records = ReadFileToFindName("v22be9.txt", name);
                        count += records;
           break;
       }
       files++;
    }
    if( count <= 0 )
        printf("Student data not found in database.\n");
}
#endif //EXPERIMENT

#if (EXPERIMENT == 1)
void EditDateOfJoining( void )
{
    STD_DETAILS_S * info;
    int d, m, y, i = 1, done = 0;
    FILE * fp;
        printf("\nTo Edit Date of Joining,\n");
        printf("Enter the batch id: ");
        scanf(" %s",info->aca_info.batch_id);
        printf("Enter Student's Name: ");
        scanf(" %[^\n]",info->aca_info.std_name);

    while( (i <= Batch_9) && (done != SUCCESS) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            DEBUG(FILE_OPEND...)
            done = SearchBatchIdNameToEditDoJ(fp, info);
            fclose(fp);
        }
        i++;
    }
    if( done == FAIL )
        printf("No info found for \"%s %s\" student in database\n", info->aca_info.batch_id, info->aca_info.std_name);
    else
        printf("The Date of Joining updated for student %s\n", info->aca_info.batch_id);
}
#endif

#if (EXPERMENT==1)
void EditDateOfBirth( void )
{
    STD_DETAILS_S * info;
    int d, m, y, i = 1, done = 0;
    FILE * fp;
    printf("\nTo Edit Date of Birth,\n");
    printf("Enter the batch id: ");
    scanf(" %s",info->aca_info.batch_id);
    printf("Enter Student's Name: ");
    scanf(" %[^\n]",info->aca_info.std_name);

    while( (i <= Batch_9) && (done != SUCCESS) )
    {
        if( (fp = OpenFile( i )) != NULL )
        {
            DEBUG(FILE_OPEND...)
            done = SearchBatchIdNameToEditDoB(fp, info);
            fclose(fp);
        }
        i++;
    }
    if( done == FAIL )
        printf("No info found for \"%s %s\" student in database\n", info->aca_info.batch_id, info->aca_info.std_name);
    else
        printf("The Date of Birth updated for student %s\n", info->aca_info.batch_id);
}
#endif

#if(EXPERIMENT==1)
/************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
*
*   int SearchBatchIdNameToEditDoB( FILE * fp, STD_DETAILS_S * info ): This function will verify
*   the name and batch id before modifying the dates, to confirm that modification taken place
*   to write persons data or not. Once verified, then this function also modify the dates.
*
/////////////////////////////////////////////////////////////////////////////////////////////////
************************************************************************************************/
int SearchBatchIdNameToEditDoB( FILE * fp, STD_DETAILS_S * info )
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

                        GetDOB(info);
                        EditDOB(buf, info);
                        fseek(fp, -length, SEEK_CUR);
                        fprintf(fp, "%s", buf);

                        free(buf);
                        return SUCCESS;
                }/* student's name matched */
            }/* student id matched */
    }
    return FAIL;
}

#endif // 0
