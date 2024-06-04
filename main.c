#include <stdio.h>
#include "double_list.h"

int main() {
    DoblelistaCruzada* list = crear_lista();
    if (!list) return 1;

    // Insertar nodos al inicio y al final
    insertar_inicio(list, 10);
    insertar_inicio(list, 20);
    insertar_final(list, 30);
    insertar_final(list, 40);

    // Imprimir la lista hacia adelante y hacia atrás
    printf("Lista hacia adelante: ");
    recorrer_adelante(list);
    printf("Lista hacia atrás: ");
    recorrer_atras(list);

    // Insertar nodo en una posición específica
    insertar_posicion_esp(list, 25, 2);
    printf("Lista después de insertar 25 en la posición 2: ");
    recorrer_adelante(list);

    // Buscar un nodo
    Node* found = buscar(list, 30);
    if (found) {
        printf("Nodo con el dato 30 encontrado.\n");
    } else {
        printf("Nodo con el dato 30 no encontrado.\n");
    }

    // Eliminar un nodo
    eliminar_nodo(list, 20);
    printf("Lista después de eliminar el nodo con el dato 20: ");
    recorrer_adelante(list);

    // Liberar la lista
    liberar_lista(list);

    return 0;
}
