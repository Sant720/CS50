#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int JPEG_count = 0;

bool is_JPEG(unsigned char bytes[]);

int main(int argc, char *argv[])
{
    // Open memory card
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if (!card)
    {
        printf("Can't open file\n");
        return 1;
    }

    // Declare and assign variables to use in while loop
    unsigned char bytes[512];
    FILE *new_image = NULL;
    char *filename = malloc(8);
    int block = 512;

    // Loop while size of block is 512. Last block will have less files to read.
    while (block == 512)
    {
        block = fread(bytes, 1, block, card);

        if (is_JPEG(bytes) == true)
        {
            // First image will not need to close any image
            if (JPEG_count == 0)
            {
                sprintf(filename, "%03i.jpg", JPEG_count);
                new_image = fopen(filename, "w");

                fwrite(bytes, 1, block, new_image);
                JPEG_count++;
            }

            else
            {
                // Close previous image and free memory
                fclose(new_image);
                free(filename);

                // Start new image
                filename = malloc(8);
                sprintf(filename, "%03i.jpg", JPEG_count);
                new_image = fopen(filename, "w");

                fwrite(bytes, 1, block, new_image);
                JPEG_count++;
            }
        }

        // Keep writing to current image if no new image
        else
        {
            if (JPEG_count > 0)
            {
                fwrite(bytes, 1, block, new_image);
            }
        }
    }

    // Close any remaining files
    free(filename);
    fclose(card);
    return 0;
}


bool is_JPEG(unsigned char bytes[])
{
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}