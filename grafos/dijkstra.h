//
//  dijkstra.h
//  grafos
//
//  Created by Bruno Schettino on 5/28/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include "grafo.h"
#include "lista_dijkstra.h"
#include "tlse.h"


#define INFINITO 999999999

#ifndef grafos_dijkstra_h
#define grafos_dijkstra_h

typedef struct tipo_dijkstra{
    TLD * informacoes;
    TLSE * vertices_abertos;
    TGrafo * grafo;
}TDijkstra;

TDijkstra * inicializa_dij(TGrafo *g, int origem);
void menor_distancia(TDijkstra * dj);
void imprimeDijkstra(TDijkstra * dj);


#endif
