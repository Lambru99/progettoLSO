//
// Created by Paolo on 02/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FileWriter.h"

char *getFileName(char *messageDir) {
    char *temp = strrchr(messageDir, '\\');
    char *fileName = (char *) malloc(sizeof(char) * strlen(temp));
    int currentIndex = 0;

    while (*temp != '.')
        fileName[currentIndex++] = *temp++;

    fileName = (char *) realloc(fileName, sizeof(char) * (currentIndex + 1));
    fileName[currentIndex] = '\0';

    return fileName;
}

char *createDestinationDir(char *outpudDir, char *messageDir, char *extension) {
    char *fileName = getFileName(messageDir);
    char *destinationDyr = (char *) malloc(
            sizeof(char) * (strlen(outpudDir) + strlen(fileName) + strlen(extension)));

    strcpy(destinationDyr, outpudDir);
    strcat(destinationDyr, fileName);
    strcat(destinationDyr, extension);

    free(fileName);

    return destinationDyr;
}

void saveMessage(char *message, char *outpudDir, char *messageDir, char *extension) {
    char *destinationDir = createDestinationDir(outpudDir, messageDir, extension);
    FILE *fWriter = fopen(destinationDir, "a");
    if (fWriter == NULL) {
        fprintf(stderr, "Errore!\nNon esiste file nella directory specificata.");
        exit(EXIT_FAILURE);
    }

    while (*message != '\0') {
        fputc(*message++, fWriter);
        if (*message != '\0') {
            fputc(*message++, fWriter);
            fputc(' ', fWriter);
        }
    }

    free(destinationDir);
    fclose(fWriter);
}