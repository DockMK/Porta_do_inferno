typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrarCriador(Criador *criadores);
Criador *removerCriador(Criador *criadores);
Criador *buscarCriador(Criador *criadores);

void mostrarCriadores(Criador *criadores);
void mostrarAtributosCriadores(Criador *criadores);
void liberarMemoriaCriadores(Criador *criadores);
void calcularPatrimonio(Criador *criador);
void atualizarPatrimonios(Criador *criadores);
