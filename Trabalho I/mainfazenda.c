#include <stdio.h>
#include <stdlib.h>

#include "fazenda.h"
#include "fazenda.c"
#include "animal.h"
#include "animal.c"


int main() {
    int receba;
    Fazenda *faz;


    faz = criarListaEncadeadaCircularFazendas();

    faz = cadastrarFazenda(faz);
    faz = cadastrarFazenda(faz);
    faz = cadastrarFazenda(faz);
    Fazenda *aux = faz;
    if (aux){ 
        do {
            printf("%d\n", aux->id_fazenda);
            printf("%d\n", aux->id_criador);
            printf("%s\n", aux->nome);
            printf("%s\n", aux->localizacao.cidade);
            printf("%s\n", aux->localizacao.estado);
            printf("%s\n", aux->localizacao.logradouro);
            
            aux = aux->prox; /* avança para o próximo nó */
        } while (aux != faz);
    }
    //removerFazenda(faz, 23);
    receba = buscarFazenda(faz);
     
    do {
        if(aux->id_fazenda == receba){
            printf("%d\n", aux->id_fazenda);
            printf("%d\n", aux->id_criador);
            printf("%s\n", aux->nome);
            printf("%s\n", aux->localizacao.cidade);
            printf("%s\n", aux->localizacao.estado);
            printf("%s\n", aux->localizacao.logradouro);
            break;
        }
        
        aux = aux->prox; /* avança para o próximo nó */
    } while (aux);

    
    
    
    

    // if (num){
    //     printf("%d\n", aux->id_fazenda);
    //     printf("%d\n", aux->id_criador);
    //     printf("%s\n", aux->nome);
    //     printf("%s\n", aux->localizacao.cidade);
    //     printf("%s\n", aux->localizacao.estado);
    //     printf("%s\n", aux->localizacao.logradouro);
    // }

    // while(aux){
    //     if(aux->prox == faz) break;
    //     printf("%d\n", aux->id_fazenda);
    //     aux = aux->prox;
    // }



    return 0;
}