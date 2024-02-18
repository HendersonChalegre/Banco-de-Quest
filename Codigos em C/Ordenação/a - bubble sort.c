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
void bubbleSort(int vetor[], int tam){
	
	int i = 1; // inicia na posicao 1
	
	
	while(i<tam){ // a quantidade de vezes que repetira é o limitado pelo tamanho do vetor
		printf("\nFase %d: ", i); // fase atual
		
		int j =0; // inicio 
		
		while(j<tam-i){ // a quantidade de verificacoes a se fazer eh limitado pelo tamanho do vetor menos a quantidade de i 
			if(vetor[j] > vetor[j+1]){ // verifica se o item na posicao j eh maior que o item na posicao seguinte
				swap(vetor, j, j+1); //troca
			}
		    j++; // incrementa o j	
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
	
	printf("                                                           BUBBLE SORT\n\n");
	
	
	printf("vetor original: ");
	imprimirVetor(vetor,t);
	
	printf("\n\n ");
	
	bubbleSort(vetor, t);
	return 0;
}
