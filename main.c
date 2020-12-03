#include <stdio.h>
#include <string.h>
#include "fileReader.h"
#include "playfair.h"

int main() {
    struct KeyFile keyFile = readKeyFile("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\keyfile.txt");
    char *message = readMessage("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\message.txt");

    init(keyFile, message);
    encode(keyFile, message);

    char *encodedMessage = readMessage("C:\\Users\\Tommy\\Documents\\CLion Workspace\\progettoLSO\\encodedMessage.txt");
    decode(keyFile, encodedMessage);

    return 0;
}
