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



int main(int argc, char *argv[]) {
	
	int i;
	
	int limiteInf, limiteSup;
	
	printf("\n\n\n                                                SORTEADOR DE NUMEROS!\n\n\n");
	
	printf("Digite um valor para o limite inferior:  ");
	scanf("%d", &limiteInf);


    do{
	    printf("\nDigite um valor para o limite superior:  ");
	    scanf("%d", &limiteSup);
			
	    if(limiteSup < limiteInf){
	        printf("\n\n\n            O limite superior nao pode ser menor que o inferior:  ");
	   
	    }
	
	}while(limiteSup < limiteInf);


	srand (time (0)); // funcao para iniciar a aleatoriedade

	
	printf("\n\nO numero sorteado foi:  %d\n", randon(limiteInf,limiteSup+1) );

	return 0;
}
