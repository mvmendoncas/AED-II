#ifndef AVL_H
#define AVL_H

typedef int tipo_dado;

typedef struct no_avl{
	tipo_dado dado;
	int fb;
	struct no_avl *esq, *dir;
} no_avl;

typedef no_avl *arvore;

void inicializar(arvore *raiz);
arvore adicionar(tipo_dado valor, arvore raiz, int *cresceu);
arvore remover(tipo_dado valor, arvore raiz, int *diminuiu);

arvore rotacionar(arvore raiz);
arvore rotacao_simples_esquerda(arvore raiz);
arvore rotacao_simples_direita(arvore raiz);
arvore rotacao_dupla_esquerda(arvore raiz);
arvore rotacao_dupla_direita(arvore raiz);

int maior(tipo_dado a, tipo_dado b);
int altura(arvore raiz);
int maior_elemento(arvore raiz);
int menor_elemento(arvore raiz);

void inorder(arvore a);
void imprimir(arvore raiz);
void imprimir_elemento(arvore raiz);

#endif
