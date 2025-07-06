# 🌌 Sistema Solar Interativo - Estruturas, Ponteiros e Arquivos

## Objetivos do Exercício

Este exercício tem como objetivo explorar conceitos fundamentais de **Algoritmos e Estruturas de Dados I**:
- Estruturas de dados compostas (structs)
- Ponteiros e alocação dinâmica de memória
- Manipulação de arquivos (salvamento e carregamento)
- Gerenciamento de memória dinâmica
- Arrays dinâmicos

## 📋 Descrição do Projeto

Você deve implementar um sistema de catalogação de sistemas solares, onde cada sistema solar contém uma estrela central e um conjunto de planetas que podem ser adicionados dinamicamente. O sistema deve ser capaz de:

1. Criar e gerenciar sistemas solares
2. Adicionar/remover planetas dinamicamente
3. Salvar o sistema solar em arquivo
4. Carregar o sistema solar de arquivo
5. Exibir informações detalhadas

## 🏗️ Estruturas de Dados

### 1. Estrutura para Informações Descritivas
```c
typedef struct {
    char sobrePlaneta[500];           // Descrição geral do planeta
    char descobridor[100];            // Nome do descobridor
    char dataDescoberta[20];          // Data da descoberta (formato: DD/MM/AAAA)
    char codigoPlaneta[20];           // Código científico do planeta
} DescricaoInfos;
```

### 2. Estrutura da Estrela
```c
typedef struct {
    char nomeEstrela[50];             // Nome da estrela
    long long int massa;              // Massa da estrela em kg
    long long int raio;               // Raio da estrela em km
    float temperaturaSuperficie;      // Temperatura da superfície em Kelvin
    float luminosidade;               // Luminosidade relativa ao Sol
    char tipoEstelar[10];             // Tipo estelar (G, K, M, etc.)
    char cor[20];                     // Cor da estrela
    float idade;                      // Idade em bilhões de anos
} Estrela;
```

### 3. Estrutura do Planeta
```c
typedef struct {
    char nomePlaneta[50];             // Nome do planeta
    float temperaturaMedia;           // Temperatura média em Celsius
    int quantidade_SatelitesNaturais; // Número de satélites naturais (luas)
    int quantidade_SatelitesArtificiais; // Número de satélites artificiais
    int quantidade_Aneis;             // Número de anéis
    float umidadeMedia;               // Umidade média em porcentagem
    long long int massa;              // Massa em kg
    long long int raio;               // Raio em km
    float duracaoAno;                 // Duração do ano em dias terrestres
    float duracaoDia;                 // Duração do dia em horas
    float distanciaEstrela;           // Distância da estrela em UA (Unidades Astronômicas)
    DescricaoInfos infos;             // Informações descritivas
} Planeta;
```

### 4. Estrutura do Sistema Solar
```c
typedef struct {
    char nomeSistema[50];             // Nome do sistema solar
    int quantidadeEstrelas;           // Número atual de estrelas
    int capacidadeEstrelas;           // Capacidade máxima atual do array de estrelas
    Estrela* estrelas;                // Array dinâmico de estrelas
    int quantidadePlanetas;           // Número atual de planetas
    int capacidadePlanetas;           // Capacidade máxima atual do array de planetas
    Planeta* planetas;                // Array dinâmico de planetas
} SistemaSolar;
```

## 📖 Sobre a Nomenclatura Científica dos Planetas

A nomenclatura científica para exoplanetas segue o padrão:
- **Estrela + sufixo**: O nome da estrela hospedeira seguido de uma letra minúscula
- **Ordem de descoberta**: 'b' para o primeiro planeta descoberto, 'c' para o segundo, etc.
- **Exemplos**: Kepler-452b, HD 209458b, TRAPPIST-1e

**Formato sugerido para o código**: `[NomeEstrela][Letra][Ano]`
- Exemplo: "Sol-b-2024", "Proxima-c-2023"

### 🌟 Tipos de Sistemas Estelares
- **Sistema simples**: Uma única estrela (como nosso Sol)
- **Sistema binário**: Duas estrelas orbitando um centro comum
- **Sistema múltiplo**: Três ou mais estrelas (ex: Alpha Centauri)

## 🎯 Funcionalidades Obrigatórias

### 1. Gerenciamento de Memória
- [ ] Função para inicializar sistema solar
- [ ] Função para adicionar estrela (com realocação dinâmica)
- [ ] Função para adicionar planeta (com realocação dinâmica)
- [ ] Função para remover estrela
- [ ] Função para remover planeta
- [ ] Função para liberar toda a memória alocada

### 2. Manipulação de Arquivos
- [ ] Função para salvar sistema solar em arquivo binário
- [ ] Função para carregar sistema solar de arquivo binário
- [ ] Tratamento de erros de arquivo

### 3. Interface do Usuário
- [ ] Menu interativo
- [ ] Função para exibir informações do sistema solar completo
- [ ] Função para exibir informações de uma estrela específica
- [ ] Função para exibir informações de um planeta específico
- [ ] Função para listar todas as estrelas
- [ ] Função para listar todos os planetas

## 🔧 Implementação Sugerida

### Estrutura do Programa Principal
```c
int main() {
    SistemaSolar* sistema = NULL;
    int opcao;
    
    do {
        printf("\n=== SISTEMA SOLAR INTERATIVO ===\n");
        printf("1. Criar novo sistema solar\n");
        printf("2. Carregar sistema solar\n");
        printf("3. Adicionar estrela\n");
        printf("4. Adicionar planeta\n");
        printf("5. Remover estrela\n");
        printf("6. Remover planeta\n");
        printf("7. Exibir sistema solar completo\n");
        printf("8. Exibir estrelas\n");
        printf("9. Exibir planetas\n");
        printf("10. Salvar sistema solar\n");
        printf("11. Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: /* Implementar criação */ break;
            case 2: /* Implementar carregamento */ break;
            case 3: /* Implementar adição de estrela */ break;
            case 4: /* Implementar adição de planeta */ break;
            case 5: /* Implementar remoção de estrela */ break;
            case 6: /* Implementar remoção de planeta */ break;
            case 7: /* Implementar exibição completa */ break;
            case 8: /* Implementar exibição de estrelas */ break;
            case 9: /* Implementar exibição de planetas */ break;
            case 10: /* Implementar salvamento */ break;
            case 11: liberarMemoria(sistema); break;
        }
    } while(opcao != 11);
    
    return 0;
}
```

### Funções Essenciais para Implementar

```c
// Gerenciamento de memória
SistemaSolar* criarSistemaSolar(char* nomeSistema, int quantidadeEstrelas);
void liberarMemoria(SistemaSolar* sistema);

// Gerenciamento de estrelas
int adicionarEstrela(SistemaSolar* sistema, Estrela novaEstrela);
int removerEstrela(SistemaSolar* sistema, int indice);
void redimensionarArrayEstrelas(SistemaSolar* sistema);

// Gerenciamento de planetas
int adicionarPlaneta(SistemaSolar* sistema, Planeta novoPlaneta);
int removerPlaneta(SistemaSolar* sistema, int indice);
void redimensionarArrayPlanetas(SistemaSolar* sistema);

// Entrada de dados
Estrela lerDadosEstrela();
Planeta lerDadosPlaneta();
void lerDescricaoPlaneta(DescricaoInfos* info);

// Exibição
void exibirSistemaSolar(SistemaSolar* sistema);
void exibirEstrela(Estrela* estrela, int indice);
void exibirPlaneta(Planeta* planeta, int indice);
void listarEstrelas(SistemaSolar* sistema);
void listarPlanetas(SistemaSolar* sistema);

// Manipulação de arquivos
int salvarSistemaSolar(SistemaSolar* sistema, char* nomeArquivo);
SistemaSolar* carregarSistemaSolar(char* nomeArquivo);
```

## 🎲 Dados de Exemplo

### Sistema Solar Simples (Sol)
- **Nome do Sistema**: "Sistema Solar"
- **Quantidade de Estrelas**: 1

#### Estrela: Sol
- **Nome**: Sol
- **Massa**: 1.989 × 10³⁰ kg
- **Raio**: 696.340 km
- **Temperatura**: 5.778 K
- **Luminosidade**: 1.0 (referência)
- **Tipo Estelar**: G2V
- **Cor**: Amarelo
- **Idade**: 4.6 bilhões de anos

### Sistema Binário (Alpha Centauri)
- **Nome do Sistema**: "Alpha Centauri"
- **Quantidade de Estrelas**: 2

#### Estrela A: Alpha Centauri A
- **Nome**: Alpha Centauri A
- **Massa**: 2.2 × 10³⁰ kg
- **Raio**: 854.000 km
- **Tipo Estelar**: G2V
- **Cor**: Amarelo

#### Estrela B: Alpha Centauri B
- **Nome**: Alpha Centauri B
- **Massa**: 1.8 × 10³⁰ kg
- **Raio**: 600.000 km
- **Tipo Estelar**: K1V
- **Cor**: Laranja

### Planetas de Exemplo
1. **Terra**
   - **Nome**: Terra
   - Temperatura média: 15°C
   - Satélites naturais: 1
   - Massa: 5.972 × 10²⁴ kg
   - Raio: 6.371 km
   - Duração do ano: 365.25 dias
   - Duração do dia: 24 horas
   - Distância da estrela: 1 UA

2. **Júpiter**
   - **Nome**: Júpiter
   - Temperatura média: -145°C
   - Satélites naturais: 79
   - Massa: 1.898 × 10²⁷ kg
   - Raio: 69.911 km
   - Duração do ano: 4.333 dias terrestres
   - Duração do dia: 9.9 horas
   - Distância da estrela: 5.2 UA

## 🏆 Desafios Extras

### Nível Intermediário
- [ ] Implementar busca por nome da estrela
- [ ] Implementar busca por nome do planeta
- [ ] Ordenar estrelas por massa
- [ ] Ordenar planetas por distância da estrela
- [ ] Calcular massa total do sistema solar
- [ ] Determinar estrela mais próxima de um planeta

## 📁 Estrutura de Arquivos

### Estrutura Básica (Obrigatória)
```
SistemaSolar/
├── main.c              // Programa principal com todas as funções
├── dados/
│   └── sistema_solar.bin    // Arquivo binário do sistema
└── README.md           // Documentação do projeto
```

## 🔍 Critérios de Avaliação

- **Implementação correta das estruturas** (20%)
- **Gerenciamento adequado de memória dinâmica** (25%)
- **Manipulação correta de arquivos** (25%)
- **Interface do usuário funcional** (15%)
- **Tratamento de erros** (10%)
- **Código limpo e comentado** (5%)

## 💡 Dicas Importantes

1. **Sempre verificar retorno de malloc()** - Nunca assuma que a alocação foi bem-sucedida
2. **Liberar toda memória alocada** - Evite vazamentos de memória (estrelas E planetas)
3. **Validar dados de entrada** - Especialmente ao carregar de arquivo
4. **Testar com diferentes tamanhos** - Teste com 0, 1, e muitos planetas/estrelas
5. **Atenção aos arrays dinâmicos** - Gerencie tanto estrelas quanto planetas
6. **Nomenclatura científica** - Use códigos apropriados para cada sistema

## 🔬 Conceitos Físicos Importantes

### Sistemas Estelares
- **Sistemas simples**: 1 estrela (maioria dos casos)
- **Sistemas binários**: 2 estrelas orbitando mutuamente
- **Sistemas múltiplos**: 3+ estrelas (mais raros)

### Zona Habitável
- Região onde água líquida pode existir
- Depende da luminosidade e temperatura da estrela
- Planetas nesta zona são mais interessantes para estudo

## 🚀 Entregáveis

### Obrigatórios
1. **Código-fonte principal** (arquivo .c)
2. **Executável** do programa (se aplicável)
<!-- 3. **Arquivo de exemplo** com dados de teste
4. **Documentação** explicando como compilar e usar
5. **Relatório** descrevendo as decisões de implementação -->


## 📚 | 🎯 Material de Estudo Recomendado

Abaixo estão listados os tópicos recomendados para estudo, especialmente focando na separação de código em arquivos header (.h) e boas práticas de programação.
- **Estruturas de Dados**: Entender como usar structs para organizar dados complexos
- **Ponteiros e Alocação Dinâmica**: Aprender a manipular memória de forma eficiente
- **Headers e Módulos**: Separar declarações de implementações para melhor organização

<details>
<summary>📚 <strong>Material de Estudo Recomendado - Arquivos Header (.h)</strong></summary>

### Nível Avançado
- [ ] Implementar múltiplos sistemas solares
- [ ] Calcular centro de massa do sistema estelar
- [ ] Simular órbitas planetárias básicas
- [ ] Salvar em formato texto (CSV) além do binário
- [ ] **Implementar sistema de backup automático** (veja seção "Sistema de Backup")
- [ ] Validação de dados de entrada
- [ ] Detectar planetas em zona habitável
- [ ] Sistema de versionamento de backups
- [ ] Limpeza automática de backups antigos

### Dicas Avançadas (Para Estudo Futuro)

Para mais informações sobre boas práticas de programação, consulte também: [💡 Dicas Importantes](#-dicas-importantes)
7. **Fazer backup** - Sempre salve antes de modificar dados importantes
8. **Considere a física real** - Sistemas binários têm características especiais

### Estrutura Avançada (Opcional - Para Estudo)
```
SistemaSolar/
├── main.c              // Programa principal
├── sistema_solar.c     // Implementação das funções
├── sistema_solar.h     // Declarações das estruturas e funções
├── dados/
│   ├── sistema_solar.bin    // Arquivo binário do sistema
│   └── backup.bin           // Arquivo de backup
└── README.md           // Documentação do projeto
```

### Aprendizado Futuro: Separação em Arquivos Header

Para estudantes que desejam aprofundar seus conhecimentos, é recomendado estudar a separação do código em arquivos header (.h):

**Benefícios dos arquivos .h:**
- **Organização**: Separa declarações de implementações
- **Reutilização**: Permite usar as estruturas em outros projetos
- **Manutenção**: Facilita mudanças e correções
- **Profissionalismo**: Prática padrão na indústria

**Exemplo de estrutura recomendada:**
```c
// sistema_solar.h
#ifndef SISTEMA_SOLAR_H
#define SISTEMA_SOLAR_H

// Declarações das estruturas
typedef struct { ... } DescricaoInfos;
typedef struct { ... } Estrela;
typedef struct { ... } Planeta;
typedef struct { ... } SistemaSolar;

// Declarações das funções
SistemaSolar* criarSistemaSolar(char* nomeSistema, int quantidadeEstrelas);
void liberarMemoria(SistemaSolar* sistema);
// ... outras funções

#endif
```

**Material de estudo:**
- Diretivas de pré-processador (#ifndef, #define, #endif)
- Separação de interface e implementação
- Compilação modular
- Boas práticas de organização de código

**Nota:** Esta parte é **opcional** para a entrega do exercício, mas **altamente recomendada** para desenvolvimento profissional.

</details>

---

<!-- **Prazo de entrega**: [Definir prazo]  
**Valor**: [Definir pontuação]   -->
**Formato de entrega**: Arquivo compactado (.zip) com todos os arquivos

---

*Que a força esteja com você!* 🌌⭐