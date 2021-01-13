#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    int width = get_int("Width: ");
    
    int array[height][width];
    
    // load array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            array[i][j] = get_int("i: %i, j: %i, num: ", i, j);
        }
    }
    
    // copy array
    int copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = array[i][j];
        }
    }
    
    // for each pixel make a grid max_x * max_y so that it is inside of the array dimensions
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int min_x = i - 1;
            if (min_x < 0)
            {
                min_x = 0;
            }
            
            int max_x = i + 1;
            if (max_x > width - 1)
            {
                max_x = width - 1;
            }
            
            int min_y = j - 1;
            if (min_y < 0)
            {
                min_y = 0;
            }
            
            int max_y = j + 1;
            if (max_y > height - 1)
            {
                max_y = height - 1;
            }
            
            int num_of_pixels =  (max_x - min_x + 1)*(max_y - min_y + 1);
            
            int pixel_counter = 0;

            for (int x = min_x; x < max_x; x++)
            {
                for (int y = min_y; y < max_y; y++)
                {
                    pixel_counter++;
                }
            }
            
            printf("\n\n(%i) pixel: %i, %i", copy[i][j], i, j);
            printf("\nmin_x: %i, max_x: %i", min_x, max_x);
            printf("\nmin_y: %i, max_y: %i", min_y, max_y);
            printf("\nnum of pixels: %i", num_of_pixels);
            printf("\npixel_counter: %i", pixel_counter);
        }
    }
    
    /*
    // print copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%i ", copy[i][j]);
        }
        printf("\n");
    }
    */
    
    /*
    printf("\n");
    int x = get_int("Pixel x: ");
    int y = get_int("Pixel y: ");
    
    printf("\nHere's pixel grid limits:");
    printf("\nmin_x: %i, max_x: %i", min_x, max_x);
    printf("\nmin_y: %i, max_y: %i", min_y, max_y);
    */
    printf("\n");
    
}