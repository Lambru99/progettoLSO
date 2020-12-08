//
// Created by Paolo on 21/11/2020.
//

#ifndef PROGETTOLSO_KEYSTRUCT_H
#define PROGETTOLSO_KEYSTRUCT_H

typedef struct {
    char alphabet[26];
    char missingChar;
    char specialChar;
    char *key;
} Key;

#endif //PROGETTOLSO_KEYSTRUCT_H