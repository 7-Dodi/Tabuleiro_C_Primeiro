#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int LIN=10;
const int COL=10;
void imprimir (char mat[LIN][COL]){
	int k, x;
	for(k=0;k<LIN;k++){
		for(x=0;x<COL;x++){
			if(x<COL-1){
				printf("%c  ", mat[k][x]);
			}
			else{
				printf("%c\n", mat[k][x]);
			}
		}
	}
}
void campo (int mat[LIN][COL], int lin, int col, int *quant){
	int x, k, cont=0;
	if(mat[lin][col]==1){
		printf("\nJogo encerrado! Vc perdeu.");
		int num=1;
		int final=fim (& num);
	}
	else if(mat[lin][col]==0){
	     for(k=col;k<col+2;k++){
	    	for(x=lin;x<lin+2;x++){
	    		quant++;
				if(mat[k][x]==1){
					cont++;}
		}
	 }	
	 printf("\nTem %d bombas perto\n", cont);
	 printf("\n");
	 }
}
int fim (int *num){
	int soma= *num+0;
	return soma;
}
void main(){
	int k, x, mat[LIN][COL]; 
	char mat2[LIN][COL];
	srand(time(NULL));
	for(k=0;k<LIN;k++){
		for(x=0;x<COL;x++){
			mat[k][x]=0;
			mat[rand()%10] [rand()%10]= 1;
			mat2[k][x]= '*';
		}
	}
	int num, lin, col;
	do{
		int final=0, quant=0;
		printf("\n\n############## TABULEIRO ################\n");
		printf("\n\n______________ REGRAS __________________\n\n");
		printf("\n1-O jogo consiste em escolher uma posicao dentro de uma matriz;\n2-Se essa posicao, for igaul a zero (0), o usuario pode continuar a jogar;");
		printf("\n3-Caso a posicao for igual a um (1), o usuario perde o jogo;\n4-O jogador ganhar ao encontrar o zero mais de 5 vezes.");
		printf("\nClique em qualquer tecla para continuar");
		getch();
		printf("\n\n########## Menu ###########\n\n");
		printf("Para iniciar o jogo tecle 1;\nPara finalizar tecle 0.\n");
		scanf("%d", & num);
		if(num==1){
			imprimir(mat2);
		}
		while(final!=1){
			printf("\nInforme a posicao da linha e a coluna:");
			scanf("%d%d", &lin, & col);
			printf("\n");
			campo ( mat, lin, col, & quant);
		    final= mat[lin][col];
		    if(quant==5){
				printf("\n\nParabens!!! Voce Ganhou!!!");
			}
		}
		printf("\n\n########## 	Quer tentar outra? ###########\n\n");
		printf("Para jogar novamente tecle 1;\nPara finalizar tecle 0.\n");
		scanf("%d", & num);	
	}
	while(num!=0);
	printf("\nJogo sendo finalizado, obrigado!!!!");
	printf("\n\nJogo em desenvolvimento, qualquer erro pesso que me mande o retorno.... clique em qualquer tecla para terminar");
	getch();
}
