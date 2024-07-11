#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];

            LONG sum = pixel->rgbtRed + pixel->rgbtGreen + pixel->rgbtBlue;
            BYTE average = round(sum / 3.0);

            RGBTRIPLE new_pixel = {average, average, average};
            *pixel = new_pixel;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE *pixel = &image[i][j];

            LONG red =
                round(0.393 * pixel->rgbtRed + 0.769 * pixel->rgbtGreen + 0.189 * pixel->rgbtBlue);
            if (red > 255)
            {
                red = 255;
            }

            LONG green =
                round(0.349 * pixel->rgbtRed + 0.686 * pixel->rgbtGreen + 0.168 * pixel->rgbtBlue);
            if (green > 255)
            {
                green = 255;
            }

            LONG blue =
                round(0.272 * pixel->rgbtRed + 0.534 * pixel->rgbtGreen + 0.131 * pixel->rgbtBlue);
            if (blue > 255)
            {
                blue = 255;
            }

            RGBTRIPLE new_pixel = {blue, green, red};
            *pixel = new_pixel;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int top = i - 1 > 0 ? i - 1 : 0;
            int left = j - 1 > 0 ? j - 1 : 0;
            int bottom = i + 1 < height ? i + 1 : height - 1;
            int right = j + 1 < width ? j + 1 : width - 1;

            int sum[] = {0, 0, 0};
            for (int a = top; a <= bottom; a++)
            {
                for (int b = left; b <= right; b++)
                {
                    sum[0] += copy[a][b].rgbtRed;
                    sum[1] += copy[a][b].rgbtGreen;
                    sum[2] += copy[a][b].rgbtBlue;
                }
            }

            int total_cells = (bottom - top + 1) * (right - left + 1);
            RGBTRIPLE new_pixel = {
                round(sum[2] / (float) total_cells),
                round(sum[1] / (float) total_cells),
                round(sum[0] / (float) total_cells),
            };

            image[i][j] = new_pixel;
        }
    }
}
