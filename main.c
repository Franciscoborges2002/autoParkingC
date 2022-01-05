#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
//Custom includes
#include "dados.c"
#include "linkedlist.c"
#include "estruturaParque.c"

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
		
	while(opcao != 6){
		printf("MENU - PARQUE ESTACIONAMENTO \n [1]- Ver o estado do parque \n [2] Inserir viatura \n [3] Ver qual carro esta num certo lugar \n [4] Retirar carro. \n [5] Limpar Consola \n [6] Sair \n Inserir opcao: " );
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				{
				listar(lista);
				imprimirParque(1,1,1,lista, eP);
												
				break;
			}
			case 2:
				{
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
				procurarNaCoordReturnMatricula(lista);
				break;
			}
			case 4:
				{
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
					break;
			}
			case 6:
				{
				encerPrograma();
				break;	
			}
		}	
	}	
	
	return 0;
}

estruturaParque* inicPrograma(){//Adicionar a inicialização dos ficheiros
	FILE *estruturaParqueFicheiro = fopen("estruturaParque.csv", "r+");//Se não existir o ficheiro retorna NULL ou 0
	
	printf("\nPointer para a estrutura do parque: %d\n", estruturaParqueFicheiro);
	
	if(estruturaParqueFicheiro == 0 || estruturaParqueFicheiro == NULL){//não existe ficheiro
		estruturaParque * eP = (estruturaParque *)initParq();
		estruturaParqueFicheiro = fopen("estruturaParque.csv", "w+");//Vai abrir o ficheiro em binary, e criar o ficheiro se não existir
		if (estruturaParqueFicheiro != NULL) {
		    fprintf(&eP, sizeof(struct estruturaParque), 1, estruturaParqueFicheiro);
		    
		    if(fwrite != 0)
        		printf("contents to file written successfully !\n");
		    else
		        printf("error writing file !\n");
				    fclose(estruturaParqueFicheiro);
			}
		return eP;//retornar a estrutura do parque
		
	}else {//existe ficheiro
		estruturaParque * eP = (estruturaParque *)initParq();
		return eP;//retornar a estrutura do parque
	}
}

void encerPrograma(){//Guardar os ficheiros
	char opcao = 'a';//dar uma opcao 
	
	do{
		printf("\nTem a certeza que pretende encerrar o programa (S=sim/N=nao) ?");
        scanf("%c",&opcao);
        
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