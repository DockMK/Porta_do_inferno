#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "criador.h"
#include "fazenda.h"
#include "fazenda.c"
#include "animal.h"
#include "animal.c"
// #include "fazenda.c"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;// Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; // esse valor deve ser constantemente modificado para que o valor esteja atualizado
	struct criador *prox, *ant; // lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *c;

	c = (Criador*)malloc(sizeof(Criador));
	printf("Id do criador: ");
	scanf("%d", &c->id_criador);
	fflush(stdin);
	printf("Nome do criador: ");
	scanf("%s[^\n]", c->nome);
	fflush(stdin);
	c->ant = NULL;
	c->prox = criadores;
	if(!criadores){
		c->prox = NULL;
	} else{
		c->prox = criadores;
		criadores->ant = c;
	}

	return c;
}

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

	printf("\nCriador\n");
	
	while(aux){
		printf("%5d\t%5s\t", aux->id_criador, aux->nome);
		aux = aux->prox;
	}
	printf("\n");
}

// void mostrarTudo(Criador *criador){
// 	Criador *aux = criador;
// 	mostrarCriadores(aux);
// 	mostrarAnimalStatus(aux->fazendas->rebanho);
// }

// https://wiki.python.org.br/ExerciciosClasses
Criador *removerCriador(Criador *criadores){
	Criador *aux = buscarCriador(criadores);
	Criador *aux2;

	if(temFazenda(aux->fazendas) != 0){
		printf("Nao eh possivel excluir esse criador.\n");
		//return NULL;
	} else{
		//printf("\nelse\n");
		/*if(aux){
			return criadores;
		}
	
		if(criadores == aux){
			criadores = aux->prox;
		} else{
			aux->ant->prox = aux->prox;
		}

		if(!aux->prox){
			aux->prox->ant = aux->ant;
		}*/

		if(!aux->prox){
			aux2 = aux->ant;
			
		}

		free(aux);

		return criadores;
	}

}
