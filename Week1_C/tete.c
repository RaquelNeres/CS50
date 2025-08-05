// // Helper function

// #include <stdio.h>

// void print_row(int width);

// int main(void)
// {
//     const int n = 3;

//     // Print n rows
//     for (int i = 0; i < n; i++)
//     {
//         print_row(n);
//     }
// }

// void print_row(int width)
// {
//     for (int i = 0; i < width; i++)
//     {
//         printf("#");
//     }
//     printf("\n");
// }
#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(i + 1);
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
