#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// contando de 0 a N
int fibonacci (int fib){
	
	if(fib == 1){
		return 0;
	}
	else if(fib == 2){
		return 1;
	}
	
	return fibonacci(fib-1) + fibonacci(fib-2);  
}

int main(int argc, char *argv[]) {
	
     
	int fib; // variavel para receber a posicao do Fibonacci
	
    
    
    do{
	  printf("Digite a posicao do fibonacci para ser calculado que seja menor ou igual a 45: ");
      scanf("%d", &fib);
      system("cls");
    }while(fib >= 45);
    
    printf("\n\n");
    printf("O valor da posicao do Fibonacci eh: %d \n\n ", fibonacci(fib)); // chamada da função
	
	return 0;
}
