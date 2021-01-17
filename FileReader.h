//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_FILEREADER_H
#define PROGETTOLSO_FILEREADER_H

#include <stdio.h>

#include "KeyStruct.h"

long getFileSize(FILE *);

char *loadMessage(FILE *, long);

char getLastCharFromFile(char *);

Key getKeyInfo(char *);

#endif //PROGETTOLSO_FILEREADER_H