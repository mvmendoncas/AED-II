#ifndef BST_H
#define BST_H
#define TRUE 1
#define FALSE 0


typedef struct no
{
	int valor;
	struct no* esq, *dir;

} no;

typedef no* arvore;

//Métodos de modficação da ávores
arvore inserir(arvore a, int v);
arvore remover(arvore a, int v);

//Métodos de busca
arvore buscar(arvore a, int v);
arvore acharMaior(arvore a);
arvore acharMenor(arvore a);
arvore sucessor(arvore a, int n);

//Métodos de verificação
int qtdPrimos(arvore a);
int verificaPrimo(int v);
int qtdDeNos(arvore a);

//Métodos de impressão
void preorder(arvore a);
void inorder(arvore a);
void posorder(arvore a);
void reverso(arvore a);
void caminho(arvore a, int v);



 
//calcular altura da árvore

#endif
