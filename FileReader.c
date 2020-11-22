//
// Created by Paolo on 15/11/2020.
//
#include <stdio.h>
#include <stdlib.h>

#include "FileReader.h"

FILE *openFile(char *filePath) {
    FILE *fReader;

    fReader = fopen(filePath, "r");

    if (fReader == NULL) {
        fprintf(stderr, "Errore!\nNon esiste file nella directory specificata.");
        // Program exits if file pointer returns NULL.
        exit(EXIT_FAILURE);
    }

    return fReader;
}

long getFileSize(FILE *file) {
    long int size;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}

int countFileLines(FILE *file) {
    int lines = 0;
    int currentChar;

    while (1) {
        currentChar = getc(file);
        if (currentChar == '\n') {
            lines++;
        }
        if (feof(file)) {
            break;
        }
    }

    return lines;
}

Key getKeyFile(char *filePath) {
    Key key;
    FILE *fReader;
    int fileSize;
    int currentChar;

    fReader = openFile(filePath);
    fileSize = getFileSize(fReader);
    key.alphabet = (char *) malloc(sizeof(char) * 25);
    if (key.alphabet == NULL) {
        fprintf(stderr, "Errore!\nNon è possibile allocare memoria.");
        exit(EXIT_FAILURE);
    }
    key.key = (char *) malloc(sizeof(char) * (fileSize - 33));
    if (key.key == NULL) {
        fprintf(stderr, "Errore!\nNon è possibile allocare memoria.");
        exit(EXIT_FAILURE);
    }
    fgets(key.alphabet, 26, fReader);
    do {
        currentChar = fgetc(fReader);
    } while (currentChar == '\n');
    key.missingChar = (char) currentChar;
    do {
        currentChar = fgetc(fReader);
    } while (currentChar == '\n');
    key.specialChar = (char) currentChar;
    do {
        currentChar = fgetc(fReader);
        if (currentChar == '\n') {
            fgets(key.key, fileSize - 32, fReader);
        }
    } while (currentChar != '\n');

    fclose(fReader);

    return key;
}

//char *readMessageFile(char *filePath) {
//
//}