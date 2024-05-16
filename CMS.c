// Project Description
// Class Management System
// - Add student
//   - student no./ID
//   - student name
//   - grades
// - Display student record
//   - grade for each subject
//   - GWA
// - Search
//   - displays the student record
//
// Data stored to a text file (CSV)

// A CSV (Comma-Separated Values) file is a simple text-based
// file format used to store tabular data. In a CSV file, each
// line represents a row of data, with fields separated by
// commas (or other delimiters like semicolons or tabs). - ChatGPT

#include <stdio.h>

// To be able to use `bool` type
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

#define TEXT_MAX_NUM 50
#define ID_NUM 15
#define MAX_RECORDS 100  // maximum number of records to store
#define MAX_FIELD_LENGTH 50 // Maximum length of each field in the CSV file

typedef struct
{
    char lastName[TEXT_MAX_NUM];
    char firstName[TEXT_MAX_NUM];
    char studentID[ID_NUM];
    double math101;
    double cmpsc113;
    double comm01;
    double math01;
    double nstp02;
    double math16;
    double cmpsc112;
    double pathfit2;
    double GWA;
} Student;

void printStudentRecords(int recordsNum, Student students[100]);

int main(void)
{
    // The program has 4 phases.
    // Phase 3 has 3 parts.
    // So, all in all, there are 6 parts.

    // Global Variables
    const char *dataFilePath = "CMS_Data.csv";
    int recordsNum = 0;  // counter for the number of records read

    // Tracks if there are students added during the execution of the program
    // To be used in part 4:
    // Part 4 should only run (stores the data back to the .csv) file
    // if there are changes (students added)
    bool isThereAdded = false;   

    // Variable of the index of the student to be added; to be incremented
    int index = -1; 

    // [1] Creates the data file if it does not exist
    //

    // [2] Reads all students data from the data file
    //  - Stores the data to an array.
    //  - Tutorial: https://www.youtube.com/watch?v=rbVt5v8NNe8
    //  - Should increment `recordsNum` by one for every record read
    //
    
    Student students[MAX_RECORDS];

    FILE *file;
    char line[MAX_FIELD_LENGTH * 2]; // buffer to read each line from the file

    // open the file for reading
    file = fopen(dataFilePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", dataFilePath);
        return 1;
    }

    // read data from the file line by line
    while (fgets(line, sizeof(line), file) != NULL && recordsNum < MAX_RECORDS) {
        // tokenize the line based on comma separator
        char *token = strtok(line, ",");
        if (token == NULL) continue;

        // copy the last name field to the student structure
        strncpy(students[recordsNum].lastName, token, sizeof(students[recordsNum].lastName) - 1);
        students[recordsNum].lastName[sizeof(students[recordsNum].lastName) - 1] = '\0'; // ensure null-termination

        // copy the first name field
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(students[recordsNum].firstName, token, sizeof(students[recordsNum].firstName) - 1);
        students[recordsNum].firstName[sizeof(students[recordsNum].firstName) - 1] = '\0'; // ensure null-termination

        // copy the student ID field
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(students[recordsNum].studentID, token, sizeof(students[recordsNum].studentID) - 1);
        students[recordsNum].studentID[sizeof(students[recordsNum].studentID) - 1] = '\0'; // ensure null-termination

        // parse the remaining double fields
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].math101 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].math01 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].math16 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].comm01 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].pathfit2 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].nstp02 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].cmpsc113 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].cmpsc112 = atof(token);
        
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[recordsNum].GWA = atof(token);

        // increment the record number if all fields are successfully parsed
        recordsNum++;
        index++;
    }
 
    // close file
    fclose(file);

    // print number of records read
    printf("Number of records read: %d\n", recordsNum);

    // [Phase 3] Displays student records and options
    //  - Use a loop for this part so that the program
    //    continues until exited by the user.
    //  - 4 options:
    //    [1] Add Student
    //    [2] Display student record
    //    [3] Search
    //    [4] Exit
    printStudentRecords(recordsNum, students);
    
    // Initialize option value
    int option = 1;
    while (option >= 1 && option <= 3)
    {
        // Print options
        printf("Select Option:\n");
        printf("[1] Add Student\n[2] Display student record\n[3] Search\n[4] Exit\n\n> ");
        scanf("%d", &option);
        if (option == 1)
        {
            // [3.A] Add Student Option
            //  - Input student data and grades
            //    - Last name, first name, ID
            //    - MATH101, CMPSC113, COMM01, MATH01, NSTP02, MATH16, PATHFIT2 grades
            //  - Computes the GWA
            //  - Stores all of these to the student struct in the array

            double sum = 0;
            index++;
            printf("Last name of student: ");
            scanf(" %[^\n]s", students[index].lastName);
            printf("First name of student: ");
            scanf(" %[^\n]s", students[index].firstName);
            printf("ID of student: ");
            scanf(" %[^\n]s", students[index].studentID);

            printf("Grade for MATH101: ");
            scanf("%lf", &students[index].math101);
            printf("Grade for MATH01: ");
            scanf("%lf", &students[index].math01);
            printf("Grade for MATH16: ");
            scanf("%lf", &students[index].math16);
            printf("Grade for COMM01: ");
            scanf("%lf", &students[index].comm01);
            printf("Grade for PATHFIT2: ");
            scanf("%lf", &students[index].pathfit2);
            printf("Grade for NSTP02: ");
            scanf("%lf", &students[index].nstp02);
            printf("Grade for CMPSC113: ");
            scanf("%lf", &students[index].cmpsc113);
            printf("Grade for CMPSC112: ");
            scanf("%lf", &students[index].cmpsc112);

            sum = students[index].math101 + students[index].math01 + students[index].math16 + students[index].comm01 + students[index].pathfit2 + students[index].nstp02 + students[index].cmpsc113 + students[index].cmpsc112;

            students[index].GWA = sum / 8;

            recordsNum++;

            isThereAdded = true;

            printf("\n");
            printStudentRecords(recordsNum, students);
        }
        else if (option == 2)
        {
            // [3.B] Display student record
            //  - Make the user select one student
            //  - and then displays the data and grades of the student
        }
        else if (option == 3)
        {
            // [3.C] Search
            //  - Let the user search for students
            //    based on the keyword/s inputted
            //  - If the search matches multiple students,
            //    ask again which specific student whose
            //    data and grades will be shown
            //  - Displays the data and grades of the selected student
        }
    }

    // [4] Stores data to the data back to the data file
    //  - Tutorial: https://www.youtube.com/watch?v=7ZFgphYJvUA
}

void printStudentRecords(int recordsNum, Student students[100])
{
    // Debug
    printf("%d record/s.\n", recordsNum);

    // Headers for the grades
    printf("MATH101 | MATH01 | MATH16 | COMM01 | PATHFIT2 | NSTP02 | CMPSC113 | CMPSC112 | GWA\n\n");

    for (int i = 0; i < recordsNum; i++)
    {
        printf("[%d] %s, %s (%s)\n", i + 1, students[i].lastName, students[i].firstName, students[i].studentID);
        printf("%7.2lf | %6.2lf | %6.2lf | %6.2lf | %8.2lf | %6.2lf | %8.2lf | %8.2lf | %3.2lf\n\n",
               students[i].math101,
               students[i].math01,
               students[i].math16,
               students[i].comm01,
               students[i].pathfit2,
               students[i].nstp02,
               students[i].cmpsc113,
               students[i].cmpsc112,
               students[i].GWA);
    }
}
