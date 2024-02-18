#include <stdio.h>
#include <stdlib.h>


/*#########################################################################################################################################################
                                                     metodo para imprimir o vetor
  #########################################################################################################################################################*/
void imprimirVetor (int vetor[], int tam){
	
	int i = 0;
	printf("\n[ ");
	
	while(i<tam-1){
		printf("%d, ", vetor[i]);
		i++;
	}
	printf("%d ] ", vetor[i]);
}



/*#########################################################################################################################################################
                                                     metodos para ordenar 
  #########################################################################################################################################################*/
void merge(int *v, int *c, int i, int m, int f) {
  int z = i; 
  int x = i;
  int ic = m + 1;

  while( z <= f){
  	c[z] = v[z];
  	z++;
  }
  
  z = i;


  while (x <= m && ic <= f) {
    

    if (c[x] <= c[ic]){
       v[z] = c[x];	
       z++;
       x++;
	} 
    else {
	   v[z] = c[ic];
	   z++;
       ic++;
    }
  }

  while (x <= m) {
  	v[z] = c[x];
  	z++;
  	x++;
  }

  while (ic <= f){ 	
     v[z] = c[ic];
     z++;
     ic++;
  }
}


void ordenacao(int *v, int *c, int i, int f) {
  if (i < f){
  
    int m = (i + f) / 2;
    ordenacao(v, c, i, m);
    ordenacao(v, c, m + 1, f);
    merge(v, c, i, m, f);
  }
}



void mergeSort(int *v,   int n) {
  
  int *c = malloc(sizeof(int) * n);
  int i = 0;
  int f = n-1;
  ordenacao(v, c, i, f);
  
  free(c);
 
}



/*#########################################################################################################################################################
                                                     metodo para iniciar o sistema
  #########################################################################################################################################################*/
int main(int argc, char *argv[]) {
	
	int vetor[10] = {10,7,9,8,5,2,6,4,3,1}; // vetor de testes
	int t = 10;
	
	printf("\n\n\n                                                            ORDENACAO\n\n");
	
	printf("                                                          MERGE SORT\n\n");
	
	
	printf("vetor original: ");
	imprimirVetor(vetor,t);
	
	printf("\n\n ");
	
	mergeSort(vetor,  t);
     
     
	 printf("vetor ordenado: "); 
	imprimirVetor(vetor,t);
	printf("\n\n\n\n\n");
	
	return 0;
}
