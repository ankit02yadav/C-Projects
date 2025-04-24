#include <stdio.h>
#include <string.h>

int hangman() {
    char word[] = "ankit";
    char guess[20];
    char guessed[20] = {0};
    int attempts = 6;
    int correct;

    while (attempts > 0) {
        correct = 1;
        printf("Word: ");
        for (int i = 0; i < strlen(word); i++) {
            if (guessed[word[i] - 'a']) {
                printf("%c ", word[i]);
            } else {
                printf("_ ");
                correct = 0;
            }
        }
        printf("\nAttempts left: %d\n", attempts);
        
        if (correct) {
            printf("You win! The word was '%s'.\n", word);
            return 0;
        }

        printf("Guess a letter: ");
        scanf(" %c", &guess[0]);
        guessed[guess[0] - 'a'] = 1;

        if (strchr(word, guess[0]) == NULL) {
            attempts--;
        }
    }

    printf("You lose! The word was '%s'.\n", word);
    return 0;
}
