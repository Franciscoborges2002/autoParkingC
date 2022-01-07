#include "estruturaParque.h"

/*
*	Este parte tem a função de manter a estrutura do parque.
*/

estruturaParque * initParq(){
	int linha,coluna, piso;
	int i,j,k;
	float preco;
    
    printf("Total de pisos? ");
    scanf("%d", &piso);
    printf("Total de linhas? ");
    scanf("%d", &linha);
    printf("Total de colunas? ");
    scanf("%d", &coluna);
    printf("Qual o preco por hora? ");
    scanf("%f", &preco);
    
    estruturaParque *eP = (estruturaParque *)malloc(sizeof(estruturaParque));//Alocar a memoria para os dados

    //Guardar na struct
	eP->piso = piso;
    eP->linha = linha;
    eP->coluna = coluna;
    eP->preco = preco;
    
    system("cls");
    
    return eP;
}

estruturaParque * criarParqueApartirDeFicheiro(int piso, int linha, int coluna, float preco){
	estruturaParque *eP = (estruturaParque *)malloc(sizeof(estruturaParque));//Alocar a memoria para os dados

    //Guardar na struct
	eP->piso = piso;
    eP->linha = linha;
    eP->coluna = coluna;
    eP->preco = preco;
    
    return eP;
}

//Esta a dar um piso a mais
void imprimirParque(int piso, int linha, int coluna, node_t *lista, estruturaParque *eP){
	
	//prints
	if(piso == 1){
		if(linha == 1 && coluna == 1){
			printf("Piso %d\n", piso);
		}
		
	}
	
	if(coluna == 1){
		if(!((linha -1) == eP->linha)){
			printf("[");
		}
	}
	
	if(linha > eP->linha){
		/*if((piso -1) == eP->piso && (coluna -1) == eP->coluna && (linha -1) == eP->linha){
			printf("oioi");
		}
		if( !((piso -1) == eP->piso) && ){
			printf("Piso %d\n", piso +1);
			printf("\n");
		}*/
		
		printf("Piso %d\n", piso +1);
			printf("\n");
		
	}
	if(coluna > eP->coluna){
			printf("]");
		printf("\n");
	}
	
	//Casos de paragem
	if(piso > eP->piso){
		printf("*L – Livre \n *O – ocupado");
		return;
	}
	if(linha > eP->linha){
		imprimirParque(piso +1, 1, 1, lista, eP);
		return;
	}
	if(coluna > eP->coluna){
		imprimirParque(piso, linha +1, 1, lista, eP);
		return;
	}

	//printf("piso: %d, linha: %d, coluna: %d", piso, linha, coluna);
	
	if(procurarNaCoord(lista, piso,linha,coluna) == 1){
        printf("O");
	}else{
		printf("L");
	}
	imprimirParque(piso, linha, coluna +1, lista, eP);
	
	/*
	for(i=0; i < eP->piso; i++){
        printf("piso %d:\n", i+1);
        for(j=0;j< eP->linha; j++){
            printf("[");
            for(k =0; k < eP->coluna; k++){
                //verificar se tem algum carro ou não
                if(procurarNaCoord(lista, i+1,j+1,k+1) == 1){
                	printf("O");
				}else{
					printf("L");
				}
				//printf("%d", procurarNaCoord(lista, i,j,k));
            }
            printf("]");
            printf("\n");
        }
        printf("\n"); 
	}*/
}

//Mudar para recursividade
int *lugarMaisProximo(int piso, int linha, int coluna, node_t *lista, estruturaParque *eP){//Retornar uma array [piso, linha, coluna]
	//int totalEspacosParque = eP->coluna * eP->linha * eP->piso;
	int i,j,k;
	int *coordenada = malloc(sizeof(int) *3);
	/*
	printf("\n[1]piso: %d, linha: %d, coluna: %d recebido\n", coordenada[0], coordenada[1], coordenada[2]);
	printf("\n[1]piso: %d, linha: %d, coluna: %d a verificar\n", piso, linha, coluna);
	
	//casos de paragem
	if(piso > eP->piso && linha > eP->linha && coluna > eP->coluna){
		coordenada[0] = -1;
		return coordenada;
	}
	
	if(piso > eP->piso || coordenada[2] != 0){
		printf("\n[final piso]piso: %d, linha: %d, coluna: %d\n", coordenada[0], coordenada[1], coordenada[2]);
		return coordenada;
	}
	
	if(linha > eP->linha || coordenada[2] != 0){
		printf("\n[final linha]piso: %d, linha: %d, coluna: %d\n", coordenada[0], coordenada[1], coordenada[2]);
		lugarMaisProximo(piso +1, 1, 1, lista, eP);
		return coordenada;
	}
	
	if(coluna > eP->coluna || coordenada[2] != 0){
		printf("\n[final coluna]piso: %d, linha: %d, coluna: %d\n", coordenada[0], coordenada[1], coordenada[2]);
		lugarMaisProximo(piso, linha +1 , 1, lista, eP);
		return coordenada;
	}
	
	//código para executar
	if(procurarNaCoord(lista, piso, linha, coluna) == 0){
		printf("\nlugar encontrado\n");
    	coordenada[0] = piso;
        coordenada[1] = linha;
        coordenada[2] = coluna;
        printf("\n[lugar encontrado]piso: %d, linha: %d, coluna: %d\n", coordenada[0], coordenada[1], coordenada[2]);
		return coordenada;	
	}
	
	lugarMaisProximo(piso, linha, coluna+1, lista, eP);*/
	
	for(i=1; i < eP->piso +1; i++){
        for(j=1;j< eP->linha +1; j++){
            for(k =1; k < eP->coluna +1; k++){
                //verificar se tem algum carro ou não
                if(procurarNaCoord(lista, i,j ,k) == 0){
                	coordenada[0] = i;
                	coordenada[1] = j;
                	coordenada[2] = k;
					return coordenada;	
					free(coordenada);
				}
				//printf("%d", procurarNaCoord(lista, i,j,k));
            }
        }
	}
}


dados_t *criarCarro(estruturaParque *eP, node_t *lista){	
	//Mudar a função
	//->Meter tabela com opções para para estacionar[X]
	//->verificar se as letras são seguidas[X]
	//->Se já existe a matricula [X]
	int coordPiso, coordLinha, coordColuna, i,haCarro = 1, opcao;
	char matriculaCarro[8], modeloCarro[100];
	int *coordeMaisProxima = lugarMaisProximo(1,1,1,lista, eP);
	
	//verificar a matricula
	int espaco;
	
	do{	
		espaco = 0;
		i= 0;
		
		printf("Matricula do carro: ");
		scanf("%s", &matriculaCarro);
        		
        for(i = 0; i < strlen(matriculaCarro); i++){
			if(isspace(matriculaCarro[i])){
				espaco++;
			}
		}
		
		//O if é para o 1ºcaso
		if(!(strlen(matriculaCarro) > 1 && strlen(matriculaCarro) <8)){//Se o tamanho d array da matricula for maior que 7
			printf("Matricula invAlida, maximo caracteres e 8\n");//Retornar erro
			i++;
		}
		
		if(procurarMatricula(&lista, matriculaCarro) == 1){
			printf("Matricula ja existedentro do parque");	
		}
		
		/*if(procurarMatriculaRetornarObjeto(lista, matriculaCarro) != NULL){
			printf("\nMatricula já existe no parque\n");
			coordPiso = -1;
			dados_t *carro = criarVeiculo(matriculaCarro, modeloCarro, coordPiso, coordLinha, coordColuna);
			return carro;
		}*/
		
	}while(!(strlen(matriculaCarro) > 1 && strlen(matriculaCarro) <8) || espaco != 0 || procurarMatricula(&lista, matriculaCarro) == 1);
	
	printf("Modelo do carro");
	scanf("%s", &modeloCarro);
	
	do{
		printf("\n [1] - Escolher lugar mais próximo livre \n [2] - Escolher por coordenadas \n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				{
					//ver como mudar isto 
					printf("piso lugar mais proximo: %d", coordeMaisProxima[0]);
					printf("linha lugar mais proximo: %d", coordeMaisProxima[1]);
					printf("coluna lugar mais proximo: %d", coordeMaisProxima[2]);
					
					printf("Coordenada mais proxima Piso %d, Linha %d, Coluna %d", coordeMaisProxima[0], coordeMaisProxima[1], coordeMaisProxima[2]);
					
					if(coordeMaisProxima[0] != -1){// Se não retornar null encontrou um lugar mais no parque, recebemos as coordenadas
						coordPiso = coordeMaisProxima[0];
						coordLinha = coordeMaisProxima[1];
						coordColuna = coordeMaisProxima[2];
					}else {
						printf("[ERRO]: Não existem lugares no parque para estacionar!");
					}
					opcao = 0;
				break;
				}
			case 2:
				{
					do{
						do{
							printf("\nPiso para estacionar carro: ");
					    	scanf("%d", &coordPiso);
					    	if((coordPiso > 0 && coordPiso <= eP->piso) == 0){
					    		printf("\n[ERRO]: Piso deve ser entre 1 e %d", eP->piso);
							}
						}while((coordPiso > 0 && coordPiso <= eP->piso) == 0);
						
						do{
							printf("\nLinha para estacionar carro:");
					    	scanf("%d", &coordLinha);
					    	if((coordLinha > 0 && coordLinha <= eP->linha) == 0){
					    		printf("\n[ERRO]: Linha deve ser entre 1 e %d", eP->linha);
							}
						}while((coordLinha > 0 && coordLinha <= eP->linha) == 0);
					
						do{
							printf("\nColuna para estacionar carro:");
					    	scanf("%d", &coordColuna);
					    	if((coordColuna > 0 && coordColuna <= eP->coluna) == 0){
					    		printf("\n[ERRO]: Coluna deve ser entre 1 e %d", eP->coluna);
							}
						}while((coordColuna > 0 && coordColuna <= eP->coluna) == 0);
						
						printf("\nCoordenadas para estacionar: %d %d %d\n", coordPiso, coordLinha, coordColuna); 
						
						haCarro = procurarNaCoord(lista, coordPiso, coordLinha, coordColuna);
						
						if(haCarro == 1){
							printf("Já existe um carro nessas coordenada");
						}
					}while(haCarro == 1 );
					opcao = 0;
				}
		}
	}while(opcao !=0);	
    
    dados_t *carro = criarVeiculo(matriculaCarro, modeloCarro, coordPiso, coordLinha, coordColuna);
    
    return carro;
    
}

dados_t *removerCarroMatricula(node_t *lista){
	char matriculaProcurar[6];
	int espaco = 0, i;
	dados_t *carroProcura;
	
	do{
		printf("Matricula do carro: ");
		gets(matriculaProcurar);
        		
        for(i = 0; i < strlen(matriculaProcurar); i++){
			if(isspace(matriculaProcurar[i])){
				espaco++;
			}
		}
		
		//O if é para o 1ºcaso
		if(!(strlen(matriculaProcurar) > 1 && strlen(matriculaProcurar) <8)){//Se o tamanho d array da matricula for maior que 7
			printf("Matricula invAlida, maximo de 8 caracteres\n");//Retornar erro
		}
		
		if(espaco > 0){
			printf("Matricula levou um espaço.\n");//Retornar erro
		}
		
		espaco = 0;
	}while(!(strlen(matriculaProcurar) > 1 && strlen(matriculaProcurar) <8) || espaco > 0);
	
	time_t horaSaida = time(&horaSaida);
	
	carroProcura = (dados_t*)procurarMatriculaRetornarObjeto(&lista, matriculaProcurar);
	carroProcura->horaSaida = horaSaida;
	
	return carroProcura;
}

double valorAPagarComPreco(estruturaParque *eP, dados_t *carro){
	double valorPagar = difftime(carro->horaSaida, carro->horaEntrada)/60/60 * eP->preco;
	printf("Valor a pagar %.2f\n", valorPagar);
	return valorPagar;
}

void mudarPrecoHora(estruturaParque *eP){
	FILE *estruturaParqueFicheiro;
	float novoPreco;
	char errorString[512];

	
	if(access("estruturaParque.csv", F_OK) == 0 ){//existe ficheiro
		printf("Qual o novo precopor hora do parque?");
		scanf("%f", &novoPreco);
		if((estruturaParqueFicheiro = fopen("estruturaParque.csv", "ab+")) == NULL){
			printf("Failed to open file.\n");
   			perror(errorString);
   			printf("%s\n", errorString);
		}	
		
		fprintf(estruturaParqueFicheiro, "%d, %d, %d, %f\n", eP->piso, eP->linha, eP->coluna, novoPreco);
		if(fwrite != 0){
			printf("contents to file written successfully !\n");
		}
		else{
			printf("error writing file !\n");
		}
		fclose(estruturaParqueFicheiro);
		printf("\nEstrutura Parque preco antigo %f\n", eP->preco);
		eP->preco = novoPreco;
		printf("\nEstrutura Parque preco novo %f\n", eP->preco);
	}else{
		printf("O ficheiro nao existe");
		
	}
	return;
}
