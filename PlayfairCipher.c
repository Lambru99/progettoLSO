//
// Created by Paolo on 15/11/2020.
//

#include <stdio.h>

#include "PlayfairCipher.h"
#include "FileReader.h"

void initializeCipher(char *dirPath) {
    Key key = getKeyFile(dirPath);
    printf("Alfabeto: %s.\nCarattere mancante: %c.\nCarattere speciale: %c.\nChiave: %s.", key.alphabet,
           key.missingChar,
           key.specialChar, key.key);
}