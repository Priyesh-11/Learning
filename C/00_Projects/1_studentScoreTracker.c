#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define FILE_NAME "students.dat"

typedef struct
{
    int id;
    char name[NAME_LEN];
    float score;
} Student;

// Functions
void addStudent(Student **list, int *count);
void displayStudents(Student *list, int count);
int findStudentIndex(Student *list, int count, int id);
void searchStudent(Student *list, int count);
void updateStudentScore(Student *list, int count);
void deleteStudent(Student **list, int *count);
void sortByScore(Student *list, int count);
void saveToFile(Student *list, int count);
void loadFromFile(Student **list, int *count);
void clearInputBuffer();

int main()
{
    Student *students = NULL;
    int count = 0;
    int choice;

    loadFromFile(&students, &count);

    do
    {
        printf("\n=== Student Score Manager ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Score\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by Score\n");
        printf("7. Save to File\n");
        printf("8. Load from File\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addStudent(&students, &count);
            break;
        case 2:
            displayStudents(students, count);
            break;
        case 3:
            searchStudent(students, count);
            break;
        case 4:
            updateStudentScore(students, count);
            break;
        case 5:
            deleteStudent(&students, &count);
            break;
        case 6:
            sortByScore(students, count);
            break;
        case 7:
            saveToFile(students, count);
            break;
        case 8:
            loadFromFile(&students, &count);
            break;
        case 9:
            saveToFile(students, count);
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (choice != 9);

    free(students);
    return 0;
}

void addStudent(Student **list, int *count)
{
    *list = realloc(*list, (*count + 1) * sizeof(Student));
    if (!*list)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    Student *s = &(*list)[*count];
    printf("Enter student ID: ");
    scanf("%d", &s->id);
    clearInputBuffer();
    printf("Enter student name: ");
    fgets(s->name, NAME_LEN, stdin);
    s->name[strcspn(s->name, "\n")] = '\0';
    printf("Enter student score: ");
    scanf("%f", &s->score);
    clearInputBuffer();

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(Student *list, int count)
{
    if (count == 0)
    {
        printf("No students to display.\n");
        return;
    }
    printf("\nID\tName\t	Score\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%-15s\t%.2f\n", list[i].id, list[i].name, list[i].score);
    }
}

int findStudentIndex(Student *list, int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (list[i].id == id)
            return i;
    }
    return -1;
}

void searchStudent(Student *list, int count)
{
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int idx = findStudentIndex(list, count, id);
    if (idx >= 0)
    {
        printf("Found: ID=%d, Name=%s, Score=%.2f\n", list[idx].id, list[idx].name, list[idx].score);
    }
    else
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateStudentScore(Student *list, int count)
{
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int idx = findStudentIndex(list, count, id);
    if (idx >= 0)
    {
        printf("Current score for %s: %.2f\n", list[idx].name, list[idx].score);
        printf("Enter new score: ");
        scanf("%f", &list[idx].score);
        clearInputBuffer();
        printf("Score updated!\n");
    }
    else
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent(Student **list, int *count)
{
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int idx = findStudentIndex(*list, *count, id);
    if (idx >= 0)
    {
        for (int i = idx; i < *count - 1; i++)
        {
            (*list)[i] = (*list)[i + 1];
        }
        *list = realloc(*list, (*count - 1) * sizeof(Student));
        (*count)--;
        printf("Student deleted.\n");
    }
    else
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void sortByScore(Student *list, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (list[j].score < list[j + 1].score)
            {
                Student temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by score (descending).\n");
}

void saveToFile(Student *list, int count)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp)
    {
        perror("Failed to open file");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(list, sizeof(Student), count, fp);
    fclose(fp);
    printf("Data saved to %s.\n", FILE_NAME);
}

void loadFromFile(Student **list, int *count)
{
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp)
    {
        printf("No existing data file found. Starting fresh.\n");
        return;
    }
    fread(count, sizeof(int), 1, fp);
    *list = malloc((*count) * sizeof(Student));
    fread(*list, sizeof(Student), *count, fp);
    fclose(fp);
    printf("Loaded %d students from %s.\n", *count, FILE_NAME);
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
