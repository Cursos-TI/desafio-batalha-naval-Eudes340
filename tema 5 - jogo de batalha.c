#include <stdio.h>
#include <stdlib.h>   

#define TAM 10
#define HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;
}

void aplicarHabilidade(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (hab[i][j] == 1) {
                int l = origemL + (i - HAB / 2);
                int c = origemC + (j - HAB / 2);

                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                    if (tab[l][c] == AGUA) {
                        tab[l][c] = HABILIDADE;
                    }
                }
            }
        }
    }
}

void imprimirTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int cone[HAB][HAB] = {0};
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= (HAB/2 - i) && j <= (HAB/2 + i)) {
                cone[i][j] = 1;
            }
        }
    }

   
    int cruz[HAB][HAB] = {0};
    for (int i = 0; i < HAB; i++) {
        cruz[HAB/2][i] = 1;
        cruz[i][HAB/2] = 1;
    }

   
    int octaedro[HAB][HAB] = {0};
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - HAB/2) + abs(j - HAB/2) <= HAB/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    printf("\nTabuleiro com habilidades aplicadas:\n\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}