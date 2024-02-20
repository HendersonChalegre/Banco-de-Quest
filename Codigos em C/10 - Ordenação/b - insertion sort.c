#include <stdio.h>
#include <stdlib.h>



/*#########################################################################################################################################################
                                                     metodo para imprimir o vetor
  #########################################################################################################################################################*/
void imprimirVetor (int vetor[], int tam){
	
	int i = 0;
	printf("\n[ ");
	
	while(i<tam-1){
		printf("%d, ", vetor[i]);
		i++;
	}
	printf("%d ] ", vetor[i]);
}



/*#########################################################################################################################################################
                                                     metodo para trocar as posicoes do vetor
  #########################################################################################################################################################*/
void swap(int vetor[], int  x, int y){
	int aux = vetor[x]; // armazena temporariamente o valor que estiver na posicao x
	vetor[x] = vetor[y]; // coloca o valor que estiver na posicao y na posicao x 
	vetor[y] = aux; // coloca o valor que estava na posicao x na posicao y
	
}

/*#########################################################################################################################################################
                                                     metodo para ordenar 
  #########################################################################################################################################################*/
void insertionSort(int vetor[], int tam){
	
	int i = 1; // inicia na posicao 1
	
	
	while(i<tam){ // a quantidade de vezes que repetira é o limitado pelo tamanho do vetor
		printf("\nFase %d: ", i); // fase atual
		
		int j =i; // inicio 
		while (j > 0 && vetor[j] < vetor[j-1]) {
			swap(vetor, j, j-1); //troca
			j--; // incrementa o j	
		}
		
		imprimirVetor ( vetor, tam);
		
		i++; // incrementa o i
	}
}

/*#########################################################################################################################################################
                                                     metodo para iniciar o sistema
  #########################################################################################################################################################*/
int main(int argc, char *argv[]) {
	
	int vetor[10] = {10,7,9,8,5,2,6,4,3,1}; // vetor de testes
	int t = 10;
	
	printf("\n\n\n                                                            ORDENACAO\n\n");
	
	printf("                                                          INSERTION SORT\n\n");
	
	
	printf("vetor original: ");
	imprimirVetor(vetor,t);
	
	printf("\n\n ");
	
	insertionSort(vetor, t);
	
	printf("\n\n\n\nvetor ordenado: "); 
	imprimirVetor(vetor,t);
	printf("\n\n\n\n\n");
	return 0;
}
