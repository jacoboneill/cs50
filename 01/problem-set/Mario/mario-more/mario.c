#include <cs50.h>
#include <stdio.h>

int get_user_height(string message)
{
    int height;
    do
    {
        height = get_int("%s", message);
    }
    while (height < 1 || height > 8);

    return height;
}

void generate_pyramid_space(int height, int layer)
{
    for (int i = 0; i < height - (layer + 1); i++)
    {
        printf(" ");
    }
}

void generate_pyramid_blocks(int layer)
{
    for (int i = 0; i < layer + 1; i++)
    {
        printf("#");
    }
}

int main()
{
    int height = get_user_height("Pick a height between 1 and 8: ");

    // Generate Pyramid
    for (int i = 0; i < height; i++)
    {
        generate_pyramid_space(height, i);
        generate_pyramid_blocks(i);
        printf("  ");
        generate_pyramid_blocks(i);
        printf("\n");
    }
}
