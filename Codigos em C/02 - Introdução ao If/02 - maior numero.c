#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int N, X;
	
	
    printf("\n\n   Digite um numero: ");
    scanf("%d", &N);
    
    printf("   Digite outro  numero: ");
    scanf("%d", &X);
    
    if(N > X){
    	printf("   O numero %d eh maior que %d", N, X);
	}
	else if(X > N){
    	printf("   O numero %d eh maior que %d", X, N);
	}
	else{
	   	printf("   Os numeros digitados sao iguais");	
	}
    
	return 0;
}
