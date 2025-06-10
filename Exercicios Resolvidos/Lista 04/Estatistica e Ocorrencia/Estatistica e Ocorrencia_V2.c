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

#define QUANT 200000 // Agora igual ao valor de QUANT do outro arquivo

int main() {
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock(); // Inicia a contagem do tempo

    int vetor[QUANT][2] = {};
    int quantDistinto = QUANT;
    int contarMaisRepetido = 0;
    int contarMenosRepetido = 0;

    srand(time(NULL));

    for (int i = 0; i < QUANT; i++) {

        // printf("[%d] Digite o valor: ", i + 1);  // <| Original para pegar os Números do usuário
        // scanf("%d", &vetor[i][0]);               // <|
        vetor[i][0] = rand() % 500 + 1; //<--- Randomizando para não ter que colocar cada número de forma manual
        vetor[i][1] = 1;
    }

    // Usa um hash temporário para contar frequências rapidamente
    // Limita os valores possíveis a 1..500 (como no rand() % 500 + 1)
    int freq[501] = {0};
    for (int i = 0; i < QUANT; i++) {
        freq[vetor[i][0]]++;
    }

    // Preenche vetor[] apenas com valores distintos e suas frequências
    quantDistinto = 0;
    for (int v = 1; v <= 500; v++) {
        if (freq[v] > 0) {
            vetor[quantDistinto][0] = v;
            vetor[quantDistinto][1] = freq[v];
            quantDistinto++;
        }
    }

    // Ordena vetor[] por valor (já está em ordem, mas se quiser garantir)
    // (pode remover este bubble sort se não precisar)
    /*
    for (int i = 0; i < quantDistinto - 1; i++) {
        for (int j = i + 1; j < quantDistinto; j++) {
            if (vetor[i][0] > vetor[j][0]) {
                int tmp0 = vetor[i][0], tmp1 = vetor[i][1];
                vetor[i][0] = vetor[j][0];
                vetor[i][1] = vetor[j][1];
                vetor[j][0] = tmp0;
                vetor[j][1] = tmp1;
            }
        }
    }
    */

    // Atualiza o maisRepetido e menosRepetido usando vetor[i][1]
    for (int i = 0; i < quantDistinto; i++) {
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

    fim = clock(); // Finaliza a contagem do tempo
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %.6f segundos\n", tempo_gasto);

    return 0;
}