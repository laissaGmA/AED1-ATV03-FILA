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

void imprimir_numeros_binarios(int n) {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 1);

    while (n > 0 && !isEmpty(&fila)) {
        int numero_binario = peek(&fila);
        dequeue(&fila);

        printf("%d ", numero_binario);
        n--;

        enqueue(&fila, numero_binario * 10);
        enqueue(&fila, numero_binario * 10 + 1);
    }

    limparFila(&fila);
}

int main() {
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    imprimir_numeros_binarios(n);

    return 0;
}
