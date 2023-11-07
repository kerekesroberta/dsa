//
// Created by Roberta Kerekes on 30.10.2023.
//
typedef struct nod {
    int val;
    struct nod* next;
}t_nod;
typedef struct {
    t_nod* head;
}t_lista;


void makenull(t_lista* lista);
void free_memory(t_lista* lista);
void print(t_lista* lista);
t_nod* insert_tail(t_lista* lista, int val);
int insert_head(t_lista* lista, int val);
int search(t_lista* lista, t_nod* nod);
int delete_val(t_lista* lista, int val);
int delete_nod(t_lista* lista, t_nod* nod);

