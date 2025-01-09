#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

FILE *openInput(int argc, char *argv[]);
BYTE *newBuffer(int size);
int readNewBlock(FILE *input, BYTE *buffer, int size);
int isNewBlock(BYTE *buffer);
FILE *createNewOutputFile(int *file_counter);
int writeBlockToFile(BYTE *buffer, int size, FILE *output);

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Setup
    FILE *input = openInput(argc, argv);
    BYTE *buffer = newBuffer(BLOCK_SIZE);
    int file_counter = 0;
    FILE *output = NULL;
    bool start_of_files = false;

    while (readNewBlock(input, buffer, BLOCK_SIZE) != 0)
    {
        if (isNewBlock(buffer) == 0 && !start_of_files)
        {
            start_of_files = true;
        }

        if (isNewBlock(buffer) == 0 && start_of_files)
        {
            if (output != NULL)
            {
                fclose(output);
            }
            output = createNewOutputFile(&file_counter);
            writeBlockToFile(buffer, BLOCK_SIZE, output);
        }

        if (isNewBlock(buffer) == 1 && start_of_files)
        {
            writeBlockToFile(buffer, BLOCK_SIZE, output);
        }
    }

    printf("%i files created\n", file_counter);

    free(buffer);
    fclose(input);
    if (output != NULL)
    {
        fclose(output);
    }

    return 0;
}

FILE *openInput(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover input.raw\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("input: %s could not be opened\n", argv[1]);
        exit(1);
    }

    return input;
}

BYTE *newBuffer(int size)
{
    BYTE *buffer = malloc(size);
    if (buffer == NULL)
    {
        printf("buffer could not be initialised\n");
        exit(1);
    }

    return buffer;
}

int readNewBlock(FILE *input, BYTE *buffer, int size)
{
    return fread(buffer, sizeof(*buffer), size, input);
}

int isNewBlock(BYTE *buffer)
{
    bool byte_a = buffer[0] == 0xff;
    bool byte_b = buffer[1] == 0xd8;
    bool byte_c = buffer[2] == 0xff;
    bool byte_d = (buffer[3] & 0xf0) == 0xe0;

    if (byte_a && byte_b && byte_c && byte_d)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

FILE *createNewOutputFile(int *file_counter)
{
    char *file_name = malloc(sizeof(char) * 8);
    if (file_name == NULL)
    {
        printf("file_name could not be stored\n");
        exit(1);
    }
    sprintf(file_name, "%03i.jpg", *file_counter);
    (*file_counter)++;

    FILE *output = fopen(file_name, "ab");
    if (output == NULL)
    {
        printf("output file: %s could not be created\n", file_name);
        free(file_name);
        exit(1);
    }

    free(file_name);

    return output;
}

int writeBlockToFile(BYTE *buffer, int size, FILE *output)
{
    return fwrite(buffer, sizeof(*buffer), size, output);
}
