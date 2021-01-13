#include <stdio.h>

int main(void)
{
    char filename[8];
    for (int i = 0; i < 3; i++)
    {
        sprintf(filename, "%03i.jpg", i);
        printf("%s\n", filename);
    }
}