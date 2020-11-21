
#include "playfair.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char matrix[5][5];

void buildMatrix(struct KeyFile keyFile) {

    char tableText[26];
    int count = 0;

    for (int i = 0; i < strlen(keyFile.key); i++) {
        if (keyFile.key[i] >= 65 && keyFile.key[i] <= 90) {
            if (!strchr(tableText, keyFile.key[i])) {
                tableText[count] = keyFile.key[i];
                if (count < 26)
                    count++;
            }
        }
    }


    for (int i = 0; i < 26; i++) {
        if (!strchr(tableText, keyFile.alphabet[i])) {
            tableText[count] = keyFile.alphabet[i];
            if (count < 26)
                count++;
        }
    }


    printf("%s", keyFile.key);
    printf("\n%s", tableText);

    printf("fine testo tabella\n\n");

//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            matrix[i][j] = tableText[count];
//            count++;
//        }
//    }
//
//
    printf("\nStampo la matrice: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}