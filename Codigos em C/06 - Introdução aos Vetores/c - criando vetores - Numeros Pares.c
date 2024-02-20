#include <stdio.h>
#include <stdlib.h>


void imprimirVetorOriginal (int vetor[], int tam){
	
	int i = 0;
	printf("\n       [ ");
	
	while(i<tam-1){
		printf("%d, ", vetor[i]);
		i++;
	}
	printf("%d ] ", vetor[i]);
}

/*#########################################################################################################################################################
                                                     metodo para imprimir o vetor
  #########################################################################################################################################################*/
void imprimirVetor (int vetor[], int tam){
	
	int i = 0;
	printf("\n       [ ");
	
	while(i<tam-1){
		
		if( vetor[i]%2 == 0){
		   printf("%d, ", vetor[i]);
	    }
		i++;
	}
	
	if( vetor[i]%2 == 0){
	    printf("%d ] ", vetor[i]);
    } else{
    	printf("] ");
	}
}

/*#########################################################################################################################################################
                                                     metodo para criar o vetor
  #########################################################################################################################################################*/
void criarVetor (int vetor[], int tam){
	
	
	int i = 0;
	
	
	while(i<tam){
		
		
		
		int num;
		int verif = 0;
		int j = 0;
		
		printf("   Digite um valor:  ");
		scanf("%d, ", &num);
			
			while (j<i){// verifica se o numero ja foi digitado
				if(num == vetor[j]){
					printf("     Numero ja digitado, escolha outro");
					scanf("%d, ", &num);
					j=0;
			   }else{
			     	j++;
			   }   
			
			   
			}
		
		vetor[i] = num;//guarda o numero digitado
		i++;
	}
	
}
	
/*#########################################################################################################################################################
                                                     metodo para imprimir a logo da questao
  #########################################################################################################################################################*/	
void imprimirInicio(){
	
		printf("\n\n\n\n     ###########################################################################################################\n");
	printf("     ###########################################################################################################\n");
	printf("     ####                                                                                                    ###\n");
	printf("     ####                                                                                                    ###\n");
	printf("     ####                                         CRIANDO VETORES                                            ###\n");
	printf("     ####                                          NUMEROS PARES                                             ###\n");
	printf("     ####                                                                                                    ###\n");
	printf("     ####                                                                                                    ###\n");
	printf("     ###########################################################################################################\n");
	printf("     ###########################################################################################################\n\n\n\n");
	
}


/*#########################################################################################################################################################
                                                     metodo para iniciar o sistema
  #########################################################################################################################################################*/
int main(int argc, char *argv[]) {
	
	
	imprimirInicio();
	
	
	int tam = 10;
	int vetor[tam];
	
	printf("  Escolha o tamanho do vetor:   ");
	scanf("%d", &tam);
	
	printf("\n\n\n");
	criarVetor (vetor,tam);
	
	system("cls");
	imprimirInicio();
	printf("     O vetor criado com %d posicoes foi:\n\n       ", tam);
	imprimirVetorOriginal (vetor,tam);
	
	printf("\n\n     Vetor com numeros pares");
	imprimirVetor(vetor,tam);
	return 0;
}
