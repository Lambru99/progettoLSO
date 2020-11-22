//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_FILEREADER_H
#define PROGETTOLSO_FILEREADER_H

#include "KeyStruct.h"

long getFileSize(FILE *);

int countFileLines(FILE *);

char *loadFile(char *);

FILE *openFile(char *);

Key getKeyFile(char *);

char *readMessageFile(char *);

#endif //PROGETTOLSO_FILEREADER_H