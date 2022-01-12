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

#define START 0//Mudar para a verificação dos ficheiros

//Valor a pagar estáa dar negativo

estruturaParque *inicPrograma();
void encerPrograma();

int main(){
	node_t *lista = NULL;
	estruturaParque *eP = serializacaoFicheiroInicioEstruturaParque();
	int opcao = -1;
		
	while(1){
		printf("MENU - PARQUE ESTACIONAMENTO \n [1]- Ver o estado do parque \n [2] Inserir viatura \n [3] Ver qual carro esta num certo lugar \n [4] Retirar carro. \n [5] Lista todos os carros \n [6] Mostrar tempo de estacionamentode um carro \n [7] Mudar preco por hora \n [8] Sair \nInserir opcao: " );
		scanf("%d", &opcao);
		printf("opcao %d", opcao);
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
				if(lugarMaisProximo(lista, eP)[0] == -1){//Verificar se o parque está cheio
					printf("\nO parque está cheio\n");
					break;
				}else {//Se tiver espaço adicionar
					dados_t *carro = criarCarro(eP, lista);
					inserirInicio(&lista,carro);
				}
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
					removerElemento(&lista, removerCarroMatricula(lista, eP));		
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
				system("cls");
				encerPrograma();
				break;	
			}
			default:
				{
				system("cls");
				fflush(stdin);//Apaga o  buffer do teclado ->a string dos caracteres digitados no teclado passa a ""		
				printf("Opcao invalida\n");	
			}
		}	
	}	
	
	return 0;
}

//Função para iniciar o programa
estruturaParque *inicPrograma(){//Adicionar a inicialização dos ficheiros
//Ficheiro da estrutura do parque
	estruturaParque *eP = serializacaoFicheiroInicioEstruturaParque();
}

//Função para sair
void encerPrograma(){//Guardar os ficheiros
	char opcao;//dar uma opcao
	fflush(stdin);//Apaga o  buffer do teclado ->a string dos caracteres digitados no teclado passa a ""
	
	do{
		
		printf("\nTem a certeza que pretende encerrar o programa (S=sim/N=nao) ?");
        scanf("%c", &opcao);
        
        opcao = tolower(opcao);//mudar a opcao para lowercase
        if(opcao == 115 || opcao == 110){//Se for uma das duas sair do while
        	break;
		}
	}while(opcao != 115 || opcao != 110);//Tabel ascii 115 = s, 110 = n
	
	
	if(opcao == 115){
		exit(0);
	}
	system("cls");
	return;
}
