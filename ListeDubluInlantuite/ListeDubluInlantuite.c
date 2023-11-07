//
// Created by Roberta Kerekes on 07.11.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "ListeDubluInlantuite.h"

void makenull(t_lista* lista) {
    if(lista != NULL)
        lista->head = NULL;
    else
        printf("Nu sunt elemente\n");
}

void free_memory(t_lista* lista){
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

t_nod* insert(t_lista* lista, int val){
    // creare si alocare nod element nou cu ->val = val si ->next = NULL
    t_nod* nod = (t_nod*)malloc(sizeof(t_nod));
    nod->val=val;
    nod->next=NULL;
    nod->prev=NULL;


    if (lista != NULL) {
        // daca lista nu e goala, traversam lista
        if (lista->head != NULL) {
            t_nod* nodcur = lista->head;
            while (nodcur->next != NULL) {
                nodcur = nodcur->next;
            }
            // adaugam nodul ca ultim element
            nodcur->next = nod;
            nod->prev = nodcur;
        } else {
            // daca lista e goala adaugam nodul ca head la lista
            lista->head = nod;
        }
    }
    return nod;
}

int search_nod(t_lista* lista, t_nod* nod){
    if(lista != NULL){
        t_nod* nodcur = lista->head;
        while(nodcur->next != NULL){
            if(nodcur == nod){
                return 1;
            }
            nodcur=nodcur->next;
        }

        if(nodcur == nod)
            return 1;
        else
            return 0;
    }
    return 0;
}

int search_val(t_lista* lista, int val){
    if(lista != NULL){
        t_nod* nodcur = lista->head;
        while(nodcur->next != NULL){
            if(nodcur->val == val){
                return 1;
            }
            nodcur=nodcur->next;
        }

        if(nodcur->val == val)
            return 1;
        else
            return 0;
    }
    return 0;
}

int delete_val(t_lista* lista, int val){
    if (lista != NULL && lista->head != NULL) {
        t_nod* head = lista->head;

        // daca nodul de sters e head
        if (head->val == val) {
            lista->head = head->next;
            lista->head->prev = NULL;
            free(head); // elibereaza memorie nod sters
            return 1;
        }

        // daca e alt nod
        t_nod* nodcur = head->next;

        while (nodcur != NULL) {
            if (nodcur->val == val) {
                nodcur->prev->next = nodcur->next;
                if (nodcur->next != NULL) {
                    nodcur->next->prev = nodcur->prev;
                }
                free(nodcur); // elibereaza memorie nod sters
                return 1;
            }
            nodcur = nodcur->next;
        }
    }
    return 0;
}

int delete_nod(t_lista* lista, t_nod* nod){
    if (lista != NULL && lista->head != NULL) {
        t_nod* head = lista->head;

        // daca nodul de sters e head
        if (head == nod) {
            lista->head = head->next;
            lista->head->prev = NULL;
            free(head); // elibereaza memorie nod sters
            return 1;
        }

        t_nod* nodcur = head->next;

        while (nodcur != NULL) {
            if (nodcur == nod) {
                nodcur->prev->next = nodcur->next;
                if (nodcur->next != NULL) {
                    nodcur->next->prev = nodcur->prev;
                }
                free(nodcur); // elibereaza memorie nod sters
                return 1;
            }
            nodcur = nodcur->next;
        }
    }
    return 0;
}
