#include <stdio.h>
#include <string.h>
#include "fileReader.h"
#include "fileWriter.h"
#include "playfair.h"

void printInfo() {
    printf("playfair <encode|decode> <keyfile> <outputdir> <file1> ... <filen>\n");
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Wrong number of parameters (expected minimum 5, are %d)!\n\n", argc);
        printInfo();
        return -1;
    }
    if (strcmp(argv[1], "encode") == 0) {
        for (int i = 4; i < argc; i++) {
            printMessageOnFile(generateFileNamePath(argv[3], extractFileName(argv[i]), ".pf"),
                               encode(readKeyFile(argv[2]), readMessage(argv[i])));
        }
        return 0;
    }
    if (strcmp(argv[1], "decode") == 0) {
        for (int i = 4; i < argc; i++) {
            printMessageOnFile(generateFileNamePath(argv[3], extractFileName(argv[i]), ".dec"),
                               decode(readKeyFile(argv[2]), readMessage(argv[i])));
        }
        return 0;
    }
    printf("Unknown command %s!\n", argv[1]);
    printInfo();

//    init(readKeyFile("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\keyfile.txt"),
//         readMessage("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\encode_outputDir\\message3.pf"));
//
//    printMessageOnFile(
//            generateFileNamePath("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\decode_outputDir",
//                                 extractFileName(
//                                         "C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\encode_outputDir\\message3.pf"),
//                                 ".dec"),
//            decode(readKeyFile("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\keyfile.txt"),
//                   readMessage(
//                           "C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\encode_outputDir\\message3.pf")));
//
//
//    char *message = readMessage(
//            "C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\messagesToDecode\\message3.pf");
//    struct KeyFile keyFile = readKeyFile("C:\\Users\\Tommy\\Documents\\CLion_Workspace\\progettoLSO\\keyfile.txt");
//    printf("decoded message: %s", decode(keyFile, message));


//    creaFiledi10kb();
//    creaFiledi1mb();
//    creaFiledi10mb();
    return 0;
}