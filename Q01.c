#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int frente;
    int fim;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->fim = -1;
}

int isEmpty(Fila *fila) {
    return (fila->frente == -1 && fila->fim == -1);
}

int isFull(Fila *fila) {
    return (fila->fim == MAX_SIZE - 1);
}

void enqueue(Fila *fila, int valor) {
    if (isFull(fila)) {
        printf("Erro: A fila está cheia.\n");
        return;
    }

    if (isEmpty(fila)) {
        fila->frente = 0;
        fila->fim = 0;
    } else {
        fila->fim++;
    }

    fila->elementos[fila->fim] = valor;
}

void dequeue(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Erro: A fila esta vazia.\n");
        return;
    }

    if (fila->frente == fila->fim) {
        fila->frente = -1;
        fila->fim = -1;
    } else {
        fila->frente++;
    }
}

int peek(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Erro: A fila esta vazia.\n");
        return -1;
    }

    return fila->elementos[fila->frente];
}

void print(Fila *fila) {
    if (isEmpty(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    printf("Fila: ");
    for (int i = fila->frente; i <= fila->fim; i++) {
        printf("%d ", fila->elementos[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Testando as funções da fila
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    print(&fila);  // Fila: 10 20 30

    dequeue(&fila); // Remove o primeiro elemento da lista: 10
    print(&fila);  // Fila: 20 30

    int frontValue = peek(&fila);
    printf("Valor do primeiro elemento: %d\n", frontValue);  // Valor do primeiro elemento: 20

    int empty = isEmpty(&fila);
    printf("A fila esta vazia? %s\n", (empty ? "Sim" : "Nao"));  // A fila está vazia? Não

    return 0;
}
