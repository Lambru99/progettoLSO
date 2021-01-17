//
// Created by Paolo on 15/11/2020.
//

#include "FileReader.h"
#include "FileManager.h"
#include "StringManager.h"

char *loadMessage(FILE *fReader, long nChar) {
    char *fText = allocateString(nChar + 1);
    size_t charactersRead = fread(fText, sizeof(char), nChar, fReader);

    if (nChar != charactersRead) {
        fText = reallocateString(fText, charactersRead + 1);
        fText[charactersRead] = '\0';

        return fText;
    } else {
        fText[nChar] = '\0';

        return fText;
    }
}

char getLastCharFromFile(char *fileDir) {
    FILE *fReader = openFileToRead(fileDir);

    fseek(fReader, -1, SEEK_END);
    char lastChar = (char) fgetc(fReader);
    fseek(fReader, 0, SEEK_SET);

    fclose(fReader);

    return lastChar;
}

Key getKeyInfo(char *filePath) {
    Key key;
    int currentChar;

    FILE *fReader = openFileToRead(filePath);
    long fileSize = getFileSize(fReader);
    key.key = allocateString(fileSize - 32);

    fgets(key.alphabet, sizeof key.alphabet, fReader);
    do
        currentChar = fgetc(fReader);
    while (currentChar == '\n');
    key.missingChar = (char) currentChar;
    do
        currentChar = fgetc(fReader);
    while (currentChar == '\n');
    key.specialChar = (char) currentChar;
//    do {
    currentChar = fgetc(fReader);
//        if (currentChar == '\n')
    fgets(key.key, fileSize - 32, fReader);
//    } while (currentChar != '\n');

    fclose(fReader);

    return key;
}