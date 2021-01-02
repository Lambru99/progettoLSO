//
// Created by Paolo on 02/01/2021.
//
#include <stdio.h>

#include <stdlib.h>
#include <libgen.h>
#include <string.h>

#include "FileWriter.h"

char *getFileName(char *file) {
    char *fileName = (char *) malloc(sizeof(char) * strlen(file));
    int currentIndex = 0;

    while (*file != '\0') {
        if (*file != '.')
            fileName[currentIndex++] = *file++;
        else
            break;
    }

    fileName = (char *) realloc(fileName, sizeof(char) * currentIndex + 1);
    fileName[currentIndex] = '\0';

    free(file);

    return fileName;
}

char *createDestinationDir(char *outpudDir, char *file, char *extension) {
    char *destinationDyr = (char *) malloc(
            sizeof(char) * (strlen(outpudDir) + strlen(basename(file)) + 1 + strlen(extension)));

    strcpy(destinationDyr, outpudDir);
    strcat(destinationDyr, "\\");
    strcat(destinationDyr, getFileName(basename(file)));
    strcat(destinationDyr, extension);

    return destinationDyr;
}

void saveMessage(char *message, char *outpudDir, char *file, char *extension) {
    FILE *fReader;

    fReader = fopen(createDestinationDir(outpudDir, file, extension), "a");
    if (fReader == NULL) {
        fprintf(stderr, "Errore!\nNon esiste file nella directory specificata.");
        exit(EXIT_FAILURE);
    }

    fprintf(fReader, "%s", message);

    free(message);
    fclose(fReader);
}