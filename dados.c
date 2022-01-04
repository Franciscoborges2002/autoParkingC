#include <stdlib.h>
#include "dados.h"

dados_t *criarVeiculo(char matricula[], char modelo[], int piso, int linha, int coluna){
	//int i;
	time_t horaEntrada = time(&horaEntrada);
	
	//printf("\nLength da matricula: %d\n", strlen(matricula));
	
	dados_t *elemento = (dados_t *)malloc(sizeof(dados_t));//Alocar a memoria para os dados
	
	//elemento->matricula = matricula;
	/*for(i = 0; i <= 6; i++){
		elemento->matricula[i] = matricula[i];
	}*/
	strcpy(elemento->matricula, matricula);
	
	/*for(i = 0; i <= 20; i++){
		elemento->modelo[i] = modelo[i];
	}*/
	strcpy(elemento->modelo, modelo);
	
	elemento->cordPiso = piso - 1;
	elemento->cordLinha = linha -1;
	elemento->cordColuna = coluna -1;
		
	//printf("hora entrada %d", horaEntrada);
	elemento->horaEntrada = horaEntrada;
	elemento->horaSaida = 0;
	
	return elemento;
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
