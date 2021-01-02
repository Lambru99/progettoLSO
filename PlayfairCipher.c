//
// Created by Paolo on 15/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "PlayfairCipher.h"
#include "FileReader.h"
#include "PlayfairUtilities.h"

char *encode(Key key, char matrix[5][5], char *message) {
    //Trasferire tutte le chiamate dei metodi dentro encodeMessage?
    toUpperString(message);

    message = toAlphaMessage(message);
    message = digraphMessage(message, (char) toupper(key.specialChar));
    message = encodeMessage(message, matrix);
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            printf("%c ", matrix[i][j]);
//        }
//        printf("\n");
//    }

    return message;
}

char *decode(Key key, char matrix[5][5], char *message) {
    //Trasferire removeCharFromMessage dentro decodeMessage?
    message = decodeMessage(message, matrix);
    message = removeCharFromMessage((char) toupper(key.specialChar), message);

    return message;
}