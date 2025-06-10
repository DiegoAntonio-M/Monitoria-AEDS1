/*
 --------------------------------------------------------------------------------------
 Questão 1 - Vetor: Estatísticas de Ocorrências e Análise de Frequência
 --------------------------------------------------------------------------------------
 Leia 30 números inteiros, armazene em um vetor e realize a análise de frequência:
 - Exiba todos os números distintos digitados e quantas vezes cada um aparece.
 - Identifique o número que mais se repete e o que menos se repete (mas que apareceu).
 - Mostre todos os números que aparecem exatamente duas vezes e os que aparecem mais
   de duas vezes.
 - Exiba os números distintos em ordem crescente.
 --------------------------------------------------------------------------------------
*/

#include <stdio.h>

/*
 * Definição da constante QUANT usando #define
 *
 * A diretiva #define é usada para criar uma substituição textual no pré-processamento do código.
 * | --> (Como se fosse um localizar e substituir)
 * 
 * Aqui, QUANT é definido como 30, mas #define pode ser usado para qualquer valor, texto, expressão ou até mesmo funções-macro.
 *
 * Diferença entre #define e variáveis:
 * - #define é processado pelo pré-processador, antes da compilação, e faz substituição direta do texto.
 * - Variáveis são alocadas em memória e avaliadas em tempo de execução.
 * - #define não ocupa espaço de memória e não tem tipo; variáveis possuem tipo e ocupam memória.
 * - #define pode ser usado para números, textos, expressões ou até nomes de funções-macro, enquanto variáveis só armazenam valores.
 *
 * Exemplo de uso não numérico:
 *   #define ATENCAO printf("Atencao!!!")
 * 
 * Uso:
 *   ATENCAO;
*/
#define QUANT 30

int main()
{
    // Vetor principal para armazenar os números digitados. Usar um vetor permite acesso rápido e indexado aos elementos.
    int vetor[QUANT] = {};

    // Vetor para armazenar apenas os números distintos. Isso facilita a ordenação e a exibição dos elementos distintos.
    int vetorDistinto[QUANT] = {};
    int quantDistinto = 0; // Controla quantos elementos distintos já foram encontrados

    // Variáveis para armazenar o número mais repetido e o menos repetido, além de suas contagens.
    int maisRepetido = 0;
    int contarMaisRepetido = 0;
    int menosRepetido = 0;
    int contarMenosRepetido = 0;

    // O laço for garante que exatamente 30 números sejam lidos do usuário.
    for (int i = 0; i < QUANT; i++)
    {
        printf("[%d] Digite o valor: ", i + 1); //<---- Indicativo visual para inserir os elementos
        scanf("%d", &vetor[i]);
    }

    printf("\n\nLista de numeros distintos digitados:\n");

    // Processamento principal: percorre o vetor para identificar a frequência e distinguir elementos.
    for (int i = 0; i < QUANT; i++)
    {
        int contador = 0; // Conta quantas vezes o número vetor[i] apareceu até agora

        // Verifica quantas vezes o número vetor[i] já apareceu até a posição i.
        // Isso evita contar o mesmo número mais de uma vez como distinto.
        for (int j = 0; j <= i; j++) // <-------------------------------------------------------------
        { //                 ^                                                                       |
            if (vetor[i] == vetor[j]) // Mantém a posição atual fixa e procura todas as ocorrências antes desta posição
            {
                contador++; // Incrementa caso encontre o elemento
            }
        }

        // Atualiza o número mais repetido, se necessário.
        if (contarMaisRepetido < contador)
        {
            contarMaisRepetido = contador;
            maisRepetido = vetor[i];
        }

        // Atualiza o número menos repetido, considerando o primeiro elemento ou um novo mínimo.
        if (i == 0 || contador < contarMenosRepetido) // <==== (i == 0) serve para forçar a primeira entrada.
        {
            contarMenosRepetido = contador;
            menosRepetido = vetor[i];
        }

        // Se o número apareceu só uma vez até agora, ele é considerado distinto.
        if (contador == 1)
        {
            int contarTodaFrequencia = 0; // Conta quantas vezes o número aparece em todo o vetor

            // Adiciona o número ao vetor de distintos e incrementa o contador de distintos.
            vetorDistinto[quantDistinto] = vetor[i];
            quantDistinto++;

            // Conta a frequência total do número no vetor.
            for (int j = 0; j < QUANT; j++)
            {
                if (vetor[i] == vetor[j])
                {
                    contarTodaFrequencia++;
                }
            }
            // Exibe o número distinto e sua frequência, com destaque para os que aparecem duas ou mais vezes.
            printf("[%03d]: %d", vetor[i], contarTodaFrequencia);
            if (contarTodaFrequencia == 2)
                printf(" <-------- [=2]\n");
            else if (contarTodaFrequencia > 2)
                printf(" <<<[+2]\n");
            else
                printf("\n");
        }
    }

    // Ordenação dos números distintos usando Bubble Sort.
    // O Bubble Sort é simples de implementar e suficiente para poucos elementos, como neste caso.
    /* ***************
     * Bubble Sort:
     * ---------------
     * O Bubble Sort é um algoritmo de ordenação simples que compara pares de elementos adjacentes
     * e os troca de posição se estiverem fora de ordem. Esse processo é repetido várias vezes,
     * fazendo com que os maiores elementos "borbulhem" para o final do vetor a cada passagem.
     * 
     * Funcionamento:
     * - Para cada elemento do vetor, percorre os elementos seguintes e compara com o atual.
     * - Se o elemento atual for maior que o seguinte, troca os dois de lugar.
     * - Repete até que todo o vetor esteja ordenado.
     * 
     * Vantagens:
     * - Fácil de implementar.
     * - Bom para pequenas quantidades de dados.
     * 
     * Desvantagens:
     * - Ineficiente para grandes conjuntos de dados (complexidade O(n²)).
     */
    // Ordena o vetorDistinto em ordem crescente usando Bubble Sort
    for (int i = 0; i < quantDistinto; i++) // Percorre cada elemento do vetor de distintos
    {
        int aux = 0; // Variável auxiliar para troca de valores
        for (int j = i; j < quantDistinto; j++) // Percorre os elementos a partir da posição i, pois os elementos das posições anteriores já estão ordenados.
        {
            // Compara o elemento atual com os próximos elementos
            if (vetorDistinto[i] > vetorDistinto[j]) // Se o elemento na posição i for maior que o da posição j
            {
                aux = vetorDistinto[i]; // Guarda o valor de vetorDistinto[i] em aux
                vetorDistinto[i] = vetorDistinto[j]; // Coloca o menor valor na posição i
                vetorDistinto[j] = aux; // Coloca o maior valor na posição j
            }
        }
    }

    // Exibe os números distintos em ordem crescente, formatados para três dígitos.
    printf("\nLista de numeros distintos digitados (ORDENADO):\n");
    printf("|");
    for (int i = 0; i < quantDistinto; i++) // Percorre cada um dos elementos
    {
        printf(" %03d |", vetorDistinto[i]);
    }

    return 0;
}

/* Observações:
 * - Este código não está 100% otimizado, mas apresenta um passo a passo mais compreensível.
 * - Se houver mais de um menor ou maior valor distinto com a mesma frequência, o programa exibirá o primeiro inserido pelo usuário.
*/