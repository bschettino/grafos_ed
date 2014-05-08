//
//  grafo.h
//  grafos
//
//  Created by Bruno Schettino on 5/8/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#ifndef grafos_grafo_h
#define grafos_grafo_h

#include "vizinho.h"


typedef struct grafo{
    int no;
    TViz * prim_viz;
    struct grafo * prox;
}TGrafo;

TGrafo * inicializa(void);
void imprime(TGrafo * g);
TGrafo * busca_no(TGrafo * g, int no);
TGrafo * ins_no(TGrafo * g, int no);
void ins_aresta(TGrafo * g, int no1, int no2, int custo);
void retira_aresta(TGrafo * g, int no1, int no2);
TGrafo * retira_no(TGrafo * g, int no);




#endif
