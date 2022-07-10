#include <stdio.h>
#include <stdlib.h>
#include "arvore_rb.h"


int main(int argc, char *argv[]) {
    arvore a;
    int opcao;
    inicializar(&a);

    while (1) {
        scanf("%d", &opcao);

        switch (opcao) {
            int valor;
            case 1:
                scanf("%d", &valor);
                adicionar(valor, &a);
                break;
                //printf("%d\n", altura(a));
            case 2:
                scanf("%d", &valor);
                remover(valor, &a);
                break;
            case 3:
                imprimir(a);
                printf("\n");
                break;
            case 99:
                exit(0);
        }
    }
}

