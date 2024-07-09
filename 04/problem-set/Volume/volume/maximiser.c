// Modifies the volume of an audio file

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 3)
    {
        printf("Usage: ./volume input.wav output.wav\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Copy header from input file to output file
    uint8_t *p_header = malloc(HEADER_SIZE);
    fread(p_header, 1, HEADER_SIZE, input);
    fwrite(p_header, 1, HEADER_SIZE, output);
    free(p_header);

    // Read samples from input file and write updated data to output file
    fseek(input, HEADER_SIZE, SEEK_SET);
    int16_t largest_value = 0;
    int16_t buffer;
    while(fread(&buffer, sizeof(buffer), 1, input) != 0){
      if(buffer < 0){ buffer *= -1; }
      if(buffer > largest_value){ largest_value = buffer; }
      printf("Buffer: %i, Largest Value: %i\n", buffer, largest_value);
    }

    float factor = (pow(2, sizeof(largest_value) * 8) - 1) / largest_value;
    printf("Factor: %f\n", factor);

    fseek(input, HEADER_SIZE, SEEK_SET);
    while (fread(&buffer, sizeof(buffer), 1, input) != 0)
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(buffer), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
