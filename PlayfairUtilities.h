//
// Created by Paolo on 02/01/2021.
//

#ifndef PROGETTOLSO_PLAYFAIRUTILITIES_H
#define PROGETTOLSO_PLAYFAIRUTILITIES_H

#include "KeyStruct.h"

typedef struct {
    int X;
    int Y;
} Coordinates;

void fillMatrix(char [5][5], Key);

void toUpperString(char *);

char *removeCharFromMessage(char, char *);

char *toAlphaMessage(char *);

Coordinates findCoordinates(char, char[5][5]);

char *digraphMessage(char *, char);

char *encodeMessage(char *, char [5][5]);

char *decodeMessage(char *, char[5][5]);

#endif //PROGETTOLSO_PLAYFAIRUTILITIES_H
