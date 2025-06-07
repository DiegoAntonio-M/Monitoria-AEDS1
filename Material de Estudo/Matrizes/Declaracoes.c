/*
 * Exeplos de declaracoes de Matrizes
 *
 *
 *
 */

/* ========================================
   ||     Declaracao com valor fixo      ||
   ========================================*/

// Matriz quadrada: ij quando i = j >> matriz[i][j]
/*      +----+----+
    [1] | 01 | 02 |
  i     +----+----+
    [2] | 01 | 02 |
        +----+----+
*/
int matrizQuadrada[2][2] = {};

// Matriz retangular: ij quando i ≠ j >> matriz[i][j]

  /*           j
            v    v    v
          +----+----+----+
      [1] | 01 | 02 | 03 |
    i     +----+----+----+
      [2] | 01 | 02 | 03 |
          +----+----+----+
  */
int matrizRetangular1[2][3] = {};

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

// Matriz cubica: ijk quando i = j = k >> matriz[i][j][k]
  /*       k __________
           /----/-----/|
        j +----+----/ ||
      [1] | 01 | 02 | ||
    i     +----+----+ |/
      [2] | 01 | 02 | /
          +----+----+/
  */
int matrizCubica[2][2][2];

// Matriz paralelepipedo: ijk quando i ≠ j ≠ k, i = j ≠ k, i ≠ j = k >>
// matriz[i][j][k]

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

// Matriz Multidimensional ou matriz n dimensoes: ijk ..., (n de dimensoes) > 1  >> matriz[i][j][k]...[n]

  /*
           ...   l   ...
           ...     ...
       j   _____ ...  k
          /... /|
  i      +----+ /
         | 01 |/ ... ... ...
         +----+
  */

int MatrizMultDimensional[5][3][3][2][2]/*...[n]*/; 

/* ===============================================
   ||  Declaracao com relativo a inicialização  ||
   ===============================================*/

  //matriz unidimensional, com itens na inicialização com declaracao relativa:
   int MatrizItens[] = {1, 3, 6, 8};

   /*Aqui o tamanho da matriz é automaticamente escolhido ao ser compilado,
    *de acordo com o numero de elementos inicializado */

   // sizeof(MatrizItens)/sizeof(int) >> É igual a 4 itens. (cada item de tipo inteiro cabem 4 bytes)

  //Matriz Multidimensional, com itens na inicialização com declaracao relativa:
  int MatrizMultDimensionalItens[][3] = {{1 , 2 , 3}, {5, 7, 3}, {7, 5, 3}, {1, 5, 9}, {7, 4, 1}};
  
  //

# include <stdio.h>
int main() {

    printf("%d", sizeof(MatrizItens)/sizeof(int));

    return 0;
}