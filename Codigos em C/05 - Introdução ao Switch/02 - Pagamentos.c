#include <stdio.h>
#include <stdlib.h>



/*#########################################################################################################################################################
                                                     metodo para calcular o desconto a vista
  #########################################################################################################################################################*/
float pagamentoAvista (float valorCompra){
	return valorCompra - (valorCompra*0.1);
	
}

/*#########################################################################################################################################################
                                                     metodo para imprimir as possiveis parcelas 
  #########################################################################################################################################################*/
float Prazo(float valorCompra, int i, int quantParc){
	 
		
		 
	 while (i<= quantParc){
		printf(" %d - %.2f\n", i, valorCompra/i);
		i++;
	}	
	
	return valorCompra;
	
}

/*#########################################################################################################################################################
                                                     metodo para finalizar o pagamento a prazo
  #########################################################################################################################################################*/
void FinalizarPagamentoPrazo (float valorCompra, int quantParcMax){
	
	int parc;
	float valorFinal;

	
	do{
		printf("\n\n\n Digite a quantidade de parcelas :");
		scanf("%d", &parc);
		
		
		if(parc > quantParcMax){
			printf("\n\nA quantidade de parcelas nao pode ultrapassar a quantidade maxima");
			
		}
	}while((parc > quantParcMax));
	
	
	if (parc < 10){
		valorFinal = valorCompra;
	}
	else {
		valorFinal = valorCompra + valorCompra*0,05;
	}
	
	printf("\n\n\n                                             %d x - R$  %.2f",parc, valorFinal/parc);
	printf("\n\n\n                             O valor total das compras ficou: R$  %.2f", valorFinal);
}


/*#########################################################################################################################################################
                                                     metodo para inicializar o pagamento a prazo
  #########################################################################################################################################################*/
int pagamentoPrazo(float valorCompra){
	
	
	int quantParc = 1;
	
	if(valorCompra < 100){
		printf("1 - %.2f", valorCompra);
	
	}
	
    else if(valorCompra <= 500){
	
	     quantParc =  valorCompra/50;
	    valorCompra = Prazo(valorCompra, 1, quantParc);
    } 
    else{
        
	    valorCompra =  Prazo(valorCompra, 1, 10);
	    
	    float valorJuros = valorCompra + valorCompra*0.05;
	    quantParc =  valorJuros/50;
	
	    if(quantParc <= 24){     
	     valorCompra =  Prazo(valorJuros, 11, quantParc);
    	}
    	else{
    		valorCompra =  Prazo(valorJuros, 11, 24);
    		quantParc = 24;
		}
	    valorCompra = valorJuros;
	}	
    	
	
	FinalizarPagamentoPrazo (valorCompra, quantParc);
	return quantParc;
}

/*#########################################################################################################################################################
                                                     metodo para inicializar o pagamento 
  #########################################################################################################################################################*/
void Compras(){
	
	float valor, valorFinal;
	int tipo;
	printf("Digite qual o valor da compras:   ");
	scanf("%f", &valor);
	
	printf("\n\n\nAgora digite o tipo de desconto:  \n\n1- A vista \n2- Prazo\n\n");
	scanf("%d", &tipo);
	
	switch(tipo) {
	
	case 1:  	
		printf("\n\n                                      Pagamento a vista");
		valorFinal = pagamentoAvista(valor);
		printf("\n\n\n                             O valor total das compras ficou: R$  %.2f", valorFinal);
		break;
		
	case 2:  	
		printf("\n\n                           Pagamento a prazo\n");
		pagamentoPrazo(valor);
		break;	
		

		
	}
	
	
	
}

/*#########################################################################################################################################################
                                                     metodo para iniciar o sistema
  #########################################################################################################################################################*/
int main(int argc, char *argv[]) {
	
	printf("\n\n\n\n       ##########################################################################################################\n");
	printf("       ##########################################################################################################\n");
	printf("       ###                                                                                                    ###\n");
	printf("       ###                                                                                                    ###\n");
	printf("       ###                                          BOM DE COMPRAS                                            ###\n");
	printf("       ###                                                                                                    ###\n");
	printf("       ###                                                                                                    ###\n");
	printf("       ##########################################################################################################\n");
	printf("       ##########################################################################################################\n\n\n\n");
	
	
	
	Compras();
	
	
	return 0;
}
