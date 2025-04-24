#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int no() {
    int number, guess;
    srand(time(0));
    number = rand() % 100 + 1;

    printf("Guess the number (1-100): ");
    do {
        scanf("%d", &guess);
        if (guess > number) {
            printf("Too high! \nTry again: ");
        } else if (guess < number) {
            printf("Too low! \nTry again: ");
        } else {
            printf("Correct! The number was %d.\n", number);
        }
    } while (guess != number);

    return 0;
}
