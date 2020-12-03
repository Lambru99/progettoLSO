#include <stdio.h>
#include <string.h>
#include "fileReader.h"
#include "playfair.h"

int main() {
    struct KeyFile keyFile = readKeyFile("/Users/leo/Documents/GitHub/progettoLSO/keyfile.txt");
    char *message = readMessage("/Users/leo/Documents/GitHub/progettoLSO/message.txt");
    char *encodedMessage = readMessage("/Users/leo/Documents/GitHub/progettoLSO/encodedMessage.txt");


    init(keyFile, message);
    printf("\nencodedMessage: %s", encode(keyFile, message));
    printf("\ndecodedMessage: %s", decode(keyFile, encodedMessage));



    return 0;
}
