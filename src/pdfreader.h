#ifndef PDFREADER_H
#define PDFREADER_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct {
        int size;
        char *content;
    } PDFFile;

    PDFFile *openPdf(char *filePath);
    void closePdf(PDFFile *pdf);
    long int getFileSize(FILE *file);

    void printPdf(PDFFile *pdf);
#endif
