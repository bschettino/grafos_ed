//
//  tlse.h
//  grafos
//
//  Created by Bruno Schettino on 5/28/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#ifndef grafos_tlse_h
#define grafos_tlse_h


typedef struct lista_tlse{
    int no;
    struct lista_tlse *prox;
}TLSE;

TLSE *inicializa_tlse(void);

TLSE * ins_ini_tlse (TLSE *l, int no);

TLSE * ins_fim_tlse (TLSE *l, int no);

TLSE * rem_tlse (TLSE *l, int no);

TLSE * busca_tlse (TLSE *l, int no);

void imprime_lista_tlse (TLSE *l);

void liberar_lista_tlse (TLSE *l);

#endif
