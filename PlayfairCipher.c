//
// Created by Paolo on 15/11/2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "PlayfairCipher.h"
#include "FileReader.h"

void initializeCipher(char *keyPath, char *dirPath) {
    Key key = getKeyInfo(keyPath);
    DirList dirList = getDirectoriesFileList(dirPath);

    encode(key, dirList);

    freeInfo(key, dirList);
}

void encode(Key key, DirList dirList) {
    size_t listSize = getLength(dirList);

    for (int i = 0; i < listSize; i++) {
        printf("%s\n", getItem(dirList, i));
    }
}

void freeInfo(Key key, DirList dirList) {
    free(key.alphabet);
    free(key.key);
    destroyList(&dirList);
}