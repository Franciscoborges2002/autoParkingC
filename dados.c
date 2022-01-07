#include <stdlib.h>
#include "dados.h"


//Função para criar o veiculo com a struct para inserir na estrutura de dados
dados_t *criarVeiculo(char matricula[], char modelo[], int piso, int linha, int coluna){
	time_t horaEntrada = time(&horaEntrada);//A var recebe a hora atual do sistema como hora de entrada do carro
	
	dados_t *elemento = (dados_t *)malloc(sizeof(dados_t));//Alocar a memoria para os dados
	strcpy(elemento->matricula, matricula);//passar a matricula para a struct
	strcpy(elemento->modelo, modelo);//passar o modelo para a struct
	
	elemento->cordPiso = piso - 1;//passar o piso para a struct
	elemento->cordLinha = linha -1;//passar a linha para a struct
	elemento->cordColuna = coluna -1;//passar a coluna para a struct
	elemento->horaEntrada = horaEntrada;//passar a hora de entrada para a struct
	elemento->horaSaida = 0;//passar a hora de saida para a struct
	
	return elemento;//retornar o elemento
}


void listarCarro(dados_t *carro){
	//conversão feita de segundos para dia
	struct tm *info;
	
	printf("Matricula: ");
	puts(carro->matricula);
	printf("Modelo: ");
	puts(carro->modelo);
	printf("Hora entrada: ");
	info = localtime(&carro->horaEntrada);
	printf("%s",asctime (info));
	printf("Hora saida: ");
	info = localtime(&carro->horaSaida);
	printf("%s",asctime (info));
}
