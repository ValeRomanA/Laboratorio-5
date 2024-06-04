#ifndef double_list_h
#define double_list_h
 
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
 
typedef struct DoblelistaCruzada {
    Node* head;
    Node* tail;
} DoblelistaCruzada;
 
DoblelistaCruzada* crear_lista();
void insertar_inicio(DoblelistaCruzada* list, int data);
void insertar_final(DoblelistaCruzada* list, int data);
void insertar_posicion_esp(DoblelistaCruzada* list, int data, int position);
void eliminar_nodo(DoblelistaCruzada* list, int data);
Node* buscar(DoblelistaCruzada* list, int data);
void recorrer_adelante(DoblelistaCruzada* list);
void recorrer_atras(DoblelistaCruzada* list);
void liberar_lista(DoblelistaCruzada* list);
 
#endif // double_list_h

