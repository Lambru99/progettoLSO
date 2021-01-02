//
// Created by Paolo on 02/01/2021.
//
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "PlayfairUtilities.h"

void fillMatrix(char matrix[5][5], Key key) {
    char letters[25] = {0};
    char *currentAlphabetChar = key.alphabet;
    int lettersIndex = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
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

void toUpperString(char *string) {
    while (*string != '\0') {
        if (isupper(*string) == 0) {
            *string = (char) toupper(*string);
            string++;
        } else
            string++;
    }
}

char *removeCharFromMessage(char charToRemove, char *message) {
    char *cleanedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    int currentIndex = 0;

    while (*message != '\0') {
        if (*message != charToRemove)
            cleanedMessage[currentIndex++] = *message++;
        else
            message++;
    }

    cleanedMessage = (char *) realloc(cleanedMessage, sizeof(char) * currentIndex + 1);
    cleanedMessage[currentIndex] = '\0';

//    free(message);

    return cleanedMessage;
}

char *toAlphaMessage(char *message) {
    char *cleanedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    int currentIndex = 0;

    while (*message != '\0') {
        if (isalpha(*message) != 0)
            cleanedMessage[currentIndex++] = *message++;
        else
            message++;
    }

    cleanedMessage = (char *) realloc(cleanedMessage, sizeof(char) * currentIndex + 1);
    cleanedMessage[currentIndex] = '\0';

//    free(message);

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

//    free(message);

    return digraphedMessage;
}

Coordinates findCoordinates(char c, char matrix[5][5]) {
    Coordinates coordinates;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (matrix[x][y] == c) {
                coordinates.X = x;
                coordinates.Y = y;
            }
        }
    }

    return coordinates;
}

char encodeSameRow(Coordinates coordinates, char matrix[5][5]) {
    if (coordinates.X == 4 && coordinates.Y == 4)
        return matrix[4][0];
    else if (coordinates.Y == 4)
        return matrix[coordinates.X][0];
    else
        return matrix[coordinates.X][coordinates.Y + 1];
}

char encodeSameCol(Coordinates coordinates, char matrix[5][5]) {
    if (coordinates.X == 4)
        return matrix[0][coordinates.Y];
    else
        return matrix[coordinates.X + 1][coordinates.Y];
}

char *encodeMessage(char *message, char matrix[5][5]) {
    printf("%s\n", message);

    char *encodedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    int currentIndex = 0;

    while (*message != '\0') {
        Coordinates firstChar = findCoordinates(*message++, matrix);
        Coordinates secondChar = findCoordinates(*message++, matrix);

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
    printf("%d\n", currentIndex);
    printf("%s\n", encodedMessage);

    encodedMessage[currentIndex] = '\0';

//    free(message);

    return encodedMessage;
}

char decodeSameRow(Coordinates coordinates, char matrix[5][5]) {
    if (coordinates.X == 0 && coordinates.Y == 0)
        return matrix[0][4];
    else if (coordinates.Y == 0)
        return matrix[coordinates.X][4];
    else
        return matrix[coordinates.X][coordinates.Y - 1];
}

char decodeSameCol(Coordinates coordinates, char matrix[5][5]) {
    if (coordinates.X == 0)
        return matrix[4][coordinates.Y];
    else
        return matrix[coordinates.X - 1][coordinates.Y];
}

char *decodeMessage(char *message, char matrix[5][5]) {
    char *decodedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    int currentIndex = 0;

    while (*message != '\0') {
        Coordinates firstChar = findCoordinates(*message++, matrix);
        Coordinates secondChar = findCoordinates(*message++, matrix);

        if (firstChar.X == secondChar.X) {
            decodedMessage[currentIndex++] = decodeSameRow(firstChar, matrix);
            decodedMessage[currentIndex++] = decodeSameRow(secondChar, matrix);
        } else if (firstChar.Y == secondChar.Y) {
            decodedMessage[currentIndex++] = decodeSameCol(firstChar, matrix);
            decodedMessage[currentIndex++] = decodeSameCol(secondChar, matrix);
        } else {
            decodedMessage[currentIndex++] = matrix[firstChar.X][secondChar.Y];
            decodedMessage[currentIndex++] = matrix[secondChar.X][firstChar.Y];
        }
    }

    decodedMessage[currentIndex] = '\0';

//    free(message);

    return decodedMessage;
}