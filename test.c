#include <stdlib.h>
#include <stdio.h>

#pragma pack(1)
typedef struct BMPHeader {
    unsigned char ID[2];
    unsigned int file_size;
    unsigned char unused[4];
    unsigned int pixel_offset;
} BMPHeader;

typedef struct DIBHeader {
    unsigned int header_size;
    unsigned int width;
    unsigned int height;
    unsigned short color_planes;
    unsigned short bits_per_pixel;
    unsigned int BI_RGB;
    unsigned int data_size;
    unsigned int pwidth;
    unsigned int pheight;
    unsigned int colors_count;
    unsigned int imp_colors_count;
} DIBHeader;

typedef struct BMPFile {
    BMPHeader bhdr;
    DIBHeader dhdr;
    unsigned char* data;
} BMPFile;
#pragma pop;


BMPFile* loadBMPFile(char* fname) {
    FILE* fp = fopen(fname, "r");
    if (!fp) {
        print("Err");
        exit(0);
    };

    BMPFile* bmp_file = (BMPFile*)malloc(sizeof(BMPFile));
    fread(bmp_file, sizeof(bmp_file), 1, fp);
    fclose(fp);
    return bmp_file;
}
void freeBMPFile(BMPFile* bmp_file) {
    if (bmp_file) {
        free(bmp_file);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Err");
        return 0;
    }

    BMPFile* bmpf = loadBMPFile(argv[1]);
    printf();
    return 0;
}