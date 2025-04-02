#include "helpers.h"
#include <math.h>
#include <stdio.h>

float test(int height, int width, RGBTRIPLE image[height][width], int i, int n);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

    // Looks at all pixels in image
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            // For each pixel, find the average colour
            average = round((image[i][n].rgbtBlue + image[i][n].rgbtRed + image[i][n].rgbtGreen) / (double) 3);

            // To convert to grey, similiar in brightness to original, assign all the equal value 'average'
            image[i][n].rgbtBlue = average;
            image[i][n].rgbtRed = average;
            image[i][n].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Algorithm:
    /*sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue*/

    int sepiaRed, sepiaGreen, sepiaBlue;
    // Look at every pixel individually
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            // Implement algorithm to find new red, green, blue
            sepiaRed = round(.393 * image[i][n].rgbtRed + .769 * image[i][n].rgbtGreen + .189 * image[i][n].rgbtBlue);
            sepiaGreen = round(.349 * image[i][n].rgbtRed + .686 * image[i][n].rgbtGreen + .168 * image[i][n].rgbtBlue);
            sepiaBlue = round(.272 * image[i][n].rgbtRed + .534 * image[i][n].rgbtGreen + .131 * image[i][n].rgbtBlue);

            // Assign new red, green, & blue, while ensuring not larger than 255 limit
            if (sepiaRed > 255)
                image[i][n].rgbtRed = 255;
            else
                image[i][n].rgbtRed = sepiaRed;

            if (sepiaGreen > 255)
                image[i][n].rgbtGreen = 255;
            else
                image[i][n].rgbtGreen = sepiaGreen;

            if (sepiaBlue > 255)
                image[i][n].rgbtBlue = 255;
            else
                image[i][n].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    // Find the difference from the position of that pixel and the middle (-- = + so don't worry about negatives)
    RGBTRIPLE placeHolderRed[height][width];
    RGBTRIPLE placeHolderGreen[height][width];
    RGBTRIPLE placeHolderBlue[height][width];

    double middle = (width - 1) / (double) 2;
    double distance = 0;
    int newPosition = 0;

    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            // Distance from that pixel to the middle
            distance = n - middle;

            // Reflected position (distance from pixel to middle then inverted distance further)
            newPosition = n - (2 * distance);

            // Store data of new position
            placeHolderRed[i][n].rgbtRed = image[i][newPosition].rgbtRed;
            placeHolderGreen[i][n].rgbtGreen = image[i][newPosition].rgbtGreen;
            placeHolderBlue[i][n].rgbtBlue = image[i][newPosition].rgbtBlue;

            // Reset
            distance = 0;
            newPosition = 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            // Change each pixel to new pixel
            image[i][n].rgbtRed = placeHolderRed[i][n].rgbtRed;
            image[i][n].rgbtGreen = placeHolderGreen[i][n].rgbtGreen;
            image[i][n].rgbtBlue = placeHolderBlue[i][n].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE placeHolder[height][width];

    // Sum & average of all neighbouring RGB values, for each pixel
    RGBTRIPLE sum;
    sum.rgbtRed = 0;
    sum.rgbtBlue = 0;
    sum.rgbtGreen = 0;
    RGBTRIPLE average[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            // See if the current pixel is an edge, corner or neither
            float result = test(height, width, image[height][width], i, n);

            // Edge or corner
            if (result > 10)
            {
                // Corner
                if (result > 25)
                {
                    average[i][n].rgbtRed = image[i][n].rgbtRed;
                    average[i][n].rgbtBlue = image[i][n].rgbtBlue;
                    average[i][n].rgbtGreen = image[i][n].rgbtGreen;
                }
                // Edge
                else
                {
                    average[i][n].rgbtRed = image[i][n].rgbtRed;
                    average[i][n].rgbtBlue = image[i][n].rgbtBlue;
                    average[i][n].rgbtGreen = image[i][n].rgbtGreen;
                }
            }
            // Neither (normal/middle)
            else
            {

                for (int x = i-1; x < i + 1; x++)
                {
                    for (int y = n-1; y < n + 1; y++)
                    {
                        sum.rgbtRed = image[x][y].rgbtRed;
                        sum.rgbtBlue = image[x][y].rgbtBlue;
                        sum.rgbtGreen = image[x][y].rgbtGreen;
                    }
                }

                average[i][n].rgbtRed = sum.rgbtRed / 9;
                average[i][n].rgbtBlue = sum.rgbtBlue / 9;
                average[i][n].rgbtGreen = sum.rgbtGreen / 9;

            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            image[i][n].rgbtRed = average[i][n].rgbtRed;
            image[i][n].rgbtBlue = average[i][n].rgbtBlue;
            image[i][n].rgbtGreen = average[i][n].rgbtGreen;
        }
    }

    return;
}

float test(int height, int width, RGBTRIPLE image[height][width], int i, int n)
{
    // Edge
    if (i + 1 >= height|| i - 1 <= height || n + 1 >= width || n - 1 <= width)
    {
        // Top
        if (i + 1 >= height)
        {
            return 20.0;
        }
        // Bottom
        else if (i - 1 <= height)
        {
             return 20.5;
        }
        // Left
        else if (n - 1 <= width)
        {
            return 25.0;
        }
        // Right
        else
        {
            return 20;
        }
    }
    // Corner
    else if ((i + 1 >= height|| i - 1 <= height) && (n + 1 >= width || n - 1 <= width))
    {
        // Left
        if (n - 1 <= width)
        {
            // Top
            if (i + 1 >= height)
            {
                return 30.0;
            }
            // Bottom
            else
            {
                return 30.5;
            }
        }
        // Right
        else
        {
            // Top
            if (i + 1 >= height)
            {
                return 35.0;
            }
            // Bottom
            else
            {
                return 35.5;
            }
        }
    }
    // Middle (standard)
    else
    {
        return 10.0;
    }
}
