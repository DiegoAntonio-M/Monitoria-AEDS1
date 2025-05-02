# include <stdio.h>
# include <math.h>


int main() {

    float x = 0;
    float hx = 0;
    float gx = 0;
    float fx = 0;

    printf("Digite um valor para x: ");
    scanf("%f", &x);

    //Calculo da Função h(x)
    hx = x*x + 3*x - 20;

    //Teste e Atribuição para g(x)
    if (hx <= 5) {
        gx = 5;
    } else if (5 < hx) {
        gx = hx;
    }
    
    //Teste e atribuição para f(x)
    if (10 < gx) {
        fx = x + 2 * powf(x, 2);
    } else if (gx <= 10) {
        fx = 10;
    }

    printf("Resultado: %.2f", fx);

    return 0;
}