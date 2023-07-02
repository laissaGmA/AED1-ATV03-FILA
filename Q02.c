#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct {
    Node* frente;
    Node* fim;
} Fila;

void inicializarFila(Fila* fila) {
    fila->frente = NULL;
    fila->fim = NULL;
}

int isEmpty(Fila* fila) {
    return (fila->frente == NULL);
}

void enqueue(Fila* fila, int valor) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->valor = valor;
    novoNode->proximo = NULL;

    if (isEmpty(fila)) {
        fila->frente = novoNode;
        fila->fim = novoNode;
    } else {
        fila->fim->proximo = novoNode;
        fila->fim = novoNode;
    }
}

void dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: A fila esta vazia.\n");
        return;
    }

    Node* temp = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->fim = NULL;
    }

    free(temp);
}

int peek(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Erro: A fila esta vazia.\n");
        return -1;
    }

    return fila->frente->valor;
}

void print(Fila* fila) {
    if (isEmpty(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    printf("Fila: ");
    Node* atual = fila->frente;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void limparFila(Fila* fila) {
    while (!isEmpty(fila)) {
        dequeue(fila);
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Testando as funções da fila
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    print(&fila);  // Fila: 10 20 30

    dequeue(&fila); // Remove o primeiro elemento lista: 10
    print(&fila);  // Fila: 20 30

    int frontValue = peek(&fila);
    printf("Valor do primeiro elemento: %d\n", frontValue);  // Valor do primeiro elemento: 20

    int empty = isEmpty(&fila);
    printf("A fila esta vazia? %s\n", (empty ? "Sim" : "Nao"));  // A fila está vazia? Não

    limparFila(&fila);

    return 0;
}
