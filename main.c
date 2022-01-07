#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>//Poder usar ao access nos ficheiros
//Custom includes
#include "dados.c"
#include "linkedlist.c"
#include "estruturaParque.c"

const char* ESTRUTURA_PARQUE_PARA_FICHEIRO_SAIR = "%d, %d, %d, %f\n";
const char* ESTRUTURA_PARQUE_PARA_FICHEIRO_ENTRAR = "%d, %d, %d, %f";

#define START 0//Mudar para a verificação dos ficheiros

//Valor a pagar estáa dar negativo

estruturaParque * inicPrograma();
void encerPrograma();

int main(){
	node_t *lista = NULL;
	estruturaParque *eP = (estruturaParque *)inicPrograma();
		
		
	int opcao = 4;
	dados_t *carro1 = criarVeiculo("aa2233", "asdkoawd", 1 , 1 , 1);
	dados_t *carro2 = criarVeiculo("aa2234", "asdkoa", 1 , 1 , 2);
		
		
	//imprimirParque(lista, eP);
		
	inserirInicio(&lista, carro1);
	inserirInicio(&lista, carro2);
		
	//inserirCarro(lista, eP);
		
		//listar(lista);
		
		//imprimirParque(lista, eP);
		
	while(opcao != 8){
		printf("MENU - PARQUE ESTACIONAMENTO \n [1]- Ver o estado do parque \n [2] Inserir viatura \n [3] Ver qual carro esta num certo lugar \n [4] Retirar carro. \n [5] Lista todos os carros \n [6] Mstrar tempo de estacionamentode um carro \n [7] Mudar preco por hora \n [8] Sair \nInserir opcao: " );
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				{
				system("cls");
				imprimirParque(1,1,1,lista, eP);
												
				break;
			}
			case 2:
				{
				system("cls");
				if(lugarMaisProximo(1,1,1,lista, eP)[0] == -1){
					printf("\nO parque está cheio\n");
				}else {
					dados_t *carro = criarCarro(eP, lista);
					if(carro->cordPiso == -1){
						break;
					}else{
						inserirInicio(&lista, carro);
					}
				}
					
				//printf("\n\n %d \n\n", tamanhoLista(lista));
				//listar(lista);
				break;
			}
			case 3:
				{
				system("cls");
				procurarNaCoordMostrarMatricula(lista);
				break;
			}
			case 4:
				{
					system("cls");
					dados_t *carroRemover = removerCarroMatricula(lista);
					
					listarCarro(carroRemover);
					valorAPagarComPreco(eP, carroRemover);
					
					if(strcmp(carroRemover->matricula, "NULL") == 0){
						printf("Matricula nao foi encontrada no parque");
					}else{
						printf("\npointer da lista : %d", lista);
						removerElemento(&lista, carroRemover);
					}
						
						
					//removerElemento(&lista, "aa2233");
					break;
				}
			case 5:
				{
					system("cls");
					listar(lista);
					break;
			}
			case 6:
				{
					system("cls");
					tempoEstacionado(lista);
					break;	
			}
			case 7:
				{
				system("cls");
				mudarPrecoHora(eP);
				break;	
			}
			case 8:
				{
				encerPrograma();
				break;	
			}
		}	
	}	
	
	return 0;
}

//Está a crashar quando passamos 
estruturaParque* inicPrograma(){//Adicionar a inicialização dos ficheiros
	char errorString[512];
	estruturaParque *eP;
	FILE *estruturaParqueFicheiro;
	//Verificar se o ficheiro existe
	if( access("estruturaParque.csv", F_OK) == 0){//Ficheiro existe
	
		int piso, linha, coluna;
		float preco;
		estruturaParqueFicheiro = fopen("estruturaParque.csv", "r");
		fscanf(estruturaParqueFicheiro, ESTRUTURA_PARQUE_PARA_FICHEIRO_ENTRAR, &piso, &linha, &coluna, &preco);
		eP = criarParqueApartirDeFicheiro(piso, linha, coluna, preco);
		fclose(estruturaParqueFicheiro);
		return eP;//retornar a estrutura do parque
		
		eP = (estruturaParque *)initParq();
		return eP;//retornar a estrutura do parque
	}else{//Ficheiro não existe
		eP = (estruturaParque *)initParq();
		estruturaParqueFicheiro = fopen("estruturaParque.csv", "ab+");//Vai criar o ficheiro
		printf("\nPointer para a estrutura do parque: %d\n", estruturaParqueFicheiro);
		
		if (estruturaParqueFicheiro != NULL) {
		    fprintf(estruturaParqueFicheiro, ESTRUTURA_PARQUE_PARA_FICHEIRO_SAIR, eP->piso, eP->linha, eP->coluna, eP->preco);
		    
			if(fwrite != 0){
				printf("contents to file written successfully !\n");
			}
			else{
				printf("error writing file !\n");
			}
		}
		
		if(estruturaParqueFicheiro == NULL){
			printf("Failed to open file.\n");
   			perror(errorString);
   			printf("%s\n", errorString);
		}
		fclose(estruturaParqueFicheiro);
		return eP;//retornar a estrutura do parque
	}
	/*
	if(estruturaParqueFicheiro == 0 || estruturaParqueFicheiro == NULL){//não existe ficheiro
		fclose(estruturaParqueFicheiro);
		
		
	}else {//existe ficheiro
		
	}*/
}

//Quando metemos não continua a sair
void encerPrograma(){//Guardar os ficheiros
	char opcao;//dar uma opcao
	
	do{
		printf("\nTem a certeza que pretende encerrar o programa (S=sim/N=nao) ?");
        scanf("%c", &opcao);
        
        opcao = tolower(opcao);//mudar a opcao para lowercase
        if(opcao == 115 || opcao == 110){//Se for uma das duas sair do while
        	break;
		}
	}while(opcao != 115 || opcao != 110);//Tabel ascii 115 = s, 110 = n
	
	if(opcao == 115){
		system("exit");
	}else {
		return;
	}
}
