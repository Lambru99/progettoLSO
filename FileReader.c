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
        exit(EXIT_FAILURE);
    }

    return fReader;
}

long getFileSize(FILE *file) {
    long size;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}

char *loadMessage(FILE *file, long nChar) {
    char *fText = (char *) malloc(sizeof(char) * (nChar + 1));
    if (fText == NULL) {
        fprintf(stderr, "Errore!\nNon è possibile allocare memoria.");
        exit(EXIT_FAILURE);
    }

    size_t charLetti = fread(fText, sizeof(char), nChar, file);

    if (nChar != charLetti) {
        fText = (char *) realloc(fText, sizeof(char) * (charLetti + 1));
        if (fText == NULL) {
            fprintf(stderr, "Errore!\nNon è possibile riallocare memoria.");
            exit(EXIT_FAILURE);
        }
        fText[charLetti] = '\0';
        return fText;
    } else {
        fText[nChar] = '\0';
        return fText;
    }
}

//int countCharLine(FILE *file) {
//    int count = 0;
//    int currentChar;
//    fpos_t pos;
//
//    fgetpos(file, &pos);
//
//    while (1) {
//        currentChar = getc(file);
//        if (currentChar != '\n' && currentChar != EOF)
//            count++;
//        else
//            break;
//    }
//
//    fsetpos(file, &pos);
//
//    return count;
//}

Key getKeyInfo(char *filePath) {
    Key key;
    FILE *fReader;
    long fileSize;
    int currentChar;

    fReader = openFile(filePath);
    fileSize = getFileSize(fReader);
    key.key = malloc(sizeof key.key * (fileSize - 32));
    if (key.key == NULL) {
        fprintf(stderr, "Errore!\nNon è possibile allocare memoria.");
        exit(EXIT_FAILURE);
    }

    fgets(key.alphabet, sizeof key.alphabet, fReader);
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