//
//  prim.h
//  grafos
//
//  Created by Bruno Schettino on 5/26/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include "grafo.h"

#ifndef grafos_prim_h
#define grafos_prim_h

typedef struct busca_prim{
    int no1;
    int no2;
    int custo;
}TBPrim;


TGrafo * arvore_geradora_minima(TGrafo *g);
int possui_no_a_inserir(TGrafo *g, TGrafo *a);
TBPrim * proxima_aresta(TGrafo *g, TGrafo *a);
void imprime_agm(TGrafo *g);

#endif
