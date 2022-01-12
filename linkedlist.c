#include <stdlib.h>
#include "linkedlist.h"

node_t *criarNode(dados_t *dadosCriarNode){
	node_t *aux = (node_t *)malloc(sizeof(node_t));//Alocar o espaço½o de uma node_t(struct) para uma variavel aux(pointer para o inicio desse espaï¿½o alocado)
	strcpy(aux->dados.matricula, dadosCriarNode->matricula);
	strcpy(aux->dados.modelo, dadosCriarNode->modelo);
	aux->dados.cordPiso = dadosCriarNode->cordPiso;
	aux->dados.cordLinha = dadosCriarNode->cordLinha;
	aux->dados.cordColuna = dadosCriarNode->cordColuna;
	aux->dados.horaEntrada = dadosCriarNode->horaEntrada;
	aux->next = NULL;//
	//printf("memoria alocada= %d; pointer= %d", sizeof(node_t), aux);
}

node_t *criarNodeComMatricula(char matricula[]){
	node_t *aux = (node_t *)malloc(sizeof(node_t));//Alocar o espaço½o de uma node_t(struct) para uma variavel aux(pointer para o inicio desse espaï¿½o alocado)
	strcpy(aux->dados.matricula, matricula);
	return aux;
}

void inserirInicio(node_t **lista, dados_t *dadosCriarNode){
	node_t *elemento = criarNode(dadosCriarNode);//Criar o node com os dados
	if(*lista == NULL){//Se a lista estiver vazia
		*lista = elemento;//O inicio da lista vai ser o elemento vai ser que criamos
	}else{
		elemento->next = *lista;//O next do elementno vai receber o inicio da lista anterior
		*lista = elemento;//O inicio da lista vai ser o elemento que acabamos de adicionar
	}
}

//Função para remover um elemento da lista ligada
int removerElemento(node_t **lista, dados_t *carroRemover){//mudar só para a matricula
	node_t *aux = *lista;
	node_t *ant = *lista;
	
	if(carroRemover == NULL){//Se não houverem elementos na lista
		printf("\ncarro não encontrado");
		return;
	}
	
	while(aux !=NULL){//Fazer o loop enquanto o carro não for encontrado ou o aux não for nulo
		if(strcmp(aux->dados.matricula, carroRemover->matricula) == 0){//Verificar se as matriculas são iguais
			if (ant == aux && aux == *lista){//Se ficar no primeiro caso
				*lista = aux->next;
			}else {//Se não ficar no primeiro caso
				ant->next=aux->next;
			}
			return 1;
		}else{//Se não forem
			ant = aux;//O ant vai para o aux a verificar
			aux=aux->next;//O aux vai para o próximo
		}
	}
		free(aux);//Libertar a mamória do aux 
		
		return 0;		
}

//Função para procurar uma matricula na lista ligada
int procurarMatricula(node_t **lista, char matriculaProcurar[]){
	node_t *aux = *lista;
	
	while(aux != NULL){//Passar a lista inteira
		if(strcmp(aux->dados.matricula, matriculaProcurar) == 0){//Se alguma matricula for encontrada
			return 1;//Matricula encontrada
		}
		aux = aux->next;
	}
	return 0;//Matricula não encontrada ou erro
}

//Função para procura ruma matricula e retornar o objeto na totalidade
node_t *procurarMatriculaRetornarObjeto(node_t **lista, char matriculaProcurar[]){
	node_t *aux = *lista;
	node_t *carroRetornar;
	
	
	while(aux != NULL){
		if(strcmp(aux->dados.matricula, matriculaProcurar) == 0){//Se encontrar a matricula
			return aux;
		}
		aux = aux->next;
	}
	carroRetornar = criarNodeComMatricula("NULL");
	return carroRetornar;
}

//Retornar tamanho da lista
int tamanhoLista(node_t *lista){
	node_t *aux = lista;
	int contador= 0;
	while(aux!=NULL){//Percorrer a lista toda
		contador++;//Adicionar ao ocntador
		aux = aux->next;//Passar para o próximo node
	}
	return contador;
}

//Função para listar os carros da lista
void listar(node_t *lista){
	printf("Lista de carros: ");
	node_t *aux = lista;
	while(aux!=NULL){//Percorrer a lista toda
		printf("\n[%d,%d,%d]Matricula: ", aux->dados.cordPiso +1,aux->dados.cordLinha +1, aux->dados.cordColuna +1);
		puts(aux->dados.matricula);
		aux = aux->next;
	}
}

//Função para procurar um carro numa certa coordenada
int procurarNaCoord(node_t *lista, int piso, int linha, int coluna){
	node_t *aux = lista;
	while(aux!=NULL){//Percorrer a lista toda
		if(aux->dados.cordPiso == (piso -1)  && aux->dados.cordLinha == (linha -1) && aux->dados.cordColuna == (coluna -1)){//Verificar as coordenadas e retornar
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}

//Semelhante a função anterior. mas retornar a matricula
void procurarNaCoordMostrarMatricula(node_t *lista){
	node_t *aux = lista;
	
	int pisoEsta, linhaEsta, colunaEsta;
	
	//Fazer verificação
	printf("Piso para verificar estacionamento: ");
    scanf("%d", &pisoEsta);
    printf("Linha para verificar estacionamento: ");
    scanf("%d", &linhaEsta);
    printf("Coluna para verificar estacionamento: ");
    scanf("%d", &colunaEsta);
    
    pisoEsta = pisoEsta -1;//para passar do inicio de index 1 para 0
	linhaEsta = linhaEsta -1;//para passar do inicio de index 1 para 0
	colunaEsta = colunaEsta -1;//para passar do inicio de index 1 para 0
	
	while(aux!=NULL){
		if(aux->dados.cordPiso == pisoEsta && aux->dados.cordLinha == linhaEsta &&aux->dados.cordColuna == colunaEsta){
			printf("\nMatricula do carro nas cordenadas: ");
			puts(aux->dados.matricula);
			free(aux);
			return;
		}
		aux = aux->next;
	}
	
	printf("\nNao existe nenhum veiculo nas coordenadas.\n");
	free(aux);
	return;
}

//Tempo estacinado pelos carros da lista ligada
void tempoEstacionado(node_t *lista){
	int i;
	node_t *aux =lista;
	struct tm *info;
	time_t horaEntrada = aux->dados.horaEntrada;
	time_t horaSaida = time(&horaSaida);
	int tamanhoDaLista = tamanhoLista(lista);
	double tempoPassado;
	
	while(aux !=NULL){
		horaEntrada = aux->dados.horaEntrada;
		tempoPassado = difftime(horaSaida, horaEntrada) /60/60;
		printf("Tempo estacionado da carro %s foi de %f horas.\n", aux->dados.matricula, tempoPassado);
		aux = aux->next;
	}
	free(aux);
	return;
}
