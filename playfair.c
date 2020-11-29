
#include "playfair.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void buildMatrix(const char *tableText) {
    char matrix[5][5] = {0};
    int count = 0;

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
}

void fixMessage(char *message) {
    printf("\nmessage: %s", message);

}