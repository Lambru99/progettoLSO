//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_FILEREADER_H
#define PROGETTOLSO_FILEREADER_H

#include "KeyStruct.h"
#include "DirList.h"

int getFileSize(FILE *);

int countFileLines(FILE *);

char *loadFile(char *);

FILE *openFile(char *);

Key getKeyInfo(char *);

DirList getDirectoriesFileList(char *);

#endif //PROGETTOLSO_FILEREADER_H