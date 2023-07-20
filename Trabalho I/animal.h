typedef struct animal Animal; 

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho);
Animal *buscarAnimal(Animal *rebanho);
//void mostrarAnimalSexo(Animal *rebanho);
//Animal *mostrarAnimalStatus(Animal *rebanho);
//void mostrarAnimalStatus(Animal *rebanho);
Animal *removerAnimal(Fazenda *fazenda, int id_animal);

Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAnimal(Fazenda *fazenda, int id_animal); 
/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/
void contAnimaisSexo(Fazenda *fazenda);
void MostrarStatus(Fazenda *fazenda, int sts);
void contArroba(Fazenda *fazenda);