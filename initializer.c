
#include "initializer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *getMatrixText(struct KeyFile keyFile) {
    char *matrixText = calloc(26, sizeof(char));
    int count = 0;

    for (int i = 0; i < strlen(keyFile.key); i++) {
        if (keyFile.key[i] >= 65 && keyFile.key[i] <= 90) {
            if (strchr(matrixText, keyFile.key[i]) == NULL) {
                matrixText[count] = keyFile.key[i];
                count++;
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        if (strchr(matrixText, keyFile.alphabet[i]) == NULL) {
            matrixText[count] = keyFile.alphabet[i];
            count++;
        }
    }
    return matrixText;
}

char **buildMatrix(const char *tableText) {
    int count = 0;

    char **matrix = (char **) malloc(5 * sizeof(char *));
    for (int row = 0; row < 5; row++) {
        matrix[row] = (char *) malloc(5 * sizeof(char));
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = tableText[count];
            count++;
        }
    }
    return matrix;
}

char *getFixedMessage(char *message, char specialChar) {
    char *onlyLettersMessage = removeNotAlphaChar(message);
    char *fixedMessage = addSpecialChar(onlyLettersMessage, specialChar);
    free(onlyLettersMessage);
    return fixedMessage;
}

char *removeNotAlphaChar(char *message) {
    char *alphaOnlyMessage = (char *) calloc((strlen(message) - countSpecialChar(message)) + 1, sizeof(char));
    int count = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 65 && message[i] <= 90) {
            alphaOnlyMessage[count] = message[i];
            count++;
        }
    }
    return alphaOnlyMessage;
}

char *addSpecialChar(char *alphaOnlyMessage, char specialChar) {
    char *fixedMessage = (char *) calloc(strlen(alphaOnlyMessage) + countDoubles(alphaOnlyMessage) + 1, sizeof(char));
    int count = 0;
    for (int i = 0; i < strlen(alphaOnlyMessage); i++) {
        if (alphaOnlyMessage[i] == alphaOnlyMessage[i + 1]) {
            fixedMessage[count++] = alphaOnlyMessage[i];
            fixedMessage[count++] = specialChar;
        } else {
            fixedMessage[count++] = alphaOnlyMessage[i];
            fixedMessage[count++] = alphaOnlyMessage[i + 1];
            i++;
        }
    }
    if ((strlen(fixedMessage) % 2) != 0) {
        fixedMessage = realloc(fixedMessage, strlen(fixedMessage) + 2);
        fixedMessage[count - 1] = specialChar;
        fixedMessage[count] = '\0';
    }
    free(alphaOnlyMessage);
    return fixedMessage;
}

unsigned int countSpecialChar(char *string) {
    unsigned int countSpecialChar = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] < 65 || string[i] > 90)
            countSpecialChar++;
    }
    return countSpecialChar;
}

unsigned int countDoubles(char *string) {
    unsigned int countDoubles = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == string[i + 1]) {
            countDoubles++;
        } else i++;
    }
    return countDoubles;
}