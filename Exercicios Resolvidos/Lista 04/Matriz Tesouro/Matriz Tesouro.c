# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define TABLE_LINHA 5
#define TABLE_COLUNA 5
#define TENTATIVAS_MAX 10

void colocarTesouro(int tabuleiro[TABLE_LINHA][TABLE_COLUNA], int quant){
    srand(time(NULL));
    int count = 0;
    while (count < quant) {
        int linha = rand() % TABLE_LINHA;
        int coluna = rand() % TABLE_COLUNA;
        if (tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = 1; // 1 Representa o tesouro colocado
            count++;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTable(int tabuleiro[TABLE_LINHA][TABLE_COLUNA], int inGame) {
    for (int i = 0; i < TABLE_LINHA; i++) {
        printf("---------------------\n");
        for (int j = 0; j < TABLE_COLUNA; j++) {
            if(inGame != 1) printf("| %d ", tabuleiro[i][j]); else {
                switch (tabuleiro[i][j])
                {
                case 0:
                    printf("|   ");
                    break;
                case 1:
                    printf("|   ");
                    break;
                case -1:
                    printf("| X ");
                    break;
                case 2:
                    printf("| # ");
                    break;
                default:
                    break;
                }
            }
        }
        printf("|\n");
    }
    printf("---------------------\n\n");
}

int main() {

    int tabuleiro[TABLE_LINHA][TABLE_COLUNA] = {};
    const int quantTesouro = 3;
    int coodLinha = 0;
    int coodColuna = 0;

    colocarTesouro(tabuleiro, quantTesouro);

    int tentativa = 0;
    int tesourosEncontrados = 0;

    do
    {
        imprimirTable(tabuleiro, 1);
        printf("[%d/%d] Digite a posição: ", tentativa + 1, TENTATIVAS_MAX);
        scanf("%d %d", &coodLinha, &coodColuna);

        // Ajusta para índices baseados em zero
        coodLinha--;
        coodColuna--;
        // Verifica se as coordenadas estão dentro dos limites
        if (coodLinha < 0 || coodLinha >= TABLE_LINHA || coodColuna < 0 || coodColuna >= TABLE_COLUNA) {
            printf(">>>> Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        switch (tabuleiro[coodLinha][coodColuna])
        {
        case 0:
                printf(">>>> Nada aqui!\n");
                tabuleiro[coodLinha][coodColuna] = -1;
            break;
        case 1:
                printf(">>>> Tesouro encontado !\n");
                tabuleiro[coodLinha][coodColuna] = 2;
                tesourosEncontrados++;
            break;

        case 2:
                printf(">>>> Tesouro já foi encontado aqui!\nTente outra posição!\n");
                tentativa--;

            break;
        case -1:
                printf(">>>> Você já jogou aqui!\nTente outra posição!\n");
                tentativa--;

            break;
        
        default:
            break;
        }
        tentativa++;

    } while (tentativa < TENTATIVAS_MAX && tesourosEncontrados < quantTesouro);

    if (tesourosEncontrados == quantTesouro) {
        printf(">>>>> Parabens, Você encontrou todos os tesouros!!!\n");
    } else {
        printf(">#>#> Suas tentativas acabaram\n");
    }
    
    
    imprimirTable(tabuleiro, 0);

    return 0;
}