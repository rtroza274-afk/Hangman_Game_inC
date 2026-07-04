# Hangman Game (C)

A classic Hangman game built in C, featuring category-based word lists, 
ASCII art, a one-time hint system, and score tracking.

## Features

-  Multiple word categories loaded from a text file
-  ASCII art banner and hangman drawings
-  One-time hint per game
-  Score tracking based on remaining attempts
-  Clean multi-file structure (separate header, source, and data files)

## Project Structure
```
Hangman-Game-C/
|-- data/
|   |-- words.txt
|-- hangman.c
|-- hangman.h
|-- main.c
|-- README.md
|-- requirements.txt
```



## How to Play

1. Compile the program.
2. Run it.
3. Choose a category, then guess letters one at a time.
4. Type `?` at any point to use your one-time hint.
5. Guess the word before you run out of attempts!

## Requirements

- A C compiler (e.g., GCC)
- Terminal with UTF-8 support (for ASCII art to render correctly)

## Author

CyRTon_