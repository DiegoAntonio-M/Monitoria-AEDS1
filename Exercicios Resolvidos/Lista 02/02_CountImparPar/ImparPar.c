// Contar quantos numeros pares e impares foram digitados pelo usuario


/*  O programa deve solicitar 5 numeros e contar quantos deles sao pares e quantos sao impares
    O resultado deve ser exibido na tela
    Restrição: Não usar mais que 3 variaveis */

# include <stdio.h>

int main() {

    // Inicializa as 3 variaveis
    // n: numero digitado pelo usuario
    // par: contador de numeros pares
    // impar: contador de numeros impares
    int n = 0;
    int par = 0;
    int impar = 0;

    // Solicita o 1º numero ao usuario
    printf("[1] Digite um numero: ");
    scanf("%d", &n);

    // Verifica se o numero digitado é par ou impar e incrementa o contador correspondente
    // O operador % (modulo) retorna o resto da divisão entre dois numeros
    if (n % 2 == 0) {
        par++;
    } else {
        impar++;
    }

    // Solicita o 2º numero ao usuario
    printf("[2] Digite um numero: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        par++;
    } else {
        impar++;
    }

    // Solicita o 3º numero ao usuario
    printf("[3] Digite um numero: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        par++;
    } else {
        impar++;
    }

    // Solicita o 4º numero ao usuario
    printf("[4] Digite um numero: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        par++;
    } else {
        impar++;
    }

    // Solicita o 5º numero ao usuario
    printf("[5] Digite um numero: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        par++;
    } else {
        impar++;
    }

    // Exibe o resultado na tela
    // O resultado é exibido com o contador de numeros pares e impares
    // O operador %d é usado para formatar a saida como um numero inteiro
    // O operador \n é usado para pular uma linha na saida
    printf("Quant Par: %d.\nQuant Impar: %d\n", par, impar);

    return 0;
}