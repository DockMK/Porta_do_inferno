typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrarCriador(Criador *criadores);
Criador *removerCriador(Criador *criadores); // nao é permitido remover criador com fazendas cadastradas
Criador *buscarCriador(Criador *criadores);


/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/
