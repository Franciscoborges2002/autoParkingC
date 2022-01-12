#include "estruturaParque.h"

/*
*	Este parte tem a função de manter a estrutura do parque.
*/

//Função para iniciar se não há ficheiro
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

//Função para criar alocar a memória apartir das informações do ficheiro
estruturaParque * criarParqueApartirDeFicheiro(int piso, int linha, int coluna, float preco){
	estruturaParque *eP = (estruturaParque *)malloc(sizeof(estruturaParque));//Alocar a memoria para os dados

    //Guardar na struct
	eP->piso = piso;
    eP->linha = linha;
    eP->coluna = coluna;
    eP->preco = preco;
    
    return eP;
}

//Função com recursividade para imprimir o parque
void imprimirParque(int piso, int linha, int coluna, node_t *lista, estruturaParque *eP){
	//prints
	if(piso<=eP->piso){//se o piso for menor ou igual aos pisos totais
		if(linha <= eP->linha){//se a linha for menor ou igual as linhas totais
			if(coluna ==1 && linha == 1){
				printf("\n");
				printf("Piso %d\n", piso);
			}
		}
	}
	
	if(coluna == 1){//Se for a primeira coluna
		if(linha -1 > eP->linha){
			
		}else if(!((linha -1) == eP->linha)){//primeira linha
			printf("[");
		}
	}
	
	
	if(coluna > eP->coluna){//Se a coluna for maior que o total, meter ]
			printf("]");
		printf("\n");
	}
	
	//Casos de paragem
	if(piso > eP->piso){
		printf("*L = Livre ]\n[*O = ocupado]\n");
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
	
	//Procurar se temos esse carro na coordenada
	if(procurarNaCoord(lista, piso,linha,coluna) == 1){
        printf("O");
	}else{
		printf("L");
	}
	
	imprimirParque(piso, linha, coluna +1, lista, eP);//chama a função de novo e vai para a próxima coluna
}

//Retornar o lugar mais próximo
int *lugarMaisProximo(node_t *lista, estruturaParque *eP){//Retornar uma array [piso, linha, coluna]
	int i,j,k;
	int *coordenada = malloc(sizeof(int) *3);//alocar a uma array o espaço necessário
	
	for(i=1; i < eP->piso +1; i++){
        for(j=1;j< eP->linha +1; j++){
            for(k =1; k < eP->coluna +1; k++){
                if(procurarNaCoord(lista, i,j ,k) == 0){
                	coordenada[0] = i;
                	coordenada[1] = j;
                	coordenada[2] = k;
					return coordenada;//retornar a array
					free(coordenada);//libertar o espaço
				}
            }
        }
	}
	
	coordenada[0] = -1;//Se estiver ocupado, o primeiro espaço da array tem -1
	return coordenada;
}

//Função para criar o carro e retornar na struct de dados
dados_t *criarCarro(estruturaParque *eP, node_t *lista){	
	int coordPiso, coordLinha, coordColuna, i,haCarro = 1, opcao, espaco;
	char matriculaCarro[8], modeloCarro[100];
	int *coordeMaisProxima = lugarMaisProximo(lista, eP);
	
	//verificar inicialização da matricula
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
			printf("Matricula invalida, maximo caracteres e 8\n");//Retornar erro
			i++;
		}
		
		if(procurarMatricula(&lista, matriculaCarro) == 1){
			printf("Matricula ja existe dentro do parque");	
		}
		
	}while(!(strlen(matriculaCarro) > 1 && strlen(matriculaCarro) <8) || espaco != 0 || procurarMatricula(&lista, matriculaCarro) == 1);
	
	fflush(stdin);//Apaga o  buffer do teclado ->a string dos caracteres digitados no teclado passa a ""
	printf("Modelo do carro: ");
	gets(modeloCarro);
	
	do{
		printf("\n [1] - Escolher lugar mais proximo livre \n [2] - Escolher por coordenadas\n Esolher opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				{
				printf("\nO carro foi estacionado no piso %d, linha %d e coluna %d\n",coordeMaisProxima[0], coordeMaisProxima[1], coordeMaisProxima[2]);
					
				coordPiso = coordeMaisProxima[0];
				coordLinha = coordeMaisProxima[1];
				coordColuna = coordeMaisProxima[2];
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
						
						haCarro = procurarNaCoord(lista, coordPiso, coordLinha, coordColuna);
						
						if(haCarro == 1){
							printf("\nJá existe um carro nessas coordenada");
						}else{
							printf("\nO carro foi estacionado no piso %d, linha %d e coluna %d\n",coordPiso, coordLinha, coordColuna);
						}
					}while(haCarro == 1 );
					opcao = 0;
				}
		}
	}while(opcao !=0);	
    
    dados_t *carro = criarVeiculo(matriculaCarro, modeloCarro, coordPiso, coordLinha, coordColuna);//criar o veiculo
    
    return carro;//retornar para a main, para remover
    
}

//Função para calcular e mostrar o valor a pagar pela pessoa do carro
double valorAPagarComPreco(estruturaParque *eP, dados_t *carro){
	double valorPagar = difftime(carro->horaSaida, carro->horaEntrada)/60/60 * eP->preco;
	return valorPagar;
}

//Remover carro com a matricula
dados_t *removerCarroMatricula(node_t *lista, estruturaParque *eP){
	char matriculaProcurar[8];
	int espaco = 0, i;
	dados_t *carroProcura;
	fflush(stdin);//Apaga o  buffer do teclado ->a string dos caracteres digitados no teclado passa a ""
	
	if(lista == NULL){
		printf("Nenhum carro a remover");
		return;
	}
	
	do{
		printf("Matricula do carro a remover: ");
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
	
	carroProcura = (dados_t*)procurarMatriculaRetornarObjeto(&lista, matriculaProcurar);//receber o objeto conforme a matricula
	carroProcura->horaSaida = horaSaida;//definir a hora de saida para ao carro
	
	printf("Valor a pagar %.2f euros\n", valorAPagarComPreco(eP, carroProcura));//mostrar o valor a pagar pela pessoa

	if(strcmp(carroProcura->matricula, "NULL") == 0){
		printf("Matricula nao foi encontrada no parque");
	}else{
		return carroProcura;//retornar o carro, para removermos no main
	}
	return NULL;
}

//Função para a serializaçao do ficheiro do parque
estruturaParque *serializacaoFicheiroInicioEstruturaParque(){
	char errorString[512];
	estruturaParque *eP;
	FILE *estruturaParqueFicheiro;
	//Verificar se o ficheiro existe
	if( access("estruturaParque.csv", F_OK) == 0){//Verificar se o ficheiro existe
	
		int piso, linha, coluna;
		float preco;
		estruturaParqueFicheiro = fopen("estruturaParque.csv", "r");//Abrir o ficheiro e meter em modo para ler
		fscanf(estruturaParqueFicheiro, "%d, %d, %d, %f", &piso, &linha, &coluna, &preco);//Dar scan ao que nós queremos
		estruturaParque *eP = (estruturaParque *)malloc(sizeof(estruturaParque));//Alocar a memoria para os dados
		eP = criarParqueApartirDeFicheiro(piso, linha, coluna, preco);//criar o objeto para meter na struct
		
		fclose(estruturaParqueFicheiro);//fechar o ficheiro
		return eP;//retornar a estrutura do parque
	}else{//Se o ficheiro não existe
		eP = (estruturaParque *)initParq();//Vamos chamar a função para perguntar o piso, linh, coluna e preco
		estruturaParqueFicheiro = fopen("estruturaParque.csv", "ab+");//Vai criar e abrir o ficheiro
		
		if (estruturaParqueFicheiro != NULL) {//Se exitir o ficheiro
		    fprintf(estruturaParqueFicheiro, "%d, %d, %d, %f\n", eP->piso, eP->linha, eP->coluna, eP->preco);//Vamos escrever o que nós queremos
		    
			if(fwrite != 0){//Se não conseguir escrever no ficheiro
				printf("Escrita bem sucedida!\n");
			}
			else{
				printf("Escrita mal sucedida!\n");
			}
		}
		
		if(estruturaParqueFicheiro == NULL){//Se não conseguir abrir o ficheiro
			printf("Erro ao abrir o ficheiro\n");
   			perror(errorString);//receber o erro que aconteceu
   			printf("%s\n", errorString);//Mostrar o erro que aconteceu
		}
		fclose(estruturaParqueFicheiro);
		return eP;//retornar a estrutura do parque
	}
}

//Fnção para mudar o preço por hora do parque
void mudarPrecoHora(estruturaParque *eP){
	FILE *estruturaParqueFicheiro;
	float novoPreco;
	char errorString[512];

	
	if(access("estruturaParque.csv", F_OK) == 0 ){//Se existir o ficheiro
		do{
			printf("Qual o novo preco por hora do parque? ");//Perguntar novo preço
			scanf("%f", &novoPreco);//Alocar a var novoPreco
		}while(novoPreco <= 0);
		
		if((estruturaParqueFicheiro = fopen("estruturaParque.csv", "w")) == NULL){//Tentar abrir o fivheiro para escrever, se for NULL, não existe ficheiro
			printf("Failed to open file.\n");
   			perror(errorString);//Erro que ocorreu ao tentar abrir
   			printf("%s\n", errorString);//Mostrar que erro foi
		}	
		
		//Se conseguir abri o ficheiro temos de escrever o novoPreco
		fprintf(estruturaParqueFicheiro, "%d, %d, %d, %f\n", eP->piso, eP->linha, eP->coluna, novoPreco);
		
		if(fwrite != 0){//Se não conseguir escrever no ficheiro
			printf("Escrita bem sucedida!\n");
		}
		else{
			printf("Escrita mal sucedida!\n");
		}

		//fechar o fichpeiro
		fclose(estruturaParqueFicheiro);
		eP->preco = novoPreco;
	}else{//O ficheiro não existe
		printf("Erro ao abrir o ficheiro");	
	}
}
