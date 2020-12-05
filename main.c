#include <stdio.h>
#include <string.h>
#include "fileReader.h"
#include "playfair.h"

void printInfo() {
    printf("playfair encode <keyfile> <file1>\n");
}

int main(int argc, char **argv) {
//    struct KeyFile keyFile = readKeyFile("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\keyfile.txt");
//    char *message = readMessage("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\message.txt");
//
//    init(keyFile, message);
//    encode(keyFile, message);
//
//    char *encodedMessage = readMessage("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\encodedMessage.pf");
//    decode(keyFile, encodedMessage);
//
//    return 0;


//    if (argc != 4) {
//        printf("Wrong number of parameters (expected 4 are %d)!\n\n", argc);
//        printInfo();
//        return -1;
//    }
    if (strcmp(argv[1], "encode")==0) {
        encode(readKeyFile(argv[2]), readMessage(argv[3]));
        return 0;
    }
    if (strcmp(argv[1], "decode")==0) {
        decode(readKeyFile(argv[2]), readMessage(argv[3]));
        return 0;
    }
    printf("Unknown command %s!\n",argv[1]);
    printInfo();
}
