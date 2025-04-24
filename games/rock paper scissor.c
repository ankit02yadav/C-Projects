#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rps() {
    char *choices[] = {"Rock", "Paper", "Scissors"};
    int playerChoice, computerChoice;
    
    srand(time(0));

    printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors: ");
    scanf("%d", &playerChoice);

    computerChoice = rand() % 3;

    printf("You chose: %s\n", choices[playerChoice]);
    printf("Computer chose: %s\n", choices[computerChoice]);

    if (playerChoice == computerChoice) {
        printf("It's a draw!\n");
    } else if ((playerChoice == 0 && computerChoice == 2) || 
               (playerChoice == 1 && computerChoice == 0) || 
               (playerChoice == 2 && computerChoice == 1)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}
