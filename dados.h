#include <time.h>

typedef struct{
	int cordPiso;// Cordenadas para o piso
	int cordLinha;// Cordenadas para o piso
	int cordColuna;
	//char codigo; ->Se não tiver hora de saida, está ocupado o espaço
	char matricula[100];
	char modelo[100];
	time_t horaEntrada;
	time_t horaSaida;//Se for NULL/estiver vazia o carro ainda estï¿½ estacionado
} dados_t;

dados_t *criarVeiculo(char matricula[], char modelo[], int piso, int linha, int coluna);
