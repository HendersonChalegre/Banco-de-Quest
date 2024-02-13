#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* gerador de numeros aleatorios  */

int randon(int N){

    int sort;
    
  
     sort = rand()%N;	
	
 

	return sort; // retorna um numero aleatorio que pertece ao limite
	
}



int main(int argc, char *argv[]) {
	
	int i;
	
	int limiteInf, limiteSup;
	
	printf("                                                SORTEADOR DE NUMEROS!\n\n\n");
	


	printf("\nDigite um valor para o limite do intervalo permitido :  ");
	scanf("%d", &limiteSup);
		
	srand (time (0)); // funcao para iniciar a aleatoriedade
	
	
	printf("\n\nO numero sorteado foi:  %d\n", randon(limiteSup+1) );

	return 0;
}
