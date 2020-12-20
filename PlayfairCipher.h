//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_PLAYFAIRCIPHER_H
#define PROGETTOLSO_PLAYFAIRCIPHER_H

#include "KeyStruct.h"
//#include "Utilities.h"

//extern const int row;
//extern const int col;

#define ROW 5
#define COL 5

typedef struct {
    int X;
    int Y;
} Coordinates;

void fillMatrix(char [ROW][COL], Key);

char *cleanMessage(char *);

char *digraphMessage(char *, char);

Coordinates findCoordinates(char, char[ROW][COL]);

char encodeSameRow(Coordinates, char[ROW][COL]);

char encodeSameCol(Coordinates, char[ROW][COL]);

char *encode(Key, char[ROW][COL], char *);

void decode(Key, char[ROW][COL], char *);

#endif //PROGETTOLSO_PLAYFAIRCIPHER_H