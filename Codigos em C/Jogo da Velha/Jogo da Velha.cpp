#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu();

//Este metodo tem como função imprimir o cabeçalho do inicio do jogo 
void imprimirCabecalho(){
	
		printf("\n\n\n\n\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n");
	printf("                #######                                                                  #######\n");
	printf("                #######                              JOGO                                #######\n");
	printf("                #######                               DA                                 #######\n");
	printf("                #######                              VELHA                               #######\n");
	printf("                #######                                                                  #######\n");
	printf("                ################################################################################\n");
	printf("                ################################################################################\n\n\n");
}

//essa função tem a serventia de iniciar o sistema para depois passar para o menu 
void inicio(){
	
	
	
	
	char h ='x';
	do{
	
            imprimirCabecalho();
	
	
	printf("\n\n\n\n                                              PRESSIONE C PARA COMECAR \n");
	printf("                                                        ");
	
		scanf(" %c", &h);
		system("cls");
} while(h != 'c' );

}

//essa função imprimi as regras para o jogador
void regras(){
	
	
	char h ='x';
	do{
		imprimirCabecalho();
	

	
	printf("                                                    REGRAS:           \n\n");
	
 	printf("  1- Neste jogo	participam duas pessoas,\n");
	printf("  2- Os participantes jogam alternadamente,\n");
    printf("  3- Cada participante deve usar um simbolo (X ou O),\n");
    printf("  4- O jogador 1 deve escolher se de começa usando o X ou o O, consequentemente o jogador 2 fica com outro simbolo\n");
    printf("  5- A cada jogada, deve-se preencher um dos espaços vazios,\n");
    printf("  6- Vence o jogador que conseguir formar primeiro uma linha com tres simbolos iguais,\n             horizontal,\n             vertical\n             diagonal"),
    
	
	printf("\n\n\n                                              PRESSIONE Z PARA VOLTAR PARA O MENU \n");
	printf("                                                        ");
	
		scanf(" %c", &h);
		system("cls");
} while(h != 'z' );
	
	menu ();
}

//essa função serve para selecionar o simbolo do primeiro jogador
char escolherJogador(){
	int x;
	do{
		system("cls");
	imprimirCabecalho();
	printf("\n\n                Escolha qual o primeiro jogador \n                1 para X \n                2 para O \n  ");
	
	
	scanf("%d", &x);
	
	switch(x){
	
	case 1 :
		return 'X';
     case 2 :	
	   return 'O';
     default: printf("Opcao invalida!\n\n\n");
	  	
}
}while(x != 1 || x!=2);
}
void limpar(char a[][3]){
	int L = 0;
	while  (L  < 3){
		int C =0;
       	while  (C  < 3){
		
	       a[L][C] = ' ';
	       C++ ;
	    }
	    
	    L++;
	}
}


//Essa função imprimi a matriz do jogo
void imprimir (char a[][3]){
	  system ("cls");
	printf("\n\n\n\n\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n\n\n\n");
	  int L = 0;	
	  while  (L  < 3){
		int C =0;
		printf ("                                                   ");
       	while  (C  < 3){
		
	       printf ("%c  ", a[L][C]);
	       if(C<2){ printf("|   ");}
	       C++ ;
	    }
	     if(L<2){
	    printf("\n                                                 _____________________ \n");}
	    L++;
	}
	
printf("\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n\n");	
}


// essa função escolhe qual a posição a ser jogada...
//p é o simbolo do jogador (X ou O) e j é o jogador (1 ou 2)
// vetorVerific serve para verificar se aquela posicao já foi jogada (ele não permite a jogada com numeros abaixo de 1 e acima de 9)
void escolherJogada(int vetorVerific[], char a[][3], char p, int j){
	
	int i =0;
	int x;
	printf("                    VEZ DO JOGADOR %d:         ", j);
	do{
	
	
	
	scanf("%d", &x);
	if(x <= 0 || x > 9){
		
		printf("                               Jogada invalida!\n                                                         ");
	}
	else if(vetorVerific[x] == 1){
		printf("                               Esse numero ja foi escolhido, escolha outro!\n                                                         ");
	}else{
		vetorVerific[x] = 1;
		i++;
	}
	
	} while(i == 0);
	switch(x){
		case 1: 
		a [0][0] =p; 
		break;
		
		case 2: 
		a [0][1] =p; 
		break;
		
		case 3: 
		a [0][2] =p; 
		break;
		
		case 4: 
		a [1][0] =p; 
		break;
		
		case 5: 
		a [1][1] =p; 
		break;
		
		case 6: 
		a [1][2] =p; 
		break;
		
		case 7: 
		a [2][0] =p; 
		break;
		
		case 8: 
		a [2][1] =p; 
		break;
		
		case 9: 
		a [2][2] =p; 
		break;
	}
	
}
//troca o simbolo do jogador (X ou O)
char trocarLetra(char p){
	
	if(p=='X'){
		return 'O';
	}
	return 'X';
}

//troca qual o jogador que deve jogar
int trocarJogador(int j){
	
	if(j==1){
		return 2;
	}
	return 1;
}


//imprimi qual foi o jogador vencedor
void vencedor(int j){
	system("cls");
	
	printf("\n\n\n\n\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n\n\n\n");
	printf("                                                  O JOGADOR  %d VENCEU!", j);
			
	printf("\n\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n\n\n\n");
}


//essa função tem como utilizade se já foi finalizada a partida e verifica se teve vencedor ou se deu velha
int verificaVencedor(char a[][3], int j, int x){
	
	//deu velha se a quantidade de jogadas já se encerrou
	// (lembrando que a contagem começa no zero, entao depois da ultima jogada, o contador estara em 8)
	if (x == 8){
		
		system("cls");
		imprimir (a);
	printf("\n\n\n\n\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n\n\n\n");
	printf("                                                  DEU VELHA!!!!");
			
	printf("\n\n\n\n                ################################################################################\n");
	printf("                ################################################################################\n\n\n\n");
		
	}
	
	// verificação da horizotal
	int i = 0;
	while (i<3){
	
	if(a[i][0] != ' '){
		if(a[i][0] == a[i][1] &&  a[i][1] == a[i][2]){
			imprimir (a);
			vencedor(j);
			return 10;
		} 
	}
	i++;
  }
  
  //verificação da vertical
  i = 0;
	while (i<3){
	
	if(a[0][i] != ' '){
		if(a[0][i] == a[1][i] &&  a[1][i] == a[2][i]){
			imprimir (a);
			vencedor(j);
			return 10;
		} 
	}
	i++;
  }
  
  //verificação da primeira diagonal
  if(a[0][0] != ' '){
		if(a[0][0] == a[1][1] &&  a[1][1] == a[2][2]){
			imprimir (a);
			vencedor(j);
			return 10;
		} 
	}
	
  // verificação da segunda diagonal
  if(a[0][2] != ' '){
		if(a[0][2] == a[1][1] &&  a[1][1] == a[2][0]){
			imprimir (a);
			vencedor(j);
			return 10;
		} 
	}
  
  //o retonrno desta função serve para parar ou não o while que existe na função partida
  //assim, se retornar 10, é pq a partida tem que ser finalizada 
  //se retornar x, é a quantidade de jogadas que já tiveram e assim pode prosseguir
  return x;
}

//função que gera 1 partida
void partida(){
	
	int v[10] = {0,0,0,0,0,0,0,0,0,0};
	char a [3][3];
	limpar(a);
	int L, j = 1;
	char p = escolherJogador();
	imprimir (a);
	L = 0;
	while ( L  < 9){
		escolherJogada(v,a, p, j);
		imprimir (a);
		L = verificaVencedor(a,  j, L);
		if(L < 9){
     		j = trocarJogador(j);
	     	p = trocarLetra(p);
		}
	
	    L++;
	  }
	  
	  char h;
	  do{
	   
	   vencedor(j);
	   
	  	printf("\n\n\n                                              PRESSIONE Z PARA VOLTAR PARA O MENU \n");
	    printf("                                                        ");
	
		scanf(" %c", &h);
		system("cls");
} while(h != 'z' );
	
	system("cls");
	  menu();		
}

//funão para criar a informção sobre o desenvolvedor
void infor(){
	char h ='x';
	do{
		imprimirCabecalho();
	

	
	printf("                                                    REGRAS:           \n\n");
	
 	printf("                        Codigo desenvolvido para a disciplina de Logica de Programacao \n ");
 	printf("                                             SENAI - Feira de Santana \n\n\n                ");
 	printf("                             Henderson Chalegre\n");
 	printf("                                    Professor e Engenheiro de Computacao                ");
    
	
	printf("\n\n\n                                      PRESSIONE Z PARA VOLTAR PARA O MENU \n");
	printf("                                                        ");
	
		scanf(" %c", &h);
		system("cls");
} while(h != 'z' );
	
	menu ();
	
}

//funcao para criar o menu
void menu (){
	
	imprimirCabecalho();
	
	printf("      Escolha uma opcao:       \n\n\n       1- Nova Partida \n       2- Regras \n       3- Sobre o desenvolvedor \n       4-Sair\n");
	int x;
	scanf("%d", &x);
	
	switch(x){
		case 1: partida();break;
		case 2: regras();break;
		case 3: infor();break;
		case 4: exit(0);break;
		
		
	}
}

//funcao principal 
int main(int argc, char *argv[]) {
	
    inicio();
	menu ();
    
	

	
	return 0;
}
