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
    printf("Total de colunas? ");
    scanf("%d", &linha);
    printf("Total de linhas? ");
    scanf("%d", &coluna);
    printf("Qual o preco por hora? ");
    scanf("%f", &preco);
    
    estruturaParque *eP = (estruturaParque *)malloc(sizeof(estruturaParque));//Alocar a memoria para os dados

    //Guardar na struct
	eP->piso = piso;
    eP->linha = linha;
    eP->coluna = coluna;
    eP->preco = preco;
    
    return eP;
}

void imprimirParque(node_t *lista, estruturaParque *eP){
	int i, j, k;
	
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
	}
}

int *lugarMaisProximo(node_t *lista, estruturaParque *eP){//Retornar uma array [piso, linha, coluna]
	//int totalEspacosParque = eP->coluna * eP->linha * eP->piso;
	int i,j,k;
	int coordenada[3];
	
	for(i=1; i < eP->piso +1; i++){
        for(j=1;j< eP->linha +1; j++){
            for(k =1; k < eP->coluna +1; k++){
                //verificar se tem algum carro ou não
                if(procurarNaCoord(lista, i,j ,k) == 0){
                	coordenada[0] = i;
                	coordenada[1] = j;
                	coordenada[2] = k;
					return coordenada;	
				}
				//printf("%d", procurarNaCoord(lista, i,j,k));
            }
        }
	}
	coordenada[0] = -1;
	return coordenada;
}


dados_t *criarCarro(estruturaParque *eP, node_t *lista){	
	//Mudar a função
	//->Meter tabela com opções para para estacionar[X]
	//->verificar se as letras são seguidas[X]
	//->Se já existe a matricula [X]
	int coordPiso, coordLinha, coordColuna, i,haCarro = 1, opcao;
	char matriculaCarro[6], modeloCarro[100];
	int coordeMaisProxima[3];
	
	//verificar a matricula
	int letras, num, espaco, charJunto;
	
	do{	
		letras = 0;
		num = 0;
		espaco = 0;
		charJunto=0;
		i= 0;
		
		printf("Matricula do carro: ");
		scanf("%s", &matriculaCarro);
        		
        for(i = 0; i < strlen(matriculaCarro); i++){
        	if(isdigit(matriculaCarro[i])){
        		num++;
			}
			if(isalpha(matriculaCarro[i])){
				letras++;
				if(!isalpha(matriculaCarro[i+1])){
					printf("proximo nao e char");
					charJunto++;
				}
			}
			if(isspace(matriculaCarro[i])){
				espaco++;
			}
		}
		
		//O if é para o 1ºcaso
		if(strlen(matriculaCarro) != 6){//Se o tamanho d array da matricula for maior que 7
			printf("Matricula invAlida.\n");//Retornar erro
			printf("Formato: '00AA00'\n");
			i++;
		}
		
		if(espaco != 0 && i == 0){
			printf("Matricula levou um espaço.\n");//Retornar erro
			i++;
		}
		
		if(letras != 2 && i == 0){
			printf("\nMatricula tem mais letras do que o devido.\n");//Retornar erro
			printf("Formato: '00AA00'\n");
			i++;
		}
		
		if(charJunto >= 2 && i == 0){
			printf("\nAs letras da matricula estam separadas.\n");//Retornar erro
			printf("Formato: '00AA00'\n");
			i++;
		}
		
		if(num != 4 && i == 0){
			printf("\nMatricula tem mais numeros do que o devido.\n");//Retornar erro
			printf("Formato: '00AA00'\n");
			i++;
		}
		
		printf("esp: %d, num: %d, letr: %d", espaco, num, letras);
		
		if(procurarMatricula(&lista, matriculaCarro) == 1){
			printf("Matricula ja existedentro do parque");	
		}
		
		/*if(procurarMatriculaRetornarObjeto(lista, matriculaCarro) != NULL){
			printf("\nMatricula já existe no parque\n");
			coordPiso = -1;
			dados_t *carro = criarVeiculo(matriculaCarro, modeloCarro, coordPiso, coordLinha, coordColuna);
			return carro;
		}*/
		
	}while(strlen(matriculaCarro) != 6 || espaco != 0 || letras != 2 || num != 4 || charJunto >= 2 || procurarMatricula(&lista, matriculaCarro) == 1);
	
	printf("Modelo do carro");
	scanf("%s", &modeloCarro);
	
	do{
		printf("\n [1] - Escolher lugar mais próximo livre \n [2] - Escolher por coordenadas \n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				{
					coordeMaisProxima[0] = lugarMaisProximo(lista, eP)[0];
					coordeMaisProxima[1] = lugarMaisProximo(lista, eP)[1];
					coordeMaisProxima[2] = lugarMaisProximo(lista, eP)[2];
					
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
						printf("\nhaCarro: %d\n", haCarro);
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
	int letras = 0, num = 0, espaco = 0, i;
	dados_t *carroProcura;
	
	do{
		printf("Matricula do carro: ");
		gets(matriculaProcurar);
        		
        for(i = 0; i < strlen(matriculaProcurar); i++){
        	if(isdigit(matriculaProcurar[i])){
        		num++;
			}
			if(isalpha(matriculaProcurar[i])){
				letras++;
			}
			if(isspace(matriculaProcurar[i])){
				espaco++;
			}
		}
		
		//O if é para o 1ºcaso
		if(strlen(matriculaProcurar) != 6){//Se o tamanho d array da matricula for maior que 7
			printf("Matricula invAlida.\n");//Retornar erro
			printf("Formato: '00AA00'");
		}
		
		if(espaco > 0){
			printf("Matricula levou um espaço.\n");//Retornar erro
		}
		
		if(letras > 3){
			printf("Matricula tem mais letras do que o devido.\n");//Retornar erro
			printf("Formato: '00AA00'");
		}
		
		if(num > 5){
			printf("Matricula tem mais numeros do que o devido.\n");//Retornar erro
			printf("Formato: '00AA00'");
		}
		
		printf("esp: %d, num: %d, letr: %d", espaco, num, letras);
		
		num = 0;
		letras = 0;
		espaco = 0;
	}while(strlen(matriculaProcurar) != 6 || espaco > 0 || letras > 3 || num > 5);
	
	printf("\nMatricula a procurar");
	puts(matriculaProcurar);
	printf("\n\n\n");
	
	time_t horaSaida = time(&horaSaida);
	
	carroProcura = (dados_t*)procurarMatriculaRetornarObjeto(&lista, matriculaProcurar);
	carroProcura->horaSaida = horaSaida;
	
	return carroProcura;
}

double valorAPagarComPreco(estruturaParque *eP, dados_t *carro){
	carro->horaSaida = 1640983652;
	double valorPagar = difftime(carro->horaSaida, carro->horaEntrada)/60/60 * eP->preco;
	printf("Valor a pagar %f\n", valorPagar);
	return valorPagar;
}
