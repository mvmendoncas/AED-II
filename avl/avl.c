#include "avl.h"
#include <stdio.h>
#include <stdlib.h>


void inicializar(arvore *raiz) {
	*raiz = NULL;
}

arvore adicionar(tipo_dado valor, arvore raiz, int *cresceu){
	//Caso base da recursão: ou a árvore está vazia ou chegou em uma folha 
	if(raiz == NULL){
		arvore novo = malloc(sizeof(struct no_avl));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		novo->fb = 0;
		*cresceu = 1;
		return novo;
	}
	//Caso recursivo , se a raiz (relativa) não for NULL,
	//acrescenta-se o elemento na sub-árvore direita ou esquerda
	//dependendo do valor a ser inserido. Elementos maiores vão
	//para direita, menores para esquerda.
	if(valor > raiz->dado){
		//Elemento maior => adicionar na direita
		raiz->dir = adicionar(valor, raiz->dir, cresceu);
		//Após adicionar o elemento na direita,
		//verifica se a sub-árvore da direita cresceu.
		//Em caso afirmativo, ajusta-se o fator de balanço
		//da raiz relativa
		if(*cresceu){
			//Chegando neste ponto, sabe se que:
			//a) 0 elemento foi inserido na sub-árvore direita; e
			//b) A sub-árvore a direita cresceu
			switch(raiz->fb){
				case 0:
					raiz->fb = 1;
					*cresceu = 1;
					break;
				case -1:
					raiz->fb = 0;
					*cresceu = 0;
					break;
				case 1:
					*cresceu = 0;
					//raiz->fb = 2;
					//O fator de balanço passaria ao valor 2
					//Prove que um movimento de rotação é suficiente para rebalancear uma árvore AVL após uma operação de inserir elemento.
					return rotacionar(raiz);
							
			}
		
		}
	
	} else {
	
		//Elemento menor que raiz relativa, fazer o caso simétrico
		raiz->esq = adicionar(valor, raiz->esq, cresceu);
		if(*cresceu){
			switch(raiz->fb){
				case 0:
					raiz->fb = -1;
					*cresceu = 1;
					break;
				case -1:
					*cresceu = 0;
					return rotacionar(raiz);
				case 1:
					raiz->fb = 0;
					*cresceu = 0;
					break;
					
			}
		}
	}
	//Se tirar isso, caga a árvore toda
	return raiz;

}


//Verifica que tipo de rotação é e depois rotaciona
arvore rotacionar(arvore raiz){
	//fb maior que zero => rotação esquerda
	if(raiz->fb > 0){
		switch(raiz->dir->fb){
			//o zero "conta" como rotação simples.
			//Só ocorre no remover
			case 0:
			case 1:
				return rotacao_simples_esquerda(raiz);
			case -1:
				return rotacao_dupla_esquerda(raiz);
		
		}
	} else {
		//implementar o simétrico
		switch(raiz->esq->fb){
			case 0:
			case -1:
				return rotacao_simples_direita(raiz);
			case 1:
				return rotacao_dupla_direita(raiz);
		}
	}
}

//Criar variável paralela ao "cresceu" da função adicionar na função remover para manter o controle de balanceamento
/*----------
Só está implementada a "base" do remover da BST.
Incluir a variável de controle "diminuir" similar a "cresceu do adicionar.
------*/
arvore remover(tipo_dado valor, arvore raiz, int *diminuiu){
	 if(raiz == NULL) {
        *diminuiu = 0;
        return NULL;
    }

    if(raiz->dado == valor) {
        *diminuiu = 1;

        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }

        if(raiz->esq != NULL && raiz->dir == NULL){
            arvore esquerdo = raiz->esq;
            free(raiz);
            return esquerdo;
        }

        if(raiz->dir != NULL && raiz->esq == NULL){
            arvore direito = raiz->dir;
            free(raiz);
            return direito;
        }

        if(raiz->esq != NULL && raiz->dir != NULL){
            arvore aux = raiz->esq;

            while(aux->dir != NULL)
                aux = aux->dir;

            raiz->dado = aux->dado;
            aux->dado = valor;
            raiz->esq = remover(valor, raiz->esq, diminuiu);

            if(*diminuiu == 1){
                switch (raiz->fb) {
                    case 0:
                        raiz->fb = 1;
                        *diminuiu = 0;
                        break;
                    case -1:
                        raiz->fb = 0;
                        *diminuiu = 1;
                        break;
                    case 1:
                        if(raiz->dir->fb != 0){
                            *diminuiu = 1;
                        }else{
                            *diminuiu = 0;
                        }
                        return rotacionar(raiz);
                }
            }

            return raiz;
        }
	}
	 if(valor > raiz->dado){
            raiz->dir = remover(valor, raiz->dir, diminuiu);
           
            if(*diminuiu){ //remover um numero a direita
                switch(raiz->fb){
                    case 0: //a arvore estava balanceada e diminuiu um ponto para a direita
                        raiz->fb = -1;
                        *diminuiu = 0;
                        break;
                    case 1: // a arvore estava pendendo um ponto para a direita e ficou balanceada
                        raiz->fb = 0;
                        *diminuiu = 1;
                        break;
                    case -1: // a arvore estava pendendo um ponto para a esquerda e agora irá pender dois
                        *diminuiu = 1;
                        return rotacionar(raiz);
                }
               
            }
        }
        
        else{
            raiz->esq = remover(valor, raiz->esq, diminuiu);
            
            if(*diminuiu){
                switch(raiz->fb){
                    case 0: // a arvore estava balanceada e diminuiu um ponto para a esquerda
                        raiz->fb = 1;
                        *diminuiu = 0;
                        break;
                    case -1: // a arvore estava pendendo um ponto para a esquerda e ficou balanceada
                        raiz->fb = 0;
                        *diminuiu = 1;
                        break;
                    case 1: // a arvore estava pendendo um ponto para a direita e agora irá pender dois
                        *diminuiu = 1;
                        return rotacionar(raiz);
                }
            }
        }
	return raiz;
} 

arvore rotacao_simples_esquerda(arvore raiz){
	arvore p, u, t1, t2, t3;
    	//inicializa os ponteiros
	p = raiz;
    u = p->dir;
    t1 = p->esq;
    	//t2 e t3 não estão sendo modificados. 
    	//só estão aqui por questões didáticas
    	t2 = u->esq;
    	t3 = u->dir;

    	//Atualiza os ponteiros
	p->dir = t2;
    u->esq = p;
    
    	//Atualiza os fatores de balanço de acordo com o fb de u
    	//Esses valores vieram dos cálculos demonstrados na aula
	if(u->fb == 1) {
		p->fb = 0;
		u->fb = 0;
	} else{
        //0 - só ocorre no remover
		p->fb = 1;
		u->fb = -1;
	}	
    
    //Retorna a raiz da sub-árvore resultante, ou seja "u".
	return u;

}

arvore rotacao_simples_direita(arvore raiz){
	arvore p, u, t1, t2, t3;
    //inicializa os ponteiros
	p = raiz;
    u = p->esq;
    t1 = u->esq;
    	//t2 e t3 não estão sendo modificados. 
    	//só estão aqui por questões didáticas
    	t2 = u->dir;
    	t3 = u->esq;

    	//Atualiza os ponteiros
	p->esq = t2;
    u->dir = p;
    
    	//Atualiza os fatores de balanço de acordo com o fb de u
    	//Esses valores vieram dos cálculos demonstrados na aula
	if(u->fb == -1) {
		p->fb = 0;
		u->fb = 0;
	} else{
        //0 - só ocorre no remover
		p->fb = -1;
		u->fb = 1;
	}	
    
    //Retorna a raiz da sub-árvore resultante, ou seja "u".
	return u;
	

}


arvore rotacao_dupla_esquerda(arvore raiz){
	arvore p, u, v, t2, t3;
    	//inicializa os ponteiros
	p = raiz;
	u = p->dir;
    v = u->esq;
    
    	//t2 e t3 não estão sendo modificados. 
    	//só estão aqui por questões didáticas
    
    t2 = v->esq;
    t3 = v->dir;

    	//Atualiza os ponteiros
    u->esq = v->dir;
    v->dir = u;
    
	p->dir = t2;
	v->esq = p;
    
    	//Atualiza os fatores de balanço de acordo com o fb de u
    	//Esses valores vieram dos cálculos demonstrados na aula
	switch(v->fb){
        case -1:
            p->fb = 0;
            u->fb = 1;
            v->fb = 0;
            break;
        case 1:
            p->fb = -1;
            u->fb = 0;
            v->fb = 0;
            break;
        case 0:
            p->fb = 0;
            u->fb = 0;
            v->fb = 0;
            break;
    }	
    
    //Retorna a raiz da sub-árvore resultante, ou seja "u".
	return v;

}


arvore rotacao_dupla_direita(arvore raiz){
	arvore p, u, v, t2, t3;
	
	//Inicializa os ponteiros
	p = raiz;
	u = p->esq;        
	v = u->dir;
	
	t2 = v->esq;
	t3 = v->dir;
	
	//Atualizar os ponteiros
    
    u->dir = v->esq;
	v->esq = u;
    
	p->esq = v->dir;
	v->dir = p;
	
	//Atualizar os fatores de balanço de acordo com o fb de u
	//Esses valores vieram dos cálculos  demonstrados na aula
	
	switch(v->fb){
		case 0:
			raiz->fb = 0;
			p->fb = 0;
			u->fb = 0;
			break;
		case 1:
			raiz->fb = 0;
			p->fb = -1;
			u->fb = 0;
			break;
		case -1:
			raiz->fb = 1;
			p->fb = 0;
			u->fb = 0;
			break;
	
	}
	return v;
}


/*---
Imprime a árvore de modo a facilitar a visualização da estrutura, incluindo também o fator de balanço.
---*/
void imprimir(arvore raiz) {
	printf("(");
	if(raiz != NULL) {
		imprimir_elemento(raiz);
		imprimir(raiz->esq);
		imprimir(raiz->dir);
	}
	printf(")");
}

/*---
Auxiliar de imprimir
---*/
void imprimir_elemento(arvore raiz) {
	printf("%d [%d]", raiz->dado, raiz->fb);
}


int maior(tipo_dado a, tipo_dado b) {
	if(a > b)
		return a;
	else
		return b;
}

//Retorna o valor do menor elemento em uma sub-árvore
//Caso a sub-árvore esteja vazia, a função deve retornar o valor -1
int maior_elemento(arvore raiz) {
	if(raiz == NULL)
		return -1;
	if(raiz->dir == NULL){
		return raiz->dado;
	} else {
		return maior_elemento(raiz->dir);
	}
	
}

int menor_elemento(arvore raiz) {
	if(raiz == NULL)
		return -1;
	if(raiz->esq == NULL){
		return raiz->dado;
	} else {
		return maior_elemento(raiz->esq);
	}
	
}



void inorder(arvore a){
	if (a != NULL){
		inorder(a->esq);
		printf("[%d]", a->dado);
		inorder(a->dir);	
	}

}












