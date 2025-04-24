#include <stdio.h>
#include <stdlib.h>

#include "number_gess.c"
#include "hangman.c"
#include "rock paper scissor.c"

void playNumberGuessing(){
    no();
};
void playHangman(){
    hangman();
};
void playRockPaperScissors(){
    rps();
};

int main_game() {
    int choice;

    do {
        printf("###### Game Menu ###### \n");
        printf("1. Number Guessing Game\n");
        printf("2. Hangman \n");
        printf("3. Rock Paper Scissors \n");
        printf("4. Exit \n");
        printf("####################### \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playNumberGuessing();
                break;
            case 2:
                playHangman();
                break;
            case 3:
                playRockPaperScissors();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
