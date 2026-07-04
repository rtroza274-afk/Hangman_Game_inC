#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hangman.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main(void) {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    printBanner();

    Category categories[10];
    int categoryCount = 0;
    loadCategories(categories, &categoryCount);

    // Show available categories
    printf("Choose a category:\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%d. %s\n", i + 1, categories[i].name);
    }

    int choice;
    printf("Enter choice (number): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > categoryCount) {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    GameState game;
    game.hintUsed = 0;
    chooseWord(&categories[choice - 1], &game);

    // ----- Main game loop -----
    while (game.attemptsLeft > 0 && !isWordGuessed(&game)) {
        displayHangman(game.attemptsLeft);
        displayWord(&game);
        printf("Attempts left: %d\n", game.attemptsLeft);

        printf("Enter a letter to guess, or '?' for a hint: ");
        char input[10];
        scanf("%s", input);

        char letter = input[0];

        if (letter == '?') {
            if (game.hintUsed == 0) {
                showHint(&game);
                game.hintUsed = 1;
            } else {
                printf("You've already used your hint!\n");
            }
        } else {
            int found = guessLetter(&game, letter);
            if (!found) {
                printf("Wrong guess!\n");
            }
        }

        printf("\n");
    }

    // ----- Game over -----
    if (isWordGuessed(&game)) {
        printf("Congratulations! You guessed the word: %s\n", game.word);
        updateScore(&game, 1);
    } else {
        displayHangman(0);
        printf("Game over! The word was: %s\n", game.word);
        updateScore(&game, 0);
    }

    printf("Final score: %d\n", game.score);

    return 0;
}