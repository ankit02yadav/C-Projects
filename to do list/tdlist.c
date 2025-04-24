#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int choice;
#define MAX_LINE 100
#define MAX_TASK_NAME 300
typedef struct{

    char detail[MAX_TASK_NAME];

} Task;

int check_file() {
    FILE *file = fopen("to do list/to_do_list.txt", "r");
    if (file) {
        fclose(file);
        return 1;
    } else {
        file = fopen("to do list/to_do_list.txt", "w");
        if (file) {
            fclose(file);
            return 1;
        } else {
            return 0;
        }
    }
}
int add_task(){
    check_file();
    int task_count = 0;
    printf("How many tasks do you want to add: ");
    scanf("%d", &task_count);
    getchar();

    FILE *file = fopen("to do list/to_do_list.txt", "a");

    for (int i = 0; i < task_count; i++) {
        Task task;
        printf("Enter name of item %d: ", i + 1);
        fgets(task.detail, sizeof(task.detail), stdin);

        task.detail[strcspn(task.detail, "\n")] = 0;
        fprintf(file, "%s\n", task.detail);
    }

    fclose(file);
    printf("Tasks added successfully!\n");
    return 0;
}
int view_task(){
    FILE *file = fopen("to do list/to_do_list.txt", "r");

    char line[MAX_LINE];
    printf("###################################################################### \n");
    while (fgets(line, sizeof(line), file))
    {
        printf("= > %s", line);
    }
    fclose(file);
    printf("###################################################################### \n");
    return 0;
}
int main_tdlist() {
    while (1)
    {
        printf("#########################################################\n");
        printf("1. Add Task \n");
        printf("2. View Task \n");
        printf("3. Exit \n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        if(choice==1){
            add_task();
        }
        else if(choice==2){
            view_task();
        }
        else{
            break;
        }
    }
    return 0;
}