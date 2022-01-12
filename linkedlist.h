#include <time.h>

typedef struct node{
	dados_t dados;
	struct node* next;
} node_t;

node_t *criarNode(dados_t *dadosCriarNode);

node_t *criarNodeComMatricula(char matricula[]);

void inserirInicio(node_t **lista, dados_t *dadosCriarNode);

int removerElemento(node_t **lista, dados_t *carroRemover);

int procurarMatricula(node_t **lista, char matriculaProcurar[]);

node_t *procurarMatriculaRetornarObjeto(node_t **lista, char matriculaProcurar[]);

int tamanhoLista(node_t *lista);

void listar(node_t *lista);

int procurarNaCoord(node_t *lista, int piso, int linha, int coluna);

void procurarNaCoordMostrarMatricula(node_t *lista);

void tempoEstacionado(node_t *lista);
