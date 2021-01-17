//
// Created by Paolo on 15/11/2020.
//

#include <stdlib.h>
#include <string.h>

#include "PlayfairCipher.h"
#include "PlayfairUtilities.h"
#include "FileManager.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "StringManager.h"

void encode(Key key, char matrix[5][5], char *outputDir, char *messageDir) {
    FILE *fReader = openFileToRead(messageDir);
    long fSize = getFileSize(fReader);

    while (fSize > 0) {
        char *message, *cleanedMessage, *digraphedMessage, *fixedDigraphedMessage, *encodedMessage;
        long nChar = (BUFFER < fSize) ? BUFFER : fSize;

        message = loadMessage(fReader, nChar);

        fSize -= nChar;

        cleanedMessage = toAlphaString(message);
        free(message);

        toUpperString(cleanedMessage);

        digraphedMessage = digraphMessage(cleanedMessage, key.specialChar);
        free(cleanedMessage);

        if (strlen(digraphedMessage) % 2 != 0) {
            fixedDigraphedMessage = fixDigraphedMessage(fReader, digraphedMessage, key.specialChar, &fSize);
            free(digraphedMessage);

            encodedMessage = encodeMessage(fixedDigraphedMessage, matrix);
            free(fixedDigraphedMessage);
        } else {
            encodedMessage = encodeMessage(digraphedMessage, matrix);
            free(digraphedMessage);
        }

        saveMessage(encodedMessage, outputDir, messageDir, ".pf");

        free(encodedMessage);
    }

    fclose(fReader);
}

void decode(Key key, char matrix[5][5], char *outputDir, char *messageDir) {
    FILE *fReader = openFileToRead(messageDir);
    long fSize = getFileSize(fReader);

    while (fSize > 0) {
        char *message, *cleanedMessage, *decodedMessage, *fixedMessage;
        long nChar = (BUFFER < fSize) ? BUFFER : fSize;

        message = loadMessage(fReader, nChar);

        if (nChar == BUFFER) {
            fSize -= nChar + 1;
            fgetc(fReader);
        } else
            fSize -= nChar;

        cleanedMessage = removeCharFromString(' ', message);
        free(message);

        decodedMessage = decodeMessage(cleanedMessage, matrix);
        free(cleanedMessage);

        fixedMessage = removeCharFromString(key.specialChar, decodedMessage);
        free(decodedMessage);

        saveMessage(fixedMessage, outputDir, messageDir, ".dec");

        free(fixedMessage);
    }

    fclose(fReader);
}