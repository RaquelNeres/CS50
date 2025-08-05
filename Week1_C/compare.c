// Conditionals

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for integers
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");

    // Compare integers
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }

    // raiz
    int a, b;

    printf("Valor de a: ");
    scanf("%i", &a);

    printf("Valor de b: ");
    scanf("%i", &b);

    if (a < b)
    {
        printf("a is less than b\n");
    }
    else if (a > b)
    {
        printf("a is greater than b\n");
    }
    else
    {
        printf("a is equal to b\n");
    }
}
