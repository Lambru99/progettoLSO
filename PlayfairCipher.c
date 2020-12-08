//
// Created by Paolo on 15/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "PlayfairCipher.h"
#include "FileReader.h"

const int row = 5;
const int col = 5;

//char **initMatrix() {
//    char **matrix = (char **) malloc(5 * sizeof(char *));
//    for (int i = 0; i < 5; i++) {
//        matrix[i] = (char *) malloc(5 * sizeof(char));
//    }
//    return matrix;
//}

//void fillMatrix(char **matrix, Key key) {
//    char *letters = (char *) malloc(sizeof(char) * strlen(key.alphabet));
//    int lettersIndex = 0;
//    int keyCharIndex = 0;
//    int alphabetCharIndex = 0;
//
//    for (int row = 0; row < 5; row++) {
//        for (int col = 0; col < 5; col++) {
//            if (keyCharIndex < strlen(key.key)) {
//                if (key.key[keyCharIndex] != ' ' && strchr(letters, key.key[keyCharIndex]) == NULL) {
//                    letters[lettersIndex] = key.key[keyCharIndex];
//                    lettersIndex++;
//                    matrix[row][col] = key.key[keyCharIndex];
//                    keyCharIndex++;
//                } else {
//                    keyCharIndex++;
//                    col--;
//                }
//            } else {
//                if (strchr(letters, key.alphabet[alphabetCharIndex]) == NULL) {
//                    letters[lettersIndex] = key.alphabet[alphabetCharIndex];
//                    lettersIndex++;
//                    matrix[row][col] = key.alphabet[alphabetCharIndex];
//                    alphabetCharIndex++;
//                } else {
//                    alphabetCharIndex++;
//                    col--;
//                }
//            }
//        }
//    }
//    free(letters);
//}

void fillMatrix(char matrix[row][col], Key key) {
    char letters[25] = {0};
    int lettersIndex = 0;
    int keyCharIndex = 0;
    int alphabetCharIndex = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (key.key[keyCharIndex] != '\0') {
                if (key.key[keyCharIndex] != ' ' && strchr(letters, key.key[keyCharIndex]) == NULL) {
                    letters[lettersIndex] = key.key[keyCharIndex];
                    lettersIndex++;
                    matrix[i][j] = key.key[keyCharIndex];
                    keyCharIndex++;
                } else {
                    keyCharIndex++;
                    j--;
                }
            } else if (key.alphabet[alphabetCharIndex] != '\0') {
                if (strchr(letters, key.alphabet[alphabetCharIndex]) == NULL) {
                    letters[lettersIndex] = key.alphabet[alphabetCharIndex];
                    lettersIndex++;
                    matrix[i][j] = key.alphabet[alphabetCharIndex];
                    alphabetCharIndex++;
                } else {
                    alphabetCharIndex++;
                    j--;
                }
            }
        }
    }
}

char *cleanMessage(char *message) {
    char *cleanedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    int currentIndex = 0;

    for (int i = 0; i < strlen(message); i++) {
        if (isspace(message[i]) == 0 && isalpha(message[i]) != 0) {
            if (islower(message[i]) == 0) {
                cleanedMessage[currentIndex] = (char) tolower(message[i]);
                currentIndex++;
            } else {
                cleanedMessage[currentIndex] = message[i];
                currentIndex++;
            }
        }
    }

    cleanedMessage = realloc(cleanedMessage, sizeof(char) * currentIndex);

    cleanedMessage[currentIndex] = '\0';

    return cleanedMessage;
}

void encode(Key key, char *file) {
    char matrix[row][col];
    char *message = loadMessage(file);
    char *cleanedMessage = cleanMessage(message);

    fillMatrix(matrix, key);

    printf("Alfabeto: %s.\nCarattere mancante: %c.\nCarattere speciale: %c.\nChiave: %s.\n", key.alphabet,
           key.missingChar,
           key.specialChar, key.key);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("%s\n", message);
    printf("%s", cleanedMessage);

    free(message);
}