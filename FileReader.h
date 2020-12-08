//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_FILEREADER_H
#define PROGETTOLSO_FILEREADER_H

#include "KeyStruct.h"

long getFileSize(FILE *);

int countFileLines(FILE *);

char *loadMessage(char *);

FILE *openFile(char *);

Key getKeyInfo(char *);

#endif //PROGETTOLSO_FILEREADER_H