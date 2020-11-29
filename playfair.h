
#ifndef PROGETTOLSO_PLAYFAIR_H
#define PROGETTOLSO_PLAYFAIR_H

#endif //PROGETTOLSO_PLAYFAIR_H

struct KeyFile {
    char alphabet[26];
    char missingCharacter;
    char specialCharacter;
    char *key;
};

void init(struct KeyFile keyFile, char *message);

const char *buildTableText(struct KeyFile);

char **buildMatrix(const char *);

char *fixMessage(char *, struct KeyFile);