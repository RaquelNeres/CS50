#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valorLetra(char l);

int main(void)
{
    int sum1 = 0, sum2 = 0;
    char palavra[20];

    printf("Player 1: ");
    scanf("%19s", palavra); // leitura segura (limita a 19 chars)

    printf("%s\n", palavra);
    printf("%i\n", (int)strlen(palavra));

    for (int i = 0, f = strlen(palavra); i < f; i++)
    {
        printf("antes: %c\n", palavra[i]);
        palavra[i] = palavra[i] - 32;
        printf("depois: %c\n", palavra[i]);
        sum1 += valorLetra(palavra[i]);
        printf("sum1: %i\n", valorLetra(palavra[i]));
    }
    printf("resultado: %i\n", sum1);

    return 1;

}

int valorLetra(char l) {
    if (l == 'A' || l == 'E' || l == 'I' || l == 'L' ||
        l == 'N' || l == 'O' || l == 'R' || l == 'S' ||
        l == 'T' || l == 'U') {
        return 1;
    }
    else if (l == 'D' || l == 'G') {
        return 2;
    }
    else if (l == 'B' || l == 'C' || l == 'M' || l == 'P') {
        return 3;
    }
    else if (l == 'F' || l == 'H' || l == 'V' || l == 'W' || l == 'Y') {
        return 4;
    }
    else if (l == 'J' || l == 'X') {
        return 8;
    }
    else if (l == 'Q' || l == 'Z') {
        return 10;
    }
    else {
        return 0;
    }
}
