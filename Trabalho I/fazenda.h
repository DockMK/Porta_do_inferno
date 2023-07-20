typedef struct fazenda Fazenda;
typedef struct endereco Endereco;


Fazenda *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrarFazenda(Fazenda *fazendas);
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
int buscarFazenda(Fazenda *fazendas);
Fazenda *getFazenda(Fazenda *fazendas, int id);

/*
Desenvolva funcoes que, dado uma FAZENDA, informar:
- Quantidade de animais por sexo;//
- Peso total em arroba (isto é, a cada 15 KG)
- Valor total da fazenda considerando o preço da arroba de R$ 235
- lista de animais por tipo de status//
- Funcao para liberar a memoria
*/

void mostrarAnimalSexo(Fazenda *rebanho);
void mostrarAnimalStatus(Fazenda *rebanho);
void arrobaTotal(Fazenda *fazendas);
void valorTotal(Fazenda *fazendas);

void liberarFazendas(Fazenda *fazendas);