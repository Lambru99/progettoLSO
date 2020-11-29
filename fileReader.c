#include "fileReader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Calcola e restituisce la dimensione in byte del file passato.
 * @param file il file di cui si deve calcolare la dimensione
 * @return la size
 */
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

/**
 * Legge il file contenente la chiave, l'alfabeto e i caratteri speciali e ritorna la rispettiva
 * struttura dopo averla opportunamente costruita.
 */
struct KeyFile readKeyFile() {
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\chiave.txt", "r+");
    struct KeyFile keyFile;

    fgets(keyFile.alphabet, 26, in);

    for (int i = 0; i < 25; i++)
        keyFile.alphabet[i] = (char) toupper(keyFile.alphabet[i]);

    int character;
    do {
        character = fgetc(in);
    } while (character == EOF || character == '\n');

    keyFile.missingCharacter = (char) character;
    keyFile.missingCharacter = (char) toupper(keyFile.missingCharacter);

    do {
        character = fgetc(in);
    } while (character == EOF || character == '\n');
    keyFile.specialCharacter = (char) toupper(character);

    int fileSize = getFileSize(in);
    char buf[fileSize];
    keyFile.key = (char *) malloc(sizeof(char) * (fileSize - 32));
//    keyFile.key = (char *) malloc(sizeof(char) + 1);

    while (fgets(buf, fileSize, in) != NULL) {}
    strcpy(keyFile.key, buf);

    printf("\nkeyFile.key: %s", keyFile.key);

    for (int i = 0; i < (fileSize - 33); i++)
        keyFile.key[i] = (char) toupper(keyFile.key[i]);

    fclose(in);
    return keyFile;
}

/**
 * Legge il file contenente il messaggio da cifrare o decifrare e ne ritorna il contenuto
 * in UPPERCASE
 * @return il contenuto del messaggio
 */
char *readMessage() {
    FILE *in = fopen("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\prova.txt", "r+");
    char *content = malloc((getFileSize(in) + 1) * sizeof(char));
    fgets(content, getFileSize(in) + 1, in);
    for (int i = 0; i < (getFileSize(in)); i++)
        content[i] = (char) toupper(content[i]);
    return content;
}
