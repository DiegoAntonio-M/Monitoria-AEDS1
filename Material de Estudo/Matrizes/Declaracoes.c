/*
 * Exemplos de declarações e Representações de Matrizes
 *
 * Este arquivo apresenta exemplos detalhados de declaração e inicialização de matrizes em C,
 * incluindo diferentes formas de definir dimensões, inicializar valores, uso de constantes,
 * defines, variáveis e alocação dinâmica.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

/* =============================================================
   || 1. Declaração de Dimensões de Matrizes                  ||
   ============================================================= */
  // Matrizes estáticas de várias dimensões

  // 1.1 Matriz quadrada: ij quando i = j >> matriz[i][j]
    /*      +----+----+
        [1] | 01 | 02 |
      i     +----+----+
        [2] | 01 | 02 |
            +----+----+
    */
    int matrizQuadrada[2][2] = {};


  // 1.2 Matriz retangular: ij quando i ≠ j >> matriz[i][j]

    /*           j
              v    v    v
            +----+----+----+
        [1] | 01 | 02 | 03 |
      i     +----+----+----+
        [2] | 01 | 02 | 03 |
            +----+----+----+
    */
    int matrizRetangular1[2][3] = {};


  // 1.3 Matriz retangular maior
    /*           j
              v    v    v
            +----+----+----+
        [1] | 01 | 02 | 03 |
      i     +----+----+----+
        [2] | 01 | 02 | 03 |
            +----+----+----+
        [3] | 01 | 02 | 03 |
            +----+----+----+
        [4] | 01 | 02 | 03 |
            +----+----+----+
        [5] | 01 | 02 | 03 |
            +----+----+----+
    */
    int matrizRetangular2[5][3] = {};

  // 1.4 Matriz cúbica: ijk quando i = j = k >> matriz[i][j][k]
    /*       k __________
            /----/-----/|
          j +----+----/ ||
        [1] | 01 | 02 | ||
      i     +----+----+ |/
        [2] | 01 | 02 | /
            +----+----+/
    */
    int matrizCubica[2][2][2];

  // 1.5 Matriz paralelepípedo: ijk quando i ≠ j ≠ k, i = j ≠ k, i ≠ j = k >> matriz[i][j][k]
    /*          __________
          k    / 01 / 02 /|
              /----/----/ |
            / 01 / 02 /|/|
            /----/----/ | |
          / 01 / 02 /|/| |
        j +----+----/ | |/
      [1] | 01 | 02 |/| /
    i     +----+----+ |/
      [2] | 01 | 02 | /
          +----+----+/
    */
      int matrizParalelepipedo[2][2][3];

  // 1.6 Matriz Multidimensional ou matriz n dimensões: ijk ... n, (n de dimensões) > 1  >> matriz[i][j][k]...[n]
    /*
            ...   l   ...
            ...     ...
        j    _____ ...  k
            /... /|
      i    +----+ /
          | 01 |/ ... ... ...
          +----+
    */
    int MatrizMultDimensional[5][3][3][2][2]/*...[n]*/; 


/* =============================================================
   || 2. Inicialização de Matrizes com Valores                ||
   ============================================================= */
  // Garante linearidade dos dados de forma física na memória
  // Acesso imediato aos dados sendo O(1)

  /*
  * 2.1 Inicialização completa:
  *    Todos os elementos são explicitamente definidos.
  *    Exemplo:
  *        +----+----+----+
  *    [0] |  1 |  2 |  3 |
  *        +----+----+----+
  *    [1] |  4 |  5 |  6 |
  *        +----+----+----+
  */
  int matrizCompleta[2][3] = { {1, 2, 3}, {4, 5, 6} };

  /*
   * 2.2 Inicialização parcial:
   *    Apenas alguns elementos são definidos; os demais são inicializados com zero.
   *    Exemplo:
   *        +----+----+----+
   *    [0] |  1 |  0 |  0 |
   *        +----+----+----+
   *    [1] |  4 |  5 |  0 |
   *        +----+----+----+
   */
  int matrizParcial[2][3] = { {1}, {4, 5} };


  /*
   * 2.3 Inicialização linear:
   *    Elementos fornecidos em sequência, preenchendo linha por linha.
   *    Exemplo:
   *        +----+----+----+
   *    [0] |  1 |  2 |  3 |
   *        +----+----+----+
   *    [1] |  4 |  5 |  6 |
   *        +----+----+----+
   */
  int matrizLinear[2][3] = {1, 2, 3, 4, 5, 6};

  /*
   * 2.4 Inicialização zerada:
   *    Todos os elementos são inicializados com zero.
    *    Exemplo:
    *        +----+----+----+
    *    [0] |  0 |  0 |  0 |
    *        +----+----+----+
    *    [1] |  0 |  0 |  0 |
    *        +----+----+----+
    */
  int matrizZerada[2][3] = {0};

  /*
   * 2.5 Inicialização de matriz multidimensional maior:
   *    Exemplo prático com 5 linhas e 3 colunas.
   *        +----+----+----+
   *    [0] |  1 |  2 |  3 |
   *        +----+----+----+
   *    [1] |  5 |  7 |  3 |
   *        +----+----+----+
   *    [2] |  7 |  5 |  3 |
   *        +----+----+----+
   *    [3] |  1 |  5 |  9 |
   *        +----+----+----+
   *    [4] |  7 |  4 |  1 |
   *        +----+----+----+
   */
  int matrizMultDimensionalItens[5][3] = { {1, 2, 3}, {5, 7, 3}, {7, 5, 3}, {1, 5, 9}, {7, 4, 1} };


/* =============================================================
   || 3. Declaração de dimensão relativa à inicialização      ||
   ============================================================= */
// Garante linearidade dos dados de forma física na memória
// Acesso imediato aos dados sendo O(1)

// 3.1 Matriz unidimensional, com itens na inicialização e declaração relativa:
int MatrizItens[] = {1, 3, 6, 8};
/* Aqui o tamanho da matriz é automaticamente escolhido ao ser compilado,
 * de acordo com o número de elementos inicializados.
 * Exemplo:
 *     +----+----+----+----+
 *     | 01 | 03 | 06 | 08 |
 *     +----+----+----+----+
 *  i  [00] [01] [02] [03]
 */
int tamanhoMatrizItens = sizeof(MatrizItens)/sizeof(int);
printf("Tamanho da Matriz de itens eh: %d >> [bytes: %d]\n", tamanhoMatrizItens, sizeof(MatrizItens));


// 3.2 Matriz bidimensional, com tamanho de linha omitido na declaração:
int matrizTamanhoOmitido[][3] = { {1, 2, 3}, {4, 5, 6} };

  /* Aqui o número de linhas é automaticamente determinado pelo compilador,
   * de acordo com o número de subarrays inicializados.
   * Neste exemplo, temos 2 linhas e 3 colunas.
   */

  /*
         +----+----+----+
     [0] |  1 |  2 |  3 |
         +----+----+----+
     [1] |  4 |  5 |  6 |
         +----+----+----+
  */

  /* 
   * Calculando o número de linhas e o número total de elementos
   * da matriz com tamanho de linha omitido na declaração.
   *
   * - O número de linhas é obtido dividindo o tamanho total da matriz
   *   pelo tamanho de uma linha (subarray).
   * 
   * - O número total de elementos é obtido dividindo o tamanho total da matriz
   *   pelo tamanho de um elemento (int).
   */

    // sizeof(matrizTamanhoOmitido)/sizeof(matrizTamanhoOmitido[0]) >> É igual a 2 linhas.
    int linhasMatrizTamanhoOmitido = sizeof(matrizTamanhoOmitido)/sizeof(matrizTamanhoOmitido[0]);

    // sizeof(matrizTamanhoOmitido)/sizeof(int) >> É igual ao número total de elementos da matriz.
    int elementosMatrizTamanhoOmitido = sizeof(matrizTamanhoOmitido)/sizeof(int);

    printf("Numero de linhas da matriz com tamanho omitido: %d\n", linhasMatrizTamanhoOmitido);
    printf("Numero total de elementos da matriz com tamanho omitido: %d\n", elementosMatrizTamanhoOmitido);


/* =============================================================
   || 4. Inicialização com Constantes e #define               ||
   ============================================================= */
    // Utilizando constantes simbólicas para definir tamanhos de matrizes.

    // 4.1 Inicialização zerada usando #define
    #define LINHAS 2
    #define COLUNAS 3

    int matrizConstDefine[LINHAS][COLUNAS] = {0};

    // 4.2 Inicialização com constantes
    const int LINHAS_CONST = 2;
    const int COLUNAS_CONST = 3;

    int matrizConstante[LINHAS_CONST][COLUNAS_CONST] = {0};


/* =============================================================
   || 5. Inicialização sem valores explícitos (Indefinidos)   ||
   ============================================================= */
  // Elementos não inicializados (valores indefinidos/lixo)
  int matrizNaoInicializada[2][3];


/* =============================================================
   || 6. Inicialização Dinâmica com malloc e calloc           ||
   ============================================================= */
  /*
    * 6.1 Linearidade garantida (bloco único):
    *    Aloca todos os elementos em um único bloco de memória, garantindo linearidade.
    *    O acesso é feito por aritmética de índices.
  */

    int linhas = 2, colunas = 3;

    int *matrizMalloc = malloc(linhas * colunas * sizeof(int)); // malloc

    int *matrizCalloc = calloc(linhas * colunas, sizeof(int));  // calloc (inicializa com zero)
    /* Uso: matrizMalloc[i * colunas + j]
     * Neste caso, como a matriz foi alocada dinamicamente em um bloco linear de memória (com malloc ou calloc),
     * o acesso ao elemento da linha i e coluna j deve ser feito usando a fórmula: i * colunas + j.
     * Isso garante que cada elemento seja acessado corretamente, simulando o comportamento de uma matriz bidimensional.
     * Exemplo de atribuição: matrizMalloc[1 * colunas + 2] = 10; // atribui o valor 10 à posição [1][2]
    */
    // Exemplo de uso: preenchendo e exibindo a matrizMalloc
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        matrizMalloc[i * colunas + j] = (i * colunas + j + 1); // Preenche com valores sequenciais
      }
    }
    printf("Conteudo da matrizMalloc:\n");
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("%d ", matrizMalloc[i * colunas + j]);
      }
      printf("\n");
    }

    //Sempre que usar malloc ou calloc fazer a liberação da memória
    free(matrizMalloc);
    free(matrizCalloc);


  /*==========================================================================================*/
    /*
    * 6.2 Ponteiro de ponteiro (não garante linearidade): <<<<< [ATENÇÃO]
    *    Cada linha é alocada separadamente, podendo ficar em locais diferentes na memória.
    */

    int **matrizPonteiro = (int**)malloc(linhas * sizeof(int*)); // Também pode ser feito com calloc
    for (int i = 0; i < linhas; i++)
        matrizPonteiro[i] = (int**)malloc(colunas * sizeof(int)); // Também pode ser feito com calloc

    // Uso: matrizPonteiro[i][j]

    // Apesar da não linearidade física dos dados acesso é feito de maneira parecida a declaração convencional

    /* Neste caso, cada linha da matriz é alocada separadamente na memória, formando um vetor de ponteiros para vetores.
     * O acesso ao elemento da linha i e coluna j é feito diretamente por matrizPonteiro[i][j], como em uma matriz estática.
     * Atenção: como as linhas podem estar em locais diferentes na memória, não há garantia de linearidade física.
     * Exemplo de atribuição: matrizPonteiro[1][2] = 10; // atribui o valor 10 à posição [1][2]
    */

    // Exemplo prático: preenchendo e exibindo a matrizPonteiro:
    /*------------------------------------------------------------------------------------------------------*/
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        matrizPonteiro[i][j] = (i + 1) * 10 + (j + 1); // Exemplo: 11, 12, 13, 21, 22, 23
      }
    }
    printf("Conteudo da matrizPonteiro:\n");
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("%d ", matrizPonteiro[i][j]);
      }
      printf("\n");
    }

    // Liberação de memória dinâmica
    for (int i = 0; i < linhas; i++) // Verre linha a linha para excluir
        free(matrizPonteiro[i]); // Limpa cada linha de maneira individual
    free(matrizPonteiro); //Limpa o local que está armazenado o conjunto de linhas
  /*------------------------------------------------------------------------------------------------------*/

/* =============================================================
   || 7. Inicialização de Matrizes Multidimensionais Dinâmicas ||
   ============================================================= */
  /*
   * 7.1 Exemplo de matriz tridimensional dinâmica (ponteiros de ponteiros de ponteiros)
   * Também nesse formato cada alocação de memória não é garantido o alinhamento físico a memória,
   * apenas o conjunto de cada reserva de endereços (cada conjunto endereçado pelo malloc ou calloc é garantido)
  */
    int profundidade = 2, altura = 3, largura = 4;
    int ***matriz3D = malloc(profundidade * sizeof(int**));
    for (int i = 0; i < profundidade; i++) {
        matriz3D[i] = malloc(altura * sizeof(int*));
        for (int j = 0; j < altura; j++) {
            matriz3D[i][j] = malloc(largura * sizeof(int));
        }
    }
    // Uso: matriz3D[i][j][k]
    // Liberação:
    for (int i = 0; i < profundidade; i++) {
        for (int j = 0; j < altura; j++) {
            free(matriz3D[i][j]);
        }
        free(matriz3D[i]);
    }
    free(matriz3D);

/* =============================================================
   || 8. Inicialização com Variáveis (VLA - C99+)             ||
   ============================================================= */
  /*
   * 8.1 A partir do C99, é possível declarar matrizes com tamanhos definidos por variáveis.
   * Exemplo:
  */
    int linha = 3, coluna = 4;
    int matrizVLA[linha][coluna]; // VLA: Variable Length Array (C99+)
  /*
   * Observação: Não é permitido em C90. Para máxima portabilidade, prefira #define ou alocação dinâmica.
  */
  //Não é indicado, mesmo que sendo possível para os compiladores mais recentes.

return 0;
}