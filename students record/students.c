#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int roll_no_input;
#define MAX_LINE 100
#define NAME_LEN 30

const char *main_student = "students record/students.csv";

typedef struct
{
    char name[NAME_LEN];
    int roll;
    char grade;
    int age;

} Students;

int check_rollno_repet(int roll_no_input)
{
    FILE *file = fopen(main_student, "r");

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file))
    {
        int check_roll_no;
        sscanf(line, "%*[^,],%d", &check_roll_no); // %*[^,] ==skip this value // %d==roll no. //than left

        if (check_roll_no == roll_no_input)
        {
            fclose(file);
            printf("Roll number already exists!\n");
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int print_detils_of_rollno(int rollno_input)
{
    FILE *file = fopen(main_student, "r");

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file))
    {
        int check_roll_no;
        int check_age;
        char check_name[NAME_LEN];
        char check_grade;
        sscanf(line, "%[^,],%d,%c,%d", check_name, &check_roll_no, &check_grade, &check_age);

        if (check_roll_no == rollno_input)
        {
            fclose(file);
            printf("\033[0;31m"); // red
            printf("##########################\n");
            printf("Roll number found!\n");
            printf("NAME    : %s\n", check_name);
            printf("ROLL NO.: %d\n", check_roll_no);
            printf("GRADE   : %c\n", check_grade);
            printf("AGE     : %d\n", check_age);
            printf("##########################\n");
            printf("\033[0;37m"); // default //WHITE
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int check_student_file()
{
    FILE *file = fopen(main_student, "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        file = fopen(main_student, "w");
    }
}

int add_student()
{
    int choice;
    check_student_file();
    FILE *main_file = fopen(main_student, "a");

    Students student;
    printf("Enter name of Student : ");
    scanf("%s", student.name);
    printf("Enter roll no. of Student : ");
    scanf("%d", &student.roll);
    if (check_rollno_repet(student.roll))
    {
        fclose(main_file);
        return 0;
    }

    printf("Enter Grade of Student : ");
    while (getchar() != '\n')
        ;
    scanf("%c", &student.grade);
    printf("Enter age of Student : ");
    scanf("%d", &student.age);

    fprintf(main_file, "%s,%d,%c,%d\n", student.name, student.roll, student.grade, student.age);

    fclose(main_file);
    printf("Student Added successfully!\n");
    printf("Wanna add more students press 1 and 0 to exit: ");
    if (scanf("%d", &choice) == 1)
    {
        if (choice == 1)
        {
            add_student();
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Invalid choice ! \n");
    }

    return 0;
}

int view_students()
{
    check_file();
    FILE *file = fopen(main_student, "r");

    char line[MAX_LINE];
    printf("\033[0;31m"); // red
    printf("#############################################################\n");
    printf("Name,roll no.,grade,age\n");
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    fclose(file);
    printf("#############################################################\n");
    printf("\033[0;37m"); // default //WHITE
    return 0;
}

int update_record(int update_roll_no)
{
    FILE *file = fopen(main_student, "r");
    FILE *temp_file = fopen("students record/temp_file.csv", "w");

    char line[MAX_LINE];
    int found = 0;

    while (fgets(line, sizeof(line), file))
    {
        int check_roll_no;
        int check_age;
        char check_name[NAME_LEN];
        char check_grade;
        sscanf(line, "%[^,],%d,%c,%d", check_name, &check_roll_no, &check_grade, &check_age);

        if (check_roll_no == update_roll_no)
        {
            found = 1;
            Students student;
            printf("Enter Update Details\n");
            printf("Enter name of Student : ");
            scanf("%s", student.name);
            student.roll = check_roll_no; 
            printf("Enter Grade of Student : ");
            while (getchar() != '\n');
            scanf("%c", &student.grade);
            printf("Enter age of Student : ");
            scanf("%d", &student.age);

            fprintf(temp_file, "%s,%d,%c,%d\n", student.name, student.roll, student.grade, student.age);
        }
        else
        {
            fprintf(temp_file, "%s,%d,%c,%d\n", check_name, check_roll_no, check_grade, check_age);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found)
    {
        remove(main_student);
        rename("students record/temp_file.csv", main_student);
        printf("Record updated successfully.\n");
    }
    else
    {
        printf("Roll number not found.\n");
        remove("students record/temp_file.csv");
    }

    return 0;
}

int delete_record(int delete_roll_no)
{
    FILE *file = fopen(main_student, "r");
    FILE *temp_file = fopen("students record/temp_file.csv", "w");

    char line[MAX_LINE];
    int found = 0;

    while (fgets(line, sizeof(line), file))
    {
        int check_roll_no;
        int check_age;
        char check_name[NAME_LEN];
        char check_grade;
        sscanf(line, "%[^,],%d,%c,%d", check_name, &check_roll_no, &check_grade, &check_age);

        if (check_roll_no == delete_roll_no)
        {
            found = 1;
        }
        else
        {
            fprintf(temp_file, "%s,%d,%c,%d\n", check_name, check_roll_no, check_grade, check_age);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found)
    {
        remove(main_student);
        rename("students record/temp_file.csv", main_student);
        printf("Record updated successfully.\n");
    }
    else
    {
        printf("Roll number not found.\n");
        remove("students record/temp_file.csv");
    }

    return 0;
}

int main_students()
{
    int choice;
    int rolll;
    int upd_roll;
    int del_roll;
    while (1)
    {
        printf("################# STUDENT RECORD SYSTEM #####################\n");
        printf("1. Add New Student\n");            // done
        printf("2. View All Student\n");           // done
        printf("3. Search Student By Roll no.\n"); // done
        printf("4. Edit Student Record\n");        // done
        printf("5. Delete Student Record\n");      //
        printf("6. Exit\n");                       // done
        printf("Enter Your Choice :");
        if (scanf("%d", &choice) == 1)
        {
            if (choice == 1)
            {
                printf("#################### ADD STUDENTS ##########################\n");
                add_student();
            }
            else if (choice == 2)
            {
                printf("################## VIEW ALL STUDENTS ########################\n");
                view_students();
            }
            else if (choice == 3)
            {
                printf("################## VIEW ROLL STUDENTS ########################\n");
                printf("Enter Roll No. :");
                if (scanf("%d", &rolll) == 1)
                {
                    print_detils_of_rollno(rolll);
                }
                else
                {
                    printf("Invalid choice ");
                }
            }
            else if (choice == 4)
            {
                printf("#####################################\n");
                printf("Enter Roll No. To Update Record :");
                if (scanf("%d", &upd_roll) == 1)
                {
                    update_record(upd_roll);
                }
                else
                {
                    printf("Invalid choice ");
                }
            }
            else if (choice == 5)
            {
                printf("#####################################\n");
                printf("Enter Roll No. To Delete Record :");
                if (scanf("%d", &del_roll) == 1)
                {
                    delete_record(del_roll);
                }
                else
                {
                    printf("Invalid choice ");
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("Invalid input. Please enter a valid integer \n");
            getchar();
        }
    }
}

