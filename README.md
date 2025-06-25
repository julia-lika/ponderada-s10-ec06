# Calculadora RPN (Notação Polonesa Reversa) em C

## Descrição

Este projeto implementa uma calculadora que avalia expressões matemáticas em Notação Polonesa Reversa (RPN), também conhecida como notação postfix. Nessa notação, os operadores aparecem após seus operandos, o que elimina a necessidade de parênteses e permite uma avaliação eficiente utilizando uma pilha.

A calculadora suporta as quatro operações básicas: adição (`+`), subtração (`-`), multiplicação (`*`) e divisão (`/`).

---

## Funcionamento da Calculadora

A expressão em RPN é lida como uma sequência de tokens separados por espaço. Para avaliar a expressão:

1. **Números**: são empilhados na pilha.
2. **Operadores**: para cada operador lido:

   * Desempilha os dois últimos números.
   * Aplica a operação.
   * Empilha o resultado.
3. Ao final da expressão, o valor restante no topo da pilha é o resultado final.

---

## Estrutura do Código

* **TAD Pilha**: Implementa a pilha de operandos com operações básicas:

  * `inicializaPilha()`: Inicializa a pilha vazia.
  * `push(pilha, valor)`: Empilha um valor.
  * `pop(pilha)`: Desempilha e retorna o valor do topo.
  * `estaVazia(pilha)`: Verifica se a pilha está vazia.

* **Leitura e Tokenização**:

  * A expressão é lida da entrada padrão (stdin).
  * É usada a função `strtok` para separar os tokens por espaço.

* **Avaliação da Expressão**:

  * Para cada token:

    * Se for número, converte e empilha.
    * Se for operador (`+`, `-`, `*`, `/`), desempilha dois valores, calcula e empilha o resultado.
  * Erros simples são tratados, como divisão por zero e pilha vazia.

---

## Como Compilar e Executar

1. Compile o código usando `gcc`:

```bash
gcc -o calculadora calculadora.c
```

2. Execute o programa:

```bash
./calculadora
```

3. Digite a expressão RPN que deseja calcular, por exemplo:

```
5 1 2 + 4 * + 3 -
```

4. O resultado será exibido no console:

```
Resultado: 14.00
```

---

## Exemplo de Uso

| Expressão RPN       | Resultado Esperado |
| ------------------- | ------------------ |
| `3 4 +`             | 7                  |
| `5 1 2 + 4 * + 3 -` | 14                 |
| `10 2 8 * + 3 -`    | 23                 |

---

## Possíveis Melhorias e Desafios

* Implementar tratamento completo de erros (expressões mal formadas).
* Suportar mais operadores (ex.: potenciação, módulo).
* Permitir o uso de variáveis e funções.
* Implementar interface gráfica ou modo interativo com múltiplas operações.

---