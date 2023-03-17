#include <stdio.h>
#include <stdlib.h>

#include"database.h"

int main()
{
    int choice = 0;
    int dd, mm, yyyy;
    char batchid[ID_BUF];
    char std_name[NAME_BUF];
    char Asmnt_Sts[STS_BUF];
    float min_range, max_range;
    STD_DETAILS_S * ptr = NULL;

    AllocateMemory( &ptr );
    InitializeFiles();

    do {
        printf("\n 1. Get details from user\n");
        printf(" 2. Print scanned data on screen\n");
        printf(" 3. Write scanned data into file\n");
        printf(" 4. Read data from file & print\n");
        printf(" 5. Search details by student's name\n");
        printf(" 6. Search details by Date of Birth\n");
        printf(" 7. Search details by Date of joining\n");
        printf(" 8. Search details by marks range\n");
        printf(" 9. Search details by Assessment Status\n");
        printf("10. Search details by Batch Id\n");
        printf("11. If data is written wrong, edit with right data\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch(choice)
        {
            case 1: /* scan student's data from user */
                    GetStdDetailInfo(ptr);
            break;
            case 2: /* print the data scanned from user on screen */
                    PrintStdDetailInfo(ptr);
            break;
            case 3: /* write the data into file of perticular file */
                    WriteStdDetailInfo(ptr);
            break;
            case 4: /* print all data contained in file onto screen */
                    printf("Enter the Batch Id, you want to read from: ");
                    scanf(" %s", batchid);
                    ReadStdInfoFromFile( ptr, batchid );
            break;
            case 5: /* search the details by name of student */
                    printf("Enter the name of student: ");
                    scanf(" %[^\n]", std_name);
                    SearchStdDetailsByName( std_name );
            break;
            case 6: /* search the details using the date of birth */
                    printf("Enter the date of birth(dd:mm:yyyy): ");
                    scanf("%d%d%d",&dd,&mm,&yyyy);
                    SearchStdDetailsByDoB(dd,mm,yyyy);
            break;
            case 7: /* search the details using the date of joining */
                    printf("Enter the date of joining(dd:mm:yyyy): ");
                    scanf("%d%d%d",&dd,&mm,&yyyy);
                    SearchStdDetailsByDoJ(dd,mm,yyyy);
            break;
            case 8: /* search the students list by range of marks */
                    printf("Enter the min_range of avg_marks: ");
                    scanf("%f", &min_range);
                    printf("Enter the max_range of avg_marks: ");
                    scanf("%f", &max_range);
                    SearchStdDetailsByRangeOfMarks( min_range, max_range );
            break;
            case 9: /* search the student info by assessment status */
                    printf("Enter the assessment status of students want to search: ");
                    scanf(" %[^\n]", Asmnt_Sts );
                    SearchStdDetailsByAssessmentSts(Asmnt_Sts);
            break;
            case 10: /* search the student details by batch id */
                    printf("Enter the student's Batch Id: ");
                    scanf(" %s", batchid);
                    SearchStdDetailsByStdBatchId( batchid );
            break;
            case 11: /* If wrong data is written in file, then edit with right data & rewrite in file */
                    EditFileDataWithCorrectInfo();
            break;
        }

    } while( choice != 0 );
    printf("Thank You..!\n");
    return 0;
}
