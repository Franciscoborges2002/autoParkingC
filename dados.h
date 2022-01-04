#include <time.h>

typedef struct{
	int cordPiso;// Cordenadas para o piso
	int cordLinha;// Cordenadas para o piso
	int cordColuna;
	//char codigo; ->Se n�o tiver hora de saida, est� ocupado o espa�o
	char matricula[100];
	char modelo[100];
	time_t horaEntrada;
	time_t horaSaida;//Se for NULL/estiver vazia o carro ainda est� estacionado
} dados_t;

dados_t *criarVeiculo(char matricula[], char modelo[], int piso, int linha, int coluna);
