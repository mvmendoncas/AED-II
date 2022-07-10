#include <stdio.h>
#include <stdlib.h>
#include "arvore_rb.h"

arvore no_null;


void inicializar(arvore *raiz) {
    *raiz = NULL;
    no_null = (arvore) malloc(sizeof(struct no_bst));
    no_null->cor = DUPLO_PRETO;
    no_null->dado = 0;
    no_null->esq = NULL;
    no_null->dir = NULL;
}

void adicionar(int valor, arvore *raiz) {
    arvore posicao, pai, novo;
    posicao = *raiz;
    pai = NULL;
    while (posicao != NULL) {
        pai = posicao;
        if (valor > posicao->dado)
            posicao = posicao->dir;
        else
            posicao = posicao->esq;
    }

    //Após achar a posição, inicializa o novo elemento
    novo = (arvore) malloc(sizeof(struct no_bst));
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = pai;
    novo->cor = VERMELHO;

    if (eh_raiz(novo))
        *raiz = novo;
    else {
        if (valor > pai->dado)
            pai->dir = novo;
        else
            pai->esq = novo;
    }

    //Após inserir, verifica e ajusta a árvore resultante
    ajustar(raiz, novo);
}


void ajustar(arvore *raiz, arvore elemento) {
    while (cor(elemento->pai) == VERMELHO && cor(elemento) == VERMELHO) {
        //Caso 1
        if (cor(tio(elemento)) == VERMELHO) {
            tio(elemento)->cor = PRETO;
            elemento->pai->cor = PRETO;
            elemento->pai->pai->cor = VERMELHO;
            elemento = elemento->pai->pai;
            continue;
        }
        //caso 2a: rotação simples direita
        if (eh_filho_esquerdo(elemento) && eh_filho_esquerdo(elemento->pai)) {
            rotacao_simples_direita(raiz, elemento->pai->pai);
            elemento->pai->cor = PRETO;
            elemento->pai->dir->cor = VERMELHO;
            continue;
        }
        //caso 2b: rotação simples esquerda
        if (eh_filho_direito(elemento) && eh_filho_direito(elemento->pai)) {
            rotacao_simples_esquerda(raiz, elemento->pai->pai);
            elemento->pai->cor = PRETO;
            elemento->pai->esq->cor = VERMELHO;
            continue;
        }
        //caso 3a: rotação dupla direita
        if (eh_filho_direito(elemento) && eh_filho_esquerdo(elemento->pai)) {

            rotacao_dupla_direita(raiz, elemento->pai->pai);
            elemento->cor = PRETO;
            elemento->dir->cor = VERMELHO;
            continue;
        }
        //caso 3b: rotação dupla esquerda
        if (eh_filho_esquerdo(elemento) && eh_filho_direito(elemento->pai)) {

            rotacao_dupla_esquerda(raiz, elemento->pai->pai);
            elemento->cor = PRETO;
            elemento->esq->cor = VERMELHO;
            continue;
        }
    }

    (*raiz)->cor = PRETO;

}

void rotacao_simples_direita(arvore *raiz, arvore pivo) {
    arvore u, t1;
    u = pivo->esq;
    t1 = u->dir;

    /*Para fazer a ligação da raiz da sub-árvore resultante com o seu pai, é preciso saber se o pivot p era um filho esquerdo ou direito*/
    int posicao_pivo_esq = eh_filho_esquerdo(pivo);

    //Atualização dos ponteiros
    pivo->esq = t1;
    if (t1 != NULL)
        t1->pai = pivo;

    u->dir = pivo;

    u->pai = pivo->pai;
    pivo->pai = u;



    //Se não existir árvore acima de u, u passa a ser a raiz da árvore
    if (eh_raiz(u))
        *raiz = u;
    else {
        //Caso contrário (se existir) é preciso ligar o restante da árvore a esta sub-árvore, resultante da rotação
        if (posicao_pivo_esq)
            u->pai->esq = u;
        else
            u->pai->dir = u;
    }
}

void rotacao_simples_esquerda(arvore *raiz, arvore pivo) {
    arvore u, t1;
    u = pivo->dir;
    t1 = u->esq;

    /*Para fazer a ligação da raiz da sub-árvore resultante com o seu pai, é preciso saber se o pivot p era um filho esquerdo ou direito*/
    int posicao_pivo_esq = eh_filho_esquerdo(pivo);

    //Atualização dos ponteiros
    pivo->dir = t1;
    if (t1 != NULL)
        t1->pai = pivo;

    u->esq = pivo;

    u->pai = pivo->pai;
    pivo->pai = u;



    //Se não existir árvore acima de u, u passa a ser a raiz da árvore
    if (eh_raiz(u))
        *raiz = u;
    else {
        //Caso contrário (se existir) é preciso ligar o restante da árvore a esta sub-árvore, resultante da rotação
        if (posicao_pivo_esq)
            u->pai->esq = u;
        else
            u->pai->dir = u;
    }
}

void rotacao_dupla_direita(arvore *raiz, arvore pivo) {
    arvore u, v, t1, t2, t3;
    u = pivo->esq;
    v = u->dir;

    t1 = v->esq;
    t2 = v->dir;
    t3 = pivo->dir;

    /*Para fazer a ligação da raiz da sub-árvore resultante com o seu pai, é preciso saber se o pivot p era um filho esquerdo ou direito*/
    int posicao_pivo_esq = eh_filho_esquerdo(pivo);

    //Atualização dos ponteiros
    pivo->esq = v;
    v->esq = u;
    u->dir = t1;
    pivo->esq = t2;
    v->dir = pivo;
    if (t1 != NULL)
        t1->pai = u;

    if (t2 != NULL)
        t2->pai = pivo;

    if (t3 != NULL)
        t3->pai = pivo;

    v->pai = pivo->pai;
    pivo->pai = v;
    u->pai = v;

    //Se não existir árvore acima de u, u passa a ser a raiz da árvore
    if (eh_raiz(v))
        *raiz = v;
    else {
        //Caso contrário (se existir) é preciso ligar o restante da árvore a esta sub-árvore, resultante da rotação
        if (posicao_pivo_esq)
            v->pai->esq = v;
        else
            v->pai->dir = v;
    }
}

void rotacao_dupla_esquerda(arvore *raiz, arvore pivo) {
    arvore u, v, t1, t2, t3;
    u = pivo->dir;
    v = u->esq;

    t1 = v->esq;
    t2 = v->dir;
    t3 = u->dir;

/*Para fazer a ligação da raiz da sub-árvore resultante com o seu pai, é preciso saber se o pivot p era um filho esquerdo ou direito*/
    int posicao_pivo_esq = eh_filho_esquerdo(pivo);

    //Atualização dos ponteiros
    pivo->dir = v;
    v->dir = u;                    //QUALQUER COISA O ERRO TÁ AQUI
    u->esq = t2;
    pivo->dir = t1;
    v->esq = pivo;
    if (t1 != NULL)
        t1->pai = pivo;

    if (t2 != NULL)
        t2->pai = u;

    if (t3 != NULL)
        t3->pai = u;

    v->pai = pivo->pai;
    pivo->pai = v;
    u->pai = v;

    //Se não existir árvore acima de u, u passa a ser a raiz da árvore
    if (eh_raiz(v))
        *raiz = v;
    else {
        //Caso contrário (se existir) é preciso ligar o restante da árvore a esta sub-árvore, resultante da rotação
        if (posicao_pivo_esq)
            v->pai->esq = v;
        else
            v->pai->dir = v;
    }
}


enum cor cor(arvore elemento) {
    enum cor c;
    if (elemento == NULL)
        c = PRETO;
    else
        c = elemento->cor;
    return c;
}

arvore tio(arvore elemento) {
    return irmao(elemento->pai);
}

arvore irmao(arvore elemento) {
    if (eh_filho_esquerdo(elemento))
        return elemento->pai->dir;
    else
        return elemento->pai->esq;
}

arvore avo(arvore elemento) {
    if (elemento != NULL && elemento->pai != NULL)
        return (elemento->pai->pai);
    else
        return NULL;

}


int eh_raiz(arvore elemento) {
    return (elemento->pai == NULL);
}

int eh_filho_esquerdo(arvore elemento) {
    return (elemento->pai != NULL && elemento == elemento->pai->esq);
}

int eh_filho_direito(arvore elemento) {
    return (elemento->pai != NULL && elemento == elemento->pai->dir);
}


void imprimir_elemento(arvore raiz) {
    switch (raiz->cor) {
        case PRETO:
            printf("\x1b[30m[%d]\x1b[0m", raiz->dado);
            break;
        case VERMELHO:
            printf("\x1b[31m[%d]\x1b[0m", raiz->dado);
            break;
        case DUPLO_PRETO:
            printf("\x1b[32m[%d]\x1b[0m", raiz->dado);
            break;
    }
}

void imprimir(arvore raiz) {
    printf("(");
    if (raiz != NULL) {
        imprimir_elemento(raiz);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
    printf(")");
}


void remover(int valor, arvore *raiz) {
    arvore posicao;
    posicao = *raiz;

    while (posicao != NULL) {
        if (valor == posicao->dado) {
            if (posicao->esq == NULL && posicao->dir == NULL) {   //elemento nao possui filhos
                if (eh_raiz(posicao)) {   //remove raiz sem filhos
                    *raiz = NULL;
                    free(posicao);
                    break;
                }
                //remove elemento que nao possui filhos e nao eh raiz
                if (posicao->cor == VERMELHO) {   //se for VERMELHO, apenas remove e atualiza o ponteiro para o pai
                    if (eh_filho_esquerdo(posicao)) {
                        posicao->pai->esq = NULL;
                    } else {
                        posicao->pai->dir = NULL;
                    }
                    free(posicao);
                    break;
                } else {      //se for PRETO, substitui pelo DUPLO_PRETO e ajusta a arvore
                    no_null->cor = DUPLO_PRETO;
                    no_null->pai = posicao->pai;
                    if (eh_filho_esquerdo(posicao)) {
                        posicao->pai->esq = no_null;
                    } else {
                        posicao->pai->dir = no_null;
                    }
                    reajustar(raiz, no_null);
                    break;
                }
            }
            if (posicao->esq == NULL) {   //elemento possui apenas um filho, o direito
                arvore temp = posicao->dir;
                posicao->dado = temp->dado;
                posicao->cor = PRETO;
                posicao->dir = NULL;

                free(temp);

                break;
            }
            if (posicao->dir == NULL) {   //elemento possui apenas um filho, o esquerdo
                arvore temp = posicao->esq;
                posicao->dado = temp->dado;
                posicao->cor = PRETO;
                posicao->esq = NULL;

                free(temp);
                break;
            }
            //elemento possui dois filhos
            posicao->dado = maior_elemento(posicao->esq);
            remover(posicao->dado, &(posicao->esq));
        }
        if (valor > posicao->dado) {      //elemento maior que o no atual
            posicao = posicao->dir;
        } else {                          //elemento menor que o no atual
            posicao = posicao->esq;
        }
    }
}

/*Realiza a correção da árvore após a remoção de um elemento preto que não possui filhos, ou seja, elimina o nó null o duplo-preto.*/


void reajustar(arvore *raiz, arvore elemento) {
//	cor(irmao(elemento)->direito), cor(irmao(elemento)->esquerdo));
    //caso 1
    if (eh_raiz(elemento)) {
        retira_duplo_preto(raiz, elemento);
        return;
    }

    //caso 2
    if (cor(elemento->pai) == PRETO &&
        cor(irmao(elemento)) == VERMELHO &&
        cor(irmao(elemento)->dir) == PRETO &&
        cor(irmao(elemento)->esq) == PRETO) {
        //Verifica se é o caso 2 esquerdo ou direito
        if (eh_filho_esquerdo(elemento))
            rotacao_simples_esquerda(raiz, elemento->pai);
        else
            rotacao_simples_direita(raiz, elemento->pai);

        elemento->pai->pai->cor = PRETO;
        elemento->pai->cor = VERMELHO;

        reajustar(raiz, elemento);
        return;
    }

    //caso 3
    if (cor(elemento->pai) == PRETO &&
        cor(irmao(elemento)) == PRETO &&
        cor(irmao(elemento)->dir) == PRETO &&
        cor(irmao(elemento)->esq) == PRETO) {

        elemento->pai->cor = DUPLO_PRETO;
        irmao(elemento)->cor = VERMELHO;
        retira_duplo_preto(raiz, elemento);
        reajustar(raiz, elemento->pai);

        return;
    }

    //caso 4
    if (cor(elemento->pai) == VERMELHO &&
        cor(irmao(elemento)) == PRETO &&
        cor(irmao(elemento)->dir) == PRETO &&
        cor(irmao(elemento)->esq) == PRETO) {
        //Verificar e remover o no_null
        elemento->pai->cor = PRETO;
        irmao(elemento)->cor = VERMELHO;
        retira_duplo_preto(raiz, elemento);
        return;
    }

    //Casos 5 e 6 ficam mais fáceis separando o esquerdo do direito
    //caso 5a
    if (cor(elemento->pai->dir) == PRETO &&
        cor(elemento->pai->dir->dir) == PRETO &&
        cor(elemento->pai->dir->esq) == VERMELHO) {

        rotacao_simples_direita(raiz, irmao(elemento));
        irmao(elemento)->cor = PRETO;
        irmao(elemento)->dir->cor = VERMELHO;
        reajustar(raiz, elemento);

        return;
    }

    //caso 5b
    if (cor(elemento->pai->esq) == PRETO &&
        cor(elemento->pai->esq->esq) == PRETO &&
        cor(elemento->pai->esq->dir) == VERMELHO) {
        //sobrinho próximo ao eixo de simetria é vermelho
        rotacao_simples_esquerda(raiz, irmao(elemento));
        irmao(elemento)->cor = PRETO;
        irmao(elemento)->esq->cor = VERMELHO;
        reajustar(raiz, elemento);

        return;
    }

    //caso 6a
    if (cor(irmao(elemento)) == PRETO &&
        cor(irmao(elemento)->dir) == VERMELHO &&
        eh_filho_esquerdo(elemento)) {
        rotacao_simples_esquerda(raiz, elemento->pai);
        avo(elemento)->cor = elemento->pai->cor;
        elemento->pai->cor = PRETO;
        tio(elemento)->cor = PRETO;
        retira_duplo_preto(raiz, elemento);
        return;
    }

    //caso 6b
    if (cor(irmao(elemento)) == PRETO &&
        cor(irmao(elemento)->esq) == VERMELHO &&
        eh_filho_direito(elemento)) {
        rotacao_simples_direita(raiz, elemento->pai);
        avo(elemento)->cor = elemento->pai->cor;
        elemento->pai->cor = PRETO;
        tio(elemento)->cor = PRETO;
        retira_duplo_preto(raiz, elemento);
        return;
    }
}

void retira_duplo_preto(arvore *raiz, arvore elemento) {
//    if (elemento == no_null)
//        if (eh_filho_esquerdo(elemento))
//            elemento->pai->esq = NULL;
//        else
//            elemento->pai->dir = NULL;
//    else
//        elemento->cor = PRETO;
    if (elemento == no_null) {
        if (eh_raiz(elemento)) {
            *raiz = NULL;
        } else {
            if (eh_filho_esquerdo(elemento)) {
                elemento->pai->esq = NULL;
            } else {
                elemento->pai->dir = NULL;
            }
        }
    } else {
        elemento->cor = PRETO;
    }
}

int maior_elemento(arvore raiz) {
    if (raiz == NULL)
        return -1;
    if (raiz->dir == NULL)
        return raiz->dado;
    else
        return maior_elemento(raiz->dir);
}

int menor_elemento(arvore raiz) {
    if (raiz == NULL)
        return -1;
    if (raiz->esq == NULL)
        return raiz->dado;
    else
        return maior_elemento(raiz->esq);
}


