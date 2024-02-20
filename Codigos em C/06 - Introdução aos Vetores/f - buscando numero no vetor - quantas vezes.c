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
                                                     metodo para verificar se o pivo esta no vetor
  #########################################################################################################################################################*/
int buscar (int vetor[], int tam, int p){
	
	int i = 0;
	int cont = 0;
	
	while (i< tam){
		if(vetor[i]== p){
			cont++;
		}
		
	   i++;	
	}
	
	return cont;
	
	
}

/*#########################################################################################################################################################
                                                     metodo para criar o vetor
  #########################################################################################################################################################*/
void criarVetor (int vetor[], int tam){
	
	
	int i = 0;
	
	
	while(i<tam){
		int verif = 0;
		int j = 0;
		
		printf("   Digite um valor:  ");
		scanf("%d, ", &vetor[i]);
			
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
	printf("     ####                                                  VETORES                                           ###\n");
	printf("     ####                                          Buscando  numero no vetor                                 ###\n");
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
	int pivo;
	
	
	printf("  Escolha o tamanho do vetor:   ");
	scanf("%d", &tam);
	
	printf("\n\n\n");
	criarVetor (vetor,tam);
	
	
	printf("     O vetor criado com %d posicoes foi:\n\n       ", tam);
	
	system("cls");
	imprimirInicio();
	printf("\n\n\n     Digite um numero para pesquisar no vetor: ");
	scanf("%d", &pivo);
	
	
	
	int r = buscar(vetor,tam, pivo);
	
	system("cls");
	
	imprimirInicio();
	imprimirVetorOriginal (vetor,tam);
	
	if (r == 0){
		printf("\n\n     O numero %d nao esta presente no vetor", pivo);
	}else{
		
		printf("\n\n     O numero %d  aparece %d x neste vetor", pivo, r);
	}
	
	return 0;
}
