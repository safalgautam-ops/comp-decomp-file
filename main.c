#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to compress the file using RLE
void compressFILE(FILE *inputFILE, FILE *outputFILE) {
    int currentChar, prevChar;
    int count = 1;

    prevChar = fgetc(inputFILE);
    if(prevChar == EOF) {
        return;
    }

    while ((currentChar == fgetc(inputFILE))!=EOF) {
        if (currentChar == prevChar) {
            count ++;
        } else {
            fprintf(outputFILE, "%d%c", count,prevChar);
            prevChar == currentChar;
            count = 1;
        }
    }
    fprintf(outputFILE,"%d%c",count, prevChar);
}