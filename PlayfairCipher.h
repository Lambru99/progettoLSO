//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_PLAYFAIRCIPHER_H
#define PROGETTOLSO_PLAYFAIRCIPHER_H

#include "KeyStruct.h"

#define BUFFER 5000

void encode(Key, char [5][5], char *, char *);

void decode(Key, char [5][5], char *, char *);

#endif //PROGETTOLSO_PLAYFAIRCIPHER_H