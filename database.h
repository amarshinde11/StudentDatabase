/****************************************************************************************************************
* @file: database.h
* @brief: This is a header file, contains all predefined as well as user-defined function prototypes,
*         structure declarations, typedefs, enum, macro defination.
*
*
* @uthor: Amar G. Shinde
* Created: 13/03/2023.
****************************************************************************************************************/

#ifndef __DATABASE_H
#define __DATABASE_H

#include<stdio.h>
#include<stdlib.h>


#define ID_BUF          10
#define STS_BUF         15
#define NAME_BUF        30
#define DEBUG           0
#define SUCCESS         1
#define FAIL            0
#define TRUE            1
#define FALSE           0
#define FILE_NOT_OPENED 0

typedef struct student_personalinfo     STD_PERS_INFO_S;
typedef struct student_acadamicsinfo    STD_ACAD_INFO_S;
typedef struct student_details          STD_DETAILS_S;

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

struct student_acadamicsinfo
{
    char batch_id[ID_BUF];
    char std_name[NAME_BUF];
    float avg_marks;
    char assmt_status[STS_BUF];
};

struct student_personalinfo
{
    unsigned int dd:8;
    unsigned int mm:8;
    unsigned int yyyy:16;
};
struct student_details
{
    STD_PERS_INFO_S d_birth, d_join;
    STD_ACAD_INFO_S aca_info;
};

void AllocateMemory( STD_DETAILS_S ** p );
void GetStdDetailInfo( STD_DETAILS_S * info );
void PrintStdDetailInfo( STD_DETAILS_S * info );
void GetPersonalDetails( STD_DETAILS_S * info );
void WriteStdDetailInfo( STD_DETAILS_S * info );
void WriteIntoFile( FILE * fp, STD_DETAILS_S * info );
void ReadFromFile( FILE * fp );
void ReadStdInfoFromFile( STD_DETAILS_S * info, const char * batchid );
BatchId_e ValidateStdDataFile( STD_DETAILS_S * info );
BatchId_e FileOpenedToRead( const char * batchid );
int ReadFileToFindName(const char * filename, const char * std_name );
int ReadFileToFindDOB(const char * filename, int dd, int mm, int yyyy);
int ReadFileToFindDOJ(const char * filename, int dd, int mm, int yyyy);
int ConvertAndCompareDate(const char * date, int dd, int mm, int yyyy);
int ReadFileToFindAssessmentSts(const char * filename, const char * Asmnt_Sts);
int ReadFileToFindRangeMarks(const char * filename, float min_marks, float max_marks);
void ReadFileStdBatchId( FILE * fp, const char * std_batchid );
void SearchStdDetailsByDoB(int dd, int mm, int yyyy);
void SearchStdDetailsByDoJ(int dd, int mm, int yyyy);
void SearchStdDetailsByName(const char * name );
void SearchStdDetailsByStdBatchId( const char * std_batchid );
void SearchStdDetailsByRangeOfMarks( float min_range, float max_range );
void SearchStdDetailsByAssessmentSts( const char * Asmnt_Sts );
char * MatchBatchId( const char * buf_id, const char * std_batchid );
void EditFileDataWithCorrectInfo( void );
void EditName( void );
void EditBatchId( void );
void EditAvgMarks( void );
void EditAssessmetSts( void );
FILE * OpenFile( BatchId_e file );
void GetMarks( STD_DETAILS_S * info );
int SearchNameDoBToEditBatchId( FILE * fp, STD_DETAILS_S * info );
int SearchBatchIdDoBToEditName( FILE * fp, STD_DETAILS_S * info );
int SearchBatchIdNameToEditMarks(FILE * fp, STD_DETAILS_S * info);
int SearchBatchIdNameToEditAsmntSts(FILE * fp, STD_DETAILS_S * info);



#endif // DATABASE_H
