#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[51];
    int matricula;
    float nota;
};

//Função e Gravar aluno
void salvarAluno(const char arquivoName[], struct aluno *alunos, int *quantAlunosMAX) {
    FILE *arquivo = fopen(arquivoName, "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    // Gravar alunos
    fwrite(quantAlunosMAX, 1, sizeof(int), arquivo); // Grava a quantidade de alunos
    fwrite(alunos, sizeof(struct aluno), *quantAlunosMAX, arquivo); // Grava os dados dos alunos

    fclose(arquivo);
}

//Carregar ALunos
struct aluno* carregarAluno (const char arquivoName[], int *quantAlunosMAX, int *alunosInseridos) {
    FILE *arquivo = fopen(arquivoName, "r");
    if (!arquivo) {
        struct aluno *alunos = calloc(*quantAlunosMAX, sizeof(struct aluno));
        *alunosInseridos = 0;
        return alunos;
    }
    // Ler a quantidade de alunos
    fread(quantAlunosMAX, sizeof(int), 1, arquivo);
    struct aluno *alunos = calloc(*quantAlunosMAX, sizeof(struct aluno));
    fread(alunos, sizeof(struct aluno), *quantAlunosMAX, arquivo); // Lê os dados dos alunos
    *alunosInseridos = *quantAlunosMAX;

    fclose(arquivo);
    return alunos;
}

//Cadastro
void cadastroAluno(struct aluno *alunos, int MAX, int *alunosInseridos) {
    if (*alunosInseridos < MAX) {
        //Limpar entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
        fputs("Digite o nome: ", stdout);
        fgets(alunos[*alunosInseridos].nome, 51, stdin);
        fputs("Digite a matricula: ", stdout);
        scanf("%d", &alunos[*alunosInseridos].matricula);
        fputs("Digite a nota: ", stdout);
        scanf("%f", &alunos[*alunosInseridos].nota);
        // Limpar o buffer de entrada
        while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
        (*alunosInseridos)++;
    } else {
        fputs("Sem espaço na sala", stdout);
    }
}

//Aumentar espaço na sala
void remanejarSala(struct aluno **alunos, int *quantAlunosMAX) {
    printf("Quantos alunos deseja adicionar: ");
    int quantAdd = 0;
    scanf("%d", &quantAdd);

    (*quantAlunosMAX) += quantAdd;

    struct aluno *tmp = realloc(*alunos, *quantAlunosMAX * sizeof(struct aluno));
    if (tmp == NULL) {
        printf("Erro ao realocar memória!\n");
        exit(1);
    }
    *alunos = tmp;

    printf("Quantidade ALocada: %d aluno(s)\n", *quantAlunosMAX);
}

void imprimirAlunoPorIndice(struct aluno *alunos, int indice) {
    if (indice < 0) {
        fputs("Aluno não encontrado\n", stdout);
        return;
    }
    printf("\n======================\n");
    printf("Aluno encontrado:\n");
    printf("Nome: %s", alunos[indice].nome);
    printf("Matrícula: %d\n", alunos[indice].matricula);
    printf("Nota: %.2f\n", alunos[indice].nota);
    printf("======================\n");
}

//Buscar Aluno por matricula
int buscarAlunoMatricula(struct aluno *alunos, int MAX) {
    
    fputs("Digite a matricula: ", stdout);
    int pesquisaMatricula = 0;
    scanf("%d", &pesquisaMatricula);

    for (int i = 0; i < MAX; i++)
    {
        if (alunos[i].matricula == pesquisaMatricula) {
            return i;
        }
    }
    return -1;
}


int main() {

    int quantAlunosMAX = 5;
    int alunosInseridos = 0;
    struct aluno *alunos = carregarAluno("Exercicios Resolvidos\\Prova 03\\Questao 01.txt", &quantAlunosMAX, &alunosInseridos);
    int opcao = 0;
    do
        {
        fputs("1. Cadastrar Aluno\n", stdout);
        fputs("2. Buscar Aluno (por matrícula)\n", stdout);
        fputs("3. Remanejar Sala\n", stdout);


        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastroAluno(alunos, quantAlunosMAX, &alunosInseridos);

        case 2: {
                int indice = buscarAlunoMatricula(alunos, alunosInseridos);
                imprimirAlunoPorIndice(alunos, indice);
            }
            break;
        case 3:
            remanejarSala(&alunos, &quantAlunosMAX);
            break;
        
        default:
            break;
        }
    } while (opcao != 0);
    
    salvarAluno("Exercicios Resolvidos\\Prova 03\\Questao 01.txt", alunos, &quantAlunosMAX);

    return 0;
}
