#include "bst.h"
#include "bst.c"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


int main(int argc, char const *argv[]){
 	arvore a;
 	//Inicialização da árvore vazia
 	a = NULL;
 	int opcao;
 	int valor;
 	int numSucessor;
 	int numCaminho;
 	int numRemover;
 	int primos;
 	
 	while(1){
 		scanf("%d", &opcao);
 		switch(opcao){
 			case 1:
 				scanf("%d", &valor);
 				a = inserir(a, valor);
 				break;
 			case 2:
 				preorder(a);
 				printf("\n");
 				break;
 			case 3:
 				inorder(a);
 				printf("\n");
 				break;
 			case 4:
 				posorder(a);
 				printf("\n");
 				break;
 			case 5:
 				reverso(a);
 				printf("\n");
 				break;
 			case 6: 
 				primos = qtdPrimos(a);
 				printf("%d\n", primos);
 				break;
 			case 7:
 				scanf("%d", &numSucessor);
 			 	arvore v = sucessor(a, numSucessor);
 			 	if(v == NULL) {
 			 		printf("-1\n");
 			 	}else{
 				printf("%d\n", v->valor);
 				}
 				break;
 			case 8:
 				scanf("%d", &numCaminho);
 				caminho(a, numCaminho);
 				printf("\n");
 				break;
 			case 9:
 				scanf("%d", &numRemover);
 				remover(a, numRemover);
 				printf("\n");
 				break;
 			case 99:
 				exit(0);
 		
 		}
 			
 	
 	
 	}
	
	return 0;

}
