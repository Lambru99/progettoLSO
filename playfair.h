
#ifndef PROGETTOLSO_PLAYFAIR_H
#define PROGETTOLSO_PLAYFAIR_H

#endif //PROGETTOLSO_PLAYFAIR_H

struct KeyFile {
    char alphabet[26];
    char missingCharacter;
    char specialCharacter;
    char *key;
};

void buildMatrix(struct KeyFile);