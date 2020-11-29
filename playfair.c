
#include "playfair.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(struct KeyFile keyFile, char *message) {
    char **matrix = buildMatrix(buildTableText(keyFile));
    char *fixedMessage = fixMessage(message, keyFile);
}

const char *buildTableText(struct KeyFile keyFile) {
    char temp[26] = {0};
    int count = 0;

    for (int i = 0; i < strlen(keyFile.key); i++) {
        // se keyFile.key[i] è una lettera maiuscola...
        if (keyFile.key[i] >= 65 && keyFile.key[i] <= 90) {
            // se temp non contiene già keyFile.key[i]...
            if (strchr(temp, keyFile.key[i]) == NULL) {
                temp[count] = keyFile.key[i];
                count++;
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        if (strchr(temp, keyFile.alphabet[i]) == NULL) {
            temp[count] = keyFile.alphabet[i];
            count++;
        }
    }

    printf("\n\n\nAlphabet: %s", keyFile.alphabet);
    printf("\nMissing character: %c", keyFile.missingCharacter);
    printf("\nSpecial character: %c", keyFile.specialCharacter);
    printf("\nKey: %s", keyFile.key);
    printf("\n");

    char *matrixText = (char *) malloc(26 * sizeof(char));
    strcpy(matrixText, temp);
    return matrixText;
}

char **buildMatrix(const char *tableText) {
//    char matrix[5][5] = {0};
    int count = 0;

    // allocate Rows rows, each row is a pointer to int
    char **matrix = (char **) malloc(5 * sizeof(char *));

    // for each row allocate Cols ints
    for (int row = 0; row < 5; row++) {
        matrix[row] = (char *) malloc(5 * sizeof(char));
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = tableText[count];
            count++;
        }
    }

    printf("\nStampo la matrice: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    return matrix;
}

char *fixMessage(char *message, struct KeyFile keyFile) {
    int countSpace = 0;
    int countDouble = 0;

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] < 65 || message[i] > 90)
            countSpace++;
        if (message[i] == message[i + 1])
            countDouble++;
    }

    unsigned int size = strlen(message) - countSpace + countDouble;

//    char *messageWithoutSpace = (char *) malloc((sizeof(char) * size) + 1);

//    int count = 0;
//    for (int i = 0; i < strlen(message); i++) {
//        if (message[i] >= 65 && message[i] <= 90) {
//            if (message[i] == keyFile.missingCharacter) {
//                messageWithoutSpace[count] = 'I';
//                count++;
//            } else {
//                messageWithoutSpace[count] = message[i];
//                count++;
//            }
//            if (message[i] == message[i + 1]) {
//                messageWithoutSpace[count] = keyFile.specialCharacter;
//                count++;
//            }
//            if (message[i + 1]==' ') {
//                if (message[i] == message[i + 2]) {
//                    messageWithoutSpace[count] = keyFile.specialCharacter;
//                    count++;
//                }
//            }
//        }
//    }
//
//    if (size % 2) {
//        messageWithoutSpace[size] = keyFile.specialCharacter;
//        messageWithoutSpace[size + 1] = '\0';
//    } else
//        messageWithoutSpace[size] = '\0';

    char *onlyLettersMessage = (char *) malloc((sizeof(char) * (strlen(message) - countSpace) + 1));

    int count = 0;

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 65 && message[i] <= 90) {
            onlyLettersMessage[count] = message[i];
            count++;
        }
    }

    for (int i = 0; i < strlen(onlyLettersMessage); i++) {
        if (onlyLettersMessage[i] == onlyLettersMessage[i + 1]) {
            char t = onlyLettersMessage[i + 1];
            onlyLettersMessage[i + 1] = keyFile.specialCharacter;
        }
    }

    printf("\nmessage: %s", message);
    printf("\nmessageWithoutSpace: %s", onlyLettersMessage);

    return onlyLettersMessage;
}