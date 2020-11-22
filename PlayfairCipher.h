//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_PLAYFAIRCIPHER_H
#define PROGETTOLSO_PLAYFAIRCIPHER_H

#include "KeyStruct.h"

void initializeCipher(char *);

void encode(Key key);

void decode(Key key);

#endif //PROGETTOLSO_PLAYFAIRCIPHER_H