#include <stdio.h>
#include "ListeDubluInlantuite.h"

int main() {

    t_lista lista;
    makenull(&lista);
    insert(&lista, 1);
    insert(&lista, 2);
    insert(&lista, 3);
    insert(&lista, 4);
    insert(&lista, 5);

    print(&lista);
    delete_val(&lista, 2);
    print(&lista);

    t_nod* head = lista.head;
    delete_nod(&lista, head->next);
    print(&lista);

    printf("%d ",search_val(&lista,3));
    printf("%d ", search_nod(&lista,head->next->next));

    return 0;
}
