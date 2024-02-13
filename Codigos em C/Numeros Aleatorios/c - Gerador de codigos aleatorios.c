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

char * geradorCodigo( int q){
	
	char* resultado=(char*)calloc(q,sizeof(char)); // vetor com alocacao de espaco
	srand (time (NULL)); // funcao para iniciar a aleatoriedade
	char alfabeto[37] =	"ABCDEFGHIJKLMNOPQRSTUVXWYZ0123456789";//grava todos os caracteres permitidos
	
	int i = 0; // variavel para manipular o while

	while(i<= q){
		
	
		resultado[i] = alfabeto[randon(1,37)]; // buscando aleatoriamente os caracteres
		
		i++;
	}

 return resultado;
}

int main(int argc, char *argv[]) {
	
	int i;
	
	int quant;
	
	printf("\n\n                                                GERADOR DE CODIGOS ALEATORIOS !\n\n\n");
	
	printf("Digite quantos digitos o codigo tera:   ");
	scanf("%d", &quant);
	quant = quant-1;
	char* cod = geradorCodigo(quant); // vetor para guardar o codigo	
   
    
 	printf("\n\n\nO codigo aleatorio gerado eh:       %s\n", cod);
//	

}
	

