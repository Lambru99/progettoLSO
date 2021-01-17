#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "PlayfairCipher.h"
#include "FileReader.h"
#include "PlayfairUtilities.h"
#include "StringManager.h"

void printInfo() {
    printf("playfair encode|decode <keyfile> <outputdir> <file1> ... <filen>\n");
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Error!\nWrong number of parameters (expected 5 instead of %d).\n", argc);
        printInfo();
    } else {
        Key key = getKeyInfo(argv[2]);
        toUpperString(key.key);
        toUpperString(key.alphabet);
        key.specialChar = (char) toupper(key.specialChar);
        char matrix[5][5];
        fillMatrix(matrix, key);
        if (strcmp(argv[1], "encode") == 0) {
            for (int i = 4; i < argc; i++) {
                encode(key, matrix, argv[3], argv[i]);
            }
        } else {
            for (int i = 4; i < argc; i++) {
                decode(key, matrix, argv[3], argv[i]);
            }
        }
        free(key.key);
    }

    return 0;
}