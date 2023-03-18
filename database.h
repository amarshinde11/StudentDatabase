/*****************************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*
* @file: database.h
* @brief: This is a header file, contains all predefined as well as user-defined function prototypes,
*         structure declarations, typedefs, enum, macro defination.
*
* @uthor: Amar G. Shinde
* @created: 13/03/2023.
*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
******************************************************************************************************************************/

#ifndef __DATABASE_H
#define __DATABASE_H

#include<stdio.h>
#include<stdlib.h>

/* macro definition */
#define ID_BUF              10  /* max size of batch id */
#define STS_BUF             15  /* max size of status string */
#define NAME_BUF            30  /* max size of student's name */

#define SUCCESS             1   /* flag used for indication of successful operation */
#define FAIL                0   /* flag used for indication of unsuccessful operation */
#define TRUE                1   /* used to compare the result of operation */
#define FALSE               0   /* used to compare the result of operation */
#define FILE_NOT_OPENED     0   /* flag used for indication of  unsuccessful opening of file */

#ifndef DEBUG
    #define DEBUG               0   /* these flags are used for debug and conditional compilation */
#endif // DEBUG

#define EXPERIMENT          0   /* these flags are used for debug and conditional compilation */


/* typedef */
typedef struct student_personalinfo     STD_PERS_INFO_S;
typedef struct student_acadamicsinfo    STD_ACAD_INFO_S;
typedef struct student_details          STD_DETAILS_S;

/* enum to indicate the batch ids */
typedef enum batchIds {
    Batch_Invalid,
    Batch_1,
    Batch_2,
    Batch_3,
    Batch_4,
    Batch_5,
    Batch_6,
    Batch_7,
    Batch_8,
    Batch_9,
}BatchId_e;

/* enum to edition fields */
typedef enum EditField_e {
    Edit_ID = 1,
    Edit_Name,
    Edit_Marks,
    Edit_ASts,
    Edit_DoB,
    Edit_DoJ,
}EditField;

/* structure to hold info about the academics only */
struct student_acadamicsinfo
{
    char batch_id[ID_BUF];
    char std_name[NAME_BUF];
    float avg_marks;
    char assmt_status[STS_BUF];
};

/* structure to hold personal info i.e. date of birth & joining */
struct student_personalinfo
{
    unsigned int dd:8;
    unsigned int mm:8;
    unsigned int yyyy:16;
};

/* this is base structure to hold different kind of info
    i.e. academic info. as well as personal info.
 */
struct student_details
{
    STD_PERS_INFO_S d_birth, d_join;
    STD_ACAD_INFO_S aca_info;
};

void AllocateMemory( STD_DETAILS_S ** p );
void InitializeFiles( void );
void GetStdDetailInfo( STD_DETAILS_S * info );
void PrintStdDetailInfo( STD_DETAILS_S * info );
void GetPersonalDetails( STD_DETAILS_S * info );
void GetDOJ( STD_DETAILS_S * info );
void GetDOB( STD_DETAILS_S * info );
void GetMarks( STD_DETAILS_S * info );
void WriteStdDetailInfo( STD_DETAILS_S * info );
void WriteIntoFile( FILE * fp, STD_DETAILS_S * info );
void ReadFromFile( FILE * fp );
void ReadStdInfoFromFile( STD_DETAILS_S * info, const char * batchid );

BatchId_e ValidateStdDataFile( const char * batchid );

/* These are function prototypes for searching & reading data from file and display on screen */
/* search details by assessment sts and name */
void SearchDetailsByNameOrAssessmentSts( int (*FunPtr)(const char *, const char *), const char * Asmnt_Sts );
int ReadFileToFindName(const char * filename, const char * std_name );
int PrintAssessmentSts(const char * filename, const char * Asmnt_Sts);

/* search details by date of birth and joining */
void SearchStdDetailsByDate( int (*ptr)(const char * , int, int, int), int dd, int mm, int yyyy );
int ReadFileToFindDOB(const char * filename, int dd, int mm, int yyyy);
int ReadFileToFindDOJ(const char * filename, int dd, int mm, int yyyy);
int ConvertAndCompareDate(const char * date, int dd, int mm, int yyyy);

/* search details by range of avg marks */
void SearchStdDetailsByRangeOfMarks( float min_range, float max_range );
int ReadFileToFindRangeMarks(const char * filename, float min_marks, float max_marks);

/* search details by batch id*/
void SearchStdDetailsByStdBatchId( const char * std_batchid );
void ReadFileStdBatchId( FILE * fp, const char * std_batchid );
char * MatchBatchId( const char * buf_id, const char * std_batchid );

/* these are function prototypes for editing data from file */
void EditFileDataWithCorrectInfo( void );
FILE * OpenFile( BatchId_e file );
void EditStudentsData( int(*FunPointer)( FILE *, STD_DETAILS_S * ), EditField field );
int SearchBatchIdNameToEditDate( FILE * fp, STD_DETAILS_S * info, EditField field );
void EditDates( int (*FunPtr)( FILE *, STD_DETAILS_S *, EditField ), EditField field  );
void EditDOJ( char * buf, STD_DETAILS_S * info );
void EditDOB( char * buf, STD_DETAILS_S * info );
int EditAsessmentSts(    FILE * fp, STD_DETAILS_S * info );
int EditStudentsMarks(   FILE * fp, STD_DETAILS_S * info );
int EditStudentsName(    FILE * fp, STD_DETAILS_S * info );
int EditStudentsBatchId( FILE * fp, STD_DETAILS_S * info );



#endif // DATABASE_H
