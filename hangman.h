#ifndef HANGMAN_H
#define HANGMAN_H

// ----- Constants -----
#define MAX_WORD_LENGTH 50
#define MAX_ATTEMPTS 6
#define MAX_WORDS_PER_CATEGORY 20

// ----- Structs -----
typedef struct {
    char name[30];
    char words[MAX_WORDS_PER_CATEGORY][MAX_WORD_LENGTH];
    char hints[MAX_WORDS_PER_CATEGORY][MAX_WORD_LENGTH];
    int wordCount;
} Category;

typedef struct {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int attemptsLeft;
    int score;
    int hintUsed;   // 0 = not used yet, 1 = already used
} GameState;

// ----- Function Prototypes -----

// Setup and word selection
void loadCategories(Category categories[], int *categoryCount);
void chooseWord(Category *category, GameState *game);

// Core gameplay
void displayHangman(int attemptsLeft);
void displayWord(GameState *game);
int guessLetter(GameState *game, char letter);
int isWordGuessed(GameState *game);

// Hints and scoring
void showHint(GameState *game);
void updateScore(GameState *game, int won);

// Utility
void toLowerCase(char *str);
//Display
void printBanner(void);
#endif