# include <stdio.h>
# include <stdlib.h>

/*
 * Este arquivo foi criado durante a monitoria para exemplificar
 * a criação de funções de impressão mais elaboradas e o cálculo
 * de índices para visualização.
 *
 * Esta função de impressão provém da "Atividade 5" do Simulado_02.md
 * deste mesmo repositório:
 * https://github.com/DiegoAntonio-M/Monitoria-AEDS1/blob/main/Simulados/Simulado%2002/Simulado_02.md
*/

#define LARGURA 6
#define FILEIRAS 16

void imprimirSalaDeCinema(int poltronas[FILEIRAS * LARGURA]) {

    printf("_______________________________.    .\n");
    for (int i = 0; i < FILEIRAS; i++)
    {
        printf("|=| ");
        for (int j = 0; j < LARGURA; j++)
        {
            int index = (FILEIRAS * LARGURA) - (i * LARGURA + (LARGURA - j));
            if (poltronas[index] == 0) {
                printf("[%02d]", index + 1);
            } else {
                printf("[--]");
            }
        }
        (i == 0) ? printf(" |=|\\  /|\n") : printf(" |=|    |\n");
    }
    printf("|                                   |\n");
    printf("|___________________________________|\n");
}

int main() {

    int poltronas[FILEIRAS * LARGURA] = {};
    int local = 0;
    int RA = 1241515;

    imprimirSalaDeCinema(poltronas);

    //Implementado apenas o procedimento de reserva de uma poltona
    do {
        fputs("Digite o acessendo a ser reservado: ", stdout);
        scanf("%d", &local);
    } while (poltronas[--local] != 0);

    poltronas[--local] = RA;

    imprimirSalaDeCinema(poltronas);

    return 0;
}