//
// Created by Paolo on 15/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "PlayfairCipher.h"

//const int row = 5;
//const int col = 5;

void fillMatrix(char matrix[ROW][COL], Key key) {
    char letters[25] = {0};
    char *currentAlphabetChar = key.alphabet;
    int lettersIndex = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (*key.key != '\0') {
                if (*key.key != ' ' && strchr(letters, *key.key) == NULL)
                    matrix[i][j] = letters[lettersIndex++] = *key.key++;
                else {
                    key.key++;
                    j--;
                }
            } else if (*currentAlphabetChar != '\0') {
                if (strchr(letters, *currentAlphabetChar) == NULL)
                    matrix[i][j] = letters[lettersIndex++] = *currentAlphabetChar++;
                else {
                    currentAlphabetChar++;
                    j--;
                }
            }
        }
    }
}

char *cleanMessage(char *message) {
    char *cleanedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    int currentIndex = 0;

    while (*message != '\0') {
        if (isspace(*message) == 0 && isalpha(*message) != 0) {
            if (islower(*message) == 0)
                cleanedMessage[currentIndex++] = (char) tolower(*message++);
            else
                cleanedMessage[currentIndex++] = *message++;

        } else
            message++;
    }

    cleanedMessage = (char *) realloc(cleanedMessage, sizeof(char) * currentIndex + 1);
    cleanedMessage[currentIndex] = '\0';

    return cleanedMessage;
}

char *digraphMessage(char *message, char specialChar) {
    char *digraphedMessage = (char *) malloc(sizeof(char) * ((strlen(message) * 2) + 1));
    int currentIndex = 0;

    while (*message != '\0') {
        digraphedMessage[currentIndex] = *message++;
        if (*message != '\0') {
            if (digraphedMessage[currentIndex] != *message) {
                currentIndex++;
                digraphedMessage[currentIndex++] = *message++;
            } else {
                currentIndex++;
                digraphedMessage[currentIndex++] = specialChar;
            }
        } else {
            currentIndex++;
            digraphedMessage[currentIndex++] = specialChar;
            break;
        }
    }

    digraphedMessage = (char *) realloc(digraphedMessage, sizeof(char) * currentIndex + 1);
    digraphedMessage[currentIndex] = '\0';

    return digraphedMessage;
}

Coordinates findCoordinates(char c, char matrix[ROW][COL]) {
    Coordinates coordinates;

    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COL; y++) {
            if (matrix[x][y] == c) {
                coordinates.X = x;
                coordinates.Y = y;
            }
        }
    }

    return coordinates;
}

char encodeSameRow(Coordinates coordinates, char matrix[ROW][COL]) {
    if (coordinates.X == 4 && coordinates.Y == 4)
        return matrix[0][0];
    else if (coordinates.Y == 4)
        return matrix[coordinates.X + 1][0];
    else
        return matrix[coordinates.X][coordinates.Y + 1];

}

char encodeSameCol(Coordinates coordinates, char matrix[ROW][COL]) {
    if (coordinates.X == 4)
        return matrix[0][coordinates.Y];
    else
        return matrix[coordinates.X + 1][coordinates.Y];
}

char *encode(Key key, char matrix[ROW][COL], char *message) {
    printf("%s\n", message);
    char *fixedMessage = cleanMessage(message);
    printf("%s\n", fixedMessage);

    fixedMessage = digraphMessage(fixedMessage, key.specialChar);
    printf("%s\n", fixedMessage);

//    printf("Alfabeto: %s.\nCarattere mancante: %c.\nCarattere speciale: %c.\nChiave: %s.\n", key.alphabet,
//           key.missingChar,
//           key.specialChar, key.key);
//
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            printf("%c ", matrix[i][j]);
//        }
//        printf("\n");
//    }

    char *encodedMessage = (char *) malloc(sizeof(char) * (strlen(fixedMessage) + 1));
    int currentIndex = 0;

    while (*fixedMessage != '\0') {
        Coordinates firstChar = findCoordinates(*fixedMessage++, matrix);
        Coordinates secondChar = findCoordinates(*fixedMessage++, matrix);

        if (firstChar.X == secondChar.X) {
            encodedMessage[currentIndex++] = encodeSameRow(firstChar, matrix);
            encodedMessage[currentIndex++] = encodeSameRow(secondChar, matrix);
        } else if (firstChar.Y == secondChar.Y) {
            encodedMessage[currentIndex++] = encodeSameCol(firstChar, matrix);
            encodedMessage[currentIndex++] = encodeSameCol(secondChar, matrix);
        } else {
            encodedMessage[currentIndex++] = matrix[firstChar.X][secondChar.Y];
            encodedMessage[currentIndex++] = matrix[secondChar.X][firstChar.Y];
        }
    }

    encodedMessage[currentIndex] = '\0';

    printf("%s\n", encodedMessage);

    free(message);

    return encodedMessage;
}

//char *decode(Key key, char matrix[row][col], char *message) {
//
//}