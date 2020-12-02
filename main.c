#include <stdio.h>
#include <string.h>
#include "fileReader.h"
#include "playfair.h"

int main() {
    struct KeyFile keyFile = readKeyFile();
    char *message = readMessage();

    init(keyFile, message);
    encode(keyFile, message);

    return 0;
}
