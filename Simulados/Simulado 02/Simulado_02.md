## 🧠 Simulado de Exercícios com Strings, Matrizes e Funções – Parte 1

### 💡 Instruções Gerais:

Todos os exercícios abaixo devem ser desenvolvidos utilizando **a linguagem C**. Utilize **funções** sempre que possível para modularizar o código. Evite globalizar variáveis. As soluções devem utilizar **strings** e/ou **matrizes**, conforme o enunciado. Ao final de cada execução, o programa deve retornar ao **menu principal** (quando houver).

---

### 🔢 1. Validador e Gerador de Dígitos do CPF

#### 📌 Enunciado:

Escreva um programa em C que receba um CPF com ou sem máscara (por exemplo: `12345678909` ou `123.456.789-09`) e valide se os dois **últimos dígitos verificadores** estão corretos, conforme o algoritmo oficial de validação.

Divida a solução em pelo menos duas funções:

* `int gerarDigitosCPF(char cpf[])`: gera e retorna os dois dígitos verificadores esperados.
* `int validarCPF(char cpf[])`: retorna 1 se o CPF for válido, 0 caso contrário.

#### 📎 Regras para cálculo dos dígitos:

1. Considere apenas os 9 primeiros dígitos.
2. Para o 10º dígito (primeiro verificador):

   * Multiplique os 9 primeiros dígitos por pesos decrescentes de 10 a 2.
        ```
        Exemplo de cálculo dos produtos para o CPF `390533447-XX`:

        3 * 10 = 30
        9 * 9  = 81
        0 * 8  = 0
        5 * 7  = 35
        3 * 6  = 18
        3 * 5  = 15
        4 * 4  = 16
        4 * 3  = 12
        7 * 2  = 14
        ```
   * Some os resultados.
        ```
        Exemplo de soma: 30 + 81 + 0 + 35 + 18 + 15 + 16 + 12 + 14 = 221
        ```

   * Calcule `soma % 11`. Se o resultado for menor que 2, o dígito é 0; senão, `11 - resto`.
        ```
        Exemplo: 221 % 11 = 1 → dígito = 0
        ```
3. Para o 11º dígito:

   * Faça o mesmo processo, agora com os 10 primeiros dígitos (incluindo o verificador anterior), com pesos de 11 a 2.
    * Multiplique os 10 primeiros dígitos por pesos decrescentes de 11 a 2.
        ```
        Exemplo de cálculo dos produtos para o CPF `3905334470`:
        
        3 * 11 = 33
        9 * 10 = 90
        0 * 9  = 0
        5 * 8  = 40
        3 * 7  = 21
        3 * 6  = 18
        4 * 5  = 20
        4 * 4  = 16
        7 * 3  = 21
        0 * 2  = 0

        Soma: 33 + 90 + 0 + 40 + 21 + 18 + 20 + 16 + 21 + 0 = 259

        Calcule `soma % 11`. Se o resultado for menor que 2, o dígito é 0; senão, `11 - resto`.
        Exemplo: 259 % 11 = 6 → dígito = 5
        ```
4. Compare os dígitos gerados com os fornecidos pelo usuário.
5. Exiba se o CPF é válido ou inválido.
   
#### Exemplo no terminal:

```
O que deseja fazer?
1. Validar CPF
2. Gerar dígitos do CPF
3. Sair

>> 1
Digite um CPF: 123.456.789-09
>#>#>#> CPF inválido.

------------------------------
O que deseja fazer?
1. Validar CPF
2. Gerar dígitos do CPF
3. Sair

>> 1
Digite um CPF: 39053344705
>>>>>> CPF válido!

------------------------------
O que deseja fazer?
1. Validar CPF
2. Gerar dígitos do CPF
3. Sair

>> 2
Digite os 9 primeiros dígitos do CPF: 390533447
>>> Dígitos gerados: 05
------------------------------
O que deseja fazer?
1. Validar CPF
2. Gerar dígitos do CPF
3. Sair

>> 3
Saindo do programa...
```

---

### 🔐 2. Criptografia Cifra de César com Chave por Letra

#### 📌 Enunciado:

Implemente um programa que aplique a **Cifra de César** com deslocamento variável para cada letra, definido por uma string-chave.

#### 📎 Funcionamento:

* O usuário insere uma **mensagem** e uma **chave**.
* A chave deve ter o mesmo comprimento da mensagem.
* Cada caractere da mensagem é deslocado de acordo com o valor do caractere da chave:

  * Exemplo: se `chave[i] = 'B'` → deslocamento = 1, pois `'B' - 'A' = 1`.

#### 💻 Exemplo:

```
Mensagem: HELLO
Chave:     BDFHJ

Resultado criptografado: IGOMT
```

**Observações:**

* Converta letras minúsculas para maiúsculas.
* Mantenha espaços e pontuações inalteradas.
* Mostre também a mensagem descriptografada no final (reverso da operação).

---

### 🧠 3. Criptografia XOR com Impressão Numérica

#### 📌 Enunciado:

Implemente uma criptografia baseada em **XOR**. O programa deverá:

1. O usuário digita uma mensagem (string) qualquer.
2. O usuário digita uma chave (string), que pode ser de qualquer tamanho.
3. Para cada caractere da mensagem, aplica-se o operador XOR (`^`) com o caractere correspondente da chave. Se a chave for menor que a mensagem, ela é repetida automaticamente usando o operador `%` (exemplo: `chave[i % tamChave]`).
4. Exibir os **valores inteiros** dos caracteres criptografados.
5. Para descriptografar, basta aplicar novamente o XOR entre o texto criptografado e a mesma chave, recuperando a mensagem original. Isso funciona porque o XOR é uma operação reversível: `A ^ B ^ B = A`.

- **Exemplo prático:**
  - Mensagem: `a` (ASCII 97)
  - Chave:    `p` (ASCII 112)
  - Criptografado: `97 ^ 112 = 15`
  - Descriptografado: `15 ^ 112 = 97` (volta para `'a'`)

- **Resumo:**  
  O processo é simétrico: criptografar e descriptografar usam o mesmo algoritmo e a mesma chave.


Adicionalmente, permita ao usuário ver a **mensagem descriptografada** após o XOR invertido.

#### 💻 Exemplo:

```
Mensagem: Segredo
Chave: KEY

Resultado criptografado: 24 32 46 40 55 46 38
Mensagem descriptografada: Segredo
```

---

### 🧾 4. Abreviação de Nome Completo

#### 📌 Enunciado:

Você foi convidado para ajudar na preparação de um artigo científico, onde é necessário formatar corretamente as referências bibliográficas segundo as normas da ABNT. Para isso, precisa-se abreviar os nomes dos autores, mantendo o último sobrenome por extenso e transformando os demais nomes em iniciais seguidas de ponto.

Faça um programa em C que receba o nome completo de um autor e retorne o nome abreviado no formato ABNT, ou seja, o último sobrenome completo no final e os demais nomes convertidos para suas iniciais, cada uma seguida de ponto.


O programa deve ignorar preposições como "de", "da", "do", "das", "dos" ao gerar as iniciais.

#### 📎 Regras:

* Use funções como `strcmp`, `strcpy`, `strlen`, `strcat`, etc.
* O nome deve conter ao menos 2 palavras.
* Ignorar preposições como "de", "da", "do", "das", "dos".

#### ℹ️ Explicação das funções da biblioteca `string.h` usadas neste exercício

A biblioteca `<string.h>` da linguagem C fornece funções para manipulação de strings (cadeias de caracteres). Algumas das funções mais utilizadas neste exercício são:

- **`strcmp(str1, str2)`**  
    Compara duas strings. Retorna 0 se forem iguais, valor negativo se `str1` for menor que `str2`, e valor positivo se for maior.

- **`strcpy(dest, src)`**  
    Copia o conteúdo da string `src` para a string `dest`.

- **`strlen(str)`**  
    Retorna o comprimento (número de caracteres) da string `str`, sem contar o caractere nulo `\0`.

- **`strcat(dest, src)`**  
    Concatena (junta) a string `src` ao final da string `dest`.

Essas funções são essenciais para manipular, comparar, copiar e montar novas strings durante o processamento do nome completo e sua abreviação.

#### 💻 Exemplo:

```
Entrada: Joana Clara de Souza Ramos
Saída: RAMOS, J. C. S.

Entrada: Maria Eduarda da Silva
Saída: SILVA, M. E.
```

---

### 🎬 5. Sistema de Reserva de Assentos no Cinema

#### 📌 Enunciado:

Implemente um sistema de reservas para um cinema com **16 fileiras** e **6 colunas** de assentos (96 ao total).

A faculdade fazerá uma sessão de cinema e precisa de um sistema para gerenciar as reservas de assentos. O sistema deve permitir que os usuários reservem, editem ou cancelem seus assentos, garantindo que cada usuário possa manipular apenas suas próprias reservas.

#### 📌 Funcionalidades:

Cada usuário deve:

* Informar seu RA .
* Visualizar os assentos livres/ocupados.
* Reservar um assento disponível.
* Editar ou cancelar **somente** o assento reservado com seu RA.

#### 📎 Requisitos:

* Mapa de assentos com visualização gráfica.
* Mostrar `[00]` para disponíveis e `[--]` para ocupados.
* RA associativo para cada assento.
* Digite `0` no RA para sair do sistema.
* O sistema deve ser interativo, com um menu principal que permita ao usuário escolher entre as opções disponíveis.

#### 💻 Exemplo no terminal:

```
Bem-vindo ao Sistema de Reservas do Cinema!

Digite seu RA: 2487515

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 1
Mapa de assentos:
____________________________________.    .
|=| [91] [92] [93] [94] [95] [96] |=|\  /|
|=| [85] [86] [87] [88] [89] [90] |=|    |
|=| [79] [80] [81] [82] [83] [84] |=|    |
|=| [73] [74] [75] [76] [77] [78] |=|    |
|=| [67] [68] [69] [70] [71] [72] |=|    |
|=| [61] [62] [63] [64] [65] [66] |=|    |
|=| [55] [56] [57] [58] [59] [60] |=|    |
|=| [49] [50] [51] [52] [53] [54] |=|    |
|=| [43] [44] [45] [46] [47] [48] |=|    |
|=| [37] [38] [39] [40] [41] [42] |=|    |
|=| [31] [32] [33] [34] [35] [36] |=|    |
|=| [25] [26] [27] [28] [29] [30] |=|    |
|=| [19] [20] [21] [22] [23] [24] |=|    |
|=| [13] [14] [15] [16] [17] [18] |=|    |
|=| [07] [08] [09] [10] [11] [12] |=|    |
|=| [01] [02] [03] [04] [05] [06] |=|    |
|                                        |
|________________________________________|

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 2
Digite o número do assento (1–96): 45
OK - Assento 45 reservado com sucesso!

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 1
Mapa de assentos:
____________________________________.    .
|=| [91] [92] [93] [94] [95] [96] |=|\  /|
|=| [85] [86] [87] [88] [89] [90] |=|    |
|=| [79] [80] [81] [82] [83] [84] |=|    |
|=| [73] [74] [75] [76] [77] [78] |=|    |
|=| [67] [68] [69] [70] [71] [72] |=|    |
|=| [61] [62] [63] [64] [65] [66] |=|    |
|=| [55] [56] [57] [58] [59] [60] |=|    |
|=| [49] [50] [51] [52] [53] [54] |=|    |
|=| [43] [44] [--] [46] [47] [48] |=|    |
|=| [37] [38] [39] [40] [41] [42] |=|    |
|=| [31] [32] [33] [34] [35] [36] |=|    |
|=| [25] [26] [27] [28] [29] [30] |=|    |
|=| [19] [20] [21] [22] [23] [24] |=|    |
|=| [13] [14] [15] [16] [17] [18] |=|    |
|=| [07] [08] [09] [10] [11] [12] |=|    |
|=| [01] [02] [03] [04] [05] [06] |=|    |
|                                        |
|________________________________________|

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 3
Seus assentos reservados:

[45]

Digite o número do assento: 45
Digite o novo número do assento (1–96): 50
OK >> Assento atualizado com sucesso!
------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 4
OK >> Você saiu do sistema.

-------------------------------------------

Digite seu RA: 23456789

-------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 3
Seus assentos reservados:
Você não possui reservas ativas.

-------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 2
Digite o número do assento (1–96): 30
OK - Assento 30 reservado com sucesso!

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 3
Seus assentos reservados:

[30]

Digite o número do assento: 50

>< Erro: Você só pode alterar assentos reservados pelo seu RA!

-------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair
>> 1
Mapa de assentos:
____________________________________.    .
|=| [91] [92] [93] [94] [95] [96] |=|\  /|
|=| [85] [86] [87] [88] [89] [90] |=|    |
|=| [79] [80] [81] [82] [83] [84] |=|    |
|=| [73] [74] [75] [76] [77] [78] |=|    |
|=| [67] [68] [69] [70] [71] [72] |=|    |
|=| [61] [62] [63] [64] [65] [66] |=|    |
|=| [55] [56] [57] [58] [59] [60] |=|    |
|=| [49] [--] [51] [52] [53] [54] |=|    |
|=| [43] [44] [45] [46] [47] [48] |=|    |
|=| [37] [38] [39] [40] [41] [42] |=|    |
|=| [31] [32] [33] [34] [35] [36] |=|    |
|=| [25] [26] [27] [28] [29] [30] |=|    |
|=| [19] [20] [21] [22] [23] [24] |=|    |
|=| [13] [14] [15] [16] [17] [18] |=|    |
|=| [07] [08] [09] [10] [11] [12] |=|    |
|=| [01] [02] [03] [04] [05] [06] |=|    |
|                                        |
|________________________________________|

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 2
Digite o número do assento (1–96): 70
OK - Assento 70 reservado com sucesso!

------------------------------------------
Menu:
1. Ver mapa de assentos
2. Reservar assento
3. Editar/Cancelar reserva
4. Sair

>> 4
OK >> Você saiu do sistema.

-------------------------------------------

Digite seu RA: 0

--------------------------------------------

OK >> Você saiu do sistema.
```

---

> ✅ **Observação:** Todos os exercícios devem ser feitos com uso extensivo de funções, e sem uso de variáveis globais.
