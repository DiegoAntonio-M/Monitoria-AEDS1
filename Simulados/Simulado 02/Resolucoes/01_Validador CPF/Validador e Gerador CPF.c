#include <stdio.h>

#define TAMANHO_STRING_CPF 11 // 9 dígitos + 2 verificadores

// Função que gera os dois dígitos verificadores do CPF a partir dos 9 primeiros dígitos
int gerarDigitosCPF(char cpf[TAMANHO_STRING_CPF]) {
    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i); // Multiplica cada dígito pelo peso correspondente
    }
    int digito1 = soma % 11;
    if (digito1 < 2)
        digito1 = 0;
    else
        digito1 = 11 - digito1;

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (11 - i); // Multiplica cada dígito pelo peso correspondente
    }
    soma += digito1 * 2; // Adiciona o primeiro dígito verificador com peso 2
    int digito2 = soma % 11;
    if (digito2 < 2)
        digito2 = 0;
    else
        digito2 = 11 - digito2;

    // Retorna os dois dígitos verificadores juntos (ex: 34 para dígitos 3 e 4)
    return digito1 * 10 + digito2;
}

// Função que valida um CPF completo (11 dígitos)
int validarCPF(char cpf[TAMANHO_STRING_CPF]) {
    // Verifica se todos os dígitos do CPF são iguais.
    // Isso é necessário porque CPFs compostos apenas por dígitos repetidos (ex: 11111111111, 00000000000)
    // são considerados inválidos, mesmo que passem pelo cálculo dos dígitos verificadores.
    int iguais = 1;
    for (int i = 1; i < 9; i++) {
        if (cpf[i] != cpf[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) return 0;

    // Gera os dígitos verificadores esperados
    int digitos = gerarDigitosCPF(cpf);
    int digito1 = digitos / 10;
    int digito2 = digitos % 10;

    // Compara com os dígitos informados no CPF
    if ((cpf[9] - '0') == digito1 && (cpf[10] - '0') == digito2) {
        return 1; // CPF válido
    }
    return 0; // CPF inválido
}

// Função para ler o CPF do usuário, aceitando com ou sem máscara
// Retorna 1 se conseguiu ler corretamente, 0 caso contrário
int getCPF(char cpf[TAMANHO_STRING_CPF]) {
    char getCPF[TAMANHO_STRING_CPF + 5] = {}; // Buffer auxiliar para leitura
    fgets(getCPF, TAMANHO_STRING_CPF + 4, stdin);

    int i = 0;
    int writer = 0;
    char c;
    // Percorre cada caractere lido
    while (!((c = getCPF[i]) == '\n' || c == 0) && writer < TAMANHO_STRING_CPF) {
        if ('0' <= c && c <= '9') {
            cpf[writer++] = getCPF[i]; // Copia apenas os dígitos numéricos
        } else if(!(c == '.' || c == '-')) {
            return 0; // Se encontrar caractere inválido, retorna erro
        }
        i++;
    }
    // Para geração, espera 9 dígitos; para validação, espera 11
    return (writer == 9 || writer == 11) ? 1 : 0;
}

int main() {

    char cpf[TAMANHO_STRING_CPF] = {}; // Vetor para armazenar o CPF

    // while (!getCPF(cpf)) {
    //     fputs(">#>#> Caracteres inválidos!", stdout);
    // }
    int opcao = 0;
    do {
        // Sempre que iniciar, reseta o vetor cpf
        for (int i = 0; i < TAMANHO_STRING_CPF; i++) {
            cpf[i] = 0;
        }
        printf("\nEscolha uma opção:\n");
        printf("1 - Gerar dígitos verificadores do CPF\n");
        printf("2 - Validar um CPF\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); // Limpa entrada inválida
            opcao = -1;
        }
        getchar(); // Limpa o '\n' do buffer

        if (opcao == 1) {
            // Geração dos dígitos verificadores
            printf("\nDigite os 9 primeiros dígitos do CPF: \n>>>> ");
            if (getCPF(cpf)) {
                // Gera e mostra os dígitos verificadores
                int digitos = gerarDigitosCPF(cpf);
                int digito1 = digitos / 10;
                int digito2 = digitos % 10;
                printf("Dígitos verificadores: %d%d\n", digito1, digito2);
                printf("CPF completo: ");
                // Imprime os 9 dígitos digitados (preenchendo com '0' se necessário)
                for (int i = 0; i < 9; i++) {
                    char c = cpf[i];
                    putchar(c != 0 ? c : '0');
                }
                // Imprime os dígitos verificadores
                printf("%d%d\n", digito1, digito2);
            } else {
                printf("#>#> Entrada inválida! Digite apenas os 9 dígitos.\n");
            }
        } else if (opcao == 2) {
            // Validação de CPF completo
            printf("\nDigite o CPF completo (11 dígitos): \n>>>> ");
            if (getCPF(cpf)) {
                if (validarCPF(cpf)) {
                    printf(">>>> CPF válido!\n");
                } else {
                    printf("#>#> CPF inválido!\n");
                }
            } else {
                printf("#>#> Entrada inválida! Digite os 11 dígitos do CPF.\n");
            }
        } else if (opcao != 0) {
            printf("#>#> Opção inválida!\n");
        }
    } while (opcao != 0);
    printf("Saindo do programa ...\n");
    return 0;
}