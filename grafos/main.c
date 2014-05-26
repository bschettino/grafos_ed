//
//  main.c
//  grafos
//
//  Created by Bruno Schettino on 5/8/14.
//  Copyright (c) 2014 UFF. All rights reserved.
//

#include <stdio.h>
#include "grafo.h"
#include "vizinho.h"

int main(int argc, const char * argv[])
{
    if(argc < 2)
        exit(1);

    TGrafo *grafo=inicializa();
    int entrada = 0;
    
    while(entrada != 6) {
		printf("\nDigite a opcao:\n");
        printf("1 - Carregar arquivo\n");
		printf("2 - Inserir vertice\n");
        printf("3 - Retirar vertice\n");
		printf("4 - Inserir aresta\n");
        printf("5 - Retirar aresta\n");
		printf("6 - Sair\n");
		scanf("%d",&entrada);
        if(entrada == 1){
            FILE * in;
            in = fopen(argv[1], "r");
            int numVertices, valorVertice, numArestas, verticeDestino, custo,i;
            if(in){
                //Leitura do tipo diz numero de vértices, depois lista os vértices
                //informa o número de arestas e depois lista as arestas da forma: "no1 no2 custo"
                fscanf(in,"%d", &numVertices);
                for (i=0; i<numVertices; i++) {
                    fscanf(in, "%d", &valorVertice);
                    grafo = ins_no(grafo, valorVertice);
                }
                fscanf(in, "%d", &numArestas);
                for (i=0; i<numArestas; i++) {
                    fscanf(in, "%d %d %d", &valorVertice,&verticeDestino,&custo);
                    ins_aresta(grafo, valorVertice, verticeDestino, custo);
                }
            }
        }
        else if (entrada == 2){
            printf("Digite o valor do vertice");
            int valorVertice;
            scanf("%d",&valorVertice);
            grafo = ins_no(grafo, valorVertice);
        }
        else if (entrada == 3){
            printf("Digite o valor do vertice");
            int valorVertice;
            scanf("%d",&valorVertice);
            grafo = retira_no(grafo, valorVertice);
        }
        
        else if (entrada == 4){
            printf("Digite o valor do vertice 1:");
            int valorVertice1, valorVertice2, custo;
            scanf("%d",&valorVertice1);
            printf("Digite o valor do vertice 2:");
            scanf("%d",&valorVertice2);
            printf("Digite o valor do custo:");
            scanf("%d",&custo);
            ins_aresta(grafo, valorVertice1, valorVertice2, custo);
        }
        else if (entrada == 5){
            printf("Digite o valor do vertice 1:");
            int valorVertice1, valorVertice2;
            scanf("%d",&valorVertice1);
            printf("Digite o valor do vertice 2:");
            scanf("%d",&valorVertice2);
            retira_aresta(grafo, valorVertice1, valorVertice2);
        }
        
    }

}