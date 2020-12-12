
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PlayfairCipher.h"
#include "FileReader.h"

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
        if (strcmp(argv[1], "encode") == 0) {
            for (int i = 4; i < argc; i++)
                encode(key, argv[i]);
        }
//        } else {
//            for (int i = 4; i < argc; i++)
//                decode(key, argv[i]);
//        }
        free(key.key);
    }

    return 0;
}