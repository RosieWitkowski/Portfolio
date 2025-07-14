#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Loops through width and height
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            // If the pixel is black
            if (image[i][n].rgbtBlue == 0 && image[i][n].rgbtGreen == 0 && image[i][n].rgbtRed == 0)
            {
                // Change value to change the colour the pixels are changed to
                image[i][n].rgbtBlue = 125;
                image[i][n].rgbtGreen = 255;
                image[i][n].rgbtRed = 125;
            }
        }
    }
}
