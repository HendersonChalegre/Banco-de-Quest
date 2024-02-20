#include <stdio.h>
#include <stdlib.h>




/*#########################################################################################################################################################
                                                     metodo para calcular o desconto do cliente vip
  #########################################################################################################################################################*/
float descontoVip (float valorCompra){
	return valorCompra - (valorCompra*0.1);
	
}

/*#########################################################################################################################################################
                                                     metodo para calcular o desconto do funcionario
  #########################################################################################################################################################*/
float descontoFuncionario (float valorCompra){
	return valorCompra - (valorCompra*0.05);
	
}


/*#########################################################################################################################################################
                                                     metodo para iniciar o calculo do desconto
  #########################################################################################################################################################*/
void Compras(){
	
	float valor, valorComDesconto;
	int tipo;
	printf("Digite qual o valor da compras:   ");
	scanf("%f", &valor);
	
	printf("\n\n\nAgora digite o tipo de desconto:  \n\n1- Comum \n2- Funcionario  \n3- Vip \n\n");
	scanf("%d", &tipo);
	
	switch(tipo) {
	
	case 1:  	
		printf("\n\n                           Esse cliente nao tem descontos em suas compras");
		valorComDesconto = valor;
		break;
		
	case 2:  	
		printf("\n\n                           Funcionarios tem direito a 5%% de desconto");
		valorComDesconto = descontoFuncionario(valor);
		break;	
		
	case 3:  	
		printf("\n\n                           Clientes Vips tem direito a 10%% de desconto");
		valorComDesconto = descontoVip(valor);
		break;
		
	}
	
	printf("\n\n\n                             O valor total das compras ficou: R$  %.2f", valorComDesconto);
	
}

/*#########################################################################################################################################################
                                                     metodo para iniciar o sistema
  #########################################################################################################################################################*/
int main(int argc, char *argv[]) {
	
	printf("\n\n\n\n                                                        DESCONTOS\n\n\n");
	
	Compras();
	return 0;
}
