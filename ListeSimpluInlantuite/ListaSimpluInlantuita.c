//
// Created by Roberta Kerekes on 30.10.2023.
//
#include "ListaSimpluInlantuita.h"
#include <stdio.h>
#include <stdlib.h>


void makenull(t_lista* lista) {
    if(lista != NULL)
       lista->head = NULL;
    else
        printf("Nu sunt elemente\n");
}


void free_memory(t_lista* lista) {
    t_nod* nod = lista->head;
    while (nod != NULL) {
        t_nod* next = nod->next; // tine urmatorul nod, inainte sa l eliberezi pe cel curent
        free(nod); // elibereaza memorie nod curent
        nod = next; // treci la urmatorul nod
    }
    makenull(&lista);
}


void print(t_lista* lista){
    if(lista != NULL){
        t_nod* nod = lista->head;
        while(nod != NULL){
            printf("%d ", nod->val);
            nod = nod->next;
        }
        printf("\n");
    }
    else
        printf("Nu sunt elemente\n");
}


t_nod* insert_tail(t_lista* lista, int val){
    // creare si alocare nod element nou cu ->val = val si ->next = NULL
    t_nod* nod = (t_nod*)malloc(sizeof(t_nod));
    nod->val=val;
    nod->next=NULL;

    if (lista != NULL) {
        // daca lista nu e goala, traversam lista
        if (lista->head != NULL) {
            t_nod* nodcur = lista->head;
            while (nodcur->next != NULL) {
                nodcur = nodcur->next;
            }
            // adaugam nodul ca ultim element
            nodcur->next = nod;
        } else {
            // daca lista e goala adaugam nodul ca head la lista
            lista->head = nod;
        }
    }
    return nod;
}


int insert_head(t_lista* lista, int val){
    // creare si alocare nod element nou cu ->val = val si ->next = NULL
    t_nod* nod = (t_nod*)malloc(sizeof(t_nod));
    nod->val = val;
    nod->next = NULL;

    // daca exista head in lista
    if (lista != NULL) {
        nod->next = lista->head;
        lista->head = nod;
    }
    else
        // daca nu exista head
        lista->head = nod;

    return val;
}


int search(t_lista* lista, t_nod* nod){
    if(lista != NULL){
        t_nod* head = lista->head;
        t_nod* nodcur = head;
        while(head->next != NULL){
            if(nodcur == nod){
                return 1;
            }
            nodcur=head->next;
            head=head->next;
        }

        if(head == nod)
            return 1;
        else
            return 0;
    }
    return 0;
}


int delete_val(t_lista* lista, int val) {
    if (lista != NULL && lista->head != NULL) {
        t_nod* head = lista->head;

        // daca nodul de sters e head
        if (head->val == val) {
            lista->head = head->next;
            free(head); // elibereaza memorie nod sters
            return 1;
        }

        // daca e alt nod
        t_nod* prevnodcur = head;
        t_nod* nodcur = head->next;

        while (nodcur != NULL) {
            if (nodcur->val == val) {
                prevnodcur->next = nodcur->next;
                free(nodcur); // elibereaza memorie nod sters
                return 1;
            }
            prevnodcur = nodcur;
            nodcur = nodcur->next;
        }
    }

    return 0;
}

int delete_nod(t_lista* lista, t_nod* nod) {
    if (lista != NULL && lista->head != NULL) {
        t_nod* head = lista->head;

        // daca nodul de sters e head
        if (head == nod) {
            lista->head = head->next;
            free(head); // elibereaza memorie nod sters
            return 1;
        }

        // daca e alt nod
        t_nod* prevnodcur = head;
        t_nod* nodcur = head->next;

        while (nodcur != NULL) {
            if (nodcur == nod) {
                prevnodcur->next = nodcur->next;
                free(nodcur); // elibereaza memorie nod sters
                return 1;
            }
            prevnodcur = nodcur;
            nodcur = nodcur->next;
        }
    }

    return 0;
}
