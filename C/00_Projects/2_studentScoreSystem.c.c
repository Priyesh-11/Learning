#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define NUM_SUBJECTS 3
#define FILENAME "students.dat"

typedef struct
{
    int id;
    char name[MAX_NAME_LEN];
    float scores[NUM_SUBJECTS];
    float total;
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void displayMenu()
{
    printf("\nStudent Score Management System\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student Scores\n");
    printf("5. Delete Student\n");
    printf("6. Sort Students by Average\n");
    printf("7. Show Class Statistics\n");
    printf("8. Save to File\n");
    printf("9. Load from File\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void calculateStudentStats(Student *student)
{
    student->total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        student->total += student->scores[i];
    }
    student->average = student->total / NUM_SUBJECTS;
}

int findStudentById(int id)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void addStudent()
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached!\n");
        return;
    }

    Student newStudent;

    printf("\nEnter Student ID: ");
    scanf("%d", &newStudent.id);
    clearInputBuffer();

    if (findStudentById(newStudent.id) != -1)
    {
        printf("Student ID already exists!\n");
        return;
    }

    printf("Enter Student Name: ");
    fgets(newStudent.name, MAX_NAME_LEN, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter scores for %d subjects:\n", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        do
        {
            printf("Subject %d: ", i + 1);
            scanf("%f", &newStudent.scores[i]);
            if (newStudent.scores[i] < 0 || newStudent.scores[i] > 100)
            {
                printf("Invalid score! Enter between 0-100.\n");
            }
        } while (newStudent.scores[i] < 0 || newStudent.scores[i] > 100);
    }

    calculateStudentStats(&newStudent);
    students[studentCount++] = newStudent;
    printf("Student added successfully!\n");
}

void displayStudents()
{
    if (studentCount == 0)
    {
        printf("No students to display!\n");
        return;
    }

    printf("\n%-10s %-20s %-15s %-15s\n", "ID", "Name", "Total Score", "Average");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("%-10d %-20s %-15.2f %-15.2f\n",
               students[i].id,
               students[i].name,
               students[i].total,
               students[i].average);
    }
}

void searchStudent()
{
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(id);
    if (index == -1)
    {
        printf("Student not found!\n");
        return;
    }

    printf("\nStudent Found:\n");
    printf("ID: %d\n", students[index].id);
    printf("Name: %s\n", students[index].name);
    printf("Scores: ");
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        printf("Subject %d: %.2f ", i + 1, students[index].scores[i]);
    }
    printf("\nTotal: %.2f\n", students[index].total);
    printf("Average: %.2f\n", students[index].average);
}

void updateStudent()
{
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(id);
    if (index == -1)
    {
        printf("Student not found!\n");
        return;
    }

    printf("Enter new scores for %d subjects:\n", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        do
        {
            printf("Subject %d: ", i + 1);
            scanf("%f", &students[index].scores[i]);
            if (students[index].scores[i] < 0 || students[index].scores[i] > 100)
            {
                printf("Invalid score! Enter between 0-100.\n");
            }
        } while (students[index].scores[i] < 0 || students[index].scores[i] > 100);
    }

    calculateStudentStats(&students[index]);
    printf("Scores updated successfully!\n");
}

void deleteStudent()
{
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(id);
    if (index == -1)
    {
        printf("Student not found!\n");
        return;
    }

    for (int i = index; i < studentCount - 1; i++)
    {
        students[i] = students[i + 1];
    }
    studentCount--;
    printf("Student deleted successfully!\n");
}

int compareStudents(const void *a, const void *b)
{
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return (studentB->average * 100) - (studentA->average * 100);
}

void sortStudents()
{
    qsort(students, studentCount, sizeof(Student), compareStudents);
    printf("Students sorted by average score!\n");
    displayStudents();
}

void showStatistics()
{
    if (studentCount == 0)
    {
        printf("No students for statistics!\n");
        return;
    }

    float classTotal = 0;
    float maxAverage = students[0].average;
    float minAverage = students[0].average;

    for (int i = 0; i < studentCount; i++)
    {
        classTotal += students[i].average;
        if (students[i].average > maxAverage)
            maxAverage = students[i].average;
        if (students[i].average < minAverage)
            minAverage = students[i].average;
    }

    printf("\nClass Statistics:\n");
    printf("Total Students: %d\n", studentCount);
    printf("Highest Average: %.2f\n", maxAverage);
    printf("Lowest Average: %.2f\n", minAverage);
    printf("Class Average: %.2f\n", classTotal / studentCount);
}

void saveToFile()
{
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        printf("Error saving file!\n");
        return;
    }

    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data saved to file successfully!\n");
}

void loadFromFile()
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("No saved data found!\n");
        return;
    }

    fread(&studentCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data loaded from file successfully!\n");
}

int main()
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            sortStudents();
            break;
        case 7:
            showStatistics();
            break;
        case 8:
            saveToFile();
            break;
        case 9:
            loadFromFile();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}