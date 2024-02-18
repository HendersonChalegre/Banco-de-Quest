#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* gerador de numeros aleatorios  */

int randon(int x, int N){

    int sort;
    
    do{
    	
     sort = rand()%N;	
	}while(sort < x);
 

	return sort; // retorna um numero aleatorio que pertece ao limite
	
}

int * geradorCodigo( int q){
	
	int* vetor = (int*)calloc(q,sizeof(int)); // vetor com alocacao de espaco
	srand (time (NULL)); // funcao para iniciar a aleatoriedade

	
	int i = 0; // variavel para manipular o while

	while(i<= q){
		
	
		vetor[i] = randon(0,q+2); // buscando aleatoriamente os caracteres
		
		i++;
	}

   


 return vetor;
}


void imprimirVetor(int* vetor, int q){
	
	
	int i = 0;
	while(i<= q){
		
	    printf("%d,  ",vetor[i]); // buscando aleatoriamente os caracteres
		i++;
	}
	
}
int main(int argc, char *argv[]) {
	
	int i;
	
	int quant;
	
	printf("\n\n                                                GERADOR DE CODIGOS ALEATORIOS !\n\n\n");
	
	printf("Digite quantos digitos o codigo tera:   ");
	scanf("%d", &quant);
	quant = quant-1;
	int* cod = geradorCodigo(quant); // vetor para guardar o codigo	
   
    imprimirVetor(cod, quant);    
 
//	

}
	

