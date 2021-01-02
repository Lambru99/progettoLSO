//
// Created by Paolo on 15/11/2020.
//

#ifndef PROGETTOLSO_PLAYFAIRCIPHER_H
#define PROGETTOLSO_PLAYFAIRCIPHER_H

#include "KeyStruct.h"

#define ROW 5
#define COL 5

//typedef struct {
//    int X;
//    int Y;
//} Coordinates;
//
//void fillMatrix(char [5][5], Key);
//
//char *cleanMessage(char *);
//
//char *digraphMessage(char *, char);
//
//char *encodeMessage(char *, char matrix[ROW][COL]);
//
//char *decodeMessage(char *, char matrix[ROW][COL], char);
//
//Coordinates findCoordinates(char, char[ROW][COL]);
//
//char encodeSameRow(Coordinates, char[ROW][COL]);
//
//char encodeSameCol(Coordinates, char[ROW][COL]);
//
//char decodeSameRow(Coordinates, char[ROW][COL]);
//
//char decodeSameCol(Coordinates, char[ROW][COL]);
//
//char *specialCharRemover(char *, char);

char *encode(Key, char [5][5], char *);

char *decode(Key, char [5][5], char *);

#endif //PROGETTOLSO_PLAYFAIRCIPHER_H