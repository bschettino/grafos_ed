//
//  grafo.c
//  grafos
//
//  Created by Bruno Schettino on 5/8/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include <stdio.h>
#include "grafo.h"
#include "vizinho.h"
#include <stdlib.h>


TGrafo * inicializa(void){
    return NULL;
}

void imprime(TGrafo * g){
    TGrafo * p = g;
    while(p){
        printf("Nó %d \n", p->no);
        TViz *q = p->prim_viz;
        while(q){
            printf("Vizinho %d \t custo %d \n", q->id, q->custo);
            q = q->prox_viz;
        }
        p = p->prox;
    }
}

TGrafo * busca_no(TGrafo *g, int no){
    TGrafo *p = g;
    while((p) && (p->no != no)){
        p=p->prox;
    }
    return p;
}

TGrafo * ins_no(TGrafo * g, int no){
    TGrafo *novo = (TGrafo *) malloc(sizeof(TGrafo));
    novo->no = no;
    novo->prim_viz = NULL;
    novo->prox = g;
    return novo;
}

void ins_aresta(TGrafo *g, int no1, int no2, int custo){
    TGrafo * p = busca_no(g, no1);
    if (!p) return;
    TViz *ant = NULL, *q = p->prim_viz;
    while(q){
        if(q->id == no2){
            q->custo = custo;
            return;
        }
        ant=q;
        q=q->prox_viz;
    }
    if(!q){
        TViz * novo = (TViz *) malloc(sizeof(TViz));
        novo->prox_viz = NULL;
        novo->id = no2;
        novo->custo = custo;
        if(!ant){
            p->prim_viz = novo;
        }
        else{
            ant->prox_viz = novo;
        }
    }
}

void retira_aresta(TGrafo *g, int no1, int no2){
    TGrafo * p = busca_no(g, no1);
    if(!p) return;
    TViz * ant = NULL, *q = p->prim_viz;
    while((q) && (q->id != no2)){
        ant=q;
        q=q->prox_viz;
    }
    if (!q) return;
    if(!ant){
        p->prim_viz = q->prox_viz;
    }else{
        ant->prox_viz = q->prox_viz;
    }
    free(q);
}

TGrafo * retira_no(TGrafo *g, int no){
    TGrafo * ant = NULL, *p = g;
    while((p) && (p->no != no)){
        ant = p;
        p = p->prox;
    }
    if(!p) return g;
    TViz * q = p->prim_viz;
    while(q){
        int no2 = q->id;
        q = q->prox_viz;
        retira_aresta(g, no, no2);
        retira_aresta(g, no2, no);
    }
    if(!ant){
        g = g->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return g;
}
void libera(TGrafo *g){
    while(g){
        g = retira_no(g, g->no);
    }
}

int conexo(TGrafo *g){
    if(!g)
        return 0;
    TGrafo *profundidade = inicializa();
    TGrafo *aux = g;
    TViz *vizinho;
    while(aux){
        vizinho = aux->prim_viz;
        if(!busca_no(profundidade, aux->no))
            profundidade = ins_no(profundidade, aux->no);
        while(vizinho){
            if(!busca_no(profundidade, vizinho->id)){
                profundidade = ins_no(profundidade, vizinho->id);
            }
            vizinho = vizinho->prox_viz;
        }
        aux = aux->prox;
    }
    aux =g;
    while(aux){
        if(!busca_no(profundidade, aux->no))
            return 0;
        aux = aux->prox;
    }
    
    return 1;
}