
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include "PlayfairCipher.h"
#include "FileManager.h"

void printInfo() {
    printf("playfair encode|decode <keyfile> <outputdir> <file1> ... <filen>\n");
}

//void freeInfo(Key key) {
//    free(key.alphabet);
//    free(key.key);
//}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Error!\nWrong number of parameters (expected 5 instead of %d).", argc);
        exit(EXIT_FAILURE);
    } else {
        char matrix[ROW][COL];
        Key key = getKeyInfo(argv[2]);
//        initMatrix(matrix, key);
        fillMatrix(matrix, key);
        if (strcmp(argv[1], "encode") == 0) {
            for (int i = 4; i < argc; i++) {
//                char *message = loadMessage(argv[i]);
                char *encodedMessage = encode(key, matrix, loadMessage(argv[i]));
                char *destinationDyr = (char *) malloc(sizeof(char) * (strlen(argv[i]) + strlen(basename(argv[i]))));
                strcpy(destinationDyr, argv[3]);

                strcat(destinationDyr, basename(argv[i]));
//                saveMessage(argv[3]+basename(argv[i]), encodedMessage);
                printf("%s", destinationDyr);
//                encode(key, matrix, message);
            }
        }
    }
//    else {
//        for (int i = 4; i < argc; i++)
//            decode(key, argv[i]);
//    }


    return 0;
}