
typedef struct estruturaParque{
	int piso;
	int coluna;
	int linha;
	float preco;
} estruturaParque;

estruturaParque * initParq();

estruturaParque * criarParqueApartirDeFicheiro(int piso, int linha, int coluna, float preco);

void imprimirParque(int piso, int linha, int coluna, node_t *lista, estruturaParque *eP);

int *lugarMaisProximo(node_t *lista, estruturaParque *eP);

dados_t *criarCarro(estruturaParque *eP, node_t *lista);

double valorAPagarComPreco(estruturaParque *eP, dados_t *carro);

dados_t *removerCarroMatricula(node_t *lista, estruturaParque *eP);

estruturaParque *serializacaoFicheiroInicioEstruturaParque();

void mudarPrecoHora(estruturaParque *eP);
