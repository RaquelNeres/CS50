#include <stdio.h>

void piramide(int h);

void piramide(int h) // h = 4
{
    for (int i = 0; i < h; i++) // loop h vezes
    {
        for (int j = ((h - 1) - i); j > 0; j--) // faz as # lado a lado ate h vezes,       Para cada
                                                // linha, h colunas são impressas.
        {
            printf(" ");
        }

        for (int a = 0; a <= i; a++)
        {
            printf("#");
        }

        printf(" ");
        printf(" ");

        for (int a = 0; a <= i; a++)
        {
            printf("#");
        }
        printf("\n"); // pula a cada h,             Após cada linha, uma nova linha é impressa.
    }
}

int main(void)
{
    int h;
    do
    {
        printf("Altura: ");
        scanf("%i", &h);
    }
    while (h < 1 || h > 8);
    piramide(h);

    return 1;
}
