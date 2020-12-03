#include "initializer.h"
#include "playfair.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(struct KeyFile keyFile, char *message) {
    char **matrix = buildMatrix(getMatrixText(keyFile));
    char *fixedMessage = getFixedMessage(message, keyFile.specialCharacter);

    printf("\nAlphabet: %s", keyFile.alphabet);
    printf("\nMissing character: %c", keyFile.missingCharacter);
    printf("\nSpecial character: %c", keyFile.specialCharacter);
    printf("\nKey: %s", keyFile.key);
    printf("\n");

    printf("\nStampo la matrice: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nmessage: %s", message);
    printf("\nfixedMessage: %s", fixedMessage);
    free(matrix);
    free(fixedMessage);
}

char *encode(struct KeyFile keyFile, char *message) {
    char **matrix = buildMatrix(getMatrixText(keyFile));
    char *fixedMessage = getFixedMessage(message, keyFile.specialCharacter);
    char *encodedMessage = (char *) calloc(strlen(fixedMessage) + 1, sizeof(char));
    int row1, column1, row2, column2, count = 0;

    for (int i = 0; i < strlen(fixedMessage); i += 2) {
        row1 = getRow(fixedMessage[i], matrix);
        column1 = getColumn(fixedMessage[i], matrix);
        row2 = getRow(fixedMessage[i + 1], matrix);
        column2 = getColumn(fixedMessage[i + 1], matrix);

        if (row1 == row2) {
            if (column1 < 4) {
                encodedMessage[count++] = matrix[row1][column1 + 1];
            } else encodedMessage[count++] = matrix[row1][0];
            if (column2 < 4) {
                encodedMessage[count++] = matrix[row2][column2 + 1];
            } else encodedMessage[count++] = matrix[row2][0];
        } else if (column1 == column2) {
            if (row1 < 4) {
                encodedMessage[count++] = matrix[row1 + 1][column1];
            } else encodedMessage[count++] = matrix[0][column1];
            if (row2 < 4) {
                encodedMessage[count++] = matrix[row2 + 1][column2];
            } else encodedMessage[count++] = matrix[0][column2];
        } else {
            encodedMessage[count++] = matrix[row1][column2];
            encodedMessage[count++] = matrix[row2][column1];
        }
    }

    free(matrix);
    free(fixedMessage);

    return encodedMessage;
}

char *decode(struct KeyFile keyFile, char *message) {
    char **matrix = buildMatrix(getMatrixText(keyFile));
    char *fixedMessage = getFixedMessage(message, keyFile.specialCharacter);
    char *decodedMessage = (char *) calloc(strlen(fixedMessage) + 1, sizeof(char));
    int row1, column1, row2, column2, count = 0;

    for (int i = 0; i < strlen(message); i += 2) {
        row1 = getRow(message[i], matrix);
        column1 = getColumn(message[i], matrix);
        row2 = getRow(message[i + 1], matrix);
        column2 = getColumn(message[i + 1], matrix);

        if (row1 == row2) {
            if (column1 > 0) {
                decodedMessage[count++] = matrix[row1][column1 - 1];
            } else decodedMessage[count++] = matrix[row1][4];
            if (column2 > 0) {
                decodedMessage[count++] = matrix[row2][column2 - 1];
            } else decodedMessage[count++] = matrix[row2][4];
        } else if (column1 == column2) {
            if (row1 > 0)
                decodedMessage[count++] = matrix[row1 - 1][column1];
            else decodedMessage[count++] = matrix[4][column1];
            if (row2 > 0)
                decodedMessage[count++] = matrix[row2 - 1][column2];
            else decodedMessage[count++] = matrix[4][column2];
        } else {
            decodedMessage[count++] = matrix[row1][column2];
            decodedMessage[count++] = matrix[row2][column1];
        }
    }

    free(matrix);
    free(fixedMessage);

    return decodedMessage;
}

int getRow(char c, char **matrix) {
    int row = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c)
                row = i;
        }
    }
    return row;
}

int getColumn(char c, char **matrix) {
    int column = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c)
                column = j;
        }
    }
    return column;
}
