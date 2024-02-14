#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int HEADER_SIZE = 44;

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse infile outfile\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *infile = argv[1];
    char *outfile = argv[2];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }
    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    check_format(header);

    // Open output file for writing
    // TODO #5
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 1;
    }
    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);
    // printf("block: %i\n", block_size);

    // Write reversed audio to file
    // TODO #8
    long current_index = ftell(inptr);

    // get file size
    fseek(inptr, 0, SEEK_END);
    long fileSize = ftell(inptr);
    fseek(inptr, -block_size, SEEK_CUR);
    // printf("The pointer is at: %ld bytes  Current Index: %ld\n", fileSize, current_index);
    if (fileSize == -1)
    {
        perror("Error getting file size");
        return 1;
    }

    int buffer[block_size];
    for (int i = 0, s = (fileSize - HEADER_SIZE + 1) / block_size; i < s; i++)
    {
        fread(&buffer, block_size, 1, inptr);
        fwrite(&buffer, block_size, 1, outptr);
        fseek(inptr, -block_size * 2, SEEK_CUR);

        current_index = ftell(inptr);

        // printf("The pointer is at: %ld bytes\n", current_index);
    }

    // printf("The file size is: %ld bytes  Current Index: %ld\n", fileSize, current_index);

    fclose(inptr);
    fclose(outptr);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE wave[4] = {87, 65, 86, 69};
    for (int i = 0, s = sizeof(header.format); i < s; i++)
    {
        if (header.format[i] != wave[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * header.bitsPerSample / 8;
    return block_size;
}
