typedef struct animal Animal; 

Animal *criaListaEncadeadaSimplesAnimais(); //
Animal *cadastrarAnimal(Animal *rebanho); // 
Animal *buscarAnimal(Animal *rebanho); //
void permutasAnimais(Fazenda *origem, Fazenda *destino);// 
Animal *removerAnimal(Fazenda *fazenda, int id_animal); // testar

int animalExiste(Animal* rebanho, int id_animal); //
void liberarmemoriaAnimal(Animal *rebanho); //
void contAnimaisSexo(Fazenda *fazenda); //
void MostrarStatus(Fazenda *fazenda, int sts);
void mostrarAnimal(Animal *rebanho); //
void mostrarTodosAnimais(Fazenda *fazenda); //
float contArroba(Fazenda *fazenda); //
