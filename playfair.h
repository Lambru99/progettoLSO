
#ifndef PROGETTOLSO_PLAYFAIR_H
#define PROGETTOLSO_PLAYFAIR_H

#endif //PROGETTOLSO_PLAYFAIR_H

void init(struct KeyFile, char *);

int getRow(char, char **);

int getColumn(char, char **);

char *encode(struct KeyFile, char *);

char* decode(struct KeyFile, char *);