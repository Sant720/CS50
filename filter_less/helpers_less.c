#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate grayscale value and round.
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            float average = ((blue + green + red) / 3);
            int grayscale_value = round(average);

            // Set current pixel to grayscale value.
            image[i][j].rgbtBlue = grayscale_value;
            image[i][j].rgbtGreen = grayscale_value;
            image[i][j].rgbtRed = grayscale_value;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Variables for clear naming
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            // Calculate sepia value in RGB
            int red_sepia = round(.393 * r + .769 * g + .189 * b);
            int green_sepia = round(.349 * r + .686 * g + .168 * b);
            int blue_sepia = round(.272 * r + .534 * g + .131 * b);

            // Cap sepia value to 255
            if (red_sepia > 255)
            {
                red_sepia = 255;
            }
            if (green_sepia > 255)
            {
                green_sepia = 255;
            }
            if (blue_sepia > 255)
            {
                blue_sepia = 255;
            }


            // Assign sepia value to pixel
            image[i][j].rgbtRed = red_sepia;
            image[i][j].rgbtGreen = green_sepia;
            image[i][j].rgbtBlue = blue_sepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // Set start and endpoints
        int start = 0;
        int end = width - 1;

        // Swap until the middle is reached
        while (start < end)
        {
            RGBTRIPLE temp = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = temp;

            start++;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Declare temporary image array
    RGBTRIPLE temp_image[height][width];

    // Iterate through image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Adjacent variables
            float adjacent_count = 0;
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;

            // Add RGB values at adjacent pixels
            for (int a = i - 1; a <= i + 1; a++)
            {
                for (int b = j - 1; b <= j + 1; b++)
                {
                    if ((a >= 0 && a <= height - 1) && (b >= 0 && b <= width - 1))
                    {
                        sum_red += image[a][b].rgbtRed;
                        sum_green += image[a][b].rgbtGreen;
                        sum_blue += image[a][b].rgbtBlue;
                        adjacent_count++;
                    }
                }
            }
            // Find the average of RGB values
            int avg_red = round(sum_red / adjacent_count);
            int avg_green = round(sum_green / adjacent_count);
            int avg_blue = round(sum_blue / adjacent_count);

            // Assign average values to temp image
            temp_image[i][j].rgbtRed = avg_red;
            temp_image[i][j].rgbtGreen = avg_green;
            temp_image[i][j].rgbtBlue = avg_blue;
        }
    }

    // Copy new array of pixels into image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed= temp_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp_image[i][j].rgbtBlue;
        }
    }
    return;
}
