#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the file using RLE================
void compressFILE(FILE *inputFILE, FILE *outputFILE) {
    int currentChar, prevChar;
    int count = 1;

    prevChar = fgetc(inputFILE);
    if (prevChar == EOF) {
        return;
    }

    while ((currentChar = fgetc(inputFILE)) != EOF) { 
        if (currentChar == prevChar) {
            count++;
        } else {
            fprintf(outputFILE, "%d%c", count, prevChar);
            prevChar = currentChar;  
            count = 1;
        }
    }
    fprintf(outputFILE, "%d%c", count, prevChar);
}

// Function to decompress the file using RLE
void decompressFile(FILE *inputFILE, FILE *outputFILE) {
    int count;
    char ch;
    while (fscanf(inputFILE, "%d%c", &count, &ch) == 2) {  
        for (int i = 0; i < count; i++) {
            fputc(ch, outputFILE);
        }
    }
}

// Main function for input and output file handling
int main() {
    FILE *inputFILE, *outputFILE;
    char inputFileName[100], outputFileName[100];
    char ans;

    printf("Do you want to compress or decompress?\n");
    printf("Write c for compression and d for decompression \n");
    scanf(" %c", &ans);  

    // Compression
    if (ans == 'c') {
        printf("Enter the input file name for compression: \n");
        scanf("%s", inputFileName);
        inputFILE = fopen(inputFileName, "r");
        if (inputFILE == NULL) {
            printf("Couldn't open the input file.\n"); 
            return 1;
        }

        printf("Enter the output file name for compression: ");
        scanf("%s", outputFileName);
        outputFILE = fopen(outputFileName, "w");
        if (outputFILE == NULL) {
            printf("Could not open the output file.\n");
            fclose(inputFILE);
            return 1;
        }

        compressFILE(inputFILE, outputFILE);
        printf("File compressed successfully!\n");
        fclose(inputFILE);
        fclose(outputFILE);
    } else if (ans == 'd') {
        // Decompression
        printf("Enter the input file name for decompression: ");
        scanf("%s", inputFileName);
        inputFILE = fopen(inputFileName, "r");

        if (inputFILE == NULL) {
            printf("Could not open the input file.\n");
            return 1;
        }

        printf("Enter the output file name for decompression: ");
        scanf("%s", outputFileName);
        outputFILE = fopen(outputFileName, "w");

        if (outputFILE == NULL) {
            printf("Could not open the output file.\n");
            fclose(inputFILE);
            return 1;
        }

        decompressFile(inputFILE, outputFILE);
        printf("File decompressed successfully!\n");
        fclose(inputFILE);
        fclose(outputFILE);
    } else {
        printf("Input Error\n");
    }

    return 0;
}
