#include <stdio.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPFileHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t x_pixels_per_m;
    int32_t y_pixels_per_m;
    uint32_t colors_used;
    uint32_t colors_important;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} BMPPixel;
#pragma pack(pop)

static int process(const char* filename) {
    FILE* fp = fopen(filename, "r+b");
    if (!fp) {
        return -1;
    }

    BMPFileHeader file_header;
    BMPInfoHeader info_header;
    fread(&file_header, sizeof(BMPFileHeader), 1, fp);
    fread(&info_header, sizeof(BMPInfoHeader), 1, fp);

    if (file_header.type != 0x4D42 || info_header.bit_count != 24) {
        fclose(fp);
        return -1;  // unsupported file
    }

    BMPPixel white = { 0, 0, 0 };
    for (int i = 0; i < info_header.width; ++i) {
        fseek(fp, file_header.offset_data + i*info_header.width*3 + i*3, SEEK_SET);
        fwrite(&white, sizeof(BMPPixel), 1, fp);

        fseek(fp, file_header.offset_data + i*info_header.width*3 + (info_header.width - i - 1)*3, SEEK_SET);
        fwrite(&white, sizeof(BMPPixel), 1, fp);
    }

    fclose(fp);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return -1;
    }

    return process(argv[1]);
}