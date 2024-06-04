#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

DoblelistaCruzada* crear_lista() {
    DoblelistaCruzada* list = (DoblelistaCruzada*)malloc(sizeof(DoblelistaCruzada));
    if (!list) {
        printf("Fallo reservando memoria\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertar_inicio(DoblelistaCruzada* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Fallo reservando memoria\n");
        return;
    }
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    list->head = new_node;
}

void insertar_final(DoblelistaCruzada* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Fallo reservando memoria\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
}

void insertar_posicion_esp(DoblelistaCruzada* list, int data, int position) {
    if (position == 0) {
        insertar_inicio(list, data);
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("La posición es mayor que la longitud de la lista.\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Fallo reservando memoria\n");
        return;
    }
    new_node->data = data;
    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL) {
        current->next->prev = new_node;
    } else {
        list->tail = new_node;
    }

    current->next = new_node;
}

void eliminar_nodo(DoblelistaCruzada* list, int data) {
    Node* current = list->head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("El nodo con el dato %d no se encuentra en la lista.\n", data);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

Node* buscar(DoblelistaCruzada* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void recorrer_adelante(DoblelistaCruzada* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void recorrer_atras(DoblelistaCruzada* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void liberar_lista(DoblelistaCruzada* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
