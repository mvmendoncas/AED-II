#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>




arvore inserir(arvore a, int v){
	//caso base de recursão 
	//inserir numa (sub)árvore vazia 
	if(a == NULL){
		//alocar espaço para o nó 
		arvore no = (arvore) malloc(sizeof(no));
		//inicializar os valores das variáveis membro
		no->valor = v;
		no->esq = NULL;
		no->dir = NULL;
		return no;
	} else {
		//se o valor que eu quero inserir (v) for 
		//menor que a raíz relativa (a->arvore), inserir 
		// na sub-árvore a esquerda
		if(v < a->valor){
			a->esq = inserir(a->esq, v);
		} else {
			a->dir = inserir(a->dir, v);
		}
		
		return a;
	}
	
	return NULL;
}

arvore buscar(arvore a, int v){
	if(a == NULL || v == a->valor){
		return a;
	
	}	
	if(v < a->valor){
		return buscar(a->esq, v);
	} else {
		return buscar(a->dir, v);
	
	}


}

arvore acharMaior(arvore a){
	while(a->dir != NULL)
		a = a->dir;
	
	return a;
}

arvore acharMenor(arvore a){
	while (a->esq != NULL)
		a = a->esq;
		
	return a;
}

arvore remover(arvore a, int v){
	//Caso base árvore vazia => Não faz nada
	if(a == NULL)
		return NULL;
		
	//Caso base elemento encontrado => Implementa toda a lógica explicada no desenho
	if(a->valor == v){
		//Elemento encontrado 
		//Verifica a quantidade de filhos
		
		
		//Zero filhos
		if(a->esq == NULL && a->dir == NULL){
			free(a);
			return NULL;
		}
		//Possui um filho esquerdo
		if(a->esq != NULL && a->dir == NULL){
			arvore esq = a->esq;
			free(a);
			return esq;
		}
		
		//Possui um filho direito
		if(a->esq == NULL && a->dir != NULL){
			arvore dir = a->dir;
			free(a);
			return dir;
		}
		
		//Possui dois filhos 
		arvore temp = acharMaior(a->esq);
		a->valor = temp->valor;
		a->esq = remover(a->esq, temp->valor);
		return a;
	} else {
	
		if(v < a->valor){
			a->esq = remover(a->esq, v);
		} else {
			a->dir = remover(a->dir, v);
		}
		
		return a;
	}

}

arvore sucessor(arvore a, int n){

	//Verificar se o valor pedido existe na árvore	
	arvore temp = buscar(a, n);
	if(temp ==  NULL)
		return NULL;
		
	//Caso a sub-árvore a direita não seja vazia, seu sucessor será o nó da extrema esquerda na sub-árvore a direita.
	if(temp->dir != NULL){
		return acharMenor(temp->dir);
	} else {
		arvore sucessor = NULL;
		arvore ancestral = a;
		while(ancestral != temp){
			if(temp->valor < ancestral->valor){				//Caso a sub-árvore a direita não seja vazia, então 
				sucessor = ancestral;					//o sucessor é o ancestral mais abaixo de v.
				ancestral = ancestral->esq;
			} else {
				ancestral = ancestral->dir;
			}
		}
		return sucessor;
	
	}

}

int verificaPrimo(int v){
	int cont = 0;
	for (int i = 1; i <=v; i++){
		if(v % i == 0){
			cont++;
		}
	} 
	return cont;
}

int qtdPrimos(arvore a){
	//árvore vazia <= 0
	if(a == NULL){
		return 0;
	}
	//r, e, q se a raíz é primo => 1 +qtdPrimos(e)+qtdPrimos(d)
	// Senão, => qtdPrimos(e) + qtdPrimos(d)
	if(verificaPrimo(a->valor) == 2){
		return 1 + qtdPrimos(a->esq) + qtdPrimos(a->dir);
	} else {
		return 0 + qtdPrimos(a->esq) + qtdPrimos(a->dir);
	}
}

int qtdDeNos(arvore a){
	if(a == NULL){
		return 0;
	} else {
		return 1 + qtdDeNos(a->esq) + qtdDeNos(a->dir);
	}
}


void preorder(arvore a){
	if(a != NULL){
		printf("[%d]", a->valor);
		preorder(a->esq);
		preorder(a->dir);
	}

}

void inorder(arvore a){
	if (a != NULL){
		inorder(a->esq);
		printf("[%d]", a->valor);
		inorder(a->dir);	
	}

}

void posorder(arvore a){
	if (a != NULL){
		inorder(a->esq);
		inorder(a->dir);
		printf("[%d]", a->valor);	
	}

}

void reverso(arvore a){
	if (a != NULL){
		reverso(a->dir);
		printf("[%d]", a->valor);
		reverso(a->esq);		
	}
}

void caminho(arvore a, int v){
	if(a != NULL){
		if(a->valor > v){
			printf("[%d]", a->valor);
			caminho(a->esq, v);
		} else {
			printf("[%d]", a->valor);
			caminho(a->dir, v);
		}
	} 

}








