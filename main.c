#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 42000


void ImprimePosicao(int t, int S0, int S1)
{
    printf("\nTempo: %is"
           "\nFrank: %im\tMarizete: %im\n", t, S0, S1);
}
int CalculaInstante(int s0, int v0, int a0, int s1, int v1, int a1)
{
    int t, S0 = 0, S1 = 0;

    for(t = 0; (S0 < TAM) && (S1 < TAM); ++t)
    {
        S0 = s0 + v0 * t + ((a0 * pow(t, 2)) / 2);
        S1 = s1 + v1 * t + ((a1 * pow(t, 2)) / 2);

        if(S0 > S1)
            return t;

        else
            ImprimePosicao(t, S0, S1);
    }

    return -1;
}

float CalculaMultiplicacao(float a, float b)
{
    if(b == 1)
        return a;

    return a + CalculaMultiplicacao(a, b - 1);
}
float CalculaPotencia(float base, int expoente)
{
    if(expoente == 0)
        return 1;

    return CalculaMultiplicacao(base, CalculaPotencia(base, expoente - 1));
}
unsigned long long int CalculaFatorial(unsigned long long int x)
{
    if(x == 0)
        return 1;

    return x * CalculaFatorial(x - 1);
}
double CalculaEX(float x, int N)
{
    if(N <= 0)
        return 1;

    return (CalculaPotencia(x,N) / CalculaFatorial(N)) + CalculaEX(x, N - 1);
}

int strstr(const char *str, const char *strSub)
{
    int i, j = 0, l;

    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == strSub[j])
        {
            for(l = i; strSub[j] != '\0'; ++j, ++l)
                if(str[l] != strSub[j])
                    break;

            if(strSub[j] == '\0')
                if((str[l] == ' ') || (str[l] == '.') || (str[l] == ',') || (str[l] == '\0'))
                    return i;

            if(str[l] == '\0')
                return -1;

            j = 0;
        }
    }

    return -1;
}

int EliminaEspacosEmBranco(char *s)
{
    if(!s)
        return 0;

    int l, i, j;

    for(i = 0; s[i] != '\0'; ++i)
        if((s[i] == ' ') && (s[i + 1] == ' '))
        {
            for(j = i + 1; s[j] == ' '; ++j);

            for(l = i + 1; s[j] != '\0'; ++l, ++j)
                s[l] = s[j];

            s[l] = '\0';
        }

    return 1;
}


int main()
{
    short int controlador = 0;
    int s0 = 0, v0 = 0, a0 = 0, s1 = 0, v1 = 0, a1 = 0, N = 0;
    float x = 0.0;
    char string[255], Bstring[255], Svar[255];

    printf("[1] Calcula Instante."
           "\n[2] CalculaEX."
           "\n[3] strstr."
           "\n[4] Elimina espa%cos em branco."
           "\n[0] Sair do programa.", 135);

    printf("\n\nDigite o numero que representa a op%c%co desejada: ", 135, 198);
    scanf(" %i", &controlador);

    while((controlador < 0) || (controlador > 4))
    {
        printf("\n\n\tTu printa com meu printo?"
               "\nPor favor Digite novamente o correspondente a op%c%co desejada: ", 135, 198);

        printf("\n[1] Calcula Instante."
               "\n[2] CalculaEX."
               "\n[3] strstr."
               "\n[4] Elimina espa%cos em branco."
               "\n[0] Sair do programa.", 135);

        printf("\n\nDigite o numero que representa a op%c%co desejada: ", 135, 198);
        scanf(" %i", &controlador);
    }

    while(controlador != 0)
    {
        switch(controlador)
        {
            case 1:
                printf("\n\n\tCorredor Frank."
                       "\nVelocida inicial: ");
                scanf(" %i", &v0);
                printf("\nAcelera%c%co: ", 135, 198);
                scanf(" %i", &a0);
                printf("\nPosi%c%co inicial: ", 135, 198);
                scanf(" %i", &s0);

                printf("\n\n\tCorredor Marizete."
                       "\nVelocida inicial: ");
                scanf(" %i", &v1);
                printf("\nAcelera%c%co: ", 135, 198);
                scanf(" %i", &a1);
                printf("\nPosi%c%co inicial: ", 135, 198);
                scanf(" %i", &s1);

                printf("\n\n\tR: %i", CalculaInstante(s0, v0, a0, s1, v1, a1));

                break;

            case 2:
                printf("\n\nQual o Valor de X: ");
                scanf(" %f", &x);

                printf("\nQual o valor de N: ");
                scanf(" %i", &N);

                printf("\nEuler: %f", CalculaEX(x, N));

                break;

            case 3:

                printf("\n\nDigite um frase: ");
                scanf(" %[^\n]s", string);

                printf("\nDigite a palavra de busca: ");
                scanf(" %[^\n]s", Bstring);

                printf("%i", strstr(string, Bstring));

                break;

            default:
                printf("\n\nDigite uma frase: ");
                scanf(" %[^\n]s", Svar);
                EliminaEspacosEmBranco(Svar);
                printf("\n%s\n", Svar);
        }

        printf("\n[1] Calcula Instante."
               "\n[2] CalculaEX."
               "\n[3] strstr."
               "\n[4] Elimina espa%cos em branco."
               "\n[0] Sair do programa.", 135);

        printf("\n\nDigite o numero que representa a op%c%co desejada: ", 135, 198);
        scanf(" %i", &controlador);

        while((controlador < 0) || (controlador > 4))
        {
            printf("\n\n\tTu printa com meu printo?"
                   "\nPor favor Digite novamente o correspondente a op%c%co desejada: ", 135, 198);

            printf("\n[1] Calcula Instante."
                   "\n[2] CalculaEX."
                   "\n[3] strstr."
                   "\n[4] Elimina espa%cos em branco."
                   "\n[0] Sair do programa.", 135);

            printf("\n\nDigite o numero que representa a op%c%co desejada: ", 135, 198);
            scanf(" %i", &controlador);
        }
    }

    return 0;
}
