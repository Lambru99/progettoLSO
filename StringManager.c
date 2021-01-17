//
// Created by Paolo on 17/01/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "StringManager.h"

char *allocateString(size_t length) {
    char *temp = (char *) malloc(sizeof(char) * length);

    if (temp == NULL) {
        fprintf(stderr, "Errore!\nMemory cannot be allocated.");
        exit(EXIT_FAILURE);
    }

    return temp;
}

char *reallocateString(char *string, size_t length) {
    char *temp = (char *) realloc(string, sizeof(char) * length);

    if (temp == NULL) {
        fprintf(stderr, "Errore!\nMemory cannot be reallocated.");
        free(string);
        exit(EXIT_FAILURE);
    } else
        string = temp;

    return string;
}

void toUpperString(char *string) {
    while (*string != '\0') {
        if (isupper(*string) == 0) {
            *string = (char) toupper(*string);
            string++;
        } else
            string++;
    }
}

char *removeCharFromString(char charToRemove, char *string) {
    size_t stringLength = strlen(string);
    char *cleanedString = allocateString(stringLength + 1);
    unsigned int currentIndex = 0;

    while (*string != '\0') {
        if (*string != charToRemove)
            cleanedString[currentIndex++] = *string++;
        else
            string++;
    }

    if (currentIndex != stringLength) {
        cleanedString = reallocateString(cleanedString, currentIndex + 1);
        cleanedString[currentIndex] = '\0';

        return cleanedString;
    } else {
        cleanedString[currentIndex] = '\0';

        return cleanedString;
    }
}

char *toAlphaString(char *string) {
    size_t stringLength = strlen(string);
    char *cleanedString = allocateString(stringLength + 1);
    unsigned currentIndex = 0;

    while (*string != '\0') {
        if (isalpha(*string) != 0)
            cleanedString[currentIndex++] = *string++;
        else
            string++;
    }

    if (currentIndex != stringLength) {
        cleanedString = reallocateString(cleanedString, currentIndex + 1);
        cleanedString[currentIndex] = '\0';

        return cleanedString;
    } else {
        cleanedString[currentIndex] = '\0';

        return cleanedString;
    }
}