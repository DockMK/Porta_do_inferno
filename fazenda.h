typedef struct fazenda Fazenda;
typedef struct endereco Endereco;

//Criador *criarListaEncadeadaCircularFazendas();
Fazenda *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrarFazenda(Fazenda *fazendas);
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
//Fazenda *removerFazenda(Fazenda *fazendas);//nao permitir remover fazenda se houver animais cadastrados
Fazenda *removerFazenda(Fazenda *fazendas, int id);
int buscarFazenda(Fazenda *fazendas);
Fazenda *getFazenda(Fazenda *fazendas, int id);
int temFazenda(Fazenda *fazenda);

/*
Desenvolva funcoes que, dado uma FAZENDA, informar:
- Quantidade de animais por sexo;
- Peso total em arroba (isto é, a cada 15 KG)
- Valor total da fazenda considerando o preço da arroba de R$ 235
- lista de animais por tipo de status
- Funcao para liberar a memoria
*/

//int quantAnimaisSexo(Fazenda *fazenda, char sexo);
void mostrarAnimalSexo(Fazenda *fazendas);
void mostrarFazendas(Fazenda *fazenda);
void arrobaTotal(Fazenda *fazendas);
void valorTotal(Fazenda *fazenda);
void listaStatusAnimais(Fazenda *fazendas, int id);
void liberarFazendas(Fazenda *fazendas);
void mostrarFazenda(Fazenda *fazenda);