
#ifndef PROGETTOLSO_PLAYFAIR_H
#define PROGETTOLSO_PLAYFAIR_H

#endif //PROGETTOLSO_PLAYFAIR_H

struct KeyFile {
    char alphabet[26];
    char missingCharacter;
    char specialCharacter;
    char *key;
};

void init(struct KeyFile keyFile, char *);

const char *getMatrixText(struct KeyFile keyFile);

char **buildMatrix(const char *);

char *getFixedMessage(char *, char);

char *removeNotAlphaChar(char *);

char *addSpecialChar(char *, char);

unsigned int countSpecialChar(char *);

unsigned int countDoubles(char *);