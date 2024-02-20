#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// contando de 0 a N
void contador (int inicio, int fim){
	
	printf("Imprimindo os numeros de %d ate %d: \n\n", inicio, fim);
	
	int cont = inicio; // variavel para contar o valor atual e iniciando pela variavel inicio
	
	while(cont <= fim){
	
	 	printf("%d\n", cont); //imprime o valor atual
	 	
	 	cont++;
	}
	
}




int main(int argc, char *argv[]) {
	
     
	int inicio, fim; // variavel para receber o limite da contagem
	
    printf("Digite um valor inicial para imprimir a sequencia: ");
    scanf("%d", &inicio);
    
    printf("Digite um valor final para imprimir a sequencia: ");
    scanf("%d", &fim);
    
    printf("\n\n");
    contador (inicio, fim); // chamada da função
	
	return 0;
}
