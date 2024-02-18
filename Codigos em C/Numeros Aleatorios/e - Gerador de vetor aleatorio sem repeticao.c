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

int * geradorVetor( int q){
	
	int* vetor = (int*)calloc(q,sizeof(int)); // vetor com alocacao de espaco
	srand (time (NULL)); // funcao para iniciar a aleatoriedade

	
	int i = 0; // variavel para manipular o while

	while(i<= q){
		
	
		int a =  randon(0,q+2); // buscando aleatoriamente os caracteres
		int verf = 0;
		int j = 0;
		
		while (j<=i){
		   
		   if (a == vetor[j]){
		   	a =  randon(0,q+2);
		   	j =0;
		   }else{
		   j++;
     	}
		}
		
		
		vetor[i] = a;
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
	int* cod = geradorVetor(quant); // vetor para guardar o codigo	
   
    imprimirVetor(cod, quant);    
 
//	

}
	

