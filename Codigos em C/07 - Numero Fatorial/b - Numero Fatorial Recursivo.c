#include <stdio.h>
#include <stdlib.h>

/* Calculando o numero fatorial utilizando funcao recursiva */

//Funcao recursiva do calculo fatorial
int fat(int num){
	
	if(num == 1){ // verificacao para o ponto de parada da recursao, onde o fatorial de 1 eh igual a 1
		return 1;
	}
	
	return num*fat(num-1); // calculo recursivo, multiplica o numero atual pelo fatorial do anterior
	
}


//Funcao main apenas para testar a funcao 
int main(int argc, char *argv[]) {
	
	
	
	int num;
	printf("Digite um numero inteiro para calcular o fatorial:    ");
	scanf("%d", &num);
	printf("O numero fatoral de %d eh %d", num, fat(num));
	
	
	return 0;
}
