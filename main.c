
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PlayfairCipher.h"
#include "FileReader.h"
#include "PlayfairUtilities.h"
#include "FileWriter.h"

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
        Key key = getKeyInfo(argv[2]);
        toUpperString(key.key);
        toUpperString(key.alphabet);
        char matrix[5][5];
        fillMatrix(matrix, key);
        if (strcmp(argv[1], "encode") == 0) {
            for (int i = 4; i < argc; i++)
                saveMessage(encode(key, matrix, loadMessage(argv[i])), argv[3], argv[i], ".pf");
        } else {
            for (int i = 4; i < argc; i++)
                saveMessage(decode(key, matrix, loadMessage(argv[i])), argv[3], argv[i], ".dec");
        }
        free(key.key);
    }

    return 0;
}