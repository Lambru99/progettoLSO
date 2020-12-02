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

/**
 * Legge il file contenente la chiave, l'alfabeto e i caratteri speciali e ritorna la rispettiva
 * struttura dopo averla opportunamente costruita.
 */
struct KeyFile readKeyFile(char *path) {
    FILE *in = fopen(path, "r+");
    struct KeyFile keyFile;
    int character;

    fgets(keyFile.alphabet, 26, in);
    toUpperString(keyFile.alphabet);

    do {
        character = fgetc(in);
    } while (character == EOF || character == '\n');
    keyFile.missingCharacter = (char) toupper(character);

    do {
        character = fgetc(in);
    } while (character == EOF || character == '\n');
    keyFile.specialCharacter = (char) toupper(character);

    int fileSize = getFileSize(in);
    char buf[fileSize];
    keyFile.key = (char *) malloc(sizeof(char) * (fileSize - 32));

    while (fgets(buf, fileSize, in) != NULL) {}
    strcpy(keyFile.key, buf);
    toUpperString(keyFile.key);

    fclose(in);
    return keyFile;
}

void toUpperString(char *string) {
    for (int i = 0; i < strlen(string); i++)
        string[i] = (char) toupper(string[i]);
}

/**
 * Legge il file contenente il messaggio da cifrare o decifrare e ne ritorna il contenuto
 * in UPPERCASE
 * @return il contenuto del messaggio
 */
char *readMessage(char *path) {
    FILE *in = fopen(path, "r+");
    char *content = malloc((getFileSize(in) + 1) * sizeof(char));
    fgets(content, getFileSize(in) + 1, in);
    for (int i = 0; i < (getFileSize(in)); i++)
        content[i] = (char) toupper(content[i]);
    return content;
}
