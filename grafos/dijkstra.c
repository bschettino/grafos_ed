//
//  dijkstra.c
//  grafos
//
//  Created by Bruno Schettino on 5/28/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include "lista_dijkstra.h"

TDijkstra * inicializa_dij(TGrafo *g, int origem){
    TDijkstra * novo = (TDijkstra *) malloc(sizeof(TDijkstra));
    novo->vertices_abertos = inicializa_tlse();
    novo->informacoes = inicializa_lista_dijkstra();
    novo->grafo = g;
    TGrafo * p = g;
    while(p){//inicializa todos os vértices como abertos, custo infinito e sem pai
        novo->informacoes = ins_fim_lista_dijkstra(novo->informacoes, p->no, INFINITO, -1);
        novo->vertices_abertos = ins_fim_tlse(novo->vertices_abertos, p->no);
        p = p->prox;
    }
    //Seta distância da origem até ela mesma como 0
    TLD * l_origem = busca_lista_dijkstra(novo->informacoes, origem);
    l_origem->distancia = 0;
    return novo;
}

TLD * minimo(TDijkstra * dj){ // Busca o vértice aberto que tem menor distância
    TLSE * abertos = dj->vertices_abertos;
    TLD * menor = busca_lista_dijkstra(dj->informacoes, abertos->no);
    while(abertos){
        TLD * no = busca_lista_dijkstra(dj->informacoes, abertos->no);
        if(no->distancia < menor->distancia) menor = no;
        abertos = abertos->prox;
    }
    return menor;
}

void imprimeDijkstra(TDijkstra * dj){
    imprime_lista_dijkstra(dj->informacoes);
    imprime_arquivo_lista_dijkstra(dj->informacoes);
}

void menor_distancia(TDijkstra * dj){
    while(dj->vertices_abertos){
        TLD * menorDist = minimo(dj);
        dj->vertices_abertos = rem_tlse(dj->vertices_abertos, menorDist->no); // Remove o nó com menor distância da lista de nós abertos
        TViz * viz = busca_no(dj->grafo, menorDist->no)->prim_viz;
        while(viz){ //percorre todos os vizinhos do nó com menor distância
            TLD * aux = busca_lista_dijkstra(dj->informacoes, viz->id);
            if(aux->distancia > (menorDist->distancia + viz->custo)){ //atualiza a menor distância dos vizinhos caso ela seja melhorada passando pelo atual vértice com menor distância 
                aux->distancia = menorDist->distancia + viz->custo;
                aux->pai = menorDist->no;
            }
            viz = viz->prox_viz;
        }
    }
}

void liberar_dijksta(TDijkstra * dj){
    liberar_lista_dijkstra(dj->informacoes);
    liberar_lista_tlse(dj->vertices_abertos);
    free(dj);
}

