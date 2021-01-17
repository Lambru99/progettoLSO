//
// Created by Paolo on 02/01/2021.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "FileWriter.h"
#include "FileManager.h"
#include "FileReader.h"
#include "StringManager.h"

char *getFileName(char *messageDir) {
    char *temp = strrchr(messageDir, '\\');
    char *fileName = allocateString(strlen(temp));
    unsigned int currentIndex = 0;

    while (*temp != '.')
        fileName[currentIndex++] = *temp++;

    fileName = reallocateString(fileName, currentIndex + 1);
    fileName[currentIndex] = '\0';

    return fileName;
}

char *createDestinationDir(char *outpudDir, char *messageDir, char *extension) {
    char *fileName = getFileName(messageDir);
    char *destinationDyr = allocateString(strlen(outpudDir) + strlen(fileName) + strlen(extension));

    strcpy(destinationDyr, outpudDir);
    strcat(destinationDyr, fileName);
    strcat(destinationDyr, extension);

    free(fileName);

    return destinationDyr;
}

void saveMessage(char *message, char *outpudDir, char *messageDir, char *extension) {
    char *destinationDir = createDestinationDir(outpudDir, messageDir, extension);
    FILE *fWriter = openFileToAppend(destinationDir);
    char lastChar = getLastCharFromFile(destinationDir);

    if (isalpha(lastChar) != 0)
        if (*message != '\0') {
            fputc(*message++, fWriter);
            putc(' ', fWriter);
        }

    int count = 0;
    while (*message != '\0') {
        fputc(*message++, fWriter);
        count++;
        if (count % 2 == 0)
            fputc(' ', fWriter);
    }

    free(destinationDir);
    fclose(fWriter);
}