#include "fileReader.h"
#include "playfair.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


long getFileSize(FILE *file) {
    long int size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

char *readFile(char *path) {
    FILE *in = fopen(path, "rb");
    if (in == NULL) {
        printf("Error while opening the file.\n");
        exit(1);
    }

    int length = getFileSize(in);

    char *buffer = malloc(33);
    fread(buffer, sizeof(char), length, in);
    fclose(in);
    return buffer;
}


void readKeyFile() {
    struct KeyFile keyFile;
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\chiave.txt", "r+");

    fgets(keyFile.alphabet, 26, in);
    printf("%s", keyFile.alphabet);

    int character;
    do {
        character = fgetc(in);
    } while (character == EOF || character == '\n');

    keyFile.missingCharacter = (char) character;
    printf("\n%c", keyFile.missingCharacter);

    do {
        character = fgetc(in);
    } while (character == EOF || character == '\n');

    keyFile.specialCharacter = (char) character;
    printf("\n%c", keyFile.specialCharacter);

    int fileSize = getFileSize(in);
    char buf[fileSize];
    keyFile.key = malloc(fileSize - 33);

    while (fgets(buf, fileSize, in) != NULL) {}
    strcpy(keyFile.key, buf);
    printf("\n%s", keyFile.key);

    fclose(in);
}

void readText() {
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\prova.txt", "r+");
    char *content = malloc((getFileSize(in) + 1) * sizeof(char));
//    fscanf(in, "%s", content);
    fgets(content, getFileSize(in), in);
    printf("\n%s", content);
}
