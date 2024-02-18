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
                                                     metodos para ordenar 
  #########################################################################################################################################################*/

int dividir(int vet[], int i, int f){
	int p = vet[f];;
	int p2 = i;
	int y;
	
	for(y = i; y < f; y++){
		
		if(vet[y] <= p) {
			swap(vet, y, p2);
			p2++;
		}
	}
	
	swap(vet, p2, f); // troca o pivô
	
	return p2;
}


int dividirRandom(int vetor[], int i, int f) {
	
	int p = (rand() % (f - i + 1)) + i; // seleciona um número entre o inicio e o  fim 
	swap(vetor, p, f); 	// faz a troca para colocar o pivô no fim
	return dividir(vetor, i, f);
}

void quickSort(int vetor[], int i, int f) {
	if(i< f) {
		int p = dividirRandom(vetor, i, f);
		quickSort(vetor, i, p - 1);
		quickSort(vetor, p + 1, f);
	}
}



/*#########################################################################################################################################################
                                                     metodo para iniciar o sistema
  #########################################################################################################################################################*/
int main(int argc, char *argv[]) {
	
	int vetor[10] = {10,7,9,8,5,2,6,4,3,1}; // vetor de testes
	int t = 10;
	
	printf("\n\n\n                                                            ORDENACAO\n\n");
	
	printf("                                                          Quick SORT\n\n");
	
	
	printf("vetor original: ");
	imprimirVetor(vetor,t);
	
	printf("\n\n");
	
	srand(time(NULL));
	 
	// chamada do quicksort
	quickSort(vetor, 0, t - 1);


    printf("vetor ordenado: "); 
	imprimirVetor(vetor,t);
	printf("\n\n\n\n\n");
	
	return 0;
}
