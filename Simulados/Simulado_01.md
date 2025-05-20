# Simulado Final - Algoritmos e Estruturas de Dados I

## 📌 Requisitos:

* Condicionais;
* Laços de repetição (em alguns casos);
* Lógica aplicada em contextos do mundo real.

---

### 🌐 Exercício 1: Conversor de Bases Numéricas

**Enunciado:**

Desenvolva um programa em C que receba um número inteiro na base decimal($n_{10}$) ou em binário($n_{2}$) e o converta para uma base à escolha do usuário.

* Permita que o usuário digite um número em binário e converta para decimal.
* Permita também que o usuário digite um número em decimal e converta para binário.

**1. Exemplo de Terminal:**

```
Base de entrada (10 ou 2): 10
Número: 25
Base desejada (10 ou 2): 2
Resultado: 11001
```

**2. Exemplo de Terminal:**
```
Base de entrada (10 ou 2): 2
Número: 11001
Base desejada (10 ou 2): 10
Resultado: 25
```

---

### ✈️ Exercício 2: Fuso Horário de Voos

**Enunciado:**

Ao chegar no aeroporto, você visualiza um monitor interativo que mostra os horários locais de cada destino dos voos em diferentes fusos horários em comparação ao horário local.

Escreva um programa em C que:

* Peça ao usuário para inserir o **fuso horário de um dos destinos** (-12 a +14);
* O **fuso horário local** (-12 a +14);
* Hora no local de destino: no formato 24h
* Converta para o **horário local**, no **formato digital 24h** e também com **"ponteiros do relógio" (formato 12h)** indicando **AM/PM** .

**1 Exemplo de Terminal:**

```
Digite o fuso horário do destino (-14 a +14): 9
Digite o fuso horário local (-14 a +14): -3
Digite a hora no destino (0 a 23): 7

Hora local em formato 24h: 19:00
Formato com ponteiros: 07:00 PM
```
**2 Exemplo de Terminal:**

```
Digite o fuso horário do destino (-14 a +14): -8
Digite o fuso horário local (-14 a +14): 6
Digite a hora no destino (0 a 23): 3

Hora local em formato 24h: 17:00
Formato com ponteiros: 05:00 PM
```
**3 Exemplo de Terminal:**

```
Digite o fuso horário do destino (-14 a +14): 10
Digite o fuso horário local (-14 a +14): -12
Digite a hora no destino (0 a 23): 5

Hora local em formato 24h: 19:00
Formato com ponteiros: 07:00 PM
```

---

### 📈 Exercício 3: Domínio de Funções com Raiz e Denominador

**Enunciado:**

João está estudando para sua prova de cálculo e decidiu programar uma calculadora que receba valores de entrada `x` e calcule o valor da função:

$$
f(x) = \frac{\sqrt{x^4 - 10x^2 + 9}}{x + 4{,}5}
$$

Inicialmente, ele permitia que qualquer número real fosse digitado, mas percebeu que certos valores geravam erros matemáticos, como radicais negativos ou divisão por zero. Por isso, João entendeu que precisava restringir os valores de `x` ao **domínio da função**.

Escreva um programa para que:

* Receba um número real `x` como parâmetro;
* Verifique se `x` pertence ao domínio da função;
* Se `x` for válido, retorne o valor de `f(x)`;
* Caso contrário, exiba uma mensagem indicando que `x` está fora do domínio.

**1 Exemplo de Terminal:**

```
Digite um valor para x: -4.5
x está fora do domínio da função
```
**2 Exemplo de Terminal:**

```
Digite um valor para x: 1.0
f(x) = 0.5
```
**3 Exemplo de Terminal:**

```
Digite um valor para x: 2.0
x está fora do domínio da função
```
**4 Exemplo de Terminal:**
```
Digite um valor para x: 3.0
f(x) = 0.0
```

---

### 🐇 Questão 4 – Os Coelhos de Fibonacci e os Recintos das Etiquetas

Um criador de coelhos decidiu simular o crescimento da população de coelhos usando a famosa **sequência de Fibonacci**, proposta pelo matemático Leonardo de Pisa, o Fibonacci.

> A cada mês, cada par de coelhos com mais de um mês de vida gera **um novo par**.  
> Inicialmente, há apenas **1 par de coelhos recém-nascidos**.

A sequência da população (representada em pares) será:

```
Mês 1: 1  
Mês 2: 1  
Mês 3: 2  
Mês 4: 3  
Mês 5: 5  
Mês 6: 8  
...
```

Após um número **N de meses**, o criador numerou todos os novos **pares de coelhos nascidos** com uma **etiqueta sequencial** (começando do número 1). Com base nessas etiquetas, ele separou os coelhos em **três recintos diferentes**, conforme a seguinte regra:



#### 📦 Regras de classificação:

- **Recinto 1:** Coelhos com etiquetas **divisíveis por 3 ou 5**.
- **Recinto 2:** Coelhos com etiquetas que são **números primos**.
- **Recinto 3:** Todos os **demais coelhos**.



#### 🎯 Seu programa deve:

1. Ler o número de meses `N`.
2. Gerar a sequência de Fibonacci até o `N`-ésimo mês (quantidade total de pares de coelhos).
3. Atribuir etiquetas de 1 até o total de pares nascidos. (os pares compartilham a mesma etiqueta)
4. Classificar cada etiqueta conforme as regras dos recintos.
5. Mostrar:
   - A sequência mês a mês.
   - A etiqueta e o recinto de cada coelho.
   - A **quantidade final de coelhos** em cada recinto.


#### 💻 Exemplo de execução:

```
Digite o número de meses: 6

Sequência de Fibonacci (representada em pares):
1 1 2 3 5 8

Total de pares de coelhos após 6 meses: 8

Etiquetas e Recintos:
Etiqueta 1 → Recinto 3
Etiqueta 2 → Recinto 2
Etiqueta 3 → Recinto 1
Etiqueta 4 → Recinto 3
Etiqueta 5 → Recinto 1
Etiqueta 6 → Recinto 1
Etiqueta 7 → Recinto 2
Etiqueta 8 → Recinto 3

Resumo:
Recinto 1 (múltiplos de 3 ou 5): 3 pares de coelhos
Recinto 2 (números primos): 2 pares pares coelhos
Recinto 3 (outros): 3 pares de coelhos
```

---

### ⚨️ Exercício 5: Verificador de Descontos

**Enunciado:**

Em uma loja, o desconto depende do valor da compra:

| Faixa de valor  | Desconto |
| --------------- | -------- |
| < R\$100        | 5%       |
| R\$100 - R\$500 | 10%      |
| > R\$500        | 15%      |

Escreva um programa que:

* Solicite o valor da compra;
* Calcule e exiba o valor com o desconto aplicado;
* Mostre também quanto foi economizado.

**Exemplo de Terminal:**

```
Valor da compra: R$250.00
Desconto aplicado: R$25.00
Total a pagar: R$225.00
```

---

### ⚖️ Exercício 6: Classificador de Riscos - Ambulatório

**Enunciado:**

Desenvolva um programa que receba as seguintes informações de um paciente:

* Temperatura (°C)
* Frequência Cardíaca (bpm)
* Pressão Arterial Sistólica (mmHg)
* Dor (escala de 0 a 10)

E classifique cada item conforme a tabela abaixo:

### Tabela 1 - Temperatura (°C)

| Intervalo   | Categoria   | Pontuação |
|-------------|-------------|-----------|
| < 36.0      | Hipotermia  | 5         |
| 36.0 – 37.4 | Normal      | 0         |
| 37.5 – 38.9 | Febril      | 3         |
| ≥ 39.0      | Febre Alta  | 5         |


### Tabela 2 - Frequência Cardíaca (bpm)

| Intervalo | Categoria   | Pontuação |
|-----------|-------------|-----------|
| < 60      | Bradicardia | 4         |
| 60 – 100  | Normal      | 0         |
| > 100     | Taquicardia | 4         |


### Tabela 3 - Pressão Arterial Sistólica (mmHg)

| Intervalo | Categoria   | Pontuação |
|-----------|-------------|-----------|
| < 90      | Hipotensão  | 4         |
| 90 – 120  | Normal      | 0         |
| > 120     | Hipertensão | 3         |


### Tabela 4 - Dor (escala 0 a 10)

| Intervalo | Categoria | Pontuação |
|-----------|-----------|-----------|
| 0 – 3     | Leve      | 0         |
| 4 – 7     | Moderada  | 3         |
| 8 – 10    | Intensa   | 5         |


### Tabela 5 - Resultado Final (Total de Pontos)

| Pontuação Total | Classificação  |
|-----------------|----------------|
| 0 – 3           | Risco Baixo    |
| 4 – 7           | Risco Moderado |
| 8 – 11          | Risco Alto     |
| ≥ 12            | Risco Crítico  |


**Exemplo de Terminal:**

```
Temperatura: 39.2
Frequência Cardíaca: 110
Pressão Sistólica: 135
Dor: 9

Resultado:
- Febre Alta (5 pts)
- Taquicardia (4 pts)
- Hipertensão (3 pts)
- Dor Intensa (5 pts)
Total: 17 pts
Classificação: Risco Crítico
```

---

### 🔢 Exercício 7: Fatoração em Primos

**Enunciado:**

Receba um número inteiro positivo e exiba sua fatoração em primos, usando potências quando aplicável.

> Trate exceções para 0 e 1 com mensagens apropriadas.

**Exemplo de Terminal:**

```
Digite um número: 112
Saída: 2^4 * 7

Digite um número: 1
Saída: O número 1 não possui fatoração em primos.
```

---

### 🏦 Exercício 8: Caixa Eletrônico - Saque Mínimo de Cédulas

**Enunciado:**

Simule um saque em um caixa eletrônico. O usuário deve informar o valor desejado, e o programa deve exibir o **menor número de cédulas** para compor esse valor, considerando as notas de:

`100, 50, 20, 10, 5, 2, 1`

**Exemplo de Terminal:**

```
Valor do saque: R$287
Notas fornecidas:
2 x R$100
1 x R$50
1 x R$20
1 x R$10
1 x R$5
1 x R$2
```

---

### 🔬Exercício 9: Limites Bilaterais e Assíntotas

**Enunciado:**

Você está ajudando Rafael, que deseja estudar limites bilaterais de uma função real. Desenvolva um programa que:

1. Peça ao usuário para qual valor de `x` ele deseja calcular o limite (por exemplo, "`x tende a n`"), onde `n` é informado via teclado.
2. Calcule os valores de `f(x)` ao se aproximar de `n` pela esquerda e pela direita, com `h = 0.1`, `0.01`, `0.001`.
3. Permita o teste de três diferentes funções:

   * `fA(x) = 1 / (x - 3)`           ➔ uma assíntota
   * `fB(x) = 1 / ((x - 1)*(x + 2))`  ➔ duas assíntotas
   * `fC(x) = x^2 + 1`               ➔ sem assíntota

**Exemplo de Terminal:**

```
Escolha a função: fA
x tende a: 3

x = 2.9 ➔ f(x) = -10.00
x = 2.99 ➔ f(x) = -100.00
x = 2.999 ➔ f(x) = -1000.00
...

x = 3.1 ➔ f(x) = 10.00
x = 3.01 ➔ f(x) = 100.00
x = 3.001 ➔ f(x) = 1000.00
...

Conclusão: O limite bilateral não existe, há uma assíntota vertical em x = 3.
```

---

### 🎢 Exercício 10: Controle de Entrada no Parque de Diversões 

## 🧠 Contexto

Um parque de diversões inaugurou sua nova atração radical: o **"Looping Infinito"**! Para garantir a segurança dos visitantes, a equipe de controle de entrada criou as seguintes regras:

#### 📏 Regras de Acesso

- **Altura mínima:** 1,50 metros  
- **Altura máxima:** 2,10 metros  
- **Idade permitida:** entre **12 e 60 anos** (inclusive)
- Visitantes **menores de idade (menos de 18 anos)** só poderão entrar se:
  - Estiverem **acompanhados de um responsável** **OU**
  - Apresentarem uma **autorização por escrito**


#### 🎯 O que seu programa deve fazer:

1. Perguntar a **idade** e a **altura** da pessoa.
2. Se a idade for menor que 18, perguntar:
   - Se está **acompanhado** (`s` ou `n`)
   - Se **não estiver**, perguntar se tem **autorização** (`s` ou `n`)
3. Verificar se a pessoa **pode entrar ou não** na atração.
4. Exibir mensagens apropriadas

#### 💻 Exemplo de execução:

```
Digite sua idade: 14
Digite sua altura (em metros): 1.52
Você está acompanhado? (s/n): n
Você possui autorização por escrito? (s/n): s
✅ Entrada permitida! Divirta-se no Looping Infinito!
```

Outro exemplo:

```
Digite sua idade: 11
Digite sua altura (em metros): 1.48
❌ Entrada negada. Você não atende aos requisitos mínimos de altura e idade.
```

---

> \[!NOTE]
> Este simulado foi projetado para revisar conteúdos fundamentais de **condicionais**, **laços**, **funções matemáticas**, **modelagem de problemas reais** e **interpretação de funções matemáticas** em linguagem C.
