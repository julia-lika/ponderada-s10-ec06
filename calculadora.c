#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100  // Tamanho máximo da pilha

typedef struct {
    double itens[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha um valor
void push(Pilha *p, double valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
}

// Desempilha e retorna o valor
double pop(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    } else {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
}

// Função para verificar se o token é operador
int ehOperador(char *token) {
    return (strlen(token) == 1) && 
           (*token == '+' || *token == '-' || *token == '*' || *token == '/');
}

int main() {
    char linha[256];
    Pilha pilha;
    inicializaPilha(&pilha);

    printf("Digite a expressão RPN (tokens separados por espaço):\n");
    if (!fgets(linha, sizeof(linha), stdin)) {
        printf("Erro na leitura\n");
        return 1;
    }

    // Remove o \n do final da linha, se existir
    linha[strcspn(linha, "\n")] = 0;

    // Tokeniza a linha com base em espaços
    char *token = strtok(linha, " ");

    while (token != NULL) {
        // Se for número, converte e empilha
        char *endptr;
        double num = strtod(token, &endptr);

        if (endptr != token) {
            // Token é número
            push(&pilha, num);
        } else if (ehOperador(token)) {
            // Token é operador, desempilha dois operandos
            double b = pop(&pilha);
            double a = pop(&pilha);
            double res;

            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': 
                    if (b == 0) {
                        printf("Erro: divisão por zero\n");
                        return 1;
                    }
                    res = a / b; 
                    break;
                default:
                    printf("Operador desconhecido\n");
                    return 1;
            }
            push(&pilha, res);
        } else {
            printf("Token inválido: %s\n", token);
            return 1;
        }

        token = strtok(NULL, " ");
    }

    // Ao final, topo da pilha tem o resultado
    if (pilha.topo == 0) {
        double resultado = pop(&pilha);
        printf("Resultado: %.2lf\n", resultado);
    } else {
        printf("Erro: Expressão inválida ou incompleta\n");
        return 1;
    }

    return 0;
}
