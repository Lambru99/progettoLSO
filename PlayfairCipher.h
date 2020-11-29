//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_PLAYFAIRCIPHER_H
#define PROGETTOLSO_PLAYFAIRCIPHER_H

#include "KeyStruct.h"
#include "DirList.h"

void initializeCipher(char *, char *);

void encode(Key, DirList);

void decode(Key, DirList);

void freeInfo(Key, DirList);

#endif //PROGETTOLSO_PLAYFAIRCIPHER_H