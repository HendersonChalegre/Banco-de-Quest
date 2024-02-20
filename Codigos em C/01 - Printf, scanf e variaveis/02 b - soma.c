#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	
	int N, X, R;
	
    printf("Digite um numero: ");
    scanf("%d", &N);
    
    printf("Digite outro  numero: ");
    scanf("%d", &X);
    
    R = N+X;
    
    printf("O resultado da soma de %d + %d eh: %d", N, X, R);
    
	return 0;
}
