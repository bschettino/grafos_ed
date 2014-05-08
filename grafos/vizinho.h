//
//  vizinho.h
//  grafos
//
//  Created by Bruno Schettino on 5/8/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#ifndef grafos_vizinho_h
#define grafos_vizinho_h


typedef struct viz{
    int id;
    int custo;
    struct viz * prox_viz;
}TViz;


#endif
