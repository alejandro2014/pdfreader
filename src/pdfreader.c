#include "pdfreader.h"

int main() {
    PDFFile *pdf = openPdf("doc/reserva.pdf");
    printPdf(pdf);
    closePdf(pdf);
    return 0;
}

void printPdf(PDFFile *pdf) {
    printf("%s", pdf->content);
}

PDFFile *openPdf(char *filePath) {
    FILE *file = fopen(filePath, "rb");

    if (! file) {
        printf("[Error] Cannot open file %s\n", filePath);
        return NULL;
    }

    PDFFile *pdf = (PDFFile *) malloc(sizeof(PDFFile));
    pdf->size = getFileSize(file);
    pdf->content = (char *) malloc(pdf->size * sizeof(char));
    fread(pdf->content, sizeof(char), pdf->size, file);
    //memcpy(pdf->content, file, pdf->size);
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
