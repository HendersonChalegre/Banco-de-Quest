#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// contando de 0 a N
void contador (int num){
	
	int cont; // variavel para contar o valor e iniciando com valor zero
	for(cont = 0; cont <= num; cont++){	
	    if(cont%2 != 0){
	  	printf("%d\n", cont); //imprime o valor atual
	    }
	  }
}




int main(int argc, char *argv[]) {
	
     
	int num; // variavel para receber o limite da contagem
	
	printf("Imprimindo numeros impares\n\n ");
	
    printf("Digite um numero para imprimir a sequencia: ");
    scanf("%d", &num);
    printf("\n\n");
    contador (num); // chamada da função
	
	return 0;
}
