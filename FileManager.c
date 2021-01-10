//
// Created by Paolo on 10/01/2021.
//

#include <stdlib.h>

#include "FileManager.h"

FILE *openFileToRead(char *filePath) {
    FILE *fReader;

    fReader = fopen(filePath, "r");
    if (fReader == NULL) {
        fprintf(stderr, "Errore!\nNon esiste file nella directory specificata.");
        exit(EXIT_FAILURE);
    }

    return fReader;
}

FILE *openFileToAppend(char *filePath) {
    FILE *fReader;

    fReader = fopen(filePath, "a");
    if (fReader == NULL) {
        fprintf(stderr, "Errore!\nNon esiste file nella directory specificata.");
        exit(EXIT_FAILURE);
    }

    return fReader;
}