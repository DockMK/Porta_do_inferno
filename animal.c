#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "criador.h"
#include "fazenda.h"

struct animal {
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; // em KG
	int status; // 1 - Nascimento na própria fazenda | 2 - venda | 3 - troca
	struct animal *prox;
};

int id_animal = 0;

Animal *criaListaEncadeadaSimplesAnimais() {
	return NULL;
}

Animal *cadastrarAnimal(Animal *rebanho) {
	Animal *novo = (Animal*)malloc(sizeof(Animal));

	novo->id_animal = ++id_animal;
	printf("Id do animal: %d\n", novo->id_animal);

	printf("Informe o sexo do animal (M ou F): ");
	scanf(" %c", &novo->sexo);
	while(novo->sexo != 'M' && novo->sexo != 'F') {
		printf("Sexo invalido. Utilize 'M' ou 'F'.\n");
		scanf(" %c", &novo->sexo);

	}

	printf("Informe o peso do animal: ");
	scanf("%f", &novo->peso);

	printf("Informe o status do animal:\n");
	printf("1 - Nascimento na propria fazenda.\n");
	printf("2 - Venda.\n");
	printf("3 - Troca\n");
	scanf("%d", &novo->status);
	while (novo->status != 1 && novo->status != 2 && novo->status != 3) {
		printf("Status invalido. Utilize 1, 2 ou 3.\n");
		printf("Informe o status do animal:\n");
		printf("1 - Nascimento na propria fazenda.\n");
		printf("2 - Venda.\n");
		printf("3 - Troca\n");
		scanf("%d", &novo->status);
	}
	novo->prox = rebanho;
	rebanho = novo;

	return novo;
}

int animalExiste(Animal* rebanho, int id_animal) {
    Animal* aux = rebanho;
    while (aux != NULL) {
        if (aux->id_animal == id_animal) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

Animal *buscarAnimal(Animal *rebanho)
{
	Animal *aux;
	int id;
	printf("Informe o id do animal: ");
	scanf("%d", &id);
	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
	{
		if(aux->id_animal == id)
		{
			printf("---------------------------------------\n");
			printf("Id da fazenda: %d\n", rebanho->id_fazenda);
			printf("Id do animal: %d\n", rebanho->id_animal);
			printf("Sexo: %c", rebanho->sexo);
			printf("Peso: %.2f", rebanho->peso);
			if (rebanho->status == 1)
			{
				printf("Status: Nascimento na propria fazenda.\n");
			}
			if (rebanho->status == 2)
			{
				printf("Status: Vendido.\n");
			}
			if (rebanho->status == 3)
			{
				printf("Status: Troca.\n");
			}
			return aux;
		}
	}

	return NULL;
}

void contAnimaisSexo(Fazenda *fazenda){
	int countF = 0, countM = 0;
	Animal *aux = fazenda->rebanho; // Criação de um ponteiro auxiliar para percorrer a lista
	while (aux) {
		if (aux->sexo == 'F') {
			countF++;
		}
		if (aux->sexo == 'M') {
			countM++;
		}
		aux = aux->prox; // Avança para o próximo nó da lista
	}

	printf("Quantidade total de animais na fazenda: %d\nMacho: %d\nFemea: %d\n", countM+countF, countM, countF);
}

void MostrarStatus(Fazenda *fazenda, int sts){
	Animal *aux = fazenda->rebanho;
	while(aux){
		if(aux->status == sts)
		{
			printf("---------------------------------------\n");
			printf("Id da fazenda: %d\n", aux->id_fazenda);
			printf("Id do animal: %d\n", aux->id_animal);
			printf("Sexo: %c\n", aux->sexo);
			printf("Peso: %.2f\n", aux->peso);
		}

		aux = aux->prox;
	}
}

float contArroba(Fazenda *fazenda){
	float soma=0.0;
	Animal *aux = fazenda->rebanho;
	while(aux){

		soma += aux->peso;

		aux = aux->prox;
	}
	return soma/15;
}

void mostrarAnimal(Animal *rebanho) {
	if(rebanho){
		printf("---------------------------------------\n");
		printf("Id da fazenda: %d\n", rebanho->id_fazenda);
		printf("Id do animal: %d\n", rebanho->id_animal);
		printf("Sexo: %c\n", rebanho->sexo);
		printf("Peso: %.2f\n", rebanho->peso);

		if (rebanho->status == 1) {
			printf("Status: Nascimento na propria fazenda.\n");
		} else if (rebanho->status == 2) {
			printf("Status: Vendido.\n");
		} else if (rebanho->status == 3) {
			printf("Status: Troca.\n");
		}
	} else{
		printf("Nenhum animal cadastrado.\n");
	}

}

void mostrarTodosAnimais(Fazenda *fazenda) {
    Animal *aux;
	if(fazenda){
		for (aux = fazenda->rebanho; aux != NULL; aux = aux->prox) {
			mostrarAnimal(aux);
		}
	} else{
		printf("Nenhum animal na fazenda.\n");
	}

}

void trocarAnimal(Animal* animal1, Animal* animal2) {
    Animal tmp = *animal1;

	int id1_animal, id2_animal, id1_fazenda, id2_fazenda;
	tmp.id_fazenda = animal1->id_fazenda;
	id1_fazenda = animal1->id_fazenda;
	id2_fazenda = animal2->id_fazenda;
	id1_animal = animal1->id_animal;
	id2_animal = animal2->id_animal;
    *animal1 = *animal2;
    *animal2 = tmp;
	animal1->id_fazenda = id1_fazenda;
	animal2->id_fazenda = id2_fazenda;
	animal1->id_animal = id1_animal; 
	animal2->id_animal = id2_animal;
}

void permutasAnimais(Fazenda* origem, Fazenda* destino) {
    Animal* rebanho_origem = origem->rebanho;

    printf("\nEndereco de Origem:\nCidade: %s;\nEstado: %c%c;\nLogradouro: %s;\n", origem->localizacao.cidade, origem->localizacao.estado[0], origem->localizacao.estado[1], origem->localizacao.logradouro);
    printf("\nEndereco de Destino:\nCidade: %s;\nEstado: %c%c;\nLogradouro: %s;\n", destino->localizacao.cidade, destino->localizacao.estado[0], destino->localizacao.estado[1], destino->localizacao.logradouro);

    Animal* animal_origem = NULL;
    Animal* animal_destino = NULL;

    int op;

    printf("Informe o status:\n");
    printf("2 - Venda.\n");
    printf("3 - Troca.\n");
    scanf("%d", &op);

    while (op != 2 && op != 3) {
        printf("Opcao invalida. Informe outra opcao.\n");
        printf("Informe o status:\n");
        printf("2 - Venda.\n");
        printf("3 - Troca.\n");
        scanf("%d", &op);
    }

    if (op == 2) {
        printf("Opcao de venda selecionada.\n");
        Animal* aux;
        int id_animal;
        printf("Informe o id do animal a ser vendido da fazenda origem: ");
        scanf("%d", &id_animal);
        for (aux = rebanho_origem; aux != NULL; aux = aux->prox) {
            if (aux->id_animal == id_animal) {
                animal_origem = aux;
                printf("---------------------------------------\n");
                printf("Id da fazenda de origem: %d\n", animal_origem->id_fazenda);
                printf("Id do animal: %d\n", animal_origem->id_animal);
                printf("Sexo: %c\n", animal_origem->sexo);
                printf("Peso: %.2f\n", animal_origem->peso);
                printf("Status antes da venda: %d\n\n", animal_origem->status);
                break;
            }
        }
        if (animal_origem == NULL) {
            printf("Animal nao encontrado na fazenda de origem.\n");
            return;
        }
        animal_origem->status = 2;
        if (destino->rebanho == NULL) {
            destino->rebanho = animal_origem;
			destino->rebanho->id_animal = id_animal;
			destino->rebanho->id_fazenda = destino->rebanho->id_fazenda;
            destino->rebanho->prox = NULL;
        } else {
            Animal* aux = destino->rebanho;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = animal_origem;
            animal_origem->prox = NULL;
        }


        if (rebanho_origem == NULL) {
            printf("A venda nao foi bem sucedida.\n");
        } else {
            origem->rebanho = removerAnimal(origem, id_animal);
            printf("Animal vendido com sucesso.\n");
		}
            
    } else if (op == 3) {
		Animal* aux;
		int id_animal, id_animal2;
		printf("Informe o id do animal a ser trocado da fazenda original: ");
		scanf("%d", &id_animal);
		printf("Informe o id do animal a ser trocado da fazenda destino: ");
		scanf("%d", &id_animal2);
    	for (aux = rebanho_origem; aux != NULL; aux = aux->prox) {
			if (aux->id_animal == id_animal) {
				animal_origem = aux;
				printf("---------------------------------------\n");
				printf("Id da fazenda: %d\n", animal_origem->id_fazenda);
				printf("Id do animal: %d\n", animal_origem->id_animal);
				printf("Sexo: %c\n", animal_origem->sexo);
				printf("Peso: %.2f\n", animal_origem->peso);
				printf("Status: %d\n\n", animal_origem->status);
				break;
			}
    	}
		for (aux = destino->rebanho; aux != NULL; aux = aux->prox) {
			if (aux->id_animal == id_animal2) {
				animal_destino = aux;
				printf("---------------------------------------\n");
				printf("Id da fazenda: %d\n", animal_destino->id_fazenda);
				printf("Id do animal: %d\n", animal_destino->id_animal);
				printf("Sexo: %c\n", animal_destino->sexo);
				printf("Peso: %.2f\n", animal_destino->peso);
				printf("Status: %d\n\n", animal_destino->status);
				break;
			}
		}

		if (animal_origem == NULL || animal_destino == NULL) {
			printf("Animal nao encontrado em ambas as fazendas.\n");
			return;
		}

        trocarAnimal(animal_origem, animal_destino);
		origem->rebanho->status = 3;
		destino->rebanho->status = 3;
        printf("Troca realizada com sucesso.\n");
    }

}

Animal *removerAnimal(Fazenda *fazenda, int id_animal){
	Animal *remover_animal = NULL;
	Animal *aux;

	while(fazenda->rebanho!= NULL){
		if (fazenda->rebanho->id_animal == id_animal)
		{
			remover_animal = fazenda->rebanho;
			fazenda->rebanho = remover_animal->prox;
		}
		else{
			aux = fazenda->rebanho;
			while (aux->prox && aux->prox->id_animal != id_animal)
			{
				aux = aux->prox;
			}
			if(aux->prox){
				remover_animal = aux->prox;
				aux->prox = remover_animal->prox;
			}
			
		}
		
	}
	return fazenda->rebanho;
}

void liberarmemoriaAnimal(Animal *rebanho){
	Animal *aux = rebanho;
	Animal *aux2;

	while(aux){
		aux2 = aux;
		free(aux2);
		aux = aux->prox;
	}

	free(aux);
}