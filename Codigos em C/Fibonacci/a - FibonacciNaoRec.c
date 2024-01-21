#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// contando de 0 a N
void fibonacci (int fim){
	
	printf("Imprimindo a sequencia de Fibonacci ate %d: \n\n", fim);
	
	int a = 0;
	int b =1;
	int aux;
	int cont = 2;
	printf("0, 1, ");
	
	
	while(cont < fim){
	    aux = a+b;
	    a = b;
	    b = aux;
	    
		 	printf("%d, ", b); //imprime o valor atual
	   
	 	cont++;
    }
    
    	
    
}

int main(int argc, char *argv[]) {
	
     
	int fim; // variavel para receber o limite da contagem
	
    
    printf("Digite um valor final para imprimir a sequencia: ");
    scanf("%d", &fim);
    printf("\n\n");
    fibonacci(fim); // chamada da função
	
	return 0;
}
