//
//  lista_dijkstra.h
//  grafos
//
//  Created by Bruno Schettino on 5/28/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#ifndef grafos_lista_dijkstra_h
#define grafos_lista_dijkstra_h


typedef struct lista_dijkstra{
    int distancia;
    int pai;
    int no;
    struct lista_dijkstra *prox;
}TLD;

TLD *inicializa_lista_dijkstra(void);

TLD * busca_lista_dijkstra(TLD *l, int no);

TLD * ins_ini_lista_dijkstra (TLD *l, int no, int distancia, int pai);

TLD * ins_fim_lista_dijkstra (TLD *l, int no, int distancia, int pai);

TLD * rem_lista_dijkstra (TLD *l, int no);

void imprime_lista_dijkstra (TLD *l);

void imprime_arquivo_lista_dijkstra (TLD *l);

void liberar_lista_dijkstra(TLD *l);



#endif
