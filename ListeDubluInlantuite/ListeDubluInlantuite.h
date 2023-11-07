//
// Created by Roberta Kerekes on 07.11.2023.
//

#ifndef LISTEDUBLUINLANTUITE_LISTEDUBLUINLANTUITE_H
#define LISTEDUBLUINLANTUITE_LISTEDUBLUINLANTUITE_H

typedef struct nod {
    int val;
    struct nod* next, * prev;
}t_nod;
typedef struct {
    t_nod* head;
}t_lista;


void makenull(t_lista* lista);
void free_memory(t_lista* lista);
void print(t_lista* lista);
t_nod* insert(t_lista* lista, int val);
int search_nod(t_lista* lista, t_nod* nod);
int search_val(t_lista* lista, int val);
int delete_val(t_lista* lista, int val);
int delete_nod(t_lista* lista, t_nod* nod);

#endif //LISTEDUBLUINLANTUITE_LISTEDUBLUINLANTUITE_H
