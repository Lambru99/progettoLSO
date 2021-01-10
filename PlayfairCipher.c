//
// Created by Paolo on 15/11/2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "PlayfairCipher.h"
#include "PlayfairUtilities.h"
#include "FileReader.h"
#include "FileWriter.h"

void encode(Key key, char matrix[5][5], char *outputDir, char *messageDir) {
    FILE *fReader = openFile(messageDir);
    long fSize = getFileSize(fReader);

    while (fSize > 0) {
        char *message;
        char *cleanedMessage;
        char *digraphedMessage;
        char *encodedMessage;

        if (BUFFER < fSize) {
            message = loadMessage(fReader, BUFFER);

            fSize -= BUFFER;

            cleanedMessage = cleanMessage(message);
            free(message);

            toUpperString(cleanedMessage);

            digraphedMessage = digraphMessage(cleanedMessage, key.specialChar);
            free(cleanedMessage);

            char *fixedDigraphedMessage = fixDigraphedMessage(fReader, digraphedMessage, key.specialChar, &fSize);
            free(digraphedMessage);

            encodedMessage = encodeMessage(fixedDigraphedMessage, matrix);
            free(fixedDigraphedMessage);

            saveMessage(encodedMessage, outputDir, messageDir, ".pf");

            free(encodedMessage);
        } else {
            message = loadMessage(fReader, fSize);

            fSize -= fSize;

            cleanedMessage = cleanMessage(message);
            free(message);

            toUpperString(cleanedMessage);

            digraphedMessage = digraphMessage(cleanedMessage, key.specialChar);
            free(cleanedMessage);

            encodedMessage = encodeMessage(digraphedMessage, matrix);
            free(digraphedMessage);

            saveMessage(encodedMessage, outputDir, messageDir, ".pf");

            free(encodedMessage);
        }
    }

    fclose(fReader);
}

void decode(Key key, char matrix[5][5], char *outputDir, char *messageDir) {
    FILE *fReader = openFile(messageDir);
    long fSize = getFileSize(fReader);

    while (fSize > 0) {
        char *message;
        char *cleanedMessage;
        char *decodedMessage;
        char *fixedMessage;

        if (BUFFER < fSize) {
            message = loadMessage(fReader, BUFFER);
            fgetc(fReader);

            fSize -= BUFFER + 1;

            cleanedMessage = removeCharFromMessage(' ', message);
            free(message);

            decodedMessage = decodeMessage(cleanedMessage, matrix);
            free(cleanedMessage);

            fixedMessage = removeCharFromMessage(key.specialChar, decodedMessage);
            free(decodedMessage);

            saveMessage(fixedMessage, outputDir, messageDir, ".dec");

            free(fixedMessage);
        } else {
            message = loadMessage(fReader, fSize);

            fSize -= fSize;

            cleanedMessage = removeCharFromMessage(' ', message);
            free(message);

            decodedMessage = decodeMessage(cleanedMessage, matrix);
            free(cleanedMessage);

            fixedMessage = removeCharFromMessage(key.specialChar, decodedMessage);
            free(decodedMessage);

            saveMessage(fixedMessage, outputDir, messageDir, ".dec");

            free(fixedMessage);
        }
    }

    fclose(fReader);
}