#include "ListaSimpluInlantuita.h"
#include <stdio.h>

int main() {
    // creezi lista simplu inlantuita
    t_lista lista;

    // initializezi lista
    makenull(&lista);

    // adaugi in lista cu valori
    insert_tail(&lista, 1);
    insert_tail(&lista, 2);
    insert_tail(&lista, 3);
    insert_tail(&lista, 4);
    insert_head(&lista, 0);

    // printezi lista
    print(&lista);

    // iei headul listei
    t_nod* head = lista.head;

    // stergi din lista cu valori
    delete_val(&lista, 3);

    // stergi din lista cu noduri
    delete_nod(&lista, head->next->next->next);

    print(&lista);

    // cauti in lista cu noduri un nod existent
    printf("%d ", search(&lista, head));

    // cauti in lista cu noduri un nod neexistent
    printf("%d ", search(&lista, head->next->next->next));

    // eliberezi memeorie din lista
    free_memory(&lista);
}
