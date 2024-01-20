#include <stdio.h>
#include <stdlib.h>

/* Calculando o numero fatorial */

//Funcao do calculo fatorial
int fat(int num){
	
   int i = num -1; // memoriza o valor anterior do numero que precisa ser calculado

   while (i>= 1){ // calcula o fatorial
   	num = num*i;
    i--;
   }

   return num; // 
	
}


//Funcao main apenas para testar a funcao 
int main(int argc, char *argv[]) {	
	int num;
	printf("Digite um numero inteiro para calcular o fatorial:    ");
	scanf("%d", &num);
	printf("O numero fatoral de %d eh %d", num, fat(num));
	
	return 0;
}
