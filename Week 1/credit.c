#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculo(const char *n);
void verificar(const char *n);

void calculo(const char *n)
{
    int cont = 0;
    for (int i = strlen(n); i >= 0; i -= 2)
    {
        char temp[2];
        temp[0] = n[i];
        temp[1] = '\0';

        int galo = (atoi(temp) * 2);

        if (galo > 9)
        {
            cont += galo / 10; // dezena
            cont += galo % 10; // unidade
        }
        else
        {
            cont += galo;
        }
    }

    int tatu = strlen(n);
    for (int i = tatu - 1; i >= 0; i -= 2)
    {
        char temp[2];
        temp[0] = n[i];
        temp[1] = '\0';

        int galo = atoi(temp); // n[i]
        cont += galo;
    }

    cont = cont % 10;
    if (cont == 0)
    {
        verificar(n);
    }
    else
    {
        printf("INVALID\n");
    }
}

void verificar(const char *n)
{
    if (strlen(n) == 15 && (n[0] == '3' && (n[1] == '4' || n[1] == '7'))) // American Express
    {
        printf("AMEX\n");
    }
    else if (strlen(n) == 16 && n[0] == '5' && (n[1] >= '1' && n[1] <= '5')) // MarterCard
    {
        printf("MASTERCARD\n");
    }
    else if ((strlen(n) == 13 || strlen(n) == 16) && (n[0] == '4')) // Visa
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    char n[20];
    int valid;

    do
    {
        valid = 1;

        printf("Number: ");
        scanf("%19s", n);

        for (int i = 0; n[i] != '\0'; i++)
        {
            if (!isdigit((unsigned char) n[i])) // not digito
            {
                valid = 0;
                break;
            }
        }
    }
    while (!valid); // repete

    calculo(n);

    return 0;
}
