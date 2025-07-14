#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for valid usage of command line arguments
    if (argc != 2)
    {
        printf("Incorrect usage. (./recover <file>)\n");
        return 1;
    }

    // Check if file is found
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Couldn't open file.\n");
        free(file);
        fclose(file);
        return 1;
    }

    // File name format
    int nameNumber = 0;
    char *name = malloc(8);

    const int block_Size = 512;

    // Buffer for storing data of blocks within memory
    typedef uint8_t BYTE;

    BYTE *buffer = malloc(block_Size);

    bool JPEG = false;
    BYTE signature[3] = {0xff, 0xd8, 0xff};
    BYTE signature_4[] = {0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};

    FILE *currentFile = NULL;
    FILE *oldFile = NULL;
    // Reads every byte in memory (returning an integar value) & stores in buffer[] array
    // Returns number of items read, so loop stops when number != block_size

    // Iterates every time buffer is filled with a block of memory
    while (fread(buffer, 1, block_Size, file) == block_Size)
    {
        // Identify if signature found
        if (buffer[0] == signature[0] && buffer[1] == signature[1] && buffer[2] == signature[2])
        {
            for (int n = 0; n < 16; n++)
            {
                if (buffer[3] == signature_4[n])
                {
                    JPEG = true;
                }
                else
                {
                    break;
                }
            }
            // Signature FOUND
            if (JPEG == true)
            {
                if (nameNumber < 10)
                    sprintf(name, "00%i.jpg", nameNumber);
                else if (nameNumber < 100)
                    sprintf(name, "0%i.jpg", nameNumber);
                else
                    sprintf(name, "%i.jpg", nameNumber);

                // CLOSES old file
                if (currentFile != NULL)
                {
                    fclose(currentFile);
                }

                // OPENS file of new name, to write
                currentFile = fopen(name, "w");
                nameNumber++;
                // Writes data from within block
                fwrite(buffer, 1, block_Size, currentFile);
            }
        }
        // Signature NOT FOUND
        else
        {
            // If WITHIN another block, file continued
            if (currentFile != NULL)
            {
                fwrite(buffer, 1, block_Size, currentFile);
                printf("File found.\n");
            }
            // If not a JPEG file
            else
            {
                printf("File not found.\n");
            }
        }
        JPEG = false;
    }
    // FREE MEMORY
    // Variables
    free(name);
    free(buffer);
    // Files (file reading to, file writing to)
    fclose(currentFile);
    fclose(file);
}