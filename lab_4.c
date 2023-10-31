#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* next;
};

struct ListaEnlazada {
    struct Nodo* cabeza;
};

void agregarNodo(struct ListaEnlazada* lista, int valor) {
    struct Nodo* nodoNuevito = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodoNuevito->dato = valor;
    nodoNuevito->next = NULL;

    if (lista->cabeza == NULL) {
        lista->cabeza = nodoNuevito;
    } else {
        struct Nodo* temp = lista->cabeza;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodoNuevito;
    }
}

void eliminarNodoPorValor(struct ListaEnlazada* lista, int valor) {
    struct Nodo* temp = lista->cabeza;
    struct Nodo* prev = NULL;

    if (temp != NULL && temp->dato == valor) {
        lista->cabeza = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->dato != valor) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("El valor no existe en la lista.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void agregarNodoAlPrincipio(struct ListaEnlazada* lista, int valor) {
    struct Nodo* nodoNuevito = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodoNuevito->dato = valor;
    nodoNuevito->next = lista->cabeza;
    lista->cabeza = nodoNuevito;
}

void agregarNodoAlFinal(struct ListaEnlazada* lista, int valor) {
    agregarNodo(lista, valor);
}

void buscarNodoPorValor(struct ListaEnlazada* lista, int valor) {
    struct Nodo* temp = lista->cabeza;
    while (temp != NULL) {
        if (temp->dato == valor) {
            printf("El valor existe.\n");
            return;
        }
        temp = temp->next;
    }
    printf("El valor no existe.\n");
}

void imprimirLista(struct ListaEnlazada* lista) {
    struct Nodo* temp = lista->cabeza;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->next;
    }
    printf("\n");
}

void obtenerElementoEnPosicion(struct ListaEnlazada* lista, int indice) {
    struct Nodo* temp = lista->cabeza;
    int contador = 0;
    while (temp != NULL) {
        if (contador == indice) {
            printf("El valor en la posición %d es: %d\n", indice, temp->dato);
            return;
        }
        contador++;
        temp = temp->next;
    }
    printf("El índice especificado no existe en la lista.\n");
}

int main() {
    struct ListaEnlazada lista;
    lista.cabeza = NULL;

    agregarNodo(&lista, 5); // Aca se agrega un nodo
    agregarNodo(&lista, 3);
    agregarNodo(&lista, 7);
    imprimirLista(&lista); // Se da a imprimir la lista

    eliminarNodoPorValor(&lista, 3); //  Deletea un nodo por valor
    imprimirLista(&lista);

    agregarNodoAlPrincipio(&lista, 1); // Añdadir un nodo al principio
    imprimirLista(&lista);

    agregarNodoAlFinal(&lista, 9); // Agregar un nodo al final
    imprimirLista(&lista);

    buscarNodoPorValor(&lista, 5); // Acá se da a buscar nodo por su valor
    buscarNodoPorValor(&lista, 11);

    obtenerElementoEnPosicion(&lista, 2); // Se obtiene el elemento en posición
    obtenerElementoEnPosicion(&lista, 5);

    // Liberarando memoria
    struct Nodo* actual = lista.cabeza;
    struct Nodo* siguiente;
    while (actual != NULL) {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }
    lista.cabeza = NULL;

    return 0;
}

