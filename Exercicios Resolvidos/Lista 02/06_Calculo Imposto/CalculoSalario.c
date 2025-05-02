// Calculo de Salário com Descontos e Benefícios

/* Este programa calcula o salário final de um funcionário com base em seu salário por hora,
 horas trabalhadas, horas extras e número de dependentes. Ele aplica descontos e benefícios */


/* Inclui as bibliotecas necessárias para entrada/saída e funções matemáticas
 A biblioteca <stdio.h> é usada para funções de entrada/saída, como printf e scanf */
#include <stdio.h>

int main() {

    // Declaração de variáveis
    // "Boas praticas" de incializar as variaveis com 0 para evitar lixo de memoria
    float salarioBase = 0;
    float salarioHora = 0;
    float horasTrabalhadas = 0;
    float horasExtras = 0;
    int numDependentes = 0;


    // Solicita os dados do usuário que preencherão as variáveis
    // Salario por hora, horas trabalhadas, horas extras e numero de dependentes
    printf("Digite o Salario por hora: ");
    scanf("%f", &salarioHora);

    printf("Digite as horas trabalhadas: ");
    scanf("%f", &horasTrabalhadas);

    printf("Digite as horas extras: ");
    scanf("%f", &horasExtras);

    printf("Numero de Dependentes: ");
    scanf("%d", &numDependentes);

    // Define o valor do beneficio por dependente
    // O valor do beneficio por dependente é fixo e definido como 128.00
    float beneficioDependente = 128.00;

    // Calcula o salário base
    // Salario base = (salario hora * horas trabalhadas) + (salario hora * horas extras * 1.5)
    salarioBase = salarioHora * horasTrabalhadas + salarioHora * horasExtras * 1.5;


    // Aplica o beneficio de acordo com o numero de dependentes
    // Salario base = salario base + beneficio dependente * numero de dependentes
    // O uso do (float) é para garantir que a divisão seja feita com ponto flutuante (como se fosse um conversor apenas para esse calculo)
    salarioBase += beneficioDependente * ((float)numDependentes);


    // Aplica o desconto de acordo com o salario base
    // Ifs para a escolha de acordo com os intervalos de salario base

    /* Para a lógica do intevalo deve se usar && < e > para definir que os valor deve estar entre
       dois limites inferior < e > superior */

    //  Intervalo aberto:  "<"  e ">" 
    //  Intervalo Fechado: "<=" e ">="

    if (1434.60 < salarioBase && salarioBase <= 2150) {
        salarioBase *= (1 - 0.075);

    } else if (2150 < salarioBase && salarioBase <= 2866.70) {
        salarioBase *= (1 - 0.150);

    } else if (2866.70 < salarioBase && salarioBase <= 3582.00) {
        salarioBase *= (1 - 0.2250);
        
    } else if (3582.00 < salarioBase) {
        salarioBase *= (1 - 0.2750);
    }

    // Aplica um benificio de acordo com a faixa salarial
    if (salarioBase <= 500){
        salarioBase += 180.00;
    } else if (500 < salarioBase && salarioBase <= 1000) {
        salarioBase += 120.00;
    } else if (1000 < salarioBase) {
        salarioBase += 100.00;
    }

    // Exibe o salário final
    // "%.2f" para exibir o valor com duas casas decimais
    printf("Salario final apos descontos: %.2f\n", salarioBase);

    // Retorna 0 para indicar que o programa foi executado com sucesso
    // O retorno 0 é uma >convenção< em C para indicar que o programa terminou sem erros
    return 0;
}