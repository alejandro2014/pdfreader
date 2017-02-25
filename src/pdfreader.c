#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    unsigned char *content;
} PDFFile;

PDFFile *openPdf(char *filePath);
void closePdf(PDFFile *pdf);
long int getFileSize(FILE *file);

int main() {
    PDFFile *pdf = openPdf("doc/reserva.pdf");
    closePdf(pdf);
    return 0;
}

PDFFile *openPdf(char *filePath) {
    FILE *file = fopen(filePath, "rb");

    if (! file) {
        printf("[Error] Cannot open file %s\n", filePath);
        return NULL;
    }

    PDFFile *pdf = (PDFFile *) malloc(sizeof(PDFFile));
    pdf->size = getFileSize(file);
    pdf->content = (unsigned char *) malloc(pdf->size * sizeof(unsigned char));
    memcpy(pdf->content, file, pdf->size);
    fclose(file);

	return pdf;
}

void closePdf(PDFFile *pdf) {
    if(! pdf) return;

    free(pdf->content);
    free(pdf);
}

long int getFileSize(FILE *file) {
	long int end = 0;

	fseek(file, 0, SEEK_END);
	end = ftell(file);
	fseek(file, 0, SEEK_SET);

	return end;
}
