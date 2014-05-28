//
//  prim.c
//  grafos
//
//  Created by Bruno Schettino on 5/26/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "prim.h"
#include "grafo.h"
#include "vizinho.h"


int possui_no_a_inserir(TGrafo *g, TGrafo *a){ // verifica se existe algum nó de g que ainda não está na árvore
    TGrafo *aux = g;
    while((aux) && (busca_no(a, aux->no))){
        aux = aux->prox;
    }
    return (aux != NULL);
}


TBPrim * proxima_aresta(TGrafo *g, TGrafo *a){
    TGrafo *aux = NULL; // itera no grafo original para ver os vizinhos reais dos vértices
    TGrafo *aux2 = a; // itera nos nós da árvore
    TViz * menor = NULL;
    TViz * aux_v = NULL;
    TBPrim * resposta = (TBPrim *) malloc(sizeof(TBPrim));
    while((!menor) && aux2){ // procura um elemento qqr com uma aresta que tenha uma ponta na arvore e outra fora para servir como base
        aux = busca_no(g, aux2->no); //busca as arestas no grafo original
        aux_v = aux->prim_viz;
        while((aux_v) && (busca_no(a, aux_v->id))){
            aux_v = aux_v->prox_viz;
        }
        if(!aux_v){ // se percorreu toda a lista de vizinhos e não encontrou nenhum fora da árvore atual
            aux2 = aux2->prox;
        }else{// se encontrou alguém com uma ponta na árvore e outra ponta fora
            menor = aux_v;
            resposta->no1 = aux2->no;
            resposta->no2 = menor->id;
            resposta->custo = menor->custo;
        }
    }
    
    while(aux2){// Nesse ponto, "menor" é um candidato qualquer a ser o menor e temos que verificar as outras arestas
        aux = busca_no(g, aux2->no);
        aux_v = aux->prim_viz;
        while(aux_v){

            if((!busca_no(a, aux_v->id)) && (aux_v->custo < menor->custo)){ // se o nó não está na árvore e a aresta tem custo menor do que o menor atual
                menor = aux_v;
                resposta->no1 = aux->no;
                resposta->no2 = menor->id;
                resposta->custo = menor->custo;
            }
            aux_v = aux_v->prox_viz;
        }
        aux2 = aux2->prox;
    }
    return resposta;
}


TGrafo * arvore_geradora_minima(TGrafo *g){
    if(!g) return g;
    TGrafo *a = inicializa(), *aux = g;

    a = ins_no(a, g->no);
    aux = aux->prox;
    while(possui_no_a_inserir(g,a)){
        TBPrim * nova_aresta = proxima_aresta(g,a);
        a = ins_no(a, nova_aresta->no2);
        ins_aresta(a, nova_aresta->no1, nova_aresta->no2, nova_aresta->custo);
        ins_aresta(a, nova_aresta->no2, nova_aresta->no1, nova_aresta->custo);
        free(nova_aresta);
    }
    
    return a;
}

void imprime_agm(TGrafo *g){
    FILE *out;
    out = fopen("/Users/MateusPelegrino/Documents/UFF/Mestrado/Estrutura de Dados e Algoritmos/grafos_ed/AGM.txt", "w");
    if (out){
        TGrafo * p = g;
        while(p){
            fprintf(out,"Nó %d \n", p->no);
            TViz *q = p->prim_viz;
            while(q){
                fprintf(out,"Vizinho %d \t custo %d \n", q->id, q->custo);
                q = q->prox_viz;
            }
            p = p->prox;
        }
        fclose(out);
    }
}




