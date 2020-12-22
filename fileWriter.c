
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileWriter.h"

void printMessageOnFile(char *outputPath, char *message) {
    FILE *in = fopen(outputPath, "w");
    for (int i = 0; i < strlen(message); i++) {
//        fputc(message[i], in);
//        if (i != (strlen(message) - 1))
//            fputc(message[i + 1], in);
//        if (i != (strlen(message) - 2))
//            fputc(' ', in);
        if ((i % 2) == 0)
            fputc(message[i], in);
        else {
            fputc(message[i], in);
            if (i != (strlen(message) - 1))
                fputc(' ', in);
        }
    }

//    fprintf(in, message, strlen(message));
    fclose(in);
}

char *generateFileNamePath(char *dirName, char *fileName, char *extension) {
    char *fileNamePath = (char *) malloc((strlen(dirName) + 1) * sizeof(char));
    strcpy(fileNamePath, dirName);
    fileNamePath = realloc(fileNamePath, strlen(fileNamePath) + 3);
    strcat(fileNamePath, "\\");

    fileNamePath = realloc(fileNamePath, strlen(fileNamePath) + strlen(fileName) + 1);
    strcat(fileNamePath, fileName);

    fileNamePath = realloc(fileNamePath, strlen(fileNamePath) + strlen(extension) + 1);
    strcat(fileNamePath, extension);

    return fileNamePath;
}

char *extractFileName(char *filePath) {
    char *temp = malloc(sizeof(char) * (strlen(filePath) + 1));
    strcpy(temp, filePath);
    char *fileName = malloc(sizeof(char) + 1);
    char *ch;
    ch = strtok(temp, "\\");
    while (ch != NULL) {
        fileName = realloc(fileName, strlen(ch) + 1);
        strcpy(fileName, ch);
        ch = strtok(NULL, "\\");
    }
    ch = strtok(fileName, ".");
    fileName = realloc(fileName, strlen(ch) + 1);
    strcpy(fileName, ch);
    free(temp);
    return fileName;
}

void creaFiledi10mb() {
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\file_grossi\\file10mb.txt", "w");
    for (int i = 0; i < 10485759; i++)
        fputc('A', in);
    fclose(in);
}

void creaFiledi1mb() {
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\file_grossi\\file1mb.txt", "w");
    for (int i = 0; i < 1048575; i++)
        fputc('A', in);
    fclose(in);
}

void creaFiledi10kb() {
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\file_grossi\\file10kb.txt", "w");
    for (int i = 0; i < 10239; i++)
        fputc('A', in);
    fclose(in);
}