//
// Created by Paolo on 02/01/2021.
//

#ifndef PROGETTOLSO_PLAYFAIRUTILITIES_H
#define PROGETTOLSO_PLAYFAIRUTILITIES_H

#include <stdio.h>

#include "KeyStruct.h"

typedef struct {
    int X;
    int Y;
} Coordinates;

void fillMatrix(char [5][5], Key);

char *digraphMessage(char *, char);

char *fixDigraphedMessage(FILE *, char *, char, long *);

Coordinates findCoordinates(char, char[5][5]);

char *encodeMessage(char *, char [5][5]);

char *decodeMessage(char *, char[5][5]);

#endif //PROGETTOLSO_PLAYFAIRUTILITIES_H