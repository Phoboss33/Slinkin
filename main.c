#include <stdio.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int file_size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_data;
} BMPFileHeader;

typedef struct {
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bit_count;
    unsigned int compression;
    unsigned int size_image;
    unsigned short x_pixels_per_m;
    unsigned short y_pixels_per_m;
    unsigned int colors_used;
    unsigned int colors_important;
} BMPInfoHeader;

typedef struct {
    unsigned short blue;
    unsigned short green;
    unsigned short red;
} BMPPixel;
#pragma pack(pop)


int main(int argc, char* argv[]) {
    if (argc != 2) {
        return -1;
    }

    FILE* img = fopen(argv[1], "rb+");
    if (!img) {
        return -1;
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;
    fread(&file_header, sizeof(BMPFileHeader), 1, img);
    fread(&info_header, sizeof(BMPInfoHeader), 1, img);
    
    unsigned short b, g, r;
    
    printf("b g r: ");
    scanf("%c", &b, &g, &r);
    BMPPixel pixel = { b, g, r};
    for (int i = 0;i < info_header.width;i++) {
        fseek(img, file_header.offset_data + (i * info_header.width + i) * 3, SEEK_SET);
        fwrite(&pixel, sizeof(BMPPixel), 1, img);

        fseek(img, file_header.offset_data + (i * info_header.width + info_header.width - i - 1) * 3, SEEK_SET);
        fwrite(&pixel, sizeof(BMPPixel), 1, img);
    }

    int y = info_header.width / 2;
    int x = info_header.height / 2;

    /*for (int i = 0;i < 5;i++) {
        fseek(img, file_header.offset_data + ((y + 4) * info_header.width + (x + i)) * 3, SEEK_SET);
        fwrite(&pixel, sizeof(BMPPixel), 1, img);

        fseek(img, file_header.offset_data + ((y + 4 - i) * info_header.width + (x)) * 3, SEEK_SET);
        fwrite(&pixel, sizeof(BMPPixel), 1, img);

        fseek(img, file_header.offset_data + ((y) * info_header.width + (x + i)) * 3, SEEK_SET);
        fwrite(&pixel, sizeof(BMPPixel), 1, img);
        
        fseek(img, file_header.offset_data + ((y + i) * info_header.width + (x + 5)) * 3, SEEK_SET);
        fwrite(&pixel, sizeof(BMPPixel), 1, img);
    }*/
    

    fclose(img);

    return 0;
}