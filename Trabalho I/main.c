#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "criador.c"
#include "fazenda.h"


int menu(){
    printf("\n---------------------------------------------\n");
    printf("1 - Cadastrar Criador\t2 - Cadastrar Fazenda\n");
    printf("3 - Cadastrar Animal\t4 - Mostrar Criador\n");
    printf("5 - Mostrar animais sexo\t6 - Mostrar animais status");
    printf("7 - Arroba");
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);

    return op;
}

int main() {

    Criador *c, *cad_fazenda, *aux;// *cad_animal;
    int receba;

    //cad_animal = NULL;
    int r = 1;

    while(r != 0){
        r = menu();
        switch (r){
            case 1:
                c = criarListaDuplaCriadores();
                c = cadastrarCriador(c);
                //printf("Tem fazenda %d\n", tem(c));
                break;
            case 2:
                cad_fazenda = buscarCriador(c);
                cad_fazenda->fazendas = criarListaEncadeadaCircularFazendas();
                //printf("Tem fazenda %d\n", temFazenda(cad_fazenda->fazendas));
                cad_fazenda->fazendas = cadastrarFazenda(cad_fazenda->fazendas);
                //printf("Tem fazenda %d\n", temFazenda(cad_fazenda->fazendas));
                break;
            case 3:
                aux = cad_fazenda;
                //cad_animal->fazendas = buscarFazenda(cad_fazenda->fazendas);
                receba = buscarFazenda(cad_fazenda->fazendas);
                if(receba){
                    do {
                        if(aux->fazendas->id_fazenda == receba){
                            aux->fazendas->rebanho = criaListaEncadeadaSimplesAnimais();
                            aux->fazendas->rebanho = cadastrarAnimal(aux->fazendas->rebanho);
                            break;
                        }
                    
                        aux = aux->prox; /* avança para o próximo nó */
                    } while (aux);
                }else{
                    printf("Fazenda inexistente\n");
                }
                // cad_fazenda->fazendas->rebanho = criaListaEncadeadaSimplesAnimais();
                // cad_fazenda->fazendas->rebanho = cadastrarAnimal(cad_fazenda->fazendas->rebanho);
                break;
            case 4:
                mostrarCriadores(c);
                c = removerCriador(c);
                mostrarCriadores(c);
                // buscarAnimal(cad_fazenda->fazendas->rebanho);
                //mostrarTudo(c);
                break;
            case 5:
                mostrarAnimalSexo(cad_fazenda->fazendas);
                break;
            case 6:
                mostrarAnimalStatus(cad_fazenda->fazendas);
                break;
            case 7:
                arrobaTotal(cad_fazenda->fazendas);
                break;
            default:
                break;
        }
    }

    //mostrarCriadores(c);
    //mostrarTudo(c);

    return 0;
}
