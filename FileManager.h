//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_FILEMANAGER_H
#define PROGETTOLSO_FILEMANAGER_H

#include <stdio.h>

#include "KeyStruct.h"

FILE *openFile(char *);

long getFileSize(FILE *);

//int countFileLines(FILE *);

char *loadMessage(char *);

void saveMessage(char *, char *);

Key getKeyInfo(char *);

#endif //PROGETTOLSO_FILEMANAGER_H