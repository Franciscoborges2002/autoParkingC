#include <stdlib.h>
#include "linkedlist.h"

node_t *criarNode(dados_t *dadosCriarNode){
	node_t *aux = (node_t *)malloc(sizeof(node_t));//Alocar o espaï¿½o de uma node_t(struct) para uma variavel aux(pointer para o inicio desse espaï¿½o alocado)
	strcpy(aux->dados.matricula, dadosCriarNode->matricula);//Passar
	strcpy(aux->dados.modelo, dadosCriarNode->modelo);
	aux->dados.cordPiso = dadosCriarNode->cordPiso;
	aux->dados.cordLinha = dadosCriarNode->cordLinha;
	aux->dados.cordColuna = dadosCriarNode->cordColuna;
	aux->dados.horaEntrada = dadosCriarNode->horaEntrada;
	aux->next = NULL;//
	//printf("memoria alocada= %d; pointer= %d", sizeof(node_t), aux);
}

node_t *criarNodeComMatricula(char Matricula[7]){
	node_t *aux = (node_t *)malloc(sizeof(node_t));//Alocar o espaï¿½o de uma node_t(struct) para uma variavel aux(pointer para o inicio desse espaï¿½o alocado)
	strcpy(aux->dados.matricula, Matricula);
	aux->next = NULL;//
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

int removerElemento(node_t **lista, dados_t *carroRemover){//mudar só para a matricula
printf("\n\npointer da lista func remover elemento: %d", lista);
	node_t *aux = *lista;
	node_t *ant = *lista;
	int encontrado = 0;

	//Se a lista estiver vazia
	if(lista == NULL){
		printf("\nNenhum item a remover");
		return;
	}
	
	
	while(encontrado == 0 && aux !=NULL){
		if(strcmp(aux->dados.matricula, carroRemover->matricula) == 0){
			encontrado = 1;
		}else{
			ant = aux;
			aux=aux->next;
		}
	}

	if(encontrado == 1){
		if (ant == aux && aux == *lista){
			if(aux->next == 0){
				*lista = NULL;
			}else {
				*lista = aux->next;
			}
		}else {
			ant->next=aux->next;
		}
		free(ant);
		free(aux);
		aux = NULL;
		
		return 1;		
	}
	return 0;
}

int procurarMatricula(node_t **lista, char matriculaProcurar[]){
	node_t *aux = *lista;
	
	/* Para verificar se a matricula a procurar está correta
	printf("\n\nmatricula");
	puts(matriculaProcurar);
	printf("\n");*/
	
	while(aux != NULL){
		if(strcmp(aux->dados.matricula, matriculaProcurar) == 0){
			return 1;//Matricula encontrada
		}
		aux = aux->next;
	}
	return 0;//Matricula não encontrada ou erro
}

node_t *procurarMatriculaRetornarObjeto(node_t **lista, char matriculaProcurar[]){
	//ADICIONAR VERIFICAÇÕES À MATRICULA []
	node_t *aux = *lista;
	node_t carroRetornar;
	char semMatricula[5] = "NULL";
	
	
	while(aux != NULL){
		printf("\nMatricula: ");
		puts(aux->dados.matricula);
		if(strcmp(aux->dados.matricula, matriculaProcurar) == 0){
			return aux;
		}
		aux = aux->next;
	}
	printf("hereeeee");
	node_t *aux2 = criarNodeComMatricula("NULL");
	printf("here");
	return aux2;
}

int tamanhoLista(node_t *lista){
	node_t *aux = lista;
	int contador= 0;
	while(aux!=NULL){
		contador++;
	}
	return contador;
}

void listar(node_t *lista){
	printf("\nLista de carros: ");
	node_t *aux = lista;
	while(aux!=NULL){
		printf("\n[%d,%d,%d]Matricula: ", aux->dados.cordPiso +1,aux->dados.cordLinha +1, aux->dados.cordColuna +1);
		puts(aux->dados.matricula);
		aux = aux->next;
	}
}

int procurarNaCoord(node_t *lista, int piso, int linha, int coluna){
	node_t *aux = lista;
	while(aux!=NULL){
		if(aux->dados.cordPiso == (piso -1)  && aux->dados.cordLinha == (linha -1) && aux->dados.cordColuna == (coluna -1)){
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}

char * procurarNaCoordReturnMatricula(node_t *lista){
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
			return "a";
		}
		aux = aux->next;
	}
	return "NULL";
}
