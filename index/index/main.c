#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"


int main(int argc, char const *argv[])
{
    table tab;
	int option, ind;
	data *book;
	table_initialize(&tab);
	int *controlFB  = malloc(sizeof(int));


    while(1) {
		scanf("%d", &option);

		switch(option) {
				int value;
				case 1:
						printf("%d\n", height(tab.index));
						break;
				case 2:
						addBook(&tab, get_books_information(), controlFB);
						break;
				case 3:
						printf("%d\n", (biggest_element(tab.index))->key);
						break;
				case 4:
						printf("%d\n", (smallest_element(tab.index))->key);
						break;
				case 5:
						pre_order(tab.index, &tab);
						printf("\n");
						break;
				case 6:
						in_order(tab.index, &tab);
						printf("\n");
						break;
				case 7:
						pos_order(tab.index, &tab);
						printf("\n");
						break;

				case 10:
						upload_files("datas.dat", tab.index);
						break;

				case 11:
				    printf("\nIndice do livro: ");
					scanf("%d", &ind);
					printf("==============================================\n");
					printf("      Informações do livro de indice: ");
					book = get_book(&tab, ind);
					printf("\n==============================================");
					printf("\n");

					if(book != NULL){
						printf("\nCódigo : %d\nTitulo: %s\nAutor: %s\nAno: %d\n", book->key, book->title, book->author, book->year);
					}else{
						printf("Livro não encontrado!\n");
					}
					break;


				case 99:
						table_finish(&tab);
						exit(0);
		}
	}
}






