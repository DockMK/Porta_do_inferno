#include <stdio.h>
#include <stdlib.h>
 
#include "fazenda.h"
#include "animal.h"
#include "criador.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

int i = 0;
int id = 0;

struct fazenda{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda; //lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas){
	Fazenda *novo = (Fazenda *) malloc(sizeof(Fazenda));
	Fazenda *aux = fazendas;

	novo->id_fazenda = ++id;
	printf("Id da fazenda: %d\n", novo->id_fazenda);
	fflush(stdin);
	printf("Insira o nome da fazenda: "); 
	scanf("%[^\n]", novo->nome);
	fflush(stdin);
	printf("Insira a cidade: "); 
	scanf("%[^\n]", novo->localizacao.cidade);
	fflush(stdin);
	char c1, c2;
	printf("Insira o estado (obs: coloque as sigla do estado): "); 
	scanf("%c%c", &c1, &c2);
	novo->localizacao.estado[0] = c1;
	novo->localizacao.estado[1] = c2;
	fflush(stdin);
	printf("Insira o logradouro: ");
	scanf("%[^\n]", novo->localizacao.logradouro);
	fflush(stdin);
	novo->rebanho = criaListaEncadeadaSimplesAnimais();

	if(fazendas == NULL){
		novo->prox = novo;
		return novo;
	}

	while(aux->prox != fazendas){
		aux = aux->prox;
	}

	aux->prox = novo;
	novo->prox = fazendas;

	return fazendas;
}

int buscarFazenda(Fazenda *fazendas){
	Fazenda *aux = fazendas;
	int id;
	printf("Informe o id da fazenda a buscar\n");
	scanf("%d", &id);

	if(fazendas == NULL){
		printf("\nSem fazendas registradas!\n");
		return 0;
	}

	if(aux->id_fazenda == id){
		return aux->id_fazenda;
	}

	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
		aux = aux->prox;
	}

	return aux->prox == fazendas ? 0 : aux->prox->id_fazenda;
}


Fazenda *getFazenda(Fazenda *fazendas, int id){

  	Fazenda *aux = fazendas;

  	if(fazendas == NULL){
  		printf("\nSem fazendas registradas!\n");
  		return fazendas;
  	}

  	if(aux->id_fazenda == id){
  		return aux;
  	}

  	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
  		aux = aux->prox;
  	}
	
  	return aux->prox == fazendas ? 0 : aux->prox;
}


Fazenda *removerFazenda(Fazenda *fazendas, int id){
  	Fazenda *aux = fazendas, *aux2;

  	if(fazendas == NULL){
  		printf("\nLista vazia\n");
  		return fazendas;
  	}

  	if(!getFazenda(fazendas, id)){
  		printf("\nFazenda nao cadastrada!\n");
  		return fazendas;
  	}

  	if(aux->id_fazenda == id){

  		if(aux->rebanho != NULL){
  			printf("\nNao eh possivel remover fazenda com rebanho!\n");
  			return fazendas;
  		}

  		if(aux->prox == aux){
  			return NULL;
  		}

  		while(aux->prox != fazendas){
  			aux = aux->prox;
  		}

  		aux->prox = fazendas->prox;
  		free(fazendas);

  		return aux->prox;
  	}

  	while(aux->prox != fazendas && aux->prox->id_fazenda != id){
  		aux = aux->prox;
  	}

  	if(aux->prox == fazendas){
  		printf("\nFazenda nao cadastrada!\n");
  		return fazendas;
  	}

  	if(aux->prox->rebanho != NULL){
  		printf("\nNao eh possivel remover fazenda com rebanho!\n");
  		return fazendas;
  	}
	

  	aux2 = aux->prox;
  	aux->prox = aux->prox->prox;
  	free(aux2);

  	return fazendas;

}

void liberarFazendas(Fazenda *fazendas){
	Fazenda *aux = fazendas, *aux2;
	aux2 = NULL;

	while(fazendas->prox != aux){
		aux2 = fazendas;
		liberarmemoriaAnimal(aux->rebanho);
		fazendas = fazendas->prox;
		free(aux2);
	}

	free(fazendas);
}

void arrobaTotal(Fazenda *fazendas){
	float arrobas=0.0;
	Fazenda *aux = fazendas;

	if(fazendas){
		//int id_inicial = fazendas->id_fazenda;
		//while(1){
		arrobas = contArroba(fazendas);
		printf("Total de arrobas: %.2f\n", arrobas);
		aux->valor_fazenda = arrobas * 235.00;
		//if(aux->id_fazenda == id_inicial) break;
		//aux = aux->prox;
		//}
	} else{
		printf("\nFazenda inexistente\n");
	}
}

void valorTotal(Fazenda *fazendas){
	int id;

	printf("\nInsira o ID da fazenda: "); 
	scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);

	if(fazenda){
		//arrobas = contArroba(fazenda);
		printf("Valor total da fazenda: %.2f\n", fazenda->valor_fazenda);
		//fazenda->valor_fazenda = arrobas * 235.95;
	}else{
		printf("\nFazenda inexistente\n");
	}
	
}

void mostrarFazendas(Fazenda *fazendas){
	Fazenda *first = fazendas;
	Fazenda *aux;

	if(!fazendas){
		printf("Nao possui fazendas cadastradas.\n");
	} else{
		aux = first->prox;

		int id_first = first->id_fazenda;
		while(1){
			printf("Id da fazenda: %d\n", aux->id_fazenda);
			//printf("Id do cria: %d\n", aux->id_criador);
			mostrarFazenda(aux);
			printf("------------------Animais-----------------\n");
			mostrarTodosAnimais(aux);
			//mostrarAnimalSexo(aux);
			printf("\n\n");
			if(aux->id_fazenda == id_first) break;
			aux = aux->prox;
		}
	}
	
}

void mostrarAnimalSexo(Fazenda *fazenda)
{

	// int id;
	// printf("\nInsira o ID da fazenda: "); 
	// scanf("%d", &id);
	//Fazenda *fazenda = getFazenda(fazendas, id);
	if (fazenda) {
        contAnimaisSexo(fazenda);
    } else {
        printf("\nFazenda inexistente\n");
    }

}

void listaStatusAnimais(Fazenda *fazendas, int id)
{

	int sts;
	// printf("\nInsira o ID da fazenda: \n"); 
	// scanf("%d", &id);
	Fazenda *fazenda = getFazenda(fazendas, id);
	printf("Informe o tipo de status do animal que queira listar: \n");
	printf("1 - Nascimento no propria fazenda\n2 - Vendido\n3 - Troca\n");
	scanf("%d", &sts);
	
	if(fazenda){
		MostrarStatus(fazenda, sts);
	}else{
		printf("\nFazenda inexistente\n");
	}
}
