#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criador.h"
#include "fazenda.h"
#include "fazenda.c"
#include "animal.h"
#include "animal.c"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

int id_unico = 0;

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));
	c->fazendas = criarListaEncadeadaCircularFazendas();

	c->id_criador = ++id_unico;
	printf("Id do criador: %d\n", c->id_criador);
	fflush(stdin);
	printf("Nome do criador: ");
	scanf("%[^\n]", c->nome);
	fflush(stdin);
	c->ant = NULL;
	c->prox = criadores;
	c->patrimonio = 0.0;

	if(!criadores){
		c->prox = NULL;
	} else{
		c->prox = criadores;
		criadores->ant = c;
	}

	return c;
}

void mostrarFazenda(Fazenda *fazenda){
	if(fazenda){
		printf("Nome da Fazenda: %s\n", fazenda->nome);
		printf("Valor da fazenda: %.2f\n", fazenda->valor_fazenda);
		printf("Cidade: %s\n", fazenda->localizacao.cidade);
		printf("Estado: %c%c\n", fazenda->localizacao.estado[0], fazenda->localizacao.estado[1]);
		printf("Logradouro: %s\n", fazenda->localizacao.logradouro);
		contAnimaisSexo(fazenda);
	} else{
		printf("Nehuma fazenda cadastrada.\n");
	}
	
}

/*
int size(Criador *c){
	Criador *aux;
	int count = 0;

	aux = c;
	while(aux){
		count++;
		aux = aux->prox;
	}

	return count;
}
*/

Criador *buscarCriador(Criador *criadores){
	Criador *aux = criadores;
	int id;
	printf("Informe o id do criador: ");
	scanf("%d", &id);

	while(aux){
		if(id == aux->id_criador){
			printf("Criador encontrado.\n");
			return aux;
		}

		aux = aux->prox;
	}

	printf("Criador nao encontrado.\n");
	return NULL;
}

int temFazenda(Fazenda *fazenda){
	if(fazenda){
		return 1;
	}

	return 0;
}

void mostrarCriadores(Criador *criadores){
	Criador *aux = criadores;

	if(aux){
		while(aux){
			printf("-----------------------------------------\n");
			printf("Id do criador: %d\nNome: %s\n", aux->id_criador, aux->nome);
			printf("Patrimonio: %.2f\n", aux->patrimonio);
			if(temFazenda(aux->fazendas)){
				printf("Tem fazenda cadastrada.\n");
			} else{
				printf("Nao tem fazenda cadastrada.\n");
			}
			aux = aux->prox;
		}
	} else{
		printf("Nao ha nenhum criador cadastrado.\n");
	}
	
	printf("\n");
}

void mostrarAtributosCriadores(Criador *criadores){
	Criador *aux = criadores;

	if(aux){
		while(aux){
			printf("-----------------------------------------\n");
			printf("Id do criador: %d\nNome: %s\n", aux->id_criador, aux->nome);
			printf("Patrimonio: %.2f\n", aux->patrimonio);
			printf("----------------Fazendas-----------------\n");
			mostrarFazendas(aux->fazendas);
			aux = aux->prox;
		}
	} else{
		printf("Nenhum criador cadastrado.\n");
	}
	
	printf("\n");
}

Criador *removerCriador(Criador *criadores){
	Criador *aux = buscarCriador(criadores);
	Criador *aux2;

	if(aux){
		if(temFazenda(aux->fazendas) != 0){
			printf("Nao eh possivel excluir esse criador.\nPara exclui-lo, exclua primeiro suas fazendas.\n");
		} else{
			if(!aux){
				printf("Lista vazia\n");
				return NULL;
			} else{
				if(!aux->ant && !aux->prox){
					free(aux);
					criadores = NULL;
				} else if(!aux->prox){
					aux2 = aux->ant;
					aux2->prox = NULL;
					free(aux);
				} else if(!aux->ant){
					aux2 = aux;
					aux = aux->prox;
					aux->ant = NULL;
					free(aux2);
					criadores = aux;
				} else{
					aux2 = aux->ant;
					aux2->prox = aux->prox;
					aux2->prox->ant = aux2;
					free(aux);
				}
				printf("Criador Removido.\n");
			}
		}

	
	} else{
		printf("A lista esta vazia.\n");
	}

	return criadores;
	
}

void calcularPatrimonio(Criador *criador){
	float quantArroba, soma = 0.0;

	Fazenda *first = criador->fazendas;
	Fazenda *aux = first->prox;

	int i = 0, id_inicial;
	id_inicial = first->id_fazenda;
	printf("here\n");
	while(1){
		printf("i = %d\n", i++);
		arrobaTotal(aux);
		soma += aux->valor_fazenda;
		if(aux->id_fazenda == id_inicial) break;
		aux = aux->prox;
	}

	criador->patrimonio = soma;

}

void atualizarPatrimonios(Criador *criadores){
	Criador *aux = criadores;
	while(aux){
		calcularPatrimonio(aux);
		aux = aux->prox;
	}
}

void liberarMemoriaCriadores(Criador *criadores){
	Criador *aux = criadores;
	Criador *aux2;
	if(aux){
		aux2 = aux;
		liberarFazendas(aux->fazendas);
		free(aux2);
		liberarMemoriaCriadores(aux->prox);
	} else{
		printf("\nMemoria liberada.\n");
	}
}