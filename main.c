#include <stdio.h>


#include "criador.h"
#include "criador.c"
#include "fazenda.h"
#include "animal.h"

int menu(){
    printf("\n-------------------------------------------------------\n");
    printf("1 - Cadastrar Criador\t2 - Cadastrar Fazenda\n");
    printf("3 - Cadastrar Animal\t4 - Mostrar Criadores\n");
    printf("5 - Mostrar Fazendas\t6 - Mostrar Atributos dos Criadores\n");
    printf("7 - Remover Criador\t8 - Remover Fazenda\n");
    printf("9 - Remover Animal\t10 - Permutar Animais\n");
    printf("11 - Listar por Status\t12 - buscar uma fazenda\n");
    
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);

    return op;
}

int main() {

    Criador *listaCriadores = criarListaDuplaCriadores();

    Criador *c;
    Criador *c2;
    Fazenda *f;
    Fazenda *f2;
    //Animal *a;

    int r = 1;
    int id, permitir, busca;

    while(r != 0){
        r = menu();
        switch (r){
        case 1:
            listaCriadores = cadastrarCriador(listaCriadores);
            break;
        case 2:
            c = buscarCriador(listaCriadores);
            if(c){
                c->fazendas = cadastrarFazenda(c->fazendas);
                //printf("%d", c->id_criador);
                c->fazendas->id_criador = c->id_criador;
            }

            break;
        case 3:
            c = buscarCriador(listaCriadores);
            if(c){
                printf("Informe o id da fazenda que voce procura: \n");
	            scanf("%d", &id);
                f = getFazenda(c->fazendas, id);
                printf("%d\n", f->id_fazenda);
                if(f){
                    f->rebanho = cadastrarAnimal(f->rebanho);
                    f->rebanho->id_fazenda = f->id_fazenda;
                    calcularPatrimonio(c);
                }
            }

            break;
        case 4:
            mostrarCriadores(listaCriadores);
            break;
        case 5:
            c = buscarCriador(listaCriadores);
            if(c){
                mostrarFazendas(c->fazendas);
            }

            break;
        case 6:
            mostrarAtributosCriadores(listaCriadores);
            break;
        case 7:
            listaCriadores = removerCriador(listaCriadores);
            break;
        case 8:
            c = buscarCriador(listaCriadores);
            if(c){
                printf("Id da fazenda: ");
                scanf("%d", &id);
                c->fazendas = removerFazenda(c->fazendas, id);
                printf("Fazenda removida\n");
                //atualizarPatrimonios(listaCriadores);
                //calcularPatrimonio(c);
            }

            break;
        case 9:
            c = buscarCriador(listaCriadores);
            if(c){
                printf("Informe o id da fazenda que voce procura: \n");
	            scanf("%d", &id);
                f = getFazenda(c->fazendas, id);
                if(f){
                    int x;
                    printf("Informe o id do animal: ");
                    scanf("%d", &x);
                    f->rebanho = removerAnimal(c->fazendas, x);
                    atualizarPatrimonios(listaCriadores);
                }
            }

            break;
        case 10:
            permitir = 0;
            c = buscarCriador(listaCriadores);
            if(c){
                printf("Informe o id da fazenda %d que voce procura: \n", permitir+1);
	            scanf("%d", &id);
                f = getFazenda(c->fazendas, id);
                if(f){
                    permitir++;
                }
            }
            if(permitir){
                c2 = buscarCriador(listaCriadores);
                if(c2){
                    printf("Informe o id da fazenda %d que voce procura: \n", permitir+1);
	                scanf("%d", &id);
                    f2 = getFazenda(c2->fazendas, id);
                    if(f2){
                        permutasAnimais(f, f2);
                        atualizarPatrimonios(listaCriadores);
                    } else{
                        printf("Essa permuta nao pode ser efetuada.\n");
                    }
                }
            } else{
                printf("Essa permuta nao pode ser efetuada.\n");
            }

            break;
        case 11:
            c = buscarCriador(listaCriadores);
            if(c){
                printf("Informe o id da fazenda que voce procura: \n");
	            scanf("%d", &id);
                f = getFazenda(c->fazendas, id);
                if(f){
                    listaStatusAnimais(f);
                }
            }
            break;
        case 12:
            busca = buscarFazenda(listaCriadores->fazendas);
            Criador *aux = listaCriadores;
            if(busca){
                do{
                    if(aux->fazendas->id_fazenda == busca){
                        printf("Id da fazenda: %d\n", aux->fazendas->id_fazenda);
                        printf("Id do criador: %d\n", aux->id_criador);
                        printf("Nome da fazenda: %s\n", aux->fazendas->nome);
                        printf("Cidade: %s\n", aux->fazendas->localizacao.cidade);
                        printf("Estado: %s\n", aux->fazendas->localizacao.estado);
                        printf("Longradouro: %s\n", aux->fazendas->localizacao.logradouro);
                        break;
                    }
                    aux->fazendas = aux->fazendas->prox; /* avança para o próximo nó */
                } while (aux);
            }else{
                printf("Id não encontrado\n");
            }
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }

    liberarMemoriaCriadores(listaCriadores);

    return 0;
}