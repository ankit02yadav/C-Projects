#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100
const char *action = "movie recommand/action.txt";
const char *comedy = "movie recommand/comedy.txt";
const char *drama = "movie recommand/drama.txt";
const char *scifi = "movie recommand/scifi.txt";
const char *horror = "movie recommand/horror.txt";


int check_movie_file(const char *check_filename){
    FILE *file = fopen(check_filename,"r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else{
        file = fopen(check_filename,"w");
        fclose(file);
        return 1;
    }
    return 0;
    
}
int find_movie(const char *filename)
{
    check_movie_file(filename);
    FILE *file = fopen(filename, "r");

    printf("\033[0;31m"); // red
    printf("##########################\n");

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s \n",line);

        fclose(file);
        printf("##########################\n");
        printf("\033[0;37m"); // default //WHITE
        return 1;
    }

    printf("##########################\n");
    printf("\033[0;37m"); // default //WHITE
    fclose(file);
    return 0;
}
int main_movies()
{
    int choice;
    while (1)
    {
        printf("##################### Movie Recommadation System #####################\n");
        printf("Please Choose a Genre\n");
        printf("1. Action\n");
        printf("2. Comedy\n");
        printf("3. Drama\n");
        printf("4. Horror\n");
        printf("5. Sci-Fi\n");
        printf("6. Exit\n");
        printf("Enter Your Choice :");
        if (scanf("%d", &choice) == 1)
        {
            if (choice == 1)
            {
                find_movie(action);
            }
            else if (choice == 2)
            {
                find_movie(comedy);
            }
            else if (choice == 3)
            {
                find_movie(drama);
            }
            else if (choice == 4)
            {
                find_movie(horror);
            }
            else if (choice == 5)
            {
                find_movie(scifi);
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
