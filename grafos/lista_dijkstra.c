//
//  lista_dijkstra.c
//  grafos
//
//  Created by Bruno Schettino on 5/28/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include <stdio.h>
#include "lista_dijkstra.h"
#include <stdlib.h>

TLD *inicializa_lista_dijkstra(void){
    return NULL;
}

TLD * ins_ini_lista_dijkstra (TLD *l, int no, int dist, int pai){
    TLD *novo = (TLD *) malloc(sizeof(TLD));
    novo->distancia = dist;
    novo->prox = l;
    novo->no = no;
    novo->pai = pai;
    return novo;
}

TLD * ins_fim_lista_dijkstra (TLD *l, int no, int dist, int pai){
    TLD *aux = l;
    if (l) {
        while(aux->prox){
            aux = aux->prox;
        }
        aux->prox = ins_ini_lista_dijkstra(aux->prox, no, dist, pai);
    }else{
        l = ins_ini_lista_dijkstra(l, no, dist, pai);
    }
    
    return l;
}

TLD *busca_lista_dijkstra(TLD* l, int no){
    TLD *p = l;
    while(p && (p->no !=no)){
        p = p->prox;
    }
    return p;
}

TLD * rem_lista_dijkstra (TLD *l, int no){
    TLD *ant = NULL, *p = l;
    while(p && (p->no !=no)){
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

void imprime_lista_dijkstra (TLD *l){
    TLD *aux = l;
    while(aux){
        printf("Nó: %d\t Distância: %d\t Pai: %d\n", aux->no, aux->distancia, aux->pai);
        aux = aux->prox;
    }
    printf("\n");
}


void liberar_lista_dijkstra(TLD *l){
    TLD *aux = l;
    TLD *aux2 = NULL;
    while(aux){
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}

