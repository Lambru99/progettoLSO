//
// Created by Paolo on 15/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "FileReader.h"

void readFile(char *fileStr){
    Key key;
    FILE *fReader;
    fReader = fopen(fileStr, "r");
    if(fReader == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }


    fclose(fReader);
}