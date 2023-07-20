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

Animal *criaListaEncadeadaSimplesAnimais() {
	printf("Animal Criar.");
	return NULL;
}

Animal *cadastrarAnimal(Animal *rebanho) {
	Animal *novo = (Animal*)malloc(sizeof(Animal));
	//printf("\nInforme o id da fazenda: ");
	//scanf("%d", &novo->id_fazenda);

	// Verifica se a fazenda já existe
	/*Animal *temp;
	for (temp = rebanho; temp != NULL; temp = temp->prox) {
		if (novo->id_fazenda == temp->id_fazenda) {
			printf("A fazenda ja existe.\n");
			free(novo);
			return rebanho; // Retorna a lista original sem adicionar o novo animal
		}
	}*/

	printf("Informe o id do animal: ");
	scanf("%d", &novo->id_animal);

	// Verifica se o id do animal já existe
	/*for (temp = rebanho; temp != NULL; temp = temp->prox) {
		if (novo->id_animal == temp->id_animal) {
			printf("O id do animal ja existe.\n");
			free(novo);
			return rebanho; // Retorna a lista original sem adicionar o novo animal
		}
	}*/
	

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

	if(!rebanho){
		novo->prox = NULL;
	} else{
		novo->prox = rebanho;
	}
	//rebanho = novo;

	return novo;
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

// void mostrarAnimalSexo(Animal *rebanho)
// {
// 	Animal *aux;
// 	int countF = 0, countM = 0;
// 	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
// 	{
// 		if (aux->sexo == 'F')
// 		{
// 			countF++;
// 		}
// 		if (aux->sexo == 'M')
// 		{
// 			countM++;
// 		}	
// 	}

// 	printf("Masculino: %d\nFeminino: %d\n", countM, countF);

// }

// void mostrarAnimalStatus(Animal *rebanho)
// {
// 	Animal *aux;
// 	int sts;
// 	printf("Informe o tipo de status do animal que queira listar: ");
// 	scanf("%d", &sts);
// 	if (sts == 1)
// 	{
// 		printf("\nStatus: Nascimento na propria fazenda.\n");
// 	}
// 	if (sts == 2)
// 	{
// 		printf("\nStatus: Vendido.\n");
// 	}
// 	if (sts == 3)
// 	{
// 		printf("\nStatus: Troca.\n");
// 	}
// 	for(aux = rebanho ; aux != NULL ; aux = aux->prox)
// 	{
// 		if(aux->status == sts)
// 		{
// 			printf("---------------------------------------\n");
// 			printf("Id da fazenda: %d\n", rebanho->id_fazenda);
// 			printf("Id do animal: %d\n", rebanho->id_animal);
// 			printf("Sexo: %c\n", rebanho->sexo);
// 			printf("Peso: %.2f\n", rebanho->peso);
// 		}
// 	}
// }


Animal *removerAnimal(Fazenda *fazenda, int id_animal)
{
	Animal *remover_animal = fazenda->rebanho;
	Animal *anterior = NULL;
	while (remover_animal != NULL && remover_animal->id_animal != id_animal)
	{
		anterior = remover_animal;
		remover_animal = remover_animal->prox;
	}
	if (remover_animal == NULL)
	{
		return fazenda->rebanho;
	}
	if (anterior == NULL)
	{
		fazenda->rebanho = remover_animal->prox;
	}else
	{
		anterior->prox = remover_animal->prox;
	}
	free(remover_animal);

	return fazenda->rebanho;	
}

Animal* permutasAnimais(Fazenda* origem, Fazenda* destino, int id_animal) {
    Animal* rebanho_origem = origem->rebanho;
    Animal* rebanho_destino = destino->rebanho;

    printf("Endereço de Origem:\n%s;\n%s;\n%s;\n", origem->localizacao.cidade, origem->localizacao.estado, origem->localizacao.logradouro);
    printf("Endereço de Destino:\n%s;\n%s;\n%s;\n", destino->localizacao.cidade, destino->localizacao.estado, destino->localizacao.logradouro);

    Animal* animal_origem = NULL;

    // Find the animal in the origin farm
    Animal* aux;
    for (aux = rebanho_origem; aux != NULL; aux = aux->prox) {
        if (aux->id_animal == id_animal) {
            animal_origem = aux;
            break;
        }
    }

    if (animal_origem == NULL) {
        printf("Animal não encontrado na fazenda de origem.\n");
        return rebanho_origem;
    }

    printf("---------------------------------------\n");
    printf("Id da fazenda: %d\n", animal_origem->id_fazenda);
    printf("Id do animal: %d\n", animal_origem->id_animal);
    printf("Sexo: %c\n", animal_origem->sexo);
    printf("Peso: %.2f\n", animal_origem->peso);
    printf("Status: %d\n\n", animal_origem->status);

    int op;

    printf("Informe o status:\n");
    printf("2 - Venda.\n");
    printf("3 - Troca.\n");
    scanf("%d", &op);

    while (op != 2 && op != 3) {
        printf("Opção inválida. Informe outra opção.\n");
        printf("Informe o status:\n");
        printf("2 - Venda.\n");
        printf("3 - Troca.\n");
        scanf("%d", &op);
    }

    if (op == 2) {
        printf("Opção de venda selecionada.\n");
        animal_origem->status = 2;
        destino->rebanho = animal_origem;
        rebanho_origem = removerAnimal(origem, id_animal);
        if (rebanho_origem == NULL) {
            printf("A venda não foi bem sucedida.\n");
        } else {
            printf("Animal vendido com sucesso.\n");
        }
    } else if (op == 3) {
        Animal* animal_destino = rebanho_destino;

        if (animal_destino == NULL) {
            printf("Animal não encontrado na fazenda de destino.\n");
            return rebanho_origem;
        }

        printf("Opção de troca selecionada.\n");
        animal_origem->status = 3;
        animal_destino->status = 3;

        // Swap animals between origin and destination farms
        if (animal_origem == rebanho_origem) {
            rebanho_origem = animal_destino;
        } else {
            for (aux = rebanho_origem; aux != NULL; aux = aux->prox) {
                if (aux->prox == animal_origem) {
                    aux->prox = animal_destino;
                    break;
                }
            }
        }

        animal_destino->prox = animal_origem->prox;
        animal_origem->prox = rebanho_destino;

        printf("Troca realizada com sucesso.\n");
    }

    return rebanho_origem;
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
	
	printf("Masculino: %d\nFeminino: %d\n", countM, countF);
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

int contArroba(Fazenda *fazenda){
	float soma=0;
	Animal *aux = fazenda->rebanho;
	while(aux){

		soma += aux->peso;

		aux = aux->prox;
	}
	return soma/15;
}