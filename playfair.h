
#ifndef PROGETTOLSO_PLAYFAIR_H
#define PROGETTOLSO_PLAYFAIR_H

#endif //PROGETTOLSO_PLAYFAIR_H

void init(struct KeyFile, char *);

int getRow(char, char **);

int getColumn(char, char **);

void *encode(struct KeyFile, char *);

void *decode(struct KeyFile, char *);