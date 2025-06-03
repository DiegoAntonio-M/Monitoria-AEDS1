/*
 * Estatística e Ocorrência - Versão 2
 *
 * Esta é uma versão mais completa e mais otimizada, contempla a modificação necessária mencionada em "Estatistica e Ocorrencia.c"
 * ao qual agora permite mostrar todas as incidências de MAIOR e MENOR. O Método de Ordenação foi modificado para já calcular a
 * frequência ao mesmo tempo que ordena.
 *
 *
 * Diferenças em relação à versão 1:
 *   - O programa agora utiliza um vetor bidimensional, onde cada linha armazena o valor e sua frequência.
 *   - Agora é capaz de exibir todas as ocorrências que apresentam a MENOR e a MAIOR frequência atribuída.
 *   - O algoritmo de ordenação (bubble sort) foi adaptado para também contabilizar a frequência dos elementos durante o processo de ordenação, tornando o código mais eficiente.
 *   - Exibição diferente, com simbulos e indicações mais visuais.
 * 
 * Recomenda-se utilizar este código como base para estudos de algoritmos de ordenação, análise de frequência e manipulação de vetores em C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANT 30

int main() {
    int vetor[QUANT][2] = {};
    int quantDistinto = QUANT;
    int contarMaisRepetido = 0;
    int contarMenosRepetido = 0;

    srand(time(NULL)); // <<<--- Usando a Lib de randomizar para não ter que colocar cada número de forma manual

    for (int i = 0; i < QUANT; i++) {

        // printf("[%d] Digite o valor: ", i + 1);  // <| Original para pegar os Números do usuário
        // scanf("%d", &vetor[i][0]);               // <|

        vetor[i][0] = rand() % 15 + 1; //<--- Randomizando para não ter que colocar cada número de forma manual
        vetor[i][1] = 1;
    }

    for (int i = 0; i < quantDistinto; i++) {
        int aux[2] = {};
        for (int j = i + 1; j < QUANT; j++) {
            if (vetor[i][1] == 0 || (vetor[j][1] != 0 && vetor[i][0] > vetor[j][0])) {
                aux[0] = vetor[i][0];
                aux[1] = vetor[i][1];

                vetor[i][0] = vetor[j][0];
                vetor[i][1] = vetor[j][1];

                vetor[j][0] = aux[0];
                vetor[j][1] = aux[1];

            } else if ((vetor[i][1] != 0 && vetor[j][1] != 0) && vetor[i][0] == vetor[j][0]) {
                vetor[i][1] += vetor[j][1];
                vetor[j][1] = 0;
                quantDistinto--;
            }
        }

        // Atualiza o maisRepetido e menosRepetido usando vetor[i][1]
        if (vetor[i][1] != 0) {
            if (vetor[i][1] > contarMaisRepetido) {
                contarMaisRepetido = vetor[i][1];
            }
            if (contarMenosRepetido == 0 || vetor[i][1] < contarMenosRepetido) {
                contarMenosRepetido = vetor[i][1];
            }
        }
    }

    printf("\n\nLista de numeros distintos digitados (ORDENADO):\n");
    for (int i = 0; i < quantDistinto; i++) {
        if (vetor[i][1] == contarMaisRepetido) {
            printf("\n<+> ");
        } else if (vetor[i][1] == contarMenosRepetido) {
            printf("\n>-< ");
        } else {
            printf("\n    ");
        }
        printf("[%03d]: %d", vetor[i][0], vetor[i][1]);
        if (vetor[i][1] == 2)
            printf(" <-------- [=2]");
        else if (vetor[i][1] > 2)
            printf(" <<[+2]");
    }

    printf("\n\nNúmeros com MAIOR frequência (%d ocorrência%s):\n|", contarMaisRepetido, contarMaisRepetido == 1 ? "" : "s");
    for (int i = 0; i < quantDistinto; i++) {
        if (vetor[i][1] == contarMaisRepetido) printf(" %03d |", vetor[i][0]);
    }

    printf("\nNúmeros com MENOR frequência (%d ocorrência%s):\n|", contarMenosRepetido, contarMenosRepetido == 1 ? "" : "s");
    for (int i = 0; i < quantDistinto; i++) {
        if (vetor[i][1] == contarMenosRepetido) printf(" %03d |", vetor[i][0]);
    }
    printf("\n");

    return 0;
}