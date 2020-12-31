#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get average of RGB values
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int grayscale_value = round((red + green + blue) / 3);

            // Change RGB values on current pixel
            image[i][j].rgbtRed = grayscale_value;
            image[i][j].rgbtGreen = grayscale_value;
            image[i][j].rgbtBlue = grayscale_value;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int start = 0;
        int end = width - 1;
        
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
    RGBTRIPLE temp_image[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Set variables. 
            int adjacent_count = 0;
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;
            
            // Iterae over adjacent pixels
            for (int a = i - 1; a <= i + 1; a++)
            {
                for (int b = j - 1; b <= j + 1; b++)
                {
                    if (a >= 0 && a <= height - 1  && b >= 0 && b <= width - 1)
                    {
                        sum_red += image[a][b].rgbtRed;
                        sum_green += image[a][b].rgbtGreen;
                        sum_blue += image[a][b].rgbtBlue;
                        adjacent_count++;
                    }
                }
            }
            
            // Calculate averages and copy to temp image
            temp_image[i][j].rgbtRed = round(sum_red / adjacent_count);
            temp_image[i][j].rgbtGreen = round(sum_green / adjacent_count);
            temp_image[i][j].rgbtBlue = round(sum_blue / adjacent_count);
        }
    }
    
    // Copy temp image to current image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_image[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Set adjacent variables
            int Gx_red = 0;
            int Gx_green = 0;
            int Gx_blue = 0;
            int Gy_red = 0;
            int Gy_green = 0;
            int Gy_blue = 0;
            
            // Iterate through adjacent pixels
            for (int a = i - 1, x = 0; a <= i + 1; a++, x++)
            {
                for (int b = j - 1, y = 0; b <= j + 1; b++, y++)
                {
                    if (a >= 0 && a <= height - 1  && b >= 0 && b <= width - 1)
                    {
                        Gx_red += image[a][b].rgbtRed * Gx[x][y];
                        Gx_green += image[a][b].rgbtGreen * Gx[x][y];
                        Gx_blue += image[a][b].rgbtBlue * Gx[x][y];
                        
                        Gy_red += image[a][b].rgbtRed * Gy[x][y];
                        Gy_green += image[a][b].rgbtGreen * Gy[x][y];
                        Gy_blue += image[a][b].rgbtBlue * Gy[x][y];
                    }
                }
            }
            // Calculate new value for current pixel and cap at 255
            int red = round(sqrt((Gx_red * Gx_red) + (Gy_red * Gy_red)));
            int green = round(sqrt((Gx_green * Gx_green) + (Gy_green * Gy_green)));
            int blue = round(sqrt((Gx_blue * Gx_blue) + (Gy_blue * Gy_blue)));
            
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            
            // Copy new values to temp image
            
            temp_image[i][j].rgbtRed = red;
            temp_image[i][j].rgbtGreen = green;
            temp_image[i][j].rgbtBlue = blue;
        }
    }
    
    // Copy temp image to current image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_image[i][j];
        }
    }
    return;
}
