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
        printf("Erro: A fila está vazia.\n");
        return;
    }

    Node* temp = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->fim = NULL;
    }

    free(temp);
}

void intercalarFilas(Fila* l1, Fila* l2, Fila* l3) {
    while (!isEmpty(l1) || !isEmpty(l2)) {
        if (!isEmpty(l1)) {
            enqueue(l3, l1->frente->valor);
            dequeue(l1);
        }
        if (!isEmpty(l2)) {
            enqueue(l3, l2->frente->valor);
            dequeue(l2);
        }
    }
}

void print(Fila* fila) {
    if (isEmpty(fila)) {
        printf("A fila está vazia.\n");
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

int main() {
    Fila l1, l2, l3;
    inicializarFila(&l1);
    inicializarFila(&l2);
    inicializarFila(&l3);

    // Preenchendo as filas de exemplo
    enqueue(&l1, 1);
    enqueue(&l1, 2);
    enqueue(&l1, 3);
    enqueue(&l1, 4);

    enqueue(&l2, 10);
    enqueue(&l2, 20);
    enqueue(&l2, 30);

    // Intercalando as filas l1 e l2 para gerar a fila l3
    intercalarFilas(&l1, &l2, &l3);

    // Exibindo a fila resultante: l3
    printf("L3: ");
    print(&l3);

    return 0;
}
