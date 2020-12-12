//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_PLAYFAIRCIPHER_H
#define PROGETTOLSO_PLAYFAIRCIPHER_H

#include "KeyStruct.h"

extern const int row;
extern const int col;

char **initMatrix();

void fillMatrix(char [row][col], Key);

char *cleanMessage(char *);

char *digraphMessage(char *, char);

void encode(Key, char *);

void decode(Key, char *);

#endif //PROGETTOLSO_PLAYFAIRCIPHER_H