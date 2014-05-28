//
//  tlse.c
//  grafos
//
//  Created by Bruno Schettino on 5/28/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include <stdio.h>
#include "tlse.h"
#include <stdlib.h>

TLSE *inicializa_tlse(void){
    return NULL;
}

TLSE * ins_ini_tlse (TLSE *l, int elem){
    TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
    novo->no = elem;
    novo->prox = l;
    return novo;
}

TLSE * ins_fim_tlse (TLSE *l, int elem){
    TLSE *aux = l;
    if (l) {
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = ins_ini_tlse(aux->prox, elem);
    }else{
        l = ins_ini_tlse(l, elem);
    }
    
    return l;
}


TLSE * rem_tlse (TLSE *l, int elem){
    TLSE *ant = NULL, *p = l;
    while(p && (p->no !=elem)){
        ant = p;
        p = p->prox;
    }
    if(p){
        if(ant){
            ant->prox = p->prox;
        }else{
            l=l->prox;
        }
        free(p);
    }
    return l;
}

void imprime_lista_tlse (TLSE *l){
    TLSE *aux = l;
    while(aux){
        printf("%d\t", aux->no);
        aux = aux->prox;
    }
    printf("\n");
}

void liberar_lista_tlse(TLSE *l){
    TLSE *aux = l;
    TLSE *aux2 = NULL;
    while(aux){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}

TLSE *busca_lista_tlse(TLSE* l, int no){
    TLSE *p = l;
    while(p && (p->no !=no)){
        p = p->prox;
    }
    return p;
}