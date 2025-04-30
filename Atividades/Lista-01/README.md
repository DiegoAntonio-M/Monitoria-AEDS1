
# 01 - Lista: Exercícios de Algoritmos e Estruturas de Dados I

## 🟢 Nível 1:

<details>
<summary>📌 Requisitos</summary>

- Apenas Condicionais.

</details>

### 🍔 Exercício 1: Comanda de Lanchonete - Com Menu de Escolhas

**Enunciado:**

Crie um programa em C que simule um pedido em uma lanchonete. O usuário irá interagir com um **menu de opções** para escolher:

- **1 lanche**
- **1 acompanhamento**
- **1 bebida**

Cada item possui um preço fixo. O programa deve calcular e exibir o **valor total da comanda**, além de mostrar um resumo com as opções escolhidas.

#### Opções de Lanches:
| Código | Lanche                | Preço (R$) |
|--------|------------------------|------------|
| 1      | Hambúrguer simples     | 10.00      |
| 2      | Cheeseburguer          | 12.00      |
| 3      | X-Bacon                | 14.00      |
| 4      | X-Tudo                 | 16.00      |
| 5      | Veggie Burger          | 13.00      |

#### Opções de Acompanhamento:
| Código | Acompanhamento         | Preço (R$) |
|--------|------------------------|------------|
| 1      | Batata frita           | 6.00       |
| 2      | Onion rings            | 7.00       |
| 3      | Nuggets                | 8.00       |

#### Opções de Bebidas:
| Código | Bebida                 | Preço (R$) |
|--------|------------------------|------------|
| 1      | Refrigerante lata      | 5.00       |
| 2      | Suco natural           | 6.00       |
| 3      | Água mineral           | 3.00       |
| 4      | Milkshake              | 8.00       |

**Exemplo de saída no terminal:**

```
Escolha seu lanche:
1. Hambúrguer simples - R$10,00
2. Cheeseburguer - R$12,00
3. X-Bacon - R$14,00
4. X-Tudo - R$16,00
5. Veggie Burger - R$13,00
>> Digite o número do lanche: 3

Escolha o acompanhamento:
1. Batata frita - R$6,00
2. Onion rings - R$7,00
3. Nuggets - R$8,00
>> Digite o número do acompanhamento: 1

Escolha a bebida:
1. Refrigerante lata - R$5,00
2. Suco natural - R$6,00
3. Água mineral - R$3,00
4. Milkshake - R$8,00
>> Digite o número da bebida: 2

Comanda:
- Lanche escolhido: X-Bacon (R$14,00)
- Acompanhamento escolhido: Batata frita (R$6,00)
- Bebida escolhida: Suco natural (R$6,00)

Total a pagar: R$26,00
```

---

## 🟡 Nível 2:

<details>
<summary>📌 Requisitos</summary>

- Condicionais;
- Laços de Repetição (1 a 2 laços).

</details>

### 🧺 Exercício 2: Lista de Compras do Mês

**Enunciado:**

Peça ao usuário que informe o **preço de 5 produtos**. Ao final, o programa deve exibir:

- O **total gasto**
- O **valor médio**
- O **produto mais caro** (identificado pela posição: Produto 1, Produto 2, ...)

**Exemplo de saída:**

```
Informe o valor do produto 1: 12.50  
Informe o valor do produto 2: 8.00  
Informe o valor do produto 3: 20.00  
Informe o valor do produto 4: 15.00  
Informe o valor do produto 5: 5.00  

Total gasto: R$60.50  
Valor médio: R$12.10  
Produto mais caro: Produto 3 (R$20.00)
```

<details>
<summary>🎯 Exercício Extra 01: Mostre Segundo Maior e Segundo Menor</summary>

**Enunciado:**

Crie um programa que receba do usuário o preço dos produtos. Ao final, o programa deve exibir:

- O **total gasto**
- O **valor médio**
- O **produto mais caro**
- O **produto mais barato**
- O **segundo produto mais caro**
- O **Segundo produto mais barato**


**Exemplo de saída esperada:**

```
Total gasto: R$124.00  
Valor médio: R$12.40  
Produto mais caro: Produto 5 (R$22.00)  
Produto mais barato: Produto 4 (R$5.00)  
Segundo mais caro: Produto 10 (R$19.00)  
Segundo mais barato: Produto 9 (R$6.50)
```

</details>

<details>
<summary>🎯 Exercício Extra 02: Lista de Compras com 10 Produtos</summary>

**Enunciado:**

Crie um programa que receba do usuário o preço de **10 produtos**. Ao final, o programa deve exibir:

**Exemplo de saída esperada:**

```
Informe o valor do produto 1: 12.50  
Informe o valor do produto 2: 18.00  
Informe o valor do produto 3: 7.00  
Informe o valor do produto 4: 5.00  
Informe o valor do produto 5: 22.00  
Informe o valor do produto 6: 10.00  
Informe o valor do produto 7: 9.00  
Informe o valor do produto 8: 15.00  
Informe o valor do produto 9: 6.50  
Informe o valor do produto 10: 19.00  
```

> 💡 **Dica**:
>
> Faça com que apenas um valor seja alterado para que isso seja possível.

</details>

---

## 🔴 Nível 3: 

<details>
<summary>📌 Requisitos</summary>

- Condicionais;
- Laços de Repetição;
- Condicionais + Laços de Repetição Combinados.

</details>

### 🧠 Exercício 3: Fatoração em Primos

**Enunciado:**

Receba um número inteiro do usuário e escreva sua **decomposição em fatores primos**, usando potências quando necessário. O resultado deve ser exibido no formato:

```
2^4*7
```

**Exemplo de saída:**

```
Digite um número: 112  
Saída: 2^4*7
```

**Observação (Trate as exceções):**
- Caso o número seja **0**, o programa deve exibir a mensagem:  
  ```
  O número deve ser positivo e diferente de 0.
  ```
- Caso o número seja **1**, o programa deve exibir a mensagem:  
  ```
  O número 1 não possui fatoração em primos.
  ```

---
> [!NOTE]
> Estes exercícios foram cuidadosamente elaborados para promover o desenvolvimento de competências fundamentais na disciplina de Algoritmos e Estruturas de Dados I. Eles visam consolidar o domínio sobre **estruturas condicionais**, **laços de repetição** e **lógica algorítmica**.
