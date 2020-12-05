
#include <stdio.h>
#include "fileWriter.h"

void printMessageOnFile(char *path, char *message) {
    FILE *in = fopen(path, "w");
    fprintf(in, "%s", message);
    fclose(in);
}