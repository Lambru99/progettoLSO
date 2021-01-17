//
// Created by Paolo on 17/01/2021.
//

#ifndef PROGETTOLSO_STRINGMANAGER_H
#define PROGETTOLSO_STRINGMANAGER_H

char *allocateString(size_t);

char *reallocateString(char *, size_t);

void toUpperString(char *);

char *removeCharFromString(char, char *);

char *toAlphaString(char *);

#endif //PROGETTOLSO_STRINGMANAGER_H